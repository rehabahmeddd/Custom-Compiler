%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "symbol_table.h"
#include "utils.h"
#include "quad_handler.h"

static Scope* global_scope = NULL;
Scope* current_scope = NULL;
int is_function_body = 0;
DataType current_param_types[100];
int current_param_index = 0;
DataType arg_types[100];
int arg_count = 0;



// Quadruple handler
QuadHandler* quad_handler = NULL;

// For function handling
DataType current_function_return_type = TYPE_VOID;
Symbol** current_function_parameters = NULL;
int num_current_parameters = 0;
Symbol** function_call_parameters = NULL;
int num_call_parameters = 0;

// For control flow
char* current_loop_start_label = NULL;
char* current_loop_end_label = NULL;
char* current_switch_end_label = NULL;
Symbol* current_switch_var = NULL;
char* current_case_next_label = NULL;




int yylex();
extern int line_number;
extern FILE* yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", line_number, s);
    exit(1);
}



Symbol* create_quad_symbol(const char* value, DataType type) {
    Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
    
    // Basic required fields
    sym->name = strdup(value);
    sym->type = type;
    sym->kind = KIND_VAR;
    sym->initialized = true;
    sym->constant = true;
    
    sym->declared = true;
    sym->value = NULL;
    sym->scope = NULL;
    sym->next = NULL;
    
    sym->param_count = 0;
    sym->param_types = NULL;
    sym->is_used = true;

    
    
    return sym;
}
%}

%union {
    int ival;
    float fval;
    char* sval;
    bool  bval;
    int dtype;  /* For DataType enum */
    struct Symbol* sym;
    char* label;
    struct {
        char* case_label;
        char* next_check_label;
    } case_info;
}

%token <sval> ID
%token <ival> INT
%token <fval> FLOAT
%token <fval> DOUBLE
%token <sval> STRING
%token <sval> CHAR
%token <bval> BOOL

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN CONST

%token INT_TYPE FLOAT_TYPE DOUBLE_TYPE STRING_TYPE CHAR_TYPE VOID_TYPE BOOL_TYPE 

%token ASSIGN
%token ADD SUB MUL DIV MOD
%token LT GT EQ NEQ LE GE
%token AND OR NOT

%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA COLON

%type <ival> argument_list argument_expr_list
%type <dtype> type_specifier
%type <sym> expression additive_expression multiplicative_expr relational_expression equality_expression logical_and_expression logical_or_expression unary_expr primary_expr assignment_expression postfix_expression function_call for_clause
%type <label> if_condition while_condition
%type <case_info> case

%%

program:
    translation_unit
;

translation_unit:
    translation_unit external_declaration
    | external_declaration
;

external_declaration:
    function_definition
    | global_declaration
;

global_declaration:
    type_specifier ID SEMICOLON {
        insert_symbol(current_scope, $2, $1, KIND_VAR, false);        
        printf("Global Declaration: %s\n", $2);
    }
    | type_specifier ID ASSIGN expression SEMICOLON {
        Symbol* sym = insert_symbol(current_scope, $2, $1, KIND_VAR, false);
        set_initialized(current_scope,$2);

        quad_gen_assign(quad_handler, sym, $4);
        
        Symbol* sym1 = lookup_symbol(current_scope, $2);
        if (sym1 && sym1->type != infer_expr_type(current_scope,$4->name)) {
            fprintf(stderr, "Semantic Error at line %d: Type mismatch in declaration of '%s'. Expected %s but got %s.\n",
                line_number, $2, dataTypeName[sym1->type], dataTypeName[infer_expr_type(current_scope,$4->name)]);
            exit(1);
        }
        printf("Global Declaration with assignment: %s\n", $2);
    }
    | CONST type_specifier ID ASSIGN expression SEMICOLON {
        Symbol* sym = insert_symbol(current_scope, $3, $2, KIND_VAR, true);
        set_initialized(current_scope,$3);
        quad_gen_assign(quad_handler, sym, $5);
        printf("Global Constant declaration: %s\n", $3);
    }
;

