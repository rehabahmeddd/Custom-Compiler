/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 146 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    DOUBLE = 261,                  /* DOUBLE  */
    STRING = 262,                  /* STRING  */
    CHAR = 263,                    /* CHAR  */
    BOOL = 264,                    /* BOOL  */
    LOWER_THAN_ELSE = 265,         /* LOWER_THAN_ELSE  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    DO = 269,                      /* DO  */
    FOR = 270,                     /* FOR  */
    SWITCH = 271,                  /* SWITCH  */
    CASE = 272,                    /* CASE  */
    DEFAULT = 273,                 /* DEFAULT  */
    BREAK = 274,                   /* BREAK  */
    CONTINUE = 275,                /* CONTINUE  */
    RETURN = 276,                  /* RETURN  */
    CONST = 277,                   /* CONST  */
    INT_TYPE = 278,                /* INT_TYPE  */
    FLOAT_TYPE = 279,              /* FLOAT_TYPE  */
    DOUBLE_TYPE = 280,             /* DOUBLE_TYPE  */
    STRING_TYPE = 281,             /* STRING_TYPE  */
    CHAR_TYPE = 282,               /* CHAR_TYPE  */
    VOID_TYPE = 283,               /* VOID_TYPE  */
    BOOL_TYPE = 284,               /* BOOL_TYPE  */
    ASSIGN = 285,                  /* ASSIGN  */
    ADD = 286,                     /* ADD  */
    SUB = 287,                     /* SUB  */
    MUL = 288,                     /* MUL  */
    DIV = 289,                     /* DIV  */
    MOD = 290,                     /* MOD  */
    LT = 291,                      /* LT  */
    GT = 292,                      /* GT  */
    EQ = 293,                      /* EQ  */
    NEQ = 294,                     /* NEQ  */
    LE = 295,                      /* LE  */
    GE = 296,                      /* GE  */
    AND = 297,                     /* AND  */
    OR = 298,                      /* OR  */
    NOT = 299,                     /* NOT  */
    LPAREN = 300,                  /* LPAREN  */
    RPAREN = 301,                  /* RPAREN  */
    LBRACE = 302,                  /* LBRACE  */
    RBRACE = 303,                  /* RBRACE  */
    SEMICOLON = 304,               /* SEMICOLON  */
    COMMA = 305,                   /* COMMA  */
    COLON = 306                    /* COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INT 259
#define FLOAT 260
#define DOUBLE 261
#define STRING 262
#define CHAR 263
#define BOOL 264
#define LOWER_THAN_ELSE 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define DO 269
#define FOR 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define BREAK 274
#define CONTINUE 275
#define RETURN 276
#define CONST 277
#define INT_TYPE 278
#define FLOAT_TYPE 279
#define DOUBLE_TYPE 280
#define STRING_TYPE 281
#define CHAR_TYPE 282
#define VOID_TYPE 283
#define BOOL_TYPE 284
#define ASSIGN 285
#define ADD 286
#define SUB 287
#define MUL 288
#define DIV 289
#define MOD 290
#define LT 291
#define GT 292
#define EQ 293
#define NEQ 294
#define LE 295
#define GE 296
#define AND 297
#define OR 298
#define NOT 299
#define LPAREN 300
#define RPAREN 301
#define LBRACE 302
#define RBRACE 303
#define SEMICOLON 304
#define COMMA 305
#define COLON 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 76 "parser.y"

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

#line 315 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_BOOL = 9,                       /* BOOL  */
  YYSYMBOL_LOWER_THAN_ELSE = 10,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_SWITCH = 16,                    /* SWITCH  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_DEFAULT = 18,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_CONST = 22,                     /* CONST  */
  YYSYMBOL_INT_TYPE = 23,                  /* INT_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 24,                /* FLOAT_TYPE  */
  YYSYMBOL_DOUBLE_TYPE = 25,               /* DOUBLE_TYPE  */
  YYSYMBOL_STRING_TYPE = 26,               /* STRING_TYPE  */
  YYSYMBOL_CHAR_TYPE = 27,                 /* CHAR_TYPE  */
  YYSYMBOL_VOID_TYPE = 28,                 /* VOID_TYPE  */
  YYSYMBOL_BOOL_TYPE = 29,                 /* BOOL_TYPE  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_ADD = 31,                       /* ADD  */
  YYSYMBOL_SUB = 32,                       /* SUB  */
  YYSYMBOL_MUL = 33,                       /* MUL  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_MOD = 35,                       /* MOD  */
  YYSYMBOL_LT = 36,                        /* LT  */
  YYSYMBOL_GT = 37,                        /* GT  */
  YYSYMBOL_EQ = 38,                        /* EQ  */
  YYSYMBOL_NEQ = 39,                       /* NEQ  */
  YYSYMBOL_LE = 40,                        /* LE  */
  YYSYMBOL_GE = 41,                        /* GE  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_NOT = 44,                       /* NOT  */
  YYSYMBOL_LPAREN = 45,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 46,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 47,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 48,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 49,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 50,                     /* COMMA  */
  YYSYMBOL_COLON = 51,                     /* COLON  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program = 53,                   /* program  */
  YYSYMBOL_translation_unit = 54,          /* translation_unit  */
  YYSYMBOL_external_declaration = 55,      /* external_declaration  */
  YYSYMBOL_global_declaration = 56,        /* global_declaration  */
  YYSYMBOL_type_specifier = 57,            /* type_specifier  */
  YYSYMBOL_function_definition = 58,       /* function_definition  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_parameters = 61,                /* parameters  */
  YYSYMBOL_parameter_list = 62,            /* parameter_list  */
  YYSYMBOL_parameter = 63,                 /* parameter  */
  YYSYMBOL_compound_statement = 64,        /* compound_statement  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_block_item_list = 66,           /* block_item_list  */
  YYSYMBOL_block_item = 67,                /* block_item  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_expression_statement = 70,      /* expression_statement  */
  YYSYMBOL_if_condition = 71,              /* if_condition  */
  YYSYMBOL_selection_statement = 72,       /* selection_statement  */
  YYSYMBOL_73_4 = 73,                      /* @4  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_case_list = 75,                 /* case_list  */
  YYSYMBOL_case = 76,                      /* case  */
  YYSYMBOL_77_6 = 77,                      /* $@6  */
  YYSYMBOL_78_7 = 78,                      /* $@7  */
  YYSYMBOL_statement_list = 79,            /* statement_list  */
  YYSYMBOL_while_condition = 80,           /* while_condition  */
  YYSYMBOL_81_8 = 81,                      /* @8  */
  YYSYMBOL_iteration_statement = 82,       /* iteration_statement  */
  YYSYMBOL_83_9 = 83,                      /* @9  */
  YYSYMBOL_84_10 = 84,                     /* $@10  */
  YYSYMBOL_for_clause = 85,                /* for_clause  */
  YYSYMBOL_for_init_statement = 86,        /* for_init_statement  */
  YYSYMBOL_jump_statement = 87,            /* jump_statement  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_assignment_expression = 89,     /* assignment_expression  */
  YYSYMBOL_logical_or_expression = 90,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 91,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 92,       /* equality_expression  */
  YYSYMBOL_relational_expression = 93,     /* relational_expression  */
  YYSYMBOL_additive_expression = 94,       /* additive_expression  */
  YYSYMBOL_multiplicative_expr = 95,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 96,                /* unary_expr  */
  YYSYMBOL_postfix_expression = 97,        /* postfix_expression  */
  YYSYMBOL_primary_expr = 98,              /* primary_expr  */
  YYSYMBOL_function_call = 99,             /* function_call  */
  YYSYMBOL_100_11 = 100,                   /* $@11  */
  YYSYMBOL_argument_list = 101,            /* argument_list  */
  YYSYMBOL_argument_expr_list = 102        /* argument_expr_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   125,   126,   130,   131,   135,   139,   153,
     162,   163,   164,   165,   166,   167,   168,   172,   188,   172,
     214,   215,   219,   220,   224,   235,   234,   255,   256,   260,
     261,   265,   269,   283,   292,   293,   294,   295,   296,   300,
     301,   306,   313,   318,   318,   331,   331,   351,   352,   356,
     356,   386,   386,   395,   396,   401,   401,   419,   433,   433,
     448,   448,   468,   489,   490,   494,   507,   515,   525,   537,
     541,   542,   568,   569,   586,   587,   602,   603,   614,   628,
     629,   640,   651,   662,   676,   677,   688,   702,   703,   714,
     725,   739,   740,   750,   764,   765,   769,   787,   794,   801,
     808,   812,   816,   820,   824,   824,   884,   885,   889,   894
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT", "FLOAT",
  "DOUBLE", "STRING", "CHAR", "BOOL", "LOWER_THAN_ELSE", "IF", "ELSE",
  "WHILE", "DO", "FOR", "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE",
  "RETURN", "CONST", "INT_TYPE", "FLOAT_TYPE", "DOUBLE_TYPE",
  "STRING_TYPE", "CHAR_TYPE", "VOID_TYPE", "BOOL_TYPE", "ASSIGN", "ADD",
  "SUB", "MUL", "DIV", "MOD", "LT", "GT", "EQ", "NEQ", "LE", "GE", "AND",
  "OR", "NOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "COLON", "$accept", "program", "translation_unit",
  "external_declaration", "global_declaration", "type_specifier",
  "function_definition", "$@1", "$@2", "parameters", "parameter_list",
  "parameter", "compound_statement", "$@3", "block_item_list",
  "block_item", "declaration", "statement", "expression_statement",
  "if_condition", "selection_statement", "@4", "$@5", "case_list", "case",
  "$@6", "$@7", "statement_list", "while_condition", "@8",
  "iteration_statement", "@9", "$@10", "for_clause", "for_init_statement",
  "jump_statement", "expression", "assignment_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression", "multiplicative_expr",
  "unary_expr", "postfix_expression", "primary_expr", "function_call",
  "$@11", "argument_list", "argument_expr_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     107,    91,  -103,  -103,  -103,  -103,  -103,  -103,  -103,    58,
     107,  -103,  -103,     9,  -103,    34,  -103,  -103,   -24,    35,
      78,  -103,  -103,    78,   -23,  -103,  -103,  -103,  -103,  -103,
    -103,   210,   210,    78,    22,  -103,    18,    48,    37,    12,
      19,    33,  -103,  -103,  -103,  -103,    91,    24,    78,  -103,
      50,  -103,  -103,    54,  -103,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,    74,    55,
      46,  -103,  -103,  -103,    78,  -103,    48,    37,    12,    12,
      19,    19,    19,    19,    33,    33,  -103,  -103,  -103,  -103,
    -103,    91,  -103,    56,    53,    59,  -103,  -103,    78,  -103,
    -103,  -103,  -103,   150,    63,    64,  -103,    67,    79,    76,
      77,    11,    91,  -103,  -103,   104,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,    89,    78,    25,  -103,    25,    25,
    -103,    78,  -103,  -103,  -103,    92,   124,    -7,  -103,    94,
     130,    78,  -103,   131,   180,   100,  -103,   117,    78,  -103,
    -103,  -103,   102,   105,  -103,  -103,   103,    78,  -103,    78,
     111,    25,  -103,    78,    25,   113,   120,   119,  -103,  -103,
     134,  -103,    78,    62,  -103,   132,  -103,   147,   139,   -13,
    -103,  -103,   140,  -103,  -103,  -103,  -103,  -103,  -103,    25,
      25,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,    12,    13,    14,    16,    15,     0,
       2,     4,     6,     0,     5,     0,     1,     3,     0,     0,
       0,    17,     7,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,    69,    70,    72,    74,    76,
      79,    84,    87,    91,    94,    95,    21,     0,     0,   104,
      96,    93,    92,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    23,     9,    71,   107,   103,    73,    75,    77,    78,
      80,    81,    82,    83,    85,    86,    88,    89,    90,    24,
      18,     0,   109,     0,   106,     0,    22,   105,     0,    25,
      19,   108,    28,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,    26,    40,     0,    35,    27,    29,    30,
      34,    36,    37,    38,     0,     0,     0,    55,     0,     0,
      60,     0,    67,    68,    66,     0,     0,     0,    39,     0,
      42,     0,    57,     0,     0,     0,    65,     0,     0,    31,
      41,    43,     0,     0,    64,    63,     0,     0,    45,     0,
       0,     0,    56,     0,     0,     0,     0,     0,    32,    44,
       0,    61,     0,     0,    33,     0,    62,     0,     0,     0,
      48,    59,     0,    51,    46,    47,    49,    54,    54,    52,
      50,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -103,   182,  -103,     1,  -103,  -103,  -103,  -103,
    -103,   109,    98,  -103,  -103,  -103,    52,  -102,    57,  -103,
    -103,  -103,  -103,  -103,    41,  -103,  -103,    23,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   -20,   162,  -103,   166,
     167,    31,   -51,    30,    32,  -103,  -103,  -103,  -103,  -103,
    -103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    14,    46,    95,    69,
      70,    71,   116,   102,   103,   117,   118,   191,   120,   126,
     121,   161,   166,   179,   180,   188,   187,   189,   128,   141,
     122,   129,   144,   156,   157,   123,   124,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    74,    93,
      94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,   119,    15,    47,   177,   178,    20,    48,    80,    81,
      82,    83,    18,    53,    24,    25,    26,    27,    28,    29,
      30,    21,    49,   148,   140,    22,   142,   143,    24,    25,
      26,    27,    28,    29,    30,   184,   104,    19,   105,   106,
     107,   108,   149,    31,   109,   110,   111,    68,    59,    60,
      63,    64,    61,    62,    92,    32,    33,    31,    16,   169,
     134,    55,   171,    51,    52,    23,    65,    66,    67,    32,
      33,    54,    99,    72,   114,    57,    58,    89,   101,   177,
     178,    24,    25,    26,    27,    28,    29,    30,    78,    79,
      56,   135,    68,    84,    85,    49,    91,    86,    87,    88,
      75,    90,    97,    98,   115,   139,    99,   137,   125,   127,
      31,   145,   130,   136,     2,     3,     4,     5,     6,     7,
       8,   152,    32,    33,   131,   132,   133,   147,   160,     1,
       2,     3,     4,     5,     6,     7,     8,   165,   138,   167,
     150,   146,   151,   170,   153,   115,   158,   159,   162,   164,
     163,   182,   176,    24,    25,    26,    27,    28,    29,    30,
     168,   104,   172,   105,   106,   107,   108,   173,   174,   109,
     110,   111,   112,     2,     3,     4,     5,     6,     7,     8,
     175,   181,    31,    24,    25,    26,    27,    28,    29,    30,
     183,   186,    17,   100,    32,    33,   154,    99,   113,   114,
      96,   155,   112,     2,     3,     4,     5,     6,     7,     8,
      73,   190,    31,    50,    25,    26,    27,    28,    29,    30,
     185,    76,     0,    77,    32,    33,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33
};

static const yytype_int16 yycheck[] =
{
      20,   103,     1,    23,    17,    18,    30,    30,    59,    60,
      61,    62,     3,    33,     3,     4,     5,     6,     7,     8,
       9,    45,    45,    30,   126,    49,   128,   129,     3,     4,
       5,     6,     7,     8,     9,    48,    11,     3,    13,    14,
      15,    16,    49,    32,    19,    20,    21,    46,    36,    37,
      31,    32,    40,    41,    74,    44,    45,    32,     0,   161,
      49,    43,   164,    31,    32,    30,    33,    34,    35,    44,
      45,    49,    47,    49,    49,    38,    39,     3,    98,    17,
      18,     3,     4,     5,     6,     7,     8,     9,    57,    58,
      42,   111,    91,    63,    64,    45,    50,    65,    66,    67,
      46,    46,    46,    50,   103,   125,    47,     3,    45,    45,
      32,   131,    45,   112,    23,    24,    25,    26,    27,    28,
      29,   141,    44,    45,    45,    49,    49,     3,   148,    22,
      23,    24,    25,    26,    27,    28,    29,   157,    49,   159,
      46,    49,    12,   163,    13,   144,    46,    30,    46,    46,
      45,     4,   172,     3,     4,     5,     6,     7,     8,     9,
      49,    11,    49,    13,    14,    15,    16,    47,    49,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      46,    49,    32,     3,     4,     5,     6,     7,     8,     9,
      51,    51,    10,    95,    44,    45,   144,    47,    48,    49,
      91,   144,    22,    23,    24,    25,    26,    27,    28,    29,
      48,   188,    32,     3,     4,     5,     6,     7,     8,     9,
     179,    55,    -1,    56,    44,    45,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    23,    24,    25,    26,    27,    28,    29,    53,
      54,    55,    56,    57,    58,    57,     0,    55,     3,     3,
      30,    45,    49,    30,     3,     4,     5,     6,     7,     8,
       9,    32,    44,    45,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,    59,    88,    30,    45,
       3,    96,    96,    88,    49,    43,    42,    38,    39,    36,
      37,    40,    41,    31,    32,    33,    34,    35,    57,    61,
      62,    63,    49,    89,   100,    46,    91,    92,    93,    93,
      94,    94,    94,    94,    95,    95,    96,    96,    96,     3,
      46,    50,    88,   101,   102,    60,    63,    46,    50,    47,
      64,    88,    65,    66,    11,    13,    14,    15,    16,    19,
      20,    21,    22,    48,    49,    57,    64,    67,    68,    69,
      70,    72,    82,    87,    88,    45,    71,    45,    80,    83,
      45,    45,    49,    49,    49,    88,    57,     3,    49,    88,
      69,    81,    69,    69,    84,    88,    49,     3,    30,    49,
      46,    12,    88,    13,    68,    70,    85,    86,    46,    30,
      88,    73,    46,    45,    46,    88,    74,    88,    49,    69,
      88,    69,    49,    47,    49,    46,    88,    17,    18,    75,
      76,    49,     4,    51,    48,    76,    51,    78,    77,    79,
      79,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    59,    60,    58,
      61,    61,    62,    62,    63,    65,    64,    66,    66,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    69,    70,
      70,    71,    72,    73,    72,    74,    72,    75,    75,    77,
      76,    78,    76,    79,    79,    81,    80,    82,    83,    82,
      84,    82,    85,    86,    86,    87,    87,    87,    87,    88,
      89,    89,    90,    90,    91,    91,    92,    92,    92,    93,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      95,    96,    96,    96,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,   100,    99,   101,   101,   102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     6,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     8,
       1,     0,     3,     1,     2,     0,     4,     2,     0,     1,
       1,     3,     5,     6,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     0,     6,     0,     8,     2,     1,     0,
       5,     0,     4,     2,     0,     0,     4,     3,     0,     8,
       0,     6,     4,     1,     1,     3,     2,     2,     2,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     5,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7: /* global_declaration: type_specifier ID SEMICOLON  */
