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

#line 98 "y.tab.c"

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
#line 28 "parser.y"

    int ival;
    float fval;
    char* sval;
    bool  bval;
    int dtype;  /* For DataType enum */

#line 261 "y.tab.c"

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
  YYSYMBOL_selection_statement = 71,       /* selection_statement  */
  YYSYMBOL_case_list = 72,                 /* case_list  */
  YYSYMBOL_case = 73,                      /* case  */
  YYSYMBOL_statement_list = 74,            /* statement_list  */
  YYSYMBOL_iteration_statement = 75,       /* iteration_statement  */
  YYSYMBOL_76_4 = 76,                      /* $@4  */
  YYSYMBOL_for_clause = 77,                /* for_clause  */
  YYSYMBOL_for_init_statement = 78,        /* for_init_statement  */
  YYSYMBOL_jump_statement = 79,            /* jump_statement  */
  YYSYMBOL_expression = 80,                /* expression  */
  YYSYMBOL_assignment_expression = 81,     /* assignment_expression  */
  YYSYMBOL_logical_or_expression = 82,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 83,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 84,       /* equality_expression  */
  YYSYMBOL_relational_expression = 85,     /* relational_expression  */
  YYSYMBOL_additive_expression = 86,       /* additive_expression  */
  YYSYMBOL_multiplicative_expr = 87,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 88,                /* unary_expr  */
  YYSYMBOL_postfix_expression = 89,        /* postfix_expression  */
  YYSYMBOL_primary_expr = 90,              /* primary_expr  */
  YYSYMBOL_function_call = 91,             /* function_call  */
  YYSYMBOL_argument_list = 92,             /* argument_list  */
  YYSYMBOL_argument_expr_list = 93         /* argument_expr_list  */
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
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

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
       0,    65,    65,    69,    70,    74,    75,    79,    83,    95,
     103,   104,   105,   106,   107,   108,   109,   113,   122,   113,
     141,   142,   146,   147,   151,   162,   161,   182,   183,   187,
     188,   192,   196,   208,   216,   217,   218,   219,   220,   224,
     225,   229,   232,   235,   241,   242,   246,   249,   255,   256,
     260,   263,   266,   266,   271,   276,   277,   281,   284,   287,
     290,   296,   300,   301,   325,   326,   340,   341,   355,   356,
     367,   381,   382,   393,   404,   415,   429,   430,   440,   453,
     454,   464,   474,   487,   488,   497,   509,   510,   514,   531,
     536,   541,   546,   550,   554,   558,   562,   587,   588,   592,
     596
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
  "selection_statement", "case_list", "case", "statement_list",
  "iteration_statement", "$@4", "for_clause", "for_init_statement",
  "jump_statement", "expression", "assignment_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression", "multiplicative_expr",
  "unary_expr", "postfix_expression", "primary_expr", "function_call",
  "argument_list", "argument_expr_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      45,   184,   -99,   -99,   -99,   -99,   -99,   -99,   -99,     2,
      45,   -99,   -99,     3,   -99,     7,   -99,   -99,    13,   -16,
     174,   -99,   -99,   174,    21,   -99,   -99,   -99,   -99,   -99,
     -99,   191,   191,   174,   -27,   -99,   -13,    -8,   -30,    51,
      47,    95,   -99,   -99,   -99,   -99,   184,    -4,   174,   174,
      35,   -99,   -99,    17,   -99,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,    79,    40,
      39,   -99,   -99,   -99,   -99,    48,    53,   -99,    -8,   -30,
      51,    51,    47,    47,    47,    47,    95,    95,   -99,   -99,
     -99,   -99,   -99,   184,   -99,   174,    75,   -99,   -99,   -99,
     -99,   -99,   144,    80,    81,    12,    87,    90,    85,    91,
      32,   184,   -99,   -99,   135,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,    93,   174,   174,   130,   -99,   174,   -99,
     -99,   -99,    96,   141,   -25,   -99,   108,   110,   116,    92,
     128,   -99,   132,   174,   -99,    12,    12,   174,   -99,   -99,
     129,   174,   137,   174,   136,   175,   -99,   140,    12,   152,
      89,   153,   -99,    12,   154,   -99,   174,   186,   163,    -6,
     -99,   -99,   -99,   -99,   -99,   164,   -99,   -99,   -99,   -99,
      12,    12,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,    12,    13,    14,    16,    15,     0,
       2,     4,     6,     0,     5,     0,     1,     3,     0,     0,
       0,    17,     7,     0,    88,    89,    90,    91,    92,    93,
      94,     0,     0,     0,     0,    61,    62,    64,    66,    68,
      71,    76,    79,    83,    86,    87,    21,     0,     0,    98,
      88,    85,    84,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    23,     9,    63,   100,     0,    97,    95,    65,    67,
      69,    70,    72,    73,    74,    75,    77,    78,    80,    81,
      82,    24,    18,     0,    96,     0,     0,    22,    99,    25,
      19,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,    40,     0,    35,    27,    29,    30,    34,
      36,    37,    38,     0,     0,     0,     0,    52,     0,    59,
      60,    58,     0,     0,     0,    39,     0,     0,     0,     0,
       0,    57,     0,     0,    31,     0,     0,     0,    56,    55,
       0,     0,     0,     0,     0,    41,    50,     0,     0,     0,
       0,     0,    32,     0,     0,    53,     0,     0,     0,     0,
      45,    33,    42,    51,    54,     0,    49,    43,    44,    49,
      47,    46,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   194,   -99,     0,   -99,   -99,   -99,   -99,
     -99,   112,   120,   -99,   -99,   -99,    78,   -98,    82,   -99,
     -99,    55,    41,   -99,   -99,   -99,   -99,   -99,   -20,   177,
     -99,   167,   170,    52,    -7,    49,    18,   -99,   -99,   -99,
     -99,   -99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    14,    46,    96,    69,
      70,    71,   115,   101,   102,   116,   117,   182,   119,   120,
     169,   170,   180,   121,   139,   150,   151,   122,   123,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    15,    16,    47,   118,   143,    18,   126,    57,    58,
      19,   167,   168,    53,    23,    24,    25,    26,    27,    28,
      29,    30,    54,   103,   144,   104,   105,   106,   107,    74,
      55,   108,   109,   110,    56,    24,    25,    26,    27,    28,
      29,    30,   177,    20,    31,    72,    68,   155,   156,    51,
      52,    48,    82,    83,    84,    85,    32,    33,    21,    99,
     165,   113,    22,    77,    31,   172,    49,     1,     2,     3,
       4,     5,     6,     7,     8,    98,    32,    33,    63,    64,
      49,   131,    91,    88,    89,    90,    92,    59,    60,    93,
     132,    61,    62,    68,    94,    24,    25,    26,    27,    28,
      29,    30,   114,    95,   136,   137,   167,   168,   140,    80,
      81,   133,    86,    87,   111,     2,     3,     4,     5,     6,
       7,     8,    99,   154,    31,   124,   125,   157,    65,    66,
      67,   159,   127,   161,   129,   128,    32,    33,   134,   114,
     130,   113,   135,   138,   142,   141,   174,    24,    25,    26,
      27,    28,    29,    30,   145,   103,   146,   104,   105,   106,
     107,   147,   153,   108,   109,   110,   111,     2,     3,     4,
       5,     6,     7,     8,   152,   158,    31,    24,    25,    26,
      27,    28,    29,    30,   160,   162,   164,   163,    32,    33,
     175,    99,   112,   113,    50,    25,    26,    27,    28,    29,
      30,   166,   171,   173,    17,    97,    31,     2,     3,     4,
       5,     6,     7,     8,   176,   179,   100,   148,    32,    33,
     181,   149,    78,    31,   178,    73,    79,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33
};

