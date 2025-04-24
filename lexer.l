%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "y.tab.h"




extern void yyerror(const char *msg);
int line_number = 1;
%}

%option noyywrap

/* Regular Definitions */
DIGIT       [0-9]
LETTER      [a-zA-Z]
ID          [a-zA-Z_][a-zA-Z0-9_]*
INT         {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
WHITESPACE  [ \t]+
NEWLINE     \n
COMMENT     \/\/.*

%%

"if"        { printf("TOKEN: IF\n"); return IF; }
"else"      { printf("TOKEN: ELSE\n"); return ELSE; }
"while"     { printf("TOKEN: WHILE\n"); return WHILE; }
"do"        { printf("TOKEN: DO\n"); return DO; }
"for"       { printf("TOKEN: FOR\n"); return FOR; }
"switch"    { printf("TOKEN: SWITCH\n"); return SWITCH; }
"case"      { printf("TOKEN: CASE\n"); return CASE; }
"default"   { printf("TOKEN: DEFAULT\n"); return DEFAULT; }
"break"     { printf("TOKEN: BREAK\n"); return BREAK; }
"continue"  { printf("TOKEN: CONTINUE\n"); return CONTINUE; }
"return"    { printf("TOKEN: RETURN\n"); return RETURN; }
"const"     { printf("TOKEN: CONST\n"); return CONST; }

"int"       { printf("TOKEN: INT_TYPE\n"); return INT_TYPE; }
"float"     { printf("TOKEN: FLOAT_TYPE\n"); return FLOAT_TYPE; }
"double"    { printf("TOKEN: DOUBLE_TYPE\n"); return DOUBLE_TYPE; }
"string"    { printf("TOKEN: STRING_TYPE\n"); return STRING_TYPE; }
"char"      { printf("TOKEN: CHAR_TYPE\n"); return CHAR_TYPE; }
"void"      { printf("TOKEN: VOID_TYPE\n"); return VOID_TYPE; }
"bool"      { printf("TOKEN: BOOL_TYPE\n"); return BOOL_TYPE; }

"true"      { yylval.bval = true; return BOOL; }
"false"     { yylval.bval = false; return BOOL; }

"="         { printf("TOKEN: ASSIGN\n"); return ASSIGN; }
"+"         { printf("TOKEN: ADD\n"); return ADD; }
"-"         { printf("TOKEN: SUB\n"); return SUB; }
"*"         { printf("TOKEN: MUL\n"); return MUL; }
"/"         { printf("TOKEN: DIV\n"); return DIV; }
"%"         { printf("TOKEN: MOD\n"); return MOD; }

"<"         { printf("TOKEN: LT\n"); return LT; }
">"         { printf("TOKEN: GT\n"); return GT; }
"=="        { printf("TOKEN: EQ\n"); return EQ; }
"!="        { printf("TOKEN: NEQ\n"); return NEQ; }
"<="        { printf("TOKEN: LE\n"); return LE; }
">="        { printf("TOKEN: GE\n"); return GE; }

"&&"        { printf("TOKEN: AND\n"); return AND; }
"||"        { printf("TOKEN: OR\n"); return OR; }
"!"         { printf("TOKEN: NOT\n"); return NOT; }

"("         { printf("TOKEN: LPAREN\n"); return LPAREN; }
")"         { printf("TOKEN: RPAREN\n"); return RPAREN; }
"{"         { printf("TOKEN: LBRACE\n"); return LBRACE; }
"}"         { printf("TOKEN: RBRACE\n"); return RBRACE; }
";"         { printf("TOKEN: SEMICOLON\n"); return SEMICOLON; }
","         { printf("TOKEN: COMMA\n"); return COMMA; }
":"         { printf("TOKEN: COLON\n"); return COLON; }

{ID}        { 
              yylval.sval = strdup(yytext);  
              return ID; 
            }

{INT}       { 
              printf("TOKEN: INT(%s)\n", yytext);
              yylval.ival = atoi(yytext); 
              return INT; 
            }

{FLOAT}     { 
              printf("TOKEN: FLOAT(%s)\n", yytext);
              yylval.fval = atof(yytext); 
              return FLOAT; 
            }

{DIGIT}+\.{DIGIT}+[eE][+-]?{DIGIT}+ { 
              printf("TOKEN: DOUBLE(%s)\n", yytext);
              yylval.fval = atof(yytext); 
              return DOUBLE; 
            }

\"[^\"]*\"  { 
              printf("TOKEN: STRING(%s)\n", yytext);
              yylval.sval = strdup(yytext); 
              return STRING; 
            }

\'[^\']\'         { yylval.sval = strdup(yytext); return CHAR; }   
\'[^\']{2,}\'     { yyerror("Invalid character literal: more than one character inside single quotes."); } 

{WHITESPACE} { /* Ignore whitespace */ }
\r { /* Ignore carriage return */ }
{NEWLINE}    { line_number++; }
{COMMENT}    { /* Ignore comments */ }

.           { 
              fprintf(stderr, "Unrecognized character: '%c' (0x%X) at line %d\n", yytext[0], (unsigned char)yytext[0], line_number);
            }
            
{DIGIT}({LETTER}|{DIGIT})*  { 
    char error_msg[100];
    sprintf(error_msg, "Invalid identifier: %s at line %d", yytext, line_number);
    yyerror(error_msg); 
}

%%

/* Additional C code can go here if needed */