type_specifier:
    INT_TYPE { $$ = TYPE_INT; }
    | FLOAT_TYPE { $$ = TYPE_FLOAT; }
    | DOUBLE_TYPE { $$ = TYPE_DOUBLE; }
    | STRING_TYPE { $$ = TYPE_STRING; }
    | CHAR_TYPE { $$ = TYPE_CHAR; }
    | BOOL_TYPE { $$ = TYPE_BOOL; }
    | VOID_TYPE { $$ = TYPE_VOID; }
;

function_definition:
    type_specifier ID LPAREN {
        Symbol* func = insert_symbol(current_scope, $2, $1, KIND_FUNCTION, false);

         

        // Reset parameter tracker
        current_param_index = 0;

        is_function_body = 1;
        current_scope = create_scope(current_scope);

        current_function_return_type = $1;
        num_current_parameters = 0;

        quad_add_func_begin(quad_handler, func->name);
    }
    parameters RPAREN {
        // Re-lookup function symbol to attach parameter types
        Symbol* func = lookup_symbol(global_scope, $2);
        if (!func) {
            fprintf(stderr, "Internal Error: Function symbol '%s' not found for parameter assignment.\n", $2);
            exit(1);
        }

        func->param_types = malloc(sizeof(DataType) * current_param_index);
        func->param_count = current_param_index;
        for (int i = 0; i < current_param_index; i++) {
            func->param_types[i] = current_param_types[i];
        }
    }
    compound_statement {
        // Write function end quadruple
        quad_add_func_end(quad_handler);
        
        // Reset function tracking
        current_function_return_type = TYPE_VOID;
        num_current_parameters = 0;
    }
;


parameters:
    parameter_list
    | /* empty */
;

parameter_list:
    parameter_list COMMA parameter
    | parameter
;

parameter:
    type_specifier ID {
        insert_symbol(current_scope, $2, $1, KIND_PARAMETER, false);
        set_initialized(current_scope, $2);
        current_param_types[current_param_index++] = $1;  // Collect type
        printf("Parameter: %s\n", $2);
    }
;


compound_statement:
    LBRACE 
    {
        if (!is_function_body) {
            // Only create a new scope for non-function blocks (loops/if)
            current_scope = create_scope(current_scope);
        }
        else
        {is_function_body=0;}
        
    }
    block_item_list 
    RBRACE 
    {
       
            // Only leave scope for non-function blocks
            leave_scope(&current_scope);
        
    }
;

block_item_list:
    block_item_list block_item
    | /* empty */
;

block_item:
    declaration
    | statement
;

declaration:
    type_specifier ID SEMICOLON {
        insert_symbol(current_scope, $2, $1, KIND_VAR, false);
        printf("Local Declaration: %s\n", $2);
    }
    | type_specifier ID ASSIGN expression SEMICOLON {
        Symbol* sym = insert_symbol(current_scope, $2, $1, KIND_VAR, false);
        set_initialized(current_scope,$2);

        quad_gen_assign(quad_handler, sym, $4);

        Symbol* sym1 = lookup_symbol(current_scope, $2);
        if (sym1 && sym1->type != infer_expr_type(current_scope,$4->name)) {
            fprintf(stderr, "Semantic Error line %d: Type mismatch in declaration of '%s'. Expected %s but got %s.\n",
                line_number, $2, dataTypeName[sym1->type], dataTypeName[infer_expr_type(current_scope,$4->name)]);
            exit(1);
        }
        printf("Local Declaration with assignment: %s\n", $2);
    }
    | CONST type_specifier ID ASSIGN expression SEMICOLON {
        Symbol* sym = insert_symbol(current_scope, $3, $2, KIND_VAR, true);
        set_initialized(current_scope,$3);
        quad_gen_assign(quad_handler, sym, $5);
        printf("Local Constant declaration: %s\n", $3);
    }
;

statement:
    expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
;

expression_statement:
    expression SEMICOLON
    | SEMICOLON
;


if_condition:
   LPAREN expression RPAREN {
       char* false_label = quad_new_label(quad_handler);
       $$ = false_label;
       quad_add_if_jump(quad_handler, $2->name, false_label, 0);
   }