static const yytype_int16 yycheck[] =
{
      20,     1,     0,    23,   102,    30,     3,   105,    38,    39,
       3,    17,    18,    33,    30,     3,     4,     5,     6,     7,
       8,     9,    49,    11,    49,    13,    14,    15,    16,    49,
      43,    19,    20,    21,    42,     3,     4,     5,     6,     7,
       8,     9,    48,    30,    32,    49,    46,   145,   146,    31,
      32,    30,    59,    60,    61,    62,    44,    45,    45,    47,
     158,    49,    49,    46,    32,   163,    45,    22,    23,    24,
      25,    26,    27,    28,    29,    95,    44,    45,    31,    32,
      45,    49,     3,    65,    66,    67,    46,    36,    37,    50,
     110,    40,    41,    93,    46,     3,     4,     5,     6,     7,
       8,     9,   102,    50,   124,   125,    17,    18,   128,    57,
      58,   111,    63,    64,    22,    23,    24,    25,    26,    27,
      28,    29,    47,   143,    32,    45,    45,   147,    33,    34,
      35,   151,    45,   153,    49,    45,    44,    45,     3,   139,
      49,    49,    49,    13,     3,    49,   166,     3,     4,     5,
       6,     7,     8,     9,    46,    11,    46,    13,    14,    15,
      16,    45,    30,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    46,    46,    32,     3,     4,     5,
       6,     7,     8,     9,    47,    49,    46,    12,    44,    45,
       4,    47,    48,    49,     3,     4,     5,     6,     7,     8,
       9,    49,    49,    49,    10,    93,    32,    23,    24,    25,
      26,    27,    28,    29,    51,    51,    96,   139,    44,    45,
     179,   139,    55,    32,   169,    48,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    23,    24,    25,    26,    27,    28,    29,    53,
      54,    55,    56,    57,    58,    57,     0,    55,     3,     3,
      30,    45,    49,    30,     3,     4,     5,     6,     7,     8,
       9,    32,    44,    45,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    59,    80,    30,    45,
       3,    88,    88,    80,    49,    43,    42,    38,    39,    36,
      37,    40,    41,    31,    32,    33,    34,    35,    57,    61,
      62,    63,    49,    81,    80,    92,    93,    46,    83,    84,
      85,    85,    86,    86,    86,    86,    87,    87,    88,    88,
      88,     3,    46,    50,    46,    50,    60,    63,    80,    47,
      64,    65,    66,    11,    13,    14,    15,    16,    19,    20,
      21,    22,    48,    49,    57,    64,    67,    68,    69,    70,
      71,    75,    79,    80,    45,    45,    69,    45,    45,    49,
      49,    49,    80,    57,     3,    49,    80,    80,    13,    76,
      80,    49,     3,    30,    49,    46,    46,    45,    68,    70,
      77,    78,    46,    30,    80,    69,    69,    80,    46,    80,
      47,    80,    49,    12,    46,    69,    49,    17,    18,    72,
      73,    49,    69,    49,    80,     4,    51,    48,    73,    51,
      74,    74,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    59,    60,    58,
      61,    61,    62,    62,    63,    65,    64,    66,    66,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    75,    77,    78,    78,    79,    79,    79,
      79,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    85,    85,    85,    85,    85,    86,    86,    86,    87,
      87,    87,    87,    88,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    92,    92,    93,
      93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     6,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     8,
       1,     0,     3,     1,     2,     0,     4,     2,     0,     1,
       1,     3,     5,     6,     1,     1,     1,     1,     1,     2,
       1,     5,     7,     7,     2,     1,     4,     3,     2,     0,
       5,     7,     0,     6,     4,     1,     1,     3,     2,     2,
       2,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     1,     0,     3,
       1
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
#line 79 "parser.y"
                                {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].dtype), KIND_VAR, false);        
        printf("Global Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1482 "y.tab.c"
    break;

  case 8: /* global_declaration: type_specifier ID ASSIGN expression SEMICOLON  */
#line 83 "parser.y"
                                                    {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, false);
        set_initialized(current_scope,(yyvsp[-3].sval));
        
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-3].sval));
        if (sym && sym->type != infer_expr_type(current_scope,(yyvsp[-1].sval))) {
            fprintf(stderr, "Semantic Error at line %d: Type mismatch in declaration of '%s'. Expected %s but got %s.\n",
                line_number, (yyvsp[-3].sval), dataTypeName[sym->type], dataTypeName[infer_expr_type(current_scope,(yyvsp[-1].sval))]);
            exit(1);
        }
        printf("Global Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1499 "y.tab.c"
    break;

  case 9: /* global_declaration: CONST type_specifier ID ASSIGN expression SEMICOLON  */
#line 95 "parser.y"
                                                          {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, true);
        set_initialized(current_scope,(yyvsp[-3].sval));
        printf("Global Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1509 "y.tab.c"
    break;

  case 10: /* type_specifier: INT_TYPE  */
#line 103 "parser.y"
             { (yyval.dtype) = TYPE_INT; }
#line 1515 "y.tab.c"
    break;

  case 11: /* type_specifier: FLOAT_TYPE  */
#line 104 "parser.y"
                 { (yyval.dtype) = TYPE_FLOAT; }
#line 1521 "y.tab.c"
    break;

  case 12: /* type_specifier: DOUBLE_TYPE  */
#line 105 "parser.y"
                  { (yyval.dtype) = TYPE_DOUBLE; }
#line 1527 "y.tab.c"
    break;

  case 13: /* type_specifier: STRING_TYPE  */
#line 106 "parser.y"
                  { (yyval.dtype) = TYPE_STRING; }
#line 1533 "y.tab.c"
    break;

  case 14: /* type_specifier: CHAR_TYPE  */
#line 107 "parser.y"
                { (yyval.dtype) = TYPE_CHAR; }
#line 1539 "y.tab.c"
    break;

  case 15: /* type_specifier: BOOL_TYPE  */
#line 108 "parser.y"
                { (yyval.dtype) = TYPE_BOOL; }
#line 1545 "y.tab.c"
    break;

  case 16: /* type_specifier: VOID_TYPE  */
#line 109 "parser.y"
                { (yyval.dtype) = TYPE_VOID; }
#line 1551 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 113 "parser.y"
                             {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].dtype), KIND_FUNCTION, false);

        // Reset parameter tracker
        current_param_index = 0;

        is_function_body = 1;
        current_scope = create_scope(current_scope);
    }
