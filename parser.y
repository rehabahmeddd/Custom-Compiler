%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "symbol_table.h"
#include "quadruples.h"
#include "utils.h"

static Scope* global_scope = NULL;
 Scope* current_scope = NULL;
int is_function_body = 0;

int yylex();
extern int line_number;
extern FILE* yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", line_number, s);
    exit(1);
}

// Temporary variable counter
int temp_counter = 0;

// Function to generate new temporary variable
char* new_temp() {
    char* temp = (char*)malloc(20);
    sprintf(temp, "t%d", temp_counter++);
    return temp;
}

// Label counter
int label_counter = 0;

// Function to generate new label
char* new_label() {
    char* label = (char*)malloc(20);
    sprintf(label, "L%d", label_counter++);
    return label;
}

// Labels for loops and control structures
char* break_label = NULL;
char* continue_label = NULL;
char* old_break_label = NULL;
char* old_continue_label = NULL;

// For loop labels
char* while_start_label = NULL;
char* do_body_label = NULL;
char* for_cond_label = NULL;
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

%type <dtype> type_specifier
%type <sval> expression additive_expression multiplicative_expr relational_expression equality_expression logical_and_expression logical_or_expression unary_expr primary_expr assignment_expression postfix_expression function_call

%%

program:
    { 
        // Initialize the quadruple system
        init_quads();
    }
    translation_unit
    {
        // Print the generated quadruples
        print_quads();
    }
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
        
        // Generate quadruple for allocation
        gen_quad(OP_ALLOCATE, $2, NULL, NULL);
        
        printf("Global Declaration: %s\n", $2);
    }
    | type_specifier ID ASSIGN expression SEMICOLON {
        insert_symbol(current_scope, $2, $1, KIND_VAR, false);
        set_initialized(current_scope,$2);
        
        // Generate quadruples - pass string version of expression
        gen_quad(OP_ALLOCATE, $2, NULL, NULL);
        gen_quad(OP_ASSIGN, $4, NULL, $2);
        
        printf("Global Declaration with assignment: %s\n", $2);
    }
    | CONST type_specifier ID ASSIGN expression SEMICOLON {
        insert_symbol(current_scope, $3, $2, KIND_VAR, true);
        set_initialized(current_scope,$3);
        
        // Generate quadruples - pass string version of expression
        gen_quad(OP_ALLOCATE, $3, NULL, NULL);
        gen_quad(OP_ASSIGN, $5, NULL, $3);
        
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
    type_specifier ID LPAREN   /* Part 1: Before parameters*/
    {
        // Insert function into global symbol table
        insert_symbol(current_scope, $2, $1, KIND_FUNCTION, false);
        printf("Function: %s\n", $2);

        // Set flag and create scope for parameters/body
        is_function_body = 1;            // Mark as function body
        current_scope = create_scope(current_scope);    // New scope for parameters + body

        // Generate function label - DO THIS FIRST
        int first_quad = quad_count;
        gen_quad(OP_LABEL, $2, NULL, NULL);
        
        // Reorder this quad to be at the beginning
        if (first_quad > 0) {
            Quadruple temp = quads[first_quad];
            for (int i = first_quad; i > 0; i--) {
                quads[i] = quads[i-1];
            }
            quads[0] = temp;
        }
    
      // Only generate return if the last instruction is not already a return
        // This check prevents duplicate returns
        int last_quad_idx = quad_count - 1;
        if (last_quad_idx >= 0 && quads[last_quad_idx].op != OP_RETURN) {
            gen_quad(OP_RETURN, NULL, NULL, NULL);
        }
    }
     parameters RPAREN compound_statement                   /* Part 2: Process body */
  
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
        set_initialized(current_scope,$2);
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
        
        // Generate allocation quadruple
        gen_quad(OP_ALLOCATE, $2, NULL, NULL);
        
        printf("Local Declaration: %s\n", $2);
    }
    | type_specifier ID ASSIGN expression SEMICOLON {
        insert_symbol(current_scope, $2, $1, KIND_VAR, false);
        set_initialized(current_scope,$2);
        
        // Generate quadruples
        gen_quad(OP_ALLOCATE, $2, NULL, NULL);
        gen_quad(OP_ASSIGN, $4, NULL, $2);
        
        printf("Local Declaration with assignment: %s\n", $2);
    }
    | CONST type_specifier ID ASSIGN expression SEMICOLON {
        insert_symbol(current_scope, $3, $2, KIND_VAR, true);
        set_initialized(current_scope,$3);
        
        // Generate quadruples
        gen_quad(OP_ALLOCATE, $3, NULL, NULL);
        gen_quad(OP_ASSIGN, $5, NULL, $3);
        
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
        // Create label for false condition
        char* false_label = new_label();
        
        // Generate conditional jump
        gen_quad(OP_JMPF, $3, NULL, false_label);
        
        // Place label at the end
        gen_quad(OP_LABEL, false_label, NULL, NULL);
        
        printf("If statement\n");
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        // If-else statement
        // Create labels
        char* false_label = new_label();
        char* end_label = new_label();
        
        // Generate jumps for condition and after 'then'
        gen_quad(OP_JMPF, $3, NULL, false_label);
        gen_quad(OP_JMP, NULL, NULL, end_label);
        
        // Insert labels
        gen_quad(OP_LABEL, false_label, NULL, NULL);
        gen_quad(OP_LABEL, end_label, NULL, NULL);
        
        printf("If-else statement\n");
    }
    | SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE {
        char* end_switch = new_label();
        old_break_label = break_label;
        break_label = end_switch;

        // Case list will be generated with jump labels, etc.

        gen_quad(OP_LABEL, break_label, NULL, NULL);
        break_label = old_break_label;
        printf("Switch statement\n");
    }