selection_statement:
    IF if_condition statement %prec LOWER_THAN_ELSE {
        quad_add_label(quad_handler, $2);
        free($2);
        printf("If statement\n");
    }
    | IF if_condition statement ELSE {
        char* end_label = quad_new_label(quad_handler);
        quad_add_goto(quad_handler, end_label);
        quad_add_label(quad_handler, $2);
        free($2);
        $<label>$ = end_label;

    } statement {

        quad_add_label(quad_handler, $<label>5);
        free($<label>5);
        printf("If-else statement\n");
    }
    | SWITCH LPAREN expression RPAREN {
        // Create end label for switch
        current_switch_end_label = quad_new_label(quad_handler);
         
        // Save the switch expression as a global variable
        current_switch_var = $3;
        printf("Switch on: %s\n", $3->name);
 
    } LBRACE case_list RBRACE {

        // Write end label
        quad_add_label(quad_handler, current_switch_end_label);
        free(current_switch_end_label);
        current_switch_end_label = NULL;
        current_switch_var = NULL;  // Clear the switch variable
        printf("Switch statement\n");
    }
;

case_list:
    case_list case
    | case
;

case:
    CASE INT COLON {
        // Generate comparison with switch variable
        char value[20];
        sprintf(value, "%d", $2);
        Symbol* const_sym = create_quad_symbol(value, TYPE_INT);
        Symbol* condition = quad_gen_rel(quad_handler, OP_EQ, current_switch_var, const_sym);
        
        // Generate two labels: one for this case and one for the next case/condition
        char* this_case_label = quad_new_label(quad_handler);
        char* next_case_label = quad_new_label(quad_handler);
        
        // Add the conditional jump - if equal, go to this case
        quad_add_if_jump(quad_handler, condition->name, this_case_label, 1);
        
        // Otherwise, go to the next case check
        quad_add_goto(quad_handler, next_case_label);
        
        // Mark the start of this case's code
        quad_add_label(quad_handler, this_case_label);
        
        // Store the label for the next case in the global variable
        current_case_next_label = next_case_label;
    } statement_list {
        // After the statement list, add the label for the next case check
        if (current_case_next_label) {
            quad_add_label(quad_handler, current_case_next_label);
            current_case_next_label = NULL; // Reset for next case
        }
        printf("Case: %d\n", $2);
    } 
    | DEFAULT COLON {
        // Simply add a label for the default case
        char* default_label = quad_new_label(quad_handler);
        quad_add_label(quad_handler, default_label);
    } statement_list {
        printf("Default case\n");
    }

statement_list:
    statement_list statement
    | /* empty */
;


while_condition:
    LPAREN {
       // Generate label for loop start
       char* start_label = quad_new_label(quad_handler);
       current_loop_start_label = start_label;
       quad_add_label(quad_handler, start_label);
       $<label>$ = start_label;
    } expression RPAREN {
       // Generate label for loop end
       char* end_label = quad_new_label(quad_handler);
       current_loop_end_label = end_label;
       
       // Jump to end if condition is false
       quad_add_if_jump(quad_handler, $3->name, end_label, 0);
       
       $$ = end_label;
    }

iteration_statement:
    WHILE while_condition statement {
        // Jump back to condition check
        quad_add_goto(quad_handler, current_loop_start_label);
        
        // End label
        quad_add_label(quad_handler, current_loop_end_label);
        
        // Cleanup
        free(current_loop_start_label);
        current_loop_start_label = NULL;
        free(current_loop_end_label);
        current_loop_end_label = NULL;
        printf("While loop\n");
    }
    | DO {
        // Generate label for loop start
        char* start_label = quad_new_label(quad_handler);
        current_loop_start_label = start_label;
        quad_add_label(quad_handler, start_label);
        $<label>$ = start_label;
    } statement WHILE LPAREN expression RPAREN SEMICOLON {
        // Jump back to start if condition is true
        quad_add_if_jump(quad_handler, $6->name, current_loop_start_label, 1);
        
        // Cleanup
        free(current_loop_start_label);
        current_loop_start_label = NULL;
        printf("Do-while loop\n");
    }
    | FOR LPAREN {is_function_body = 1; current_scope = create_scope(current_scope);}
        for_clause RPAREN statement {       
            // Jump back to condition check
            quad_add_goto(quad_handler, current_loop_start_label);
            
            // Add end label
            quad_add_label(quad_handler, current_loop_end_label);
            
            // Cleanup
            free(current_loop_start_label);
            current_loop_start_label = NULL;
            free(current_loop_end_label);
            current_loop_end_label = NULL;
            
            // Return to original scope
            //leave_scope(&current_scope);
            printf("For loop\n"); 
        }  