#line 135 "parser.y"
                                {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].dtype), KIND_VAR, false);        
        printf("Global Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1555 "y.tab.c"
    break;

  case 8: /* global_declaration: type_specifier ID ASSIGN expression SEMICOLON  */
#line 139 "parser.y"
                                                    {
        Symbol* sym = insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, false);
        set_initialized(current_scope,(yyvsp[-3].sval));

        quad_gen_assign(quad_handler, sym, (yyvsp[-1].sym));
        
        Symbol* sym1 = lookup_symbol(current_scope, (yyvsp[-3].sval));
        if (sym1 && sym1->type != infer_expr_type(current_scope,(yyvsp[-1].sym)->name)) {
            fprintf(stderr, "Semantic Error at line %d: Type mismatch in declaration of '%s'. Expected %s but got %s.\n",
                line_number, (yyvsp[-3].sval), dataTypeName[sym1->type], dataTypeName[infer_expr_type(current_scope,(yyvsp[-1].sym)->name)]);
            exit(1);
        }
        printf("Global Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1574 "y.tab.c"
    break;

  case 9: /* global_declaration: CONST type_specifier ID ASSIGN expression SEMICOLON  */
#line 153 "parser.y"
                                                          {
        Symbol* sym = insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, true);
        set_initialized(current_scope,(yyvsp[-3].sval));
        quad_gen_assign(quad_handler, sym, (yyvsp[-1].sym));
        printf("Global Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1585 "y.tab.c"
    break;

  case 10: /* type_specifier: INT_TYPE  */
#line 162 "parser.y"
             { (yyval.dtype) = TYPE_INT; }
#line 1591 "y.tab.c"
    break;

  case 11: /* type_specifier: FLOAT_TYPE  */
#line 163 "parser.y"
                 { (yyval.dtype) = TYPE_FLOAT; }
#line 1597 "y.tab.c"
    break;

  case 12: /* type_specifier: DOUBLE_TYPE  */
#line 164 "parser.y"
                  { (yyval.dtype) = TYPE_DOUBLE; }
#line 1603 "y.tab.c"
    break;

  case 13: /* type_specifier: STRING_TYPE  */
#line 165 "parser.y"
                  { (yyval.dtype) = TYPE_STRING; }
#line 1609 "y.tab.c"
    break;

  case 14: /* type_specifier: CHAR_TYPE  */
#line 166 "parser.y"
                { (yyval.dtype) = TYPE_CHAR; }
#line 1615 "y.tab.c"
    break;

  case 15: /* type_specifier: BOOL_TYPE  */
#line 167 "parser.y"
                { (yyval.dtype) = TYPE_BOOL; }
#line 1621 "y.tab.c"
    break;

  case 16: /* type_specifier: VOID_TYPE  */
#line 168 "parser.y"
                { (yyval.dtype) = TYPE_VOID; }
#line 1627 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 172 "parser.y"
                             {
        Symbol* func = insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].dtype), KIND_FUNCTION, false);

         

        // Reset parameter tracker
        current_param_index = 0;

        is_function_body = 1;
        current_scope = create_scope(current_scope);

        current_function_return_type = (yyvsp[-2].dtype);
        num_current_parameters = 0;

        quad_add_func_begin(quad_handler, func->name);
    }
