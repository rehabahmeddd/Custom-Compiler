%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "symbol_table.h"
#include "utils.h"

static Scope* global_scope = NULL;
Scope* current_scope = NULL;
int is_function_body = 0;
DataType current_param_types[100];
int current_param_index = 0;
DataType arg_types[100];
int arg_count = 0;


int yylex();
extern int line_number;
extern FILE* yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", line_number, s);
    exit(1);
}
%}

%union {
    int ival;
    float fval;
    char* sval;
    bool  bval;
    int dtype;  /* For DataType enum */
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
%type <sval> expression additive_expression multiplicative_expr relational_expression equality_expression logical_and_expression logical_or_expression unary_expr primary_expr assignment_expression postfix_expression function_call

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
        insert_symbol(current_scope, $2, $1, KIND_VAR, false);
        set_initialized(current_scope,$2);
        
        Symbol* sym = lookup_symbol(current_scope, $2);
        if (sym && sym->type != infer_expr_type(current_scope,$4)) {
            fprintf(stderr, "Semantic Error at line %d: Type mismatch in declaration of '%s'. Expected %s but got %s.\n",
                line_number, $2, dataTypeName[sym->type], dataTypeName[infer_expr_type(current_scope,$4)]);
            exit(1);
        }
        printf("Global Declaration with assignment: %s\n", $2);
    }
    | CONST type_specifier ID ASSIGN expression SEMICOLON {
        insert_symbol(current_scope, $3, $2, KIND_VAR, true);
        set_initialized(current_scope,$3);
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
        insert_symbol(current_scope, $2, $1, KIND_FUNCTION, false);

        // Reset parameter tracker
        current_param_index = 0;

        is_function_body = 1;
        current_scope = create_scope(current_scope);
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
    compound_statement 
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
        insert_symbol(current_scope, $2, $1, KIND_VAR, false);
        set_initialized(current_scope,$2);

        Symbol* sym = lookup_symbol(current_scope, $2);
        if (sym && sym->type != infer_expr_type(current_scope,$4)) {
            fprintf(stderr, "Semantic Error line %d: Type mismatch in declaration of '%s'. Expected %s but got %s.\n",
                line_number, $2, dataTypeName[sym->type], dataTypeName[infer_expr_type(current_scope,$4)]);
            exit(1);
        }
        printf("Local Declaration with assignment: %s\n", $2);
    }
    | CONST type_specifier ID ASSIGN expression SEMICOLON {
        insert_symbol(current_scope, $3, $2, KIND_VAR, true);
        set_initialized(current_scope,$3);
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

selection_statement:
    IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
        printf("If statement\n");
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        printf("If-else statement\n");
    }
    | SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE {
        printf("Switch statement\n");
    }
;

case_list:
    case_list case
    | case
;

case:
    CASE INT COLON statement_list {
        printf("Case: %d\n", $2);
    } 
    | DEFAULT COLON statement_list {
        printf("Default case\n");
    } 
;

statement_list:
    statement_list statement
    | /* empty */
;

iteration_statement:
    WHILE LPAREN expression RPAREN statement {
        printf("While loop\n");
    }
    | DO statement WHILE LPAREN expression RPAREN SEMICOLON {
        printf("Do-while loop\n");
    }
    | FOR LPAREN { is_function_body = 1; current_scope = create_scope(current_scope);}
        for_clause RPAREN statement {  printf("For loop\n"); }
;   

for_clause:
    for_init_statement expression SEMICOLON expression
;


for_init_statement:
    expression_statement
    | declaration 
;

jump_statement:
    RETURN expression SEMICOLON {
        printf("Return statement\n");
    }
    | RETURN SEMICOLON {
        printf("Return void\n");
    }
    | BREAK SEMICOLON {
        printf("Break statement\n");
    }
    | CONTINUE SEMICOLON {
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

            if (sym->type != infer_expr_type(current_scope,$3)) {
            fprintf(stderr, "Semantic Error line %d: Type mismatch in assignment to '%s'. Expected %s but got %s.\n",
                line_number, $1, dataTypeName[sym->type], dataTypeName[infer_expr_type(current_scope,$3)]);
                exit(1);
            }
            printf("Assignment to %s\n", $1);
        }
        $$ = strdup($1);
    }