for_clause:
    for_init_statement expression SEMICOLON expression {
        // Create labels for for loop
        char* cond_label = quad_new_label(quad_handler);
        char* end_label = quad_new_label(quad_handler);
        
        // Generate condition label
        quad_add_label(quad_handler, cond_label);
        
        // Jump to end if condition is false
        quad_add_if_jump(quad_handler, $2->name, end_label, 0);
        
        // Store for later use in break/continue
        current_loop_start_label = cond_label;
        current_loop_end_label = end_label;
        
        // Return the increment expression
        $$ = $4;
    }


for_init_statement:
    expression_statement
    | declaration 
;

jump_statement:
    RETURN expression SEMICOLON {
        if (current_function_return_type == TYPE_VOID) {
            yyerror("Cannot return a value from a void function");
        }

        // Generate return quadruple (handle NULL expression case gracefully)
        if ($2 != NULL) {
            quad_add_return(quad_handler, $2->name);
        } else {
            quad_add_return(quad_handler, "0"); // default return value
        }
        printf("Return statement\n");
    }
    | RETURN SEMICOLON {
        if (current_function_return_type != TYPE_VOID) {
            yyerror("Function should return a value");
        }
        
        // Generate return quadruple
        quad_add_return(quad_handler, NULL);
    }
    | BREAK SEMICOLON {
       if (current_loop_end_label != NULL) {
           quad_add_goto(quad_handler, current_loop_end_label);
       } else if (current_switch_end_label != NULL) {
           quad_add_goto(quad_handler, current_switch_end_label);
       } else {
           yyerror("Break statement outside loop or switch");
       }
       printf("Break statement\n");
    }
    | CONTINUE SEMICOLON {
         // Jump to start of current loop
        if (current_loop_start_label == NULL) {
            yyerror("Continue statement outside loop");
        } else {
            quad_add_goto(quad_handler, current_loop_start_label);
        }
        printf("Continue statement\n");
    }
;

expression:
    assignment_expression { $$ = $1; }
;

assignment_expression:
    logical_or_expression { $$ = $1; }
    | ID ASSIGN assignment_expression {
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym == NULL) {
            fprintf(stderr, "Semantic Error at line %d: Undeclared variable %s\n",line_number, $1);
            exit(1);
        } else if (sym->constant) {
            fprintf(stderr, "Semantic Error at line %d: Cannot reassign to constant variable %s\n",line_number, $1);
            exit(1);
        } else {
            set_initialized(current_scope,$1);
            sym->is_used = true;

            if (sym->type != infer_expr_type(current_scope,$3->name)) {
            fprintf(stderr, "Semantic Error line %d: Type mismatch in assignment to '%s'. Expected %s but got %s.\n",
                line_number, $1, dataTypeName[sym->type], dataTypeName[infer_expr_type(current_scope,$3->name)]);
                exit(1);
            }
            printf("Assignment to %s\n", $1);
        }
        quad_gen_assign(quad_handler, sym, $3);
        $$ = sym;
        //$$ = strdup($1);
    }
;

logical_or_expression:
    logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "||")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical or: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }

        $$ = quad_gen_logic(quad_handler, OP_OR, $1, $3);

        
        printf("Logical OR\n"); 
    }
;

logical_and_expression:
    equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "&&")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical and: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_logic(quad_handler, OP_AND, $1, $3);
        printf("Logical AND\n"); 

    }
;

equality_expression:
    relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "==")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_rel(quad_handler, OP_EQ, $1, $3);
        printf("Equality\n");
    }
    | equality_expression NEQ relational_expression {
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "!=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for not equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_rel(quad_handler, OP_NEQ, $1, $3);
        printf("Not Equal\n");
    }
;