#line 1648 "y.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 188 "parser.y"
                      {
        // Re-lookup function symbol to attach parameter types
        Symbol* func = lookup_symbol(global_scope, (yyvsp[-4].sval));
        if (!func) {
            fprintf(stderr, "Internal Error: Function symbol '%s' not found for parameter assignment.\n", (yyvsp[-4].sval));
            exit(1);
        }

        func->param_types = malloc(sizeof(DataType) * current_param_index);
        func->param_count = current_param_index;
        for (int i = 0; i < current_param_index; i++) {
            func->param_types[i] = current_param_types[i];
        }
    }
#line 1667 "y.tab.c"
    break;

  case 19: /* function_definition: type_specifier ID LPAREN $@1 parameters RPAREN $@2 compound_statement  */
#line 202 "parser.y"
                       {
        // Write function end quadruple
        quad_add_func_end(quad_handler);
        
        // Reset function tracking
        current_function_return_type = TYPE_VOID;
        num_current_parameters = 0;
    }
#line 1680 "y.tab.c"
    break;

  case 24: /* parameter: type_specifier ID  */
#line 224 "parser.y"
                      {
        insert_symbol(current_scope, (yyvsp[0].sval), (yyvsp[-1].dtype), KIND_PARAMETER, false);
        set_initialized(current_scope, (yyvsp[0].sval));
        current_param_types[current_param_index++] = (yyvsp[-1].dtype);  // Collect type
        printf("Parameter: %s\n", (yyvsp[0].sval));
    }