;

case_list:
    case_list case
    | case
;

case:
    CASE INT COLON statement_list {
        // Generate case label
        char* case_label = new_label();
        char* int_str = int_to_str($2);
        gen_quad(OP_LABEL, case_label, NULL, NULL);
        free(int_str);

        printf("Case: %d\n", $2);
    } 
    | DEFAULT COLON statement_list {
        // Generate default label
        char* default_label = new_label();
        gen_quad(OP_LABEL, default_label, NULL, NULL);
        printf("Default case\n");
    } 
;

statement_list:
    statement_list statement
    | /* empty */
;

iteration_statement:
    WHILE LPAREN expression RPAREN statement {
        // Create labels for loop
        char* start_label = new_label();
        char* end_label = new_label();
        
        // Generate quadruples
        gen_quad(OP_LABEL, start_label, NULL, NULL);
        gen_quad(OP_JMPF, $3, NULL, end_label);
        gen_quad(OP_JMP, NULL, NULL, start_label);
        gen_quad(OP_LABEL, end_label, NULL, NULL);
        
        printf("While loop\n");
    }
    | DO statement WHILE LPAREN expression RPAREN SEMICOLON {
        // Create labels for do-while loop
        char* start_label = new_label();
        char* end_label = new_label();
        
        // Generate quadruples
        gen_quad(OP_LABEL, start_label, NULL, NULL);
        gen_quad(OP_JMPT, $5, NULL, start_label);
        gen_quad(OP_LABEL, end_label, NULL, NULL);
        
        printf("Do-while loop\n");
    }
    | FOR LPAREN { is_function_body = 1; current_scope = create_scope(current_scope);}
        for_clause RPAREN statement {  printf("For loop\n"); }
    

    for_clause:
    for_init_statement expression SEMICOLON expression{
         // Create labels for for loop
        char* cond_label = new_label();
        char* body_label = new_label();
        char* update_label = new_label();
        char* end_label = new_label();
        
        // Generate quadruples
        gen_quad(OP_LABEL, cond_label, NULL, NULL);
        gen_quad(OP_JMPF, $4, NULL, end_label);
        gen_quad(OP_LABEL, body_label, NULL, NULL);
        gen_quad(OP_LABEL, update_label, NULL, NULL);
        gen_quad(OP_JMP, NULL, NULL, cond_label);
        gen_quad(OP_LABEL, end_label, NULL, NULL);
    }
;


for_init_statement:
    expression_statement
    | declaration 
;

jump_statement:
    RETURN expression SEMICOLON {
        gen_quad(OP_RETURN, $2, NULL, NULL);
        printf("Return statement\n");
    }
    | RETURN SEMICOLON {
        gen_quad(OP_RETURN, NULL, NULL, NULL);
        printf("Return void\n");
    }
    | BREAK SEMICOLON {
        if (break_label) {
            gen_quad(OP_JMP, NULL, NULL, break_label);
        }
        printf("Break statement\n");
    }
    | CONTINUE SEMICOLON {
        if (continue_label) {
            gen_quad(OP_JMP, NULL, NULL, continue_label);
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
            fprintf(stderr, "Semantic Error: Undeclared variable %s\n", $1);
        } else {
            set_initialized(current_scope,$1);
        }
        
        // Generate assignment quadruple
        gen_quad(OP_ASSIGN, $3, NULL, $1);
        
        $$ = strdup($1);
        printf("Assignment to %s\n", $1);
    }
;

logical_or_expression:
    logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression { 
        // Generate OR operation
        char* temp = new_temp();
        gen_quad(OP_OR, $1, $3, temp);
        $$ = temp;
        
        printf("Logical OR\n"); 
    }
;