#line 1565 "y.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 122 "parser.y"
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
#line 1584 "y.tab.c"
    break;

  case 24: /* parameter: type_specifier ID  */
#line 151 "parser.y"
                      {
        insert_symbol(current_scope, (yyvsp[0].sval), (yyvsp[-1].dtype), KIND_PARAMETER, false);
        set_initialized(current_scope, (yyvsp[0].sval));
        current_param_types[current_param_index++] = (yyvsp[-1].dtype);  // Collect type
        printf("Parameter: %s\n", (yyvsp[0].sval));
    }
#line 1595 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 162 "parser.y"
    {
        if (!is_function_body) {
            // Only create a new scope for non-function blocks (loops/if)
            current_scope = create_scope(current_scope);
        }
        else
        {is_function_body=0;}
        
    }
#line 1609 "y.tab.c"
    break;

  case 26: /* compound_statement: LBRACE $@3 block_item_list RBRACE  */
#line 173 "parser.y"
    {
       
            // Only leave scope for non-function blocks
            leave_scope(&current_scope);
        
    }
#line 1620 "y.tab.c"
    break;

  case 31: /* declaration: type_specifier ID SEMICOLON  */
#line 192 "parser.y"
                                {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].dtype), KIND_VAR, false);
        printf("Local Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1629 "y.tab.c"
    break;

  case 32: /* declaration: type_specifier ID ASSIGN expression SEMICOLON  */
#line 196 "parser.y"
                                                    {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, false);
        set_initialized(current_scope,(yyvsp[-3].sval));

        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-3].sval));
        if (sym && sym->type != infer_expr_type(current_scope,(yyvsp[-1].sval))) {
            fprintf(stderr, "Semantic Error line %d: Type mismatch in declaration of '%s'. Expected %s but got %s.\n",
                line_number, (yyvsp[-3].sval), dataTypeName[sym->type], dataTypeName[infer_expr_type(current_scope,(yyvsp[-1].sval))]);
            exit(1);
        }
        printf("Local Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1646 "y.tab.c"
    break;

  case 33: /* declaration: CONST type_specifier ID ASSIGN expression SEMICOLON  */
#line 208 "parser.y"
                                                          {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, true);
        set_initialized(current_scope,(yyvsp[-3].sval));
        printf("Local Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1656 "y.tab.c"
    break;

  case 41: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 229 "parser.y"
                                                                {
        printf("If statement\n");
    }
#line 1664 "y.tab.c"
    break;

  case 42: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 232 "parser.y"
                                                           {
        printf("If-else statement\n");
    }
#line 1672 "y.tab.c"
    break;

  case 43: /* selection_statement: SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE  */
#line 235 "parser.y"
                                                              {
        printf("Switch statement\n");
    }
#line 1680 "y.tab.c"
    break;

  case 46: /* case: CASE INT COLON statement_list  */
#line 246 "parser.y"
                                  {
        printf("Case: %d\n", (yyvsp[-2].ival));
    }
#line 1688 "y.tab.c"
    break;

  case 47: /* case: DEFAULT COLON statement_list  */
#line 249 "parser.y"
                                   {
        printf("Default case\n");
    }
#line 1696 "y.tab.c"
    break;

  case 50: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 260 "parser.y"
                                             {
        printf("While loop\n");
    }
#line 1704 "y.tab.c"
    break;

  case 51: /* iteration_statement: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 263 "parser.y"
                                                            {
        printf("Do-while loop\n");
    }
#line 1712 "y.tab.c"
    break;

  case 52: /* $@4: %empty  */
#line 266 "parser.y"
                 { is_function_body = 1; current_scope = create_scope(current_scope);}
#line 1718 "y.tab.c"
    break;

  case 53: /* iteration_statement: FOR LPAREN $@4 for_clause RPAREN statement  */
#line 267 "parser.y"
                                    {  printf("For loop\n"); }
#line 1724 "y.tab.c"
    break;

  case 57: /* jump_statement: RETURN expression SEMICOLON  */
#line 281 "parser.y"
                                {
        printf("Return statement\n");
    }
#line 1732 "y.tab.c"
    break;

  case 58: /* jump_statement: RETURN SEMICOLON  */
#line 284 "parser.y"
                       {
        printf("Return void\n");
    }
#line 1740 "y.tab.c"
    break;

  case 59: /* jump_statement: BREAK SEMICOLON  */
#line 287 "parser.y"
                      {
        printf("Break statement\n");
    }
#line 1748 "y.tab.c"
    break;

  case 60: /* jump_statement: CONTINUE SEMICOLON  */
#line 290 "parser.y"
                         {
        printf("Continue statement\n");
    }
#line 1756 "y.tab.c"
    break;

  case 61: /* expression: assignment_expression  */
#line 296 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1762 "y.tab.c"
    break;

  case 62: /* assignment_expression: logical_or_expression  */
#line 300 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1768 "y.tab.c"
    break;

  case 63: /* assignment_expression: ID ASSIGN assignment_expression  */
#line 301 "parser.y"
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

            if (sym->type != infer_expr_type(current_scope,(yyvsp[0].sval))) {
            fprintf(stderr, "Semantic Error line %d: Type mismatch in assignment to '%s'. Expected %s but got %s.\n",
                line_number, (yyvsp[-2].sval), dataTypeName[sym->type], dataTypeName[infer_expr_type(current_scope,(yyvsp[0].sval))]);
                exit(1);
            }
            printf("Assignment to %s\n", (yyvsp[-2].sval));
        }
        (yyval.sval) = strdup((yyvsp[-2].sval));
    }