#line 1691 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 235 "parser.y"
    {
        if (!is_function_body) {
            // Only create a new scope for non-function blocks (loops/if)
            current_scope = create_scope(current_scope);
        }
        else
        {is_function_body=0;}
        
    }
#line 1705 "y.tab.c"
    break;

  case 26: /* compound_statement: LBRACE $@3 block_item_list RBRACE  */
#line 246 "parser.y"
    {
       
            // Only leave scope for non-function blocks
            leave_scope(&current_scope);
        
    }
#line 1716 "y.tab.c"
    break;

  case 31: /* declaration: type_specifier ID SEMICOLON  */
#line 265 "parser.y"
                                {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].dtype), KIND_VAR, false);
        printf("Local Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1725 "y.tab.c"
    break;

  case 32: /* declaration: type_specifier ID ASSIGN expression SEMICOLON  */
#line 269 "parser.y"
                                                    {
        Symbol* sym = insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, false);
        set_initialized(current_scope,(yyvsp[-3].sval));

        quad_gen_assign(quad_handler, sym, (yyvsp[-1].sym));

        Symbol* sym1 = lookup_symbol(current_scope, (yyvsp[-3].sval));
        if (sym1 && sym1->type != infer_expr_type(current_scope,(yyvsp[-1].sym)->name)) {
            fprintf(stderr, "Semantic Error line %d: Type mismatch in declaration of '%s'. Expected %s but got %s.\n",
                line_number, (yyvsp[-3].sval), dataTypeName[sym1->type], dataTypeName[infer_expr_type(current_scope,(yyvsp[-1].sym)->name)]);
            exit(1);
        }
        printf("Local Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1744 "y.tab.c"
    break;

  case 33: /* declaration: CONST type_specifier ID ASSIGN expression SEMICOLON  */
#line 283 "parser.y"
                                                          {
        Symbol* sym = insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, true);
        set_initialized(current_scope,(yyvsp[-3].sval));
        quad_gen_assign(quad_handler, sym, (yyvsp[-1].sym));
        printf("Local Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1755 "y.tab.c"
    break;

  case 41: /* if_condition: LPAREN expression RPAREN  */
#line 306 "parser.y"
                            {
       char* false_label = quad_new_label(quad_handler);
       (yyval.label) = false_label;
       quad_add_if_jump(quad_handler, (yyvsp[-1].sym)->name, false_label, 0);
   }
#line 1765 "y.tab.c"
    break;

  case 42: /* selection_statement: IF if_condition statement  */
#line 313 "parser.y"
                                                    {
        quad_add_label(quad_handler, (yyvsp[-1].label));
        free((yyvsp[-1].label));
        printf("If statement\n");
    }
#line 1775 "y.tab.c"
    break;

  case 43: /* @4: %empty  */
#line 318 "parser.y"
                                     {
        char* end_label = quad_new_label(quad_handler);
        quad_add_goto(quad_handler, end_label);
        quad_add_label(quad_handler, (yyvsp[-2].label));
        free((yyvsp[-2].label));
        (yyval.label) = end_label;

    }
#line 1788 "y.tab.c"
    break;

  case 44: /* selection_statement: IF if_condition statement ELSE @4 statement  */
#line 325 "parser.y"
                {

        quad_add_label(quad_handler, (yyvsp[-1].label));
        free((yyvsp[-1].label));
        printf("If-else statement\n");
    }
#line 1799 "y.tab.c"
    break;

  case 45: /* $@5: %empty  */
#line 331 "parser.y"
                                      {
        // Create end label for switch
        current_switch_end_label = quad_new_label(quad_handler);
         
        // Save the switch expression as a global variable
        current_switch_var = (yyvsp[-1].sym);
        printf("Switch on: %s\n", (yyvsp[-1].sym)->name);
 
    }
#line 1813 "y.tab.c"
    break;

  case 46: /* selection_statement: SWITCH LPAREN expression RPAREN $@5 LBRACE case_list RBRACE  */
#line 339 "parser.y"
                              {

        // Write end label
        quad_add_label(quad_handler, current_switch_end_label);
        free(current_switch_end_label);
        current_switch_end_label = NULL;
        current_switch_var = NULL;  // Clear the switch variable
        printf("Switch statement\n");
    }
#line 1827 "y.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 356 "parser.y"
                   {
        // Generate comparison with switch variable
        char value[20];
        sprintf(value, "%d", (yyvsp[-1].ival));
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
    }
#line 1855 "y.tab.c"
    break;

  case 50: /* case: CASE INT COLON $@6 statement_list  */
#line 378 "parser.y"
                     {
        // After the statement list, add the label for the next case check
        if (current_case_next_label) {
            quad_add_label(quad_handler, current_case_next_label);
            current_case_next_label = NULL; // Reset for next case
        }
        printf("Case: %d\n", (yyvsp[-3].ival));
    }
#line 1868 "y.tab.c"
    break;

  case 51: /* $@7: %empty  */
#line 386 "parser.y"
                    {
        // Simply add a label for the default case
        char* default_label = quad_new_label(quad_handler);
        quad_add_label(quad_handler, default_label);
    }
#line 1878 "y.tab.c"
    break;

  case 52: /* case: DEFAULT COLON $@7 statement_list  */
#line 390 "parser.y"
                     {
        printf("Default case\n");
    }
#line 1886 "y.tab.c"
    break;

  case 55: /* @8: %empty  */
#line 401 "parser.y"
           {
       // Generate label for loop start
       char* start_label = quad_new_label(quad_handler);
       current_loop_start_label = start_label;
       quad_add_label(quad_handler, start_label);
       (yyval.label) = start_label;
    }
#line 1898 "y.tab.c"
    break;

  case 56: /* while_condition: LPAREN @8 expression RPAREN  */
#line 407 "parser.y"
                        {
       // Generate label for loop end
       char* end_label = quad_new_label(quad_handler);
       current_loop_end_label = end_label;
       
       // Jump to end if condition is false
       quad_add_if_jump(quad_handler, (yyvsp[-1].sym)->name, end_label, 0);
       
       (yyval.label) = end_label;
    }
#line 1913 "y.tab.c"
    break;

  case 57: /* iteration_statement: WHILE while_condition statement  */
#line 419 "parser.y"
                                    {
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
#line 1932 "y.tab.c"
    break;

  case 58: /* @9: %empty  */
#line 433 "parser.y"
         {
        // Generate label for loop start
        char* start_label = quad_new_label(quad_handler);
        current_loop_start_label = start_label;
        quad_add_label(quad_handler, start_label);
        (yyval.label) = start_label;
    }
#line 1944 "y.tab.c"
    break;

  case 59: /* iteration_statement: DO @9 statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 439 "parser.y"
                                                         {
        // Jump back to start if condition is true
        quad_add_if_jump(quad_handler, (yyvsp[-2].sym)->name, current_loop_start_label, 1);
        
        // Cleanup
        free(current_loop_start_label);
        current_loop_start_label = NULL;
        printf("Do-while loop\n");
    }
#line 1958 "y.tab.c"
    break;

  case 60: /* $@10: %empty  */
#line 448 "parser.y"
                 {is_function_body = 1; current_scope = create_scope(current_scope);}
#line 1964 "y.tab.c"
    break;

  case 61: /* iteration_statement: FOR LPAREN $@10 for_clause RPAREN statement  */
#line 449 "parser.y"
                                    {       
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
#line 1986 "y.tab.c"
    break;

  case 62: /* for_clause: for_init_statement expression SEMICOLON expression  */
#line 468 "parser.y"
                                                       {
        // Create labels for for loop
        char* cond_label = quad_new_label(quad_handler);
        char* end_label = quad_new_label(quad_handler);
        
        // Generate condition label
        quad_add_label(quad_handler, cond_label);
        
        // Jump to end if condition is false
        quad_add_if_jump(quad_handler, (yyvsp[-2].sym)->name, end_label, 0);
        
        // Store for later use in break/continue
        current_loop_start_label = cond_label;
        current_loop_end_label = end_label;
        
        // Return the increment expression
        (yyval.sym) = (yyvsp[0].sym);
    }
#line 2009 "y.tab.c"
    break;

  case 65: /* jump_statement: RETURN expression SEMICOLON  */
#line 494 "parser.y"
                                {
        if (current_function_return_type == TYPE_VOID) {
            yyerror("Cannot return a value from a void function");
        }

        // Generate return quadruple (handle NULL expression case gracefully)
        if ((yyvsp[-1].sym) != NULL) {
            quad_add_return(quad_handler, (yyvsp[-1].sym)->name);
        } else {
            quad_add_return(quad_handler, "0"); // default return value
        }
        printf("Return statement\n");
    }
#line 2027 "y.tab.c"
    break;

  case 66: /* jump_statement: RETURN SEMICOLON  */
#line 507 "parser.y"
                       {
        if (current_function_return_type != TYPE_VOID) {
            yyerror("Function should return a value");
        }
        
        // Generate return quadruple
        quad_add_return(quad_handler, NULL);
    }
#line 2040 "y.tab.c"
    break;

  case 67: /* jump_statement: BREAK SEMICOLON  */
#line 515 "parser.y"
                      {
       if (current_loop_end_label != NULL) {
           quad_add_goto(quad_handler, current_loop_end_label);
       } else if (current_switch_end_label != NULL) {
           quad_add_goto(quad_handler, current_switch_end_label);
       } else {
           yyerror("Break statement outside loop or switch");
       }
       printf("Break statement\n");
    }
#line 2055 "y.tab.c"
    break;

  case 68: /* jump_statement: CONTINUE SEMICOLON  */
#line 525 "parser.y"
                         {
         // Jump to start of current loop
        if (current_loop_start_label == NULL) {
            yyerror("Continue statement outside loop");
        } else {
            quad_add_goto(quad_handler, current_loop_start_label);
        }
        printf("Continue statement\n");
    }
#line 2069 "y.tab.c"
    break;

  case 69: /* expression: assignment_expression  */
#line 537 "parser.y"
                          { (yyval.sym) = (yyvsp[0].sym); }
#line 2075 "y.tab.c"
    break;

  case 70: /* assignment_expression: logical_or_expression  */
#line 541 "parser.y"
                          { (yyval.sym) = (yyvsp[0].sym); }
#line 2081 "y.tab.c"
    break;

  case 71: /* assignment_expression: ID ASSIGN assignment_expression  */
#line 542 "parser.y"
                                      {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].sval));
        if (sym == NULL) {
            fprintf(stderr, "Semantic Error at line %d: Undeclared variable %s\n",line_number, (yyvsp[-2].sval));
            exit(1);
        } else if (sym->constant) {
            fprintf(stderr, "Semantic Error at line %d: Cannot reassign to constant variable %s\n",line_number, (yyvsp[-2].sval));
            exit(1);
        } else {
            set_initialized(current_scope,(yyvsp[-2].sval));
            sym->is_used = true;

            if (sym->type != infer_expr_type(current_scope,(yyvsp[0].sym)->name)) {
            fprintf(stderr, "Semantic Error line %d: Type mismatch in assignment to '%s'. Expected %s but got %s.\n",
                line_number, (yyvsp[-2].sval), dataTypeName[sym->type], dataTypeName[infer_expr_type(current_scope,(yyvsp[0].sym)->name)]);
                exit(1);
            }
            printf("Assignment to %s\n", (yyvsp[-2].sval));
        }
        quad_gen_assign(quad_handler, sym, (yyvsp[0].sym));
        (yyval.sym) = sym;
        //$$ = strdup($1);
    }
#line 2109 "y.tab.c"
    break;

  case 72: /* logical_or_expression: logical_and_expression  */
#line 568 "parser.y"
                           { (yyval.sym) = (yyvsp[0].sym); }
#line 2115 "y.tab.c"
    break;

  case 73: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 569 "parser.y"
                                                      { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "||")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical or: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }

        (yyval.sym) = quad_gen_logic(quad_handler, OP_OR, (yyvsp[-2].sym), (yyvsp[0].sym));

        
        printf("Logical OR\n"); 
    }