relational_expression:
    additive_expression { $$ = $1; }
    | relational_expression LT additive_expression { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "<")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for less than: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_rel(quad_handler, OP_LT, $1, $3);
        printf("Less than\n"); 
    }
    | relational_expression GT additive_expression { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, ">")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for greater than: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_rel(quad_handler, OP_GT, $1, $3);
        printf("Greater than\n"); 
    }
    | relational_expression LE additive_expression { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "<=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for less than or equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_rel(quad_handler, OP_LE, $1, $3);
        printf("Less than or equal\n"); 
    }
    | relational_expression GE additive_expression { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, ">=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for greater than or equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_rel(quad_handler, OP_GE, $1, $3);
        printf("Greater than or equal\n"); 
    }
;

additive_expression:
    multiplicative_expr { $$ = $1; }
    | additive_expression ADD multiplicative_expr { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "+")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for addition: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_math(quad_handler, OP_ADD, $1, $3);
        printf("Addition\n"); 
    }
    | additive_expression SUB multiplicative_expr { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "-")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for subtraction: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_math(quad_handler, OP_SUB, $1, $3);
        printf("Subtraction\n"); 
    }
;

multiplicative_expr:
    unary_expr { $$ = $1; }
    | multiplicative_expr MUL unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "*")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for multiplication: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_math(quad_handler, OP_MUL, $1, $3);
        printf("Multiplication\n"); 
    }
    | multiplicative_expr DIV unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "/")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for division: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_math(quad_handler, OP_DIV, $1, $3);
        printf("Division\n"); 
    }
    | multiplicative_expr MOD unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$1->name);
        DataType rightType = infer_expr_type(current_scope,$3->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "%")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for modulus: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        $$ = quad_gen_math(quad_handler, OP_MOD, $1, $3);
        printf("Modulo\n"); 
    }
;

unary_expr:
    postfix_expression { $$ = $1; }
    | NOT unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$2->name);
        if (!areTypesCompatibleForOp(leftType, TYPE_BOOL, "!")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical not: %s\n",
                line_number, dataTypeName[leftType]);
            exit(1);
        }
        $$ = quad_gen_logic(quad_handler, OP_NOT, $2, NULL);
        printf("Logical NOT\n"); 
    }
    | SUB unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$2->name);
        if (!areTypesCompatibleForOp(leftType, TYPE_INT, "-")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for unary minus: %s\n",
                line_number, dataTypeName[leftType]);
            exit(1);
        }
        Symbol* zero = create_quad_symbol("0", $2->type);
        $$ = quad_gen_math(quad_handler, OP_SUB, zero, $2);
        printf("Unary minus\n"); 
    }
;

postfix_expression:
    primary_expr { $$ = $1; }
    | function_call { $$ = $1; }
;

primary_expr:
    ID {
        Symbol* sym = lookup_symbol(current_scope, $1);
        const char* name=get_symbol_name(sym);
        if (sym == NULL) {
            fprintf(stderr, "Semantic Error at line %d: Use of undeclared variable %s\n",line_number, $1);
            exit(1);
        } else if(!is_initialized(current_scope,name)) {
           
            fprintf(stderr, "Symbol Name: %s\n", name);

            fprintf(stderr, "Semantic Error at line %d: Use of uninitialized variable %s\n",line_number, $1);
            exit(1);
        }
        sym->is_used = true;
        //$$ = strdup($1);
        $$ = sym;
        printf("Primary ID: %s\n", $1);
    }
    | INT { 
        // Convert INT to string
        char value[20];
        sprintf(value, "%d", $1);
        $$ = create_quad_symbol(value, TYPE_INT);
        printf("Primary int: %d\n", $1); 
    }
    | FLOAT { 
       // Convert FLOAT to string
       char value[20];
       sprintf(value, "%f", $1);
       $$ = create_quad_symbol(value, TYPE_FLOAT);
        printf("Primary float: %f\n", $1); 
    }
    | DOUBLE { 
        // Convert DOUBLE to string
        char value[20];
        sprintf(value, "%f", $1);
        $$ = create_quad_symbol(value, TYPE_DOUBLE);
        printf("Primary double: %f\n", $1); 
    }
    | STRING { 
        $$ = create_quad_symbol($1, TYPE_STRING);
        printf("Primary string: %s\n", $1); 
    }
    | CHAR { 
        $$ = create_quad_symbol($1, TYPE_CHAR);
        printf("Primary char: %c\n", $1[1]); 
    }
    | BOOL { 
        $$ = create_quad_symbol($1 ? "true" : "false", TYPE_BOOL);
        printf("Primary bool: %s\n", $1 ? "true" : "false"); 
    }
    | LPAREN expression RPAREN { $$ = $2; }