#line 1794 "y.tab.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 325 "parser.y"
                           { (yyval.sval) = (yyvsp[0].sval); }
#line 1800 "y.tab.c"
    break;

  case 65: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 326 "parser.y"
                                                      { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "||")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical or: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
         (yyval.sval)="true";
        printf("Logical OR\n"); 
    }
#line 1816 "y.tab.c"
    break;

  case 66: /* logical_and_expression: equality_expression  */
#line 340 "parser.y"
                        { (yyval.sval) = (yyvsp[0].sval); }
#line 1822 "y.tab.c"
    break;

  case 67: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 341 "parser.y"
                                                     { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "&&")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical and: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
         (yyval.sval)="true";
        printf("Logical AND\n"); 
    }
#line 1838 "y.tab.c"
    break;

  case 68: /* equality_expression: relational_expression  */
#line 355 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1844 "y.tab.c"
    break;

  case 69: /* equality_expression: equality_expression EQ relational_expression  */
#line 356 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "==")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
         (yyval.sval)="true";
        printf("Equality\n");
    }
#line 1860 "y.tab.c"
    break;

  case 70: /* equality_expression: equality_expression NEQ relational_expression  */
#line 367 "parser.y"
                                                    {
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "!=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for not equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
         (yyval.sval)="true";
        printf("Not Equal\n");
    }