#line 2134 "y.tab.c"
    break;

  case 74: /* logical_and_expression: equality_expression  */
#line 586 "parser.y"
                        { (yyval.sym) = (yyvsp[0].sym); }
#line 2140 "y.tab.c"
    break;

  case 75: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 587 "parser.y"
                                                     { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "&&")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical and: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_logic(quad_handler, OP_AND, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Logical AND\n"); 

    }
#line 2157 "y.tab.c"
    break;

  case 76: /* equality_expression: relational_expression  */
#line 602 "parser.y"
                          { (yyval.sym) = (yyvsp[0].sym); }
#line 2163 "y.tab.c"
    break;

  case 77: /* equality_expression: equality_expression EQ relational_expression  */
#line 603 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "==")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_rel(quad_handler, OP_EQ, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Equality\n");
    }
#line 2179 "y.tab.c"
    break;

  case 78: /* equality_expression: equality_expression NEQ relational_expression  */
#line 614 "parser.y"
                                                    {
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "!=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for not equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_rel(quad_handler, OP_NEQ, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Not Equal\n");
    }
#line 2195 "y.tab.c"
    break;

  case 79: /* relational_expression: additive_expression  */
#line 628 "parser.y"
                        { (yyval.sym) = (yyvsp[0].sym); }
