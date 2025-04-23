%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Tokens
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
    function_type ID LPAREN parameters RPAREN block 
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
    parameter_type ID 
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
declarations:
    declarations declaration
    | /* empty */
;

declaration:
    parameter_type ID SEMICOLON
    | CONST parameter_type ID ASSIGN expression SEMICOLON
;

block:
    LBRACE declarations statements RBRACE
;

statements:
    statements statement
    | /* empty */
;

statement:
    assignment
    | if_statement
    | while_loop
    | do_while_loop
    | for_loop
    | switch_statement
    | block
    | RETURN expression SEMICOLON
    | BREAK SEMICOLON
    | CONTINUE SEMICOLON
    | SEMICOLON 
;

assignment:
    ID ASSIGN expression SEMICOLON
;

if_statement:
    IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
    | IF LPAREN expression RPAREN statement ELSE statement
;


while_loop:
    WHILE LPAREN expression RPAREN statement
;

do_while_loop:
    DO statement WHILE LPAREN expression RPAREN SEMICOLON
;

for_loop:
    FOR LPAREN assignment SEMICOLON expression SEMICOLON assignment RPAREN statement 
    |FOR LPAREN parameter_type assignment SEMICOLON expression SEMICOLON assignment RPAREN statement
;

switch_statement:
    SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE
;

case_list:
    case_list case
    | case
;

case:
    CASE INT COLON statements
    | DEFAULT COLON statements
;

expression: 
          or_expr
;

or_expr:
         or_expr OR and_expr
        | and_expr 
;

and_expr: 
         and_expr AND equality_expr
         | equality_expr 
;

equality_expr:
            equality_expr EQ relational_expr
            | equality_expr NEQ relational_expr
            | relational_expr 
;

relational_expr: 
                relational_expr LT additive_expr
                 | relational_expr LE additive_expr
                 | relational_expr GT additive_expr
                 | relational_expr GE additive_expr
                 | additive_expr 
;

additive_expr:
                 additive_expr ADD multiplicative_expr
                 | additive_expr SUB multiplicative_expr
                 | multiplicative_expr 
;

multiplicative_expr: 
                 multiplicative_expr MUL unary_expr
                 | multiplicative_expr DIV unary_expr
                 | multiplicative_expr MOD unary_expr
                 | unary_expr 
;

unary_expr:
      NOT unary_expr     { $$ = !$2; }
    | primary_expr       { $$ = $1; }
;


primary_expr:
      INT    { $$ = $1; }
    | FLOAT  { $$ = (int)$1; }      // Cast float to int
    | DOUBLE { $$ = (int)$1; }      // Cast double to int
    | STRING { $$ = 0; /* Placeholder */ fprintf(stderr, "Warning: string in expression not supported\n"); }
    | CHAR   { $$ = $1[0]; }        // Assuming CHAR token returns string like 'a'
    | BOOL   { $$ = $1 ? 1 : 0; }
    | ID     { $$ = sym[$1[0] - 'a']; } // Basic lookup using first char (if you're doing single-letter vars)
    | LPAREN expression RPAREN { $$ = $2; }
    | function_call { $$ = 0; fprintf(stderr, "Function call handling not implemented\n"); }
;


function_call: 
              ID LPAREN argument_list RPAREN 
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