#line 1876 "y.tab.c"
    break;

  case 71: /* relational_expression: additive_expression  */
#line 381 "parser.y"
                        { (yyval.sval) = (yyvsp[0].sval); }
#line 1882 "y.tab.c"
    break;

  case 72: /* relational_expression: relational_expression LT additive_expression  */
#line 382 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "<")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for less than: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sval)="true";
        printf("Less than\n"); 
    }
#line 1898 "y.tab.c"
    break;

  case 73: /* relational_expression: relational_expression GT additive_expression  */
#line 393 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, ">")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for greater than: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sval)="true";
        printf("Greater than\n"); 
    }
#line 1914 "y.tab.c"
    break;

  case 74: /* relational_expression: relational_expression LE additive_expression  */
#line 404 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "<=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for less than or equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sval)="true";
        printf("Less than or equal\n"); 
    }
#line 1930 "y.tab.c"
    break;

  case 75: /* relational_expression: relational_expression GE additive_expression  */
#line 415 "parser.y"
                                                   { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, ">=")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for greater than or equal: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        (yyval.sval)="true";
        printf("Greater than or equal\n"); 
    }
#line 1946 "y.tab.c"
    break;

  case 76: /* additive_expression: multiplicative_expr  */
#line 429 "parser.y"
                        { (yyval.sval) = (yyvsp[0].sval); }