#line 2201 "y.tab.c"
    break;

  case 80: /* relational_expression: relational_expression LT additive_expression  */
#line 629 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "<")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for less than: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_rel(quad_handler, OP_LT, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Less than\n"); 
    }
#line 2217 "y.tab.c"
    break;

  case 81: /* relational_expression: relational_expression GT additive_expression  */
#line 640 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, ">")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for greater than: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_rel(quad_handler, OP_GT, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Greater than\n"); 
    }
#line 2233 "y.tab.c"
    break;

  case 82: /* relational_expression: relational_expression LE additive_expression  */
#line 651 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "<=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for less than or equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_rel(quad_handler, OP_LE, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Less than or equal\n"); 
    }
#line 2249 "y.tab.c"
    break;

  case 83: /* relational_expression: relational_expression GE additive_expression  */
#line 662 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, ">=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for greater than or equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_rel(quad_handler, OP_GE, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Greater than or equal\n"); 
    }
#line 2265 "y.tab.c"
    break;

  case 84: /* additive_expression: multiplicative_expr  */
#line 676 "parser.y"
                        { (yyval.sym) = (yyvsp[0].sym); }
#line 2271 "y.tab.c"
    break;

  case 85: /* additive_expression: additive_expression ADD multiplicative_expr  */