logical_and_expression:
    equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression { 
        // Generate AND operation
        char* temp = new_temp();
        gen_quad(OP_AND, $1, $3, temp);
        $$ = temp;
        
        printf("Logical AND\n"); 
    }
;

equality_expression:
    relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression { 
        // Generate equality comparison
        char* temp = new_temp();
        gen_quad(OP_EQ, $1, $3, temp);
        $$ = temp;
        
        printf("Equality\n");
    }
    | equality_expression NEQ relational_expression {
        // Generate inequality comparison
        char* temp = new_temp();
        gen_quad(OP_NEQ, $1, $3, temp);
        $$ = temp;
        
        printf("Not Equal\n");
    }
;

relational_expression:
    additive_expression { $$ = $1; }
    | relational_expression LT additive_expression { 
        // Generate less than comparison
        char* temp = new_temp();
        gen_quad(OP_LT, $1, $3, temp);
        $$ = temp;
        
        printf("Less than\n"); 
    }
    | relational_expression GT additive_expression { 
        // Generate greater than comparison
        char* temp = new_temp();
        gen_quad(OP_GT, $1, $3, temp);
        $$ = temp;
        
        printf("Greater than\n"); 
    }
    | relational_expression LE additive_expression { 
        // Generate less than or equal comparison
        char* temp = new_temp();
        gen_quad(OP_LE, $1, $3, temp);
        $$ = temp;
        
        printf("Less than or equal\n"); 
    }
    | relational_expression GE additive_expression { 
        // Generate greater than or equal comparison
        char* temp = new_temp();
        gen_quad(OP_GE, $1, $3, temp);
        $$ = temp;
        
        printf("Greater than or equal\n"); 
    }
;

additive_expression:
    multiplicative_expr { $$ = $1; }
    | additive_expression ADD multiplicative_expr { 
        // Generate addition
        char* temp = new_temp();
        gen_quad(OP_ADD, $1, $3, temp);
        $$ = temp;
        
        printf("Addition\n"); 
    }
    | additive_expression SUB multiplicative_expr { 
        // Generate subtraction
        char* temp = new_temp();
        gen_quad(OP_SUB, $1, $3, temp);
        $$ = temp;
        
        printf("Subtraction\n"); 
    }
;

multiplicative_expr:
    unary_expr { $$ = $1; }
    | multiplicative_expr MUL unary_expr { 
        // Generate multiplication
        char* temp = new_temp();
        gen_quad(OP_MUL, $1, $3, temp);
        $$ = temp;
        
        printf("Multiplication\n"); 
    }
    | multiplicative_expr DIV unary_expr { 
        // Generate division
        char* temp = new_temp();
        gen_quad(OP_DIV, $1, $3, temp);
        $$ = temp;
        
        printf("Division\n"); 
    }
    | multiplicative_expr MOD unary_expr { 
        // Generate modulo
        char* temp = new_temp();
        gen_quad(OP_MOD, $1, $3, temp);
        $$ = temp;
        
        printf("Modulo\n"); 
    }
;

unary_expr:
    postfix_expression { $$ = $1; }
    | NOT unary_expr { 
        // Generate logical NOT
        char* temp = new_temp();
        gen_quad(OP_NOT, $2, NULL, temp);
        $$ = temp;
        
        printf("Logical NOT\n"); 
    }
    | SUB unary_expr { 
        // Generate unary minus
        char* temp = new_temp();
        gen_quad(OP_NEG, $2, NULL, temp);
        $$ = temp;
        
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
            fprintf(stderr, "Semantic Error: Use of undeclared variable %s\n", $1);
        } else if(!is_initialized(current_scope,name)) {
           
            fprintf(stderr, "Symbol Name: %s\n", name);

            fprintf(stderr, "Semantic Error: Use of uninitialized variable %s\n", $1);
        }
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
            fprintf(stderr, "Semantic Error: Undefined function %s\n", $1);
        }
        
        // Generate call quadruple
        char* temp = new_temp();
        gen_quad(OP_CALL, $1, "0", temp);  // "0" is placeholder for arg count
        $$ = temp;
        
        printf("Function call to: %s\n", $1);
    }
;

argument_list:
    argument_expr_list
    | /* empty */
;

argument_expr_list:
    argument_expr_list COMMA expression {
        // Generate parameter quadruple
        gen_quad(OP_PARAM, $3, NULL, NULL);
    }
    | expression {
        // Generate parameter quadruple
        gen_quad(OP_PARAM, $1, NULL, NULL);
    }
;

%%

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
    
    // Print symbol table
    printf("\n---- SYMBOL TABLE ----\n");
    print_scope(global_scope, 0);
    
    // Free resources
    free_scope(global_scope);
    free_quads();
    
    return 0;
}