#line 1952 "y.tab.c"
    break;

  case 77: /* additive_expression: additive_expression ADD multiplicative_expr  */
#line 430 "parser.y"
                                                  { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "+")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for addition: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Addition\n"); 
    }
#line 1967 "y.tab.c"
    break;

  case 78: /* additive_expression: additive_expression SUB multiplicative_expr  */
#line 440 "parser.y"
                                                  { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "-")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for subtraction: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Subtraction\n"); 
    }
#line 1982 "y.tab.c"
    break;

  case 79: /* multiplicative_expr: unary_expr  */
#line 453 "parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 1988 "y.tab.c"
    break;

  case 80: /* multiplicative_expr: multiplicative_expr MUL unary_expr  */
#line 454 "parser.y"
                                         { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "*")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for multiplication: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Multiplication\n"); 
    }
#line 2003 "y.tab.c"
    break;

  case 81: /* multiplicative_expr: multiplicative_expr DIV unary_expr  */
#line 464 "parser.y"
                                         { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "/")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for division: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Division\n"); 
    }
#line 2018 "y.tab.c"
    break;

  case 82: /* multiplicative_expr: multiplicative_expr MOD unary_expr  */
#line 474 "parser.y"
                                         { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[-2].sval));
        DataType rightType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, rightType, "%")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for modulus: %s and %s\n",
                line_number, dataTypeName[leftType], dataTypeName[rightType]);
            exit(1);
        }
        printf("Modulo\n"); 
    }
#line 2033 "y.tab.c"
    break;

  case 83: /* unary_expr: postfix_expression  */
#line 487 "parser.y"
                       { (yyval.sval) = (yyvsp[0].sval); }
#line 2039 "y.tab.c"
    break;

  case 84: /* unary_expr: NOT unary_expr  */
#line 488 "parser.y"
                     { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, TYPE_BOOL, "!")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for logical not: %s\n",
                line_number, dataTypeName[leftType]);
            exit(1);
        }
        printf("Logical NOT\n"); 
    }
#line 2053 "y.tab.c"
    break;

  case 85: /* unary_expr: SUB unary_expr  */
#line 497 "parser.y"
                     { 
        DataType leftType = infer_expr_type(current_scope,(yyvsp[0].sval));
        if (!areTypesCompatibleForOp(leftType, TYPE_INT, "-")) {
            fprintf(stderr, "Semantic Error at line %d: Incompatible types for unary minus: %s\n",
                line_number, dataTypeName[leftType]);
            exit(1);
        }
        printf("Unary minus\n"); 
    }
#line 2067 "y.tab.c"
    break;

  case 86: /* postfix_expression: primary_expr  */
#line 509 "parser.y"
                 { (yyval.sval) = (yyvsp[0].sval); }
#line 2073 "y.tab.c"
    break;

  case 87: /* postfix_expression: function_call  */
#line 510 "parser.y"
                    { (yyval.sval) = (yyvsp[0].sval); }
#line 2079 "y.tab.c"
    break;

  case 88: /* primary_expr: ID  */
#line 514 "parser.y"
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
        (yyval.sval) = strdup((yyvsp[0].sval));
        printf("Primary ID: %s\n", (yyvsp[0].sval));
    }