#line 677 "parser.y"
                                                  { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "+")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for addition: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_math(quad_handler, OP_ADD, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Addition\n"); 
    }
#line 2287 "y.tab.c"
    break;

  case 86: /* additive_expression: additive_expression SUB multiplicative_expr  */
#line 688 "parser.y"
                                                  { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "-")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for subtraction: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_math(quad_handler, OP_SUB, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Subtraction\n"); 
    }
#line 2303 "y.tab.c"
    break;

  case 87: /* multiplicative_expr: unary_expr  */
#line 702 "parser.y"
               { (yyval.sym) = (yyvsp[0].sym); }
#line 2309 "y.tab.c"
    break;

  case 88: /* multiplicative_expr: multiplicative_expr MUL unary_expr  */
#line 703 "parser.y"
                                         { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "*")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for multiplication: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_math(quad_handler, OP_MUL, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Multiplication\n"); 
    }
#line 2325 "y.tab.c"
    break;

  case 89: /* multiplicative_expr: multiplicative_expr DIV unary_expr  */
#line 714 "parser.y"
                                         { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "/")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for division: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_math(quad_handler, OP_DIV, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Division\n"); 
    }
#line 2341 "y.tab.c"
    break;

  case 90: /* multiplicative_expr: multiplicative_expr MOD unary_expr  */
#line 725 "parser.y"
                                         { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sym)->name);
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, rightType, "%")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for modulus: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_math(quad_handler, OP_MOD, (yyvsp[-2].sym), (yyvsp[0].sym));
        printf("Modulo\n"); 
    }
#line 2357 "y.tab.c"
    break;

  case 91: /* unary_expr: postfix_expression  */
#line 739 "parser.y"
                       { (yyval.sym) = (yyvsp[0].sym); }
#line 2363 "y.tab.c"
    break;

  case 92: /* unary_expr: NOT unary_expr  */
#line 740 "parser.y"
                     { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, TYPE_BOOL, "!")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical not: %s\n",
                line_number, dataTypeName[leftType]);
            exit(1);
        }
        (yyval.sym) = quad_gen_logic(quad_handler, OP_NOT, (yyvsp[0].sym), NULL);
        printf("Logical NOT\n"); 
    }
#line 2378 "y.tab.c"
    break;

  case 93: /* unary_expr: SUB unary_expr  */
#line 750 "parser.y"
                     { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[0].sym)->name);
        if (!areTypesCompatibleForOp(leftType, TYPE_INT, "-")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for unary minus: %s\n",
                line_number, dataTypeName[leftType]);
            exit(1);
        }
        Symbol* zero = create_quad_symbol("0", (yyvsp[0].sym)->type);
        (yyval.sym) = quad_gen_math(quad_handler, OP_SUB, zero, (yyvsp[0].sym));
        printf("Unary minus\n"); 
    }
#line 2394 "y.tab.c"
    break;

  case 94: /* postfix_expression: primary_expr  */
#line 764 "parser.y"
                 { (yyval.sym) = (yyvsp[0].sym); }
#line 2400 "y.tab.c"
    break;

  case 95: /* postfix_expression: function_call  */
#line 765 "parser.y"
                    { (yyval.sym) = (yyvsp[0].sym); }
#line 2406 "y.tab.c"
    break;

  case 96: /* primary_expr: ID  */