;

function_call:
    ID LPAREN {
        num_call_parameters = 0;
    } argument_list RPAREN {
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (!sym || sym->kind != KIND_FUNCTION) {
            fprintf(stderr, "Semantic Error at line %d: Undefined function %s\n", line_number,$1);
            exit(1);
        } else {
            if (arg_count != sym->param_count) {
                fprintf(stderr, "Semantic Error at line %d: Function '%s' expects %d arguments, but %d were given\n",
                    line_number,$1, sym->param_count, arg_count);
                exit(1);
            } else {

                // Create a temporary for the result
                char* temp = quad_new_temp(quad_handler, sym->type);
                num_call_parameters = $4;

                // Add parameters
                for (int i = 0; i < arg_count; i++) {
  
                    quad_add_param(quad_handler, function_call_parameters[i]->name);
                }

                

                for (int i = 0; i < arg_count; i++) {
                    if (arg_types[i] != sym->param_types[i]) {
                        fprintf(stderr, "Semantic Error at line %d: Type mismatch for parameter %d in function '%s'. Expected %s but got %s\n",
                            line_number,i + 1, $1, dataTypeName[sym->param_types[i]], dataTypeName[arg_types[i]]);
                        exit(1);
                    }
                }

                // Call the function
                quad_add_call(quad_handler, sym->name, arg_count, temp);

                // Create and return a symbol for the result
                Symbol* result = (Symbol*)malloc(sizeof(Symbol));
                result->name = temp;
                result->type = sym->type;
                result->kind = KIND_VAR;
                result->declared = true;
                result->initialized = true;
                result->constant = false;
                result->value = NULL;
                result->scope = NULL;
                result->next = NULL;
                
                $$ = result;
            }


           
        }
        printf("Function call to: %s\n", $1);
    }
;

argument_list:
    argument_expr_list { arg_count = $$; }
    | /* empty */ { arg_count = 0; }
;

argument_expr_list:
    argument_expr_list COMMA expression {
        arg_types[$$++] = infer_expr_type(current_scope, $3->name);
        function_call_parameters[arg_count++] = $3;
        $$ = arg_count;
    }
    | expression {
        arg_types[0] = infer_expr_type(current_scope, $1->name);
        function_call_parameters[0] = $1;
        arg_count = 1;
        $$ = 1;
    }
;


%%

void warn_unused_vars(Scope* scope) {
    if (!scope) return;

    Symbol* sym = scope->symbols;
    while (sym) {
        if (sym->kind == KIND_VAR && !sym->is_used) {
            fprintf(stderr, "Warning: Variable '%s' declared but never used\n", sym->name);
        }
        sym = sym->next;
    }

    // Recurse into child scopes
    Scope* child = scope->children;
    while (child) {
        warn_unused_vars(child);
        child = child->sibling;
    }
}


int main(int argc, char* argv[]) {
    // Initialize symbol table
    global_scope = create_scope(NULL);
    current_scope = global_scope;


    // Initialize quad handler
    quad_handler = quad_init("quads.txt");

    // Allocate space for function parameters
    current_function_parameters = (Symbol**)malloc(100 * sizeof(Symbol*));
    function_call_parameters = (Symbol**)malloc(100 * sizeof(Symbol*));
    
    // Check if a file is provided
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
        
        // Set input to the file
        yyin = file;
    }
    
    // Parse input
    yyparse();

    warn_unused_vars(global_scope);
    
    // Print symbol table
    printf("\n---- SYMBOL TABLE ----\n");
    print_scope(global_scope, 0);
    
    // Free resources
    free_scope(global_scope);
    quad_cleanup(quad_handler);
    free(current_function_parameters);
    free(function_call_parameters);
    
    return 0;
}