#line 2101 "y.tab.c"
    break;

  case 89: /* primary_expr: INT  */
#line 531 "parser.y"
          { 
        // Convert INT to string
        (yyval.sval) = int_to_str((yyvsp[0].ival));
        printf("Primary int: %d\n", (yyvsp[0].ival)); 
    }
#line 2111 "y.tab.c"
    break;

  case 90: /* primary_expr: FLOAT  */
#line 536 "parser.y"
            { 
        // Convert FLOAT to string
        (yyval.sval) = float_to_str((yyvsp[0].fval));
        printf("Primary float: %f\n", (yyvsp[0].fval)); 
    }
#line 2121 "y.tab.c"
    break;

  case 91: /* primary_expr: DOUBLE  */
#line 541 "parser.y"
             { 
        // Convert DOUBLE to string
        (yyval.sval) = double_to_str((yyvsp[0].fval));
        printf("Primary double: %f\n", (yyvsp[0].fval)); 
    }
#line 2131 "y.tab.c"
    break;

  case 92: /* primary_expr: STRING  */
#line 546 "parser.y"
             { 
        (yyval.sval) = strdup((yyvsp[0].sval));
        printf("Primary string: %s\n", (yyvsp[0].sval)); 
    }
#line 2140 "y.tab.c"
    break;

  case 93: /* primary_expr: CHAR  */
#line 550 "parser.y"
           { 
        (yyval.sval) = strdup((yyvsp[0].sval));
        printf("Primary char: %c\n", (yyvsp[0].sval)[1]); 
    }
#line 2149 "y.tab.c"
    break;

  case 94: /* primary_expr: BOOL  */
#line 554 "parser.y"
           { 
        (yyval.sval) = bool_to_str((yyvsp[0].bval));
        printf("Primary bool: %s\n", (yyvsp[0].bval) ? "true" : "false"); 
    }
#line 2158 "y.tab.c"
    break;

  case 95: /* primary_expr: LPAREN expression RPAREN  */
#line 558 "parser.y"
                               { (yyval.sval) = (yyvsp[-1].sval); }
#line 2164 "y.tab.c"
    break;

  case 96: /* function_call: ID LPAREN argument_list RPAREN  */
#line 562 "parser.y"
                                   {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-3].sval));
    if (!sym || sym->kind != KIND_FUNCTION) {
        fprintf(stderr, "Semantic Error at line %d: Undefined function %s\n", line_number,(yyvsp[-3].sval));
        exit(1);
    } else {
        if (arg_count != sym->param_count) {
            fprintf(stderr, "Semantic Error at line %d: Function '%s' expects %d arguments, but %d were given\n",
                line_number,(yyvsp[-3].sval), sym->param_count, arg_count);
            exit(1);
        } else {
            for (int i = 0; i < arg_count; i++) {
                if (arg_types[i] != sym->param_types[i]) {
                    fprintf(stderr, "Semantic Error at line %d: Type mismatch for parameter %d in function '%s'. Expected %s but got %s\n",
                        line_number,i + 1, (yyvsp[-3].sval), dataTypeName[sym->param_types[i]], dataTypeName[arg_types[i]]);
                    exit(1);
                }
            }
        }
    }
    printf("Function call to: %s\n", (yyvsp[-3].sval));
    }
#line 2191 "y.tab.c"
    break;

  case 97: /* argument_list: argument_expr_list  */
#line 587 "parser.y"
                       { arg_count = (yyval.ival); }
#line 2197 "y.tab.c"
    break;

  case 98: /* argument_list: %empty  */
#line 588 "parser.y"
                  { arg_count = 0; }
#line 2203 "y.tab.c"
    break;

  case 99: /* argument_expr_list: argument_expr_list COMMA expression  */
#line 592 "parser.y"
                                        {
        arg_types[(yyval.ival)++] = infer_expr_type(current_scope,(yyvsp[0].sval));
        (yyval.ival) = (yyval.ival);
    }
#line 2212 "y.tab.c"
    break;

  case 100: /* argument_expr_list: expression  */
#line 596 "parser.y"
                 {
        arg_types[0] = infer_expr_type(current_scope,(yyvsp[0].sval));
        (yyval.ival) = 1;
    }
#line 2221 "y.tab.c"
    break;


#line 2225 "y.tab.c"

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

#line 603 "parser.y"


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
