%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "symbol_table.h"

Scope* global_scope = NULL;
Scope* current_scope = NULL;
int is_function_body = 0;

int yylex();
void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
%}



%union {
    int ival;
    float fval;
    char* sval;
    bool  bval;
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

%type <ival> type_specifier
%type <ival> expression additive_expression multiplicative_expr relational_expression equality_expression logical_and_expression logical_or_expression unary_expr primary_expr assignment_expression postfix_expression function_call

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
        set_initialized($2);
        set_value($2, $1, &$4);
        printf("Global Declaration with assignment: %s\n", $2);
    }
    | CONST type_specifier ID ASSIGN expression SEMICOLON {
        Symbol* sym = insert_symbol(current_scope, $3, $2, KIND_VAR, true);
        set_initialized($3);
        set_value($3, $2, &$5);
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
    type_specifier ID LPAREN parameters RPAREN  /* Part 1: Before compound_statement */
    {
        // Insert function into global symbol table
        insert_symbol(current_scope, $2, $1, KIND_FUNCTION, false);
        printf("Function: %s\n", $2);

        // Set flag and create scope for parameters/body
        is_function_body = 1;            // Mark as function body
        current_scope = create_scope(current_scope);    // New scope for parameters + body
    }
    compound_statement                   /* Part 2: Process body */
    {
        is_function_body = 0;            // Reset flag after function body
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
    }
    block_item_list 
    RBRACE 
    {
        if (!is_function_body) {
            // Only leave scope for non-function blocks
            leave_scope(&current_scope);
        }
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
        set_value($2, $1, &$4);
        set_initialized($2);
        printf("Local Declaration with assignment: %s\n", $2);
    }
    | CONST type_specifier ID ASSIGN expression SEMICOLON {
        insert_symbol(current_scope, $3, $2, KIND_VAR, true);
        set_initialized($3);
        set_value($3, $2, &$5);
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
        for_clause RPAREN statement { is_function_body = 0;  printf("For loop\n"); }
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
    assignment_expression
;

assignment_expression:
    logical_or_expression
    | ID ASSIGN assignment_expression {
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym == NULL) {
            fprintf(stderr, "Semantic Error: Undeclared variable %s\n", $1);
        } else {
            set_initialized($1);
            set_value($1, sym->type, &$3);
        }
        printf("Assignment to %s\n", $1);
    }
;

logical_or_expression:
    logical_and_expression
    | logical_or_expression OR logical_and_expression { printf("Logical OR\n"); }
;

logical_and_expression:
    equality_expression
    | logical_and_expression AND equality_expression { printf("Logical AND\n"); }
;

equality_expression:
    relational_expression
    | equality_expression EQ relational_expression { printf("Equality\n");}
    | equality_expression NEQ relational_expression {printf("Not Equal\n");}
;

relational_expression:
    additive_expression
    | relational_expression LT additive_expression { printf("Less than\n"); }
    | relational_expression GT additive_expression { printf("Greater than\n"); }
    | relational_expression LE additive_expression { printf("Less than or equal\n"); }
    | relational_expression GE additive_expression { printf("Greater than or equal\n"); }
;

additive_expression:
    multiplicative_expr
    | additive_expression ADD multiplicative_expr { printf("Addition\n"); }
    | additive_expression SUB multiplicative_expr { printf("Subtraction\n"); }
;

multiplicative_expr:
    unary_expr
    | multiplicative_expr MUL unary_expr { printf("Multiplication\n"); }
    | multiplicative_expr DIV unary_expr { printf("Division\n"); }
    | multiplicative_expr MOD unary_expr { printf("Modulo\n"); }
;

unary_expr:
    postfix_expression
    | NOT unary_expr { printf("Logical NOT\n"); }
;

postfix_expression:
    primary_expr
    | function_call
;

primary_expr:
    ID {
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (sym == NULL)
         { fprintf(stderr, "Semantic Error: Use of undeclared variable %s\n", $1);}
        else if(!sym->initialized)
        {fprintf(stderr, "Semantic Error: Use of uninitialized variable %s\n", $1);}
        else 
        {$$ = sym && sym->value ? *((int*)sym->value) : 0;  // Assuming TYPE_INT for now
        printf("Primary ID: %s\n", $1);}}
    | INT { $$ = $1; printf("Primary int: %d\n", $1); }
    | FLOAT { $$ = (int)$1; printf("Primary float: %f\n", $1); } // cast needed for int-only $$ now
    | DOUBLE { $$ = (int)$1; printf("Primary double: %f\n", $1); }
    | STRING { $$ = 0; printf("Primary string: %s\n", $1); }
    | CHAR { $$ = $1[1]; printf("Primary char: %c\n", $1[1]); }
    | BOOL { $$ = $1; printf("Primary bool: %s\n", $1 ? "true" : "false"); }
    | LPAREN expression RPAREN { $$ = $2; }
;


function_call:
    ID LPAREN argument_list RPAREN {
        Symbol* sym = lookup_symbol(current_scope, $1);
        if (!sym || sym->kind != KIND_FUNCTION) {
            fprintf(stderr, "Semantic Error: Undefined function %s\n", $1);
        }
        printf("Function call to: %s\n", $1);
    }
;

argument_list:
    assignment_expression
    | argument_list COMMA assignment_expression
    | /* empty */
;

%%

int main() {
    global_scope = create_scope(NULL);
    current_scope = global_scope;
    return yyparse();
}