#line 769 "parser.y"
       {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].sval));
        const char* name=get_symbol_name(sym);
        if (sym == NULL) {
            fprintf(stderr, "Semantic Error at line %d: Use of undeclared variable %s\n",line_number, (yyvsp[0].sval));
            exit(1);
        } else if(!is_initialized(current_scope,name)) {
           
            fprintf(stderr, "Symbol Name: %s\n", name);

            fprintf(stderr, "Semantic Error at line %d: Use of uninitialized variable %s\n",line_number, (yyvsp[0].sval));
            exit(1);
        }
        sym->is_used = true;
        //$$ = strdup($1);
        (yyval.sym) = sym;
        printf("Primary ID: %s\n", (yyvsp[0].sval));
    }
#line 2429 "y.tab.c"
    break;

  case 97: /* primary_expr: INT  */
#line 787 "parser.y"
          { 
        // Convert INT to string
        char value[20];
        sprintf(value, "%d", (yyvsp[0].ival));
        (yyval.sym) = create_quad_symbol(value, TYPE_INT);
        printf("Primary int: %d\n", (yyvsp[0].ival)); 
    }
#line 2441 "y.tab.c"
    break;

  case 98: /* primary_expr: FLOAT  */
#line 794 "parser.y"
            { 
       // Convert FLOAT to string
       char value[20];
       sprintf(value, "%f", (yyvsp[0].fval));
       (yyval.sym) = create_quad_symbol(value, TYPE_FLOAT);
        printf("Primary float: %f\n", (yyvsp[0].fval)); 
    }
#line 2453 "y.tab.c"
    break;

  case 99: /* primary_expr: DOUBLE  */
#line 801 "parser.y"
             { 
        // Convert DOUBLE to string
        char value[20];
        sprintf(value, "%f", (yyvsp[0].fval));
        (yyval.sym) = create_quad_symbol(value, TYPE_DOUBLE);
        printf("Primary double: %f\n", (yyvsp[0].fval)); 
    }
#line 2465 "y.tab.c"
    break;

  case 100: /* primary_expr: STRING  */
#line 808 "parser.y"
             { 
        (yyval.sym) = create_quad_symbol((yyvsp[0].sval), TYPE_STRING);
        printf("Primary string: %s\n", (yyvsp[0].sval)); 
    }
#line 2474 "y.tab.c"
    break;

  case 101: /* primary_expr: CHAR  */
#line 812 "parser.y"
           { 
        (yyval.sym) = create_quad_symbol((yyvsp[0].sval), TYPE_CHAR);
        printf("Primary char: %c\n", (yyvsp[0].sval)[1]); 
    }
#line 2483 "y.tab.c"
    break;

  case 102: /* primary_expr: BOOL  */
#line 816 "parser.y"
           { 
        (yyval.sym) = create_quad_symbol((yyvsp[0].bval) ? "true" : "false", TYPE_BOOL);
        printf("Primary bool: %s\n", (yyvsp[0].bval) ? "true" : "false"); 
    }
#line 2492 "y.tab.c"
    break;

  case 103: /* primary_expr: LPAREN expression RPAREN  */
#line 820 "parser.y"
                               { (yyval.sym) = (yyvsp[-1].sym); }
#line 2498 "y.tab.c"
    break;

  case 104: /* $@11: %empty  */
#line 824 "parser.y"
              {
        num_call_parameters = 0;
    }
#line 2506 "y.tab.c"
    break;

  case 105: /* function_call: ID LPAREN $@11 argument_list RPAREN  */
#line 826 "parser.y"
                           {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-4].sval));
        if (!sym || sym->kind != KIND_FUNCTION) {
            fprintf(stderr, "Semantic Error at line %d: Undefined function %s\n", line_number,(yyvsp[-4].sval));
            exit(1);
        } else {
            if (arg_count != sym->param_count) {
                fprintf(stderr, "Semantic Error at line %d: Function '%s' expects %d arguments, but %d were given\n",
                    line_number,(yyvsp[-4].sval), sym->param_count, arg_count);
                exit(1);
            } else {

                // Create a temporary for the result
                char* temp = quad_new_temp(quad_handler, sym->type);
                num_call_parameters = (yyvsp[-1].ival);

                // Add parameters
                for (int i = 0; i < arg_count; i++) {
  
                    quad_add_param(quad_handler, function_call_parameters[i]->name);
                }

                

                for (int i = 0; i < arg_count; i++) {
                    if (arg_types[i] != sym->param_types[i]) {
                        fprintf(stderr, "Semantic Error at line %d: Type mismatch for parameter %d in function '%s'. Expected %s but got %s\n",
                            line_number,i + 1, (yyvsp[-4].sval), dataTypeName[sym->param_types[i]], dataTypeName[arg_types[i]]);
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
                
                (yyval.sym) = result;
            }


           
        }
        printf("Function call to: %s\n", (yyvsp[-4].sval));
    }
#line 2566 "y.tab.c"
    break;

  case 106: /* argument_list: argument_expr_list  */
#line 884 "parser.y"
                       { arg_count = (yyval.ival); }
#line 2572 "y.tab.c"
    break;

  case 107: /* argument_list: %empty  */
#line 885 "parser.y"
                  { arg_count = 0; }
#line 2578 "y.tab.c"
    break;

  case 108: /* argument_expr_list: argument_expr_list COMMA expression  */
#line 889 "parser.y"
                                        {
        arg_types[(yyval.ival)++] = infer_expr_type(current_scope, (yyvsp[0].sym)->name);
        function_call_parameters[arg_count++] = (yyvsp[0].sym);
        (yyval.ival) = arg_count;
    }
#line 2588 "y.tab.c"
    break;

  case 109: /* argument_expr_list: expression  */
#line 894 "parser.y"
                 {
        arg_types[0] = infer_expr_type(current_scope, (yyvsp[0].sym)->name);
        function_call_parameters[0] = (yyvsp[0].sym);
        arg_count = 1;
        (yyval.ival) = 1;
    }
#line 2599 "y.tab.c"
    break;


#line 2603 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 903 "parser.y"


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