;

logical_or_expression:
    logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "||")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical or: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Logical OR\n"); 
    }
;

logical_and_expression:
    equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "&&")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical and: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Logical AND\n"); 
    }
;

equality_expression:
    relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "==")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Equality\n");
    }
    | equality_expression NEQ relational_expression {
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "!=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for not equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Not Equal\n");
    }
;

relational_expression:
    additive_expression { $$ = $1; }
    | relational_expression LT additive_expression { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "<")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for less than: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Less than\n"); 
    }
    | relational_expression GT additive_expression { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, ">")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for greater than: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Greater than\n"); 
    }
    | relational_expression LE additive_expression { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "<=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for less than or equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Less than or equal\n"); 
    }
    | relational_expression GE additive_expression { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, ">=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for greater than or equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Greater than or equal\n"); 
    }
;

additive_expression:
    multiplicative_expr { $$ = $1; }
    | additive_expression ADD multiplicative_expr { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "+")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for addition: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Addition\n"); 
    }
    | additive_expression SUB multiplicative_expr { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "-")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for subtraction: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Subtraction\n"); 
    }
;

multiplicative_expr:
    unary_expr { $$ = $1; }
    | multiplicative_expr MUL unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "*")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for multiplication: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Multiplication\n"); 
    }
    | multiplicative_expr DIV unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "/")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for division: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Division\n"); 
    }
    | multiplicative_expr MOD unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$1);
        DataType rightType = infer_expr_type(current_scope,$3);
        if (!areTypesCompatibleForOp(leftType, rightType, "%")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for modulus: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Modulo\n"); 
    }
;

unary_expr:
    postfix_expression { $$ = $1; }
    | NOT unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$2);
        if (!areTypesCompatibleForOp(leftType, TYPE_BOOL, "!")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical not: %s\n",
                line_number, dataTypeName[leftType]);
            exit(1);
        }
        printf("Logical NOT\n"); 
    }
    | SUB unary_expr { 
        DataType leftType = infer_expr_type(current_scope,$2);
        if (!areTypesCompatibleForOp(leftType, TYPE_INT, "-")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for unary minus: %s\n",
                line_number, dataTypeName[leftType]);
            exit(1);
        }
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
        $$ = strdup($1);
        printf("Primary ID: %s\n", $1);
    }
    | INT { 
        // Convert INT to string
        $$ = int_to_str($1);
        printf("Primary int: %d\n", $1); 
    }
    | FLOAT { 
        // Convert FLOAT to string
        $$ = float_to_str($1);
        printf("Primary float: %f\n", $1); 
    }
    | DOUBLE { 
        // Convert DOUBLE to string
        $$ = double_to_str($1);
        printf("Primary double: %f\n", $1); 
    }
    | STRING { 
        $$ = strdup($1);
        printf("Primary string: %s\n", $1); 
    }
    | CHAR { 
        $$ = strdup($1);
        printf("Primary char: %c\n", $1[1]); 
    }
    | BOOL { 
        $$ = bool_to_str($1);
        printf("Primary bool: %s\n", $1 ? "true" : "false"); 
    }
    | LPAREN expression RPAREN { $$ = $2; }
;

function_call:
    ID LPAREN argument_list RPAREN {
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
            for (int i = 0; i < arg_count; i++) {
                if (arg_types[i] != sym->param_types[i]) {
                    fprintf(stderr, "Semantic Error at line %d: Type mismatch for parameter %d in function '%s'. Expected %s but got %s\n",
                        line_number,i + 1, $1, dataTypeName[sym->param_types[i]], dataTypeName[arg_types[i]]);
                    exit(1);
                }
            }
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
        arg_types[$$++] = infer_expr_type(current_scope,$3);
        $$ = $$;
    }
    | expression {
        arg_types[0] = infer_expr_type(current_scope,$1);
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
    
    return 0;
}