%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int sym[26]; 
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

%token ASSIGN // =
%token ADD SUB MUL DIV MOD // + - * / %
%token LT GT EQ NEQ LE GE // < > == != <= >=
%token AND OR NOT          // && || !

%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA COLON

%type <ival> expression additive_expr multiplicative_expr relational_expr equality_expr and_expr or_expr unary_expr primary_expr

%%

program:
    program statement
    | program function
    | /* empty */
;

function:
    function_type ID LPAREN parameters RPAREN block {
        printf("Function: %s\n", $2);
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
    parameter_type ID {
        printf("Parameter: type and name = [type], %s\n", $2);
    }
;

parameter_type:
    INT_TYPE
    | FLOAT_TYPE
    | STRING_TYPE
    | CHAR_TYPE
    | BOOL_TYPE
    | DOUBLE_TYPE
;

function_type:
    INT_TYPE
    | FLOAT_TYPE
    | STRING_TYPE
    | CHAR_TYPE
    | BOOL_TYPE
    | DOUBLE_TYPE
    | VOID_TYPE
;


declaration:
    parameter_type ID SEMICOLON {
        printf("Declaration: %s\n", $2);
    }
    | parameter_type ID ASSIGN expression SEMICOLON {
        printf("Declaration with assignment: %s\n", $2);
    }
    | CONST parameter_type ID ASSIGN expression SEMICOLON {
        printf("Constant declaration: %s\n", $3);
    }
;

block:
    LBRACE block_items RBRACE
;

block_items:
    block_items block_item
    | /*empty*/
;

block_item:
    declaration
    | statement
;

statements:
    statements statement
    | /*empty*/
;

statement:
    assignment SEMICOLON
    | if_statement
    | while_loop
    | do_while_loop
    | for_loop
    | switch_statement
    | block
    | RETURN expression SEMICOLON {
        printf("Return statement\n");
    }
    | SEMICOLON
    | function_call SEMICOLON {fprintf(stderr, "Function call handling not implemented statement\n"); }
  
;

assignment:
    ID ASSIGN expression  {
        printf("Assignment to %s\n", $1);
    }
;

if_statement:
    IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
        printf("If statement\n");
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        printf("If-else statement\n");
    }
;

loop_statement:
    statement
    | BREAK SEMICOLON {
        printf("Break statement\n");
    }
    | CONTINUE SEMICOLON {
        printf("Continue statement\n");
    }
;

while_loop:
    WHILE LPAREN expression RPAREN loop_statement {
        printf("While loop\n");
    }

;

do_while_loop:
    DO loop_statement WHILE LPAREN expression RPAREN SEMICOLON {
        printf("Do-while loop\n");
    }
;

for_loop:
    FOR LPAREN for_init expression SEMICOLON for_update RPAREN statement {
        printf("For loop\n");
    }
;

for_init:
    assignment SEMICOLON
    | declaration
;

for_update:
    assignment
;

switch_statement:
    SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE {
        printf("Switch statement\n");
    }
;

case_list:
    case_list case
    | case
;

case:
    CASE INT COLON statements {
        printf("Case: %d\n", $2);
    }
    | DEFAULT COLON statements {
        printf("Default case\n");
    }
;

expression: 
          or_expr
;

or_expr:
         or_expr OR and_expr { $$ = $1 || $3; printf("Logical OR\n"); }
        | and_expr 
;

and_expr: 
         and_expr AND equality_expr { $$ = $1 && $3; printf("Logical AND\n"); }
         | equality_expr 
;

equality_expr:
            equality_expr EQ relational_expr { $$ = $1 == $3; printf("Equality\n"); }
            | equality_expr NEQ relational_expr { $$ = $1 != $3; printf("Not Equal\n"); }
            | relational_expr 
;

relational_expr: 
                relational_expr LT additive_expr { $$ = $1 < $3; printf("Less than\n"); }
                | relational_expr LE additive_expr { $$ = $1 <= $3; printf("Less than or equal\n"); }
                | relational_expr GT additive_expr { $$ = $1 > $3; printf("Greater than\n"); }
                | relational_expr GE additive_expr { $$ = $1 >= $3; printf("Greater than or equal\n"); }
                | additive_expr 
;

additive_expr:
                 additive_expr ADD multiplicative_expr { $$ = $1 + $3; printf("Addition\n"); }
                 | additive_expr SUB multiplicative_expr { $$ = $1 - $3; printf("Subtraction\n"); }
                 | multiplicative_expr 
;

multiplicative_expr: 
                 multiplicative_expr MUL unary_expr { $$ = $1 * $3; printf("Multiplication\n"); }
                 | multiplicative_expr DIV unary_expr { $$ = $1 / $3; printf("Division\n"); }
                 | multiplicative_expr MOD unary_expr { $$ = $1 % $3; printf("Modulo\n"); }
                 | unary_expr 
;

unary_expr:
      NOT unary_expr     { $$ = !$2; printf("Logical NOT\n"); }
    | primary_expr       { $$ = $1; }
;

primary_expr:
      INT    { $$ = $1; printf("Primary int: %d\n", $1); }
    | FLOAT  { $$ = (int)$1; printf("Primary float: %f\n", $1); }
    | DOUBLE { $$ = (int)$1; printf("Primary double: %f\n", $1); }
    | STRING { $$ = 0; fprintf(stderr, "Warning: string in expression not supported\n"); }
    | CHAR   { $$ = $1[0]; printf("Primary char: %c\n", $1[0]); }
    | BOOL   { $$ = $1 ? 1 : 0; printf("Primary bool: %s\n", $1 ? "true" : "false"); }
    | ID     { $$ = sym[$1[0] - 'a']; printf("Primary ID: %s = %d\n", $1, $$); }
    | LPAREN expression RPAREN { $$ = $2; }
    | function_call { $$ = 0; fprintf(stderr, "Function call handling not implemented\n"); }
;

function_call: 
              ID LPAREN argument_list RPAREN {
                  printf("Function call to: %s\n", $1);
              }
;

argument_list
    : /* empty */
    | expression
    | argument_list COMMA expression 
;

%%

int main() {
    return yyparse();
}
