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
#include "quadruples.h"
#include "utils.h"

Scope* global_scope = NULL;
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

#line 125 "parser.tab.c"

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

#include "parser.tab.h"
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
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_translation_unit = 55,          /* translation_unit  */
  YYSYMBOL_external_declaration = 56,      /* external_declaration  */
  YYSYMBOL_global_declaration = 57,        /* global_declaration  */
  YYSYMBOL_type_specifier = 58,            /* type_specifier  */
  YYSYMBOL_function_definition = 59,       /* function_definition  */
  YYSYMBOL_parameters = 60,                /* parameters  */
  YYSYMBOL_parameter_list = 61,            /* parameter_list  */
  YYSYMBOL_parameter = 62,                 /* parameter  */
  YYSYMBOL_compound_statement = 63,        /* compound_statement  */
  YYSYMBOL_block_item_list = 64,           /* block_item_list  */
  YYSYMBOL_block_item = 65,                /* block_item  */
  YYSYMBOL_declaration = 66,               /* declaration  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_expression_statement = 68,      /* expression_statement  */
  YYSYMBOL_selection_statement = 69,       /* selection_statement  */
  YYSYMBOL_case_list = 70,                 /* case_list  */
  YYSYMBOL_case = 71,                      /* case  */
  YYSYMBOL_statement_list = 72,            /* statement_list  */
  YYSYMBOL_iteration_statement = 73,       /* iteration_statement  */
  YYSYMBOL_for_init_statement = 74,        /* for_init_statement  */
  YYSYMBOL_jump_statement = 75,            /* jump_statement  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_assignment_expression = 77,     /* assignment_expression  */
  YYSYMBOL_logical_or_expression = 78,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 79,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 80,       /* equality_expression  */
  YYSYMBOL_relational_expression = 81,     /* relational_expression  */
  YYSYMBOL_additive_expression = 82,       /* additive_expression  */
  YYSYMBOL_multiplicative_expr = 83,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 84,                /* unary_expr  */
  YYSYMBOL_postfix_expression = 85,        /* postfix_expression  */
  YYSYMBOL_primary_expr = 86,              /* primary_expr  */
  YYSYMBOL_function_call = 87,             /* function_call  */
  YYSYMBOL_argument_list = 88,             /* argument_list  */
  YYSYMBOL_argument_expr_list = 89         /* argument_expr_list  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

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
       0,    91,    91,    91,   103,   104,   108,   109,   113,   121,
     131,   144,   145,   146,   147,   148,   149,   150,   154,   190,
     191,   195,   196,   200,   208,   218,   219,   223,   224,   228,
     236,   246,   259,   260,   261,   262,   263,   267,   268,   272,
     284,   300,   314,   315,   319,   328,   337,   338,   342,   355,
     367,   387,   388,   392,   396,   400,   406,   415,   419,   420,
     437,   438,   449,   450,   461,   462,   470,   481,   482,   490,
     498,   506,   517,   518,   526,   537,   538,   546,   554,   565,
     566,   574,   585,   586,   590,   600,   605,   610,   615,   619,
     623,   627,   631,   647,   648,   652,   656
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
  "COMMA", "COLON", "$accept", "program", "$@1", "translation_unit",
  "external_declaration", "global_declaration", "type_specifier",
  "function_definition", "parameters", "parameter_list", "parameter",
  "compound_statement", "block_item_list", "block_item", "declaration",
  "statement", "expression_statement", "selection_statement", "case_list",
  "case", "statement_list", "iteration_statement", "for_init_statement",
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
     -99,     4,    86,   -99,   202,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,    86,   -99,   -99,    11,   -99,    16,   -99,    21,
       8,   192,   202,   -99,   192,   -15,   -99,   -99,   -99,   -99,
     -99,   -99,   209,   209,   192,    -3,   -99,    17,    26,   -22,
      38,   -10,   -25,   -99,   -99,   -99,   -99,    70,    30,    33,
     -99,    35,   192,   192,    40,   -99,   -99,    46,   -99,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   -99,    39,   202,   -99,   -99,   -99,    47,    48,
     -99,    26,   -22,    38,    38,   -10,   -10,   -10,   -10,   -25,
     -25,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   192,   132,
     -99,    51,    55,    20,    58,    59,    57,    67,    50,   202,
     -99,   -99,   114,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,    71,   192,   192,   106,   162,   192,   -99,   -99,   -99,
      72,   121,   -12,   -99,    79,    81,    83,   -99,   -99,   192,
      84,   -99,   101,   192,   -99,    20,    20,   192,    93,    85,
     192,    95,   137,   -99,    87,   192,    32,   113,   -99,    20,
     123,   104,   159,   122,    -6,   -99,   -99,   -99,   -99,    20,
     124,   -99,   -99,   -99,   -99,   -99,    20,    20,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,    11,    12,    13,    14,    15,
      17,    16,     3,     5,     7,     0,     6,     0,     4,     0,
       0,     0,    20,     8,     0,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    57,    58,    60,    62,
      64,    67,    72,    75,    79,    82,    83,     0,     0,    19,
      22,     0,     0,    94,    84,    81,    80,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,    10,    59,    96,     0,    93,
      91,    61,    63,    65,    66,    68,    69,    70,    71,    73,
      74,    76,    77,    78,    26,    18,    21,    92,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    38,     0,    33,    25,    27,    28,    32,    34,    35,
      36,     0,     0,     0,     0,     0,     0,    55,    56,    54,
       0,     0,     0,    37,     0,     0,     0,    52,    51,     0,
       0,    53,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,    39,    48,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    43,    31,    40,    49,     0,
       0,    47,    41,    42,    50,    47,    45,    44,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   -99,   166,   -99,    -2,   -99,   -99,   -99,
     100,   109,   -99,   -99,    68,   -98,    77,   -99,   -99,    19,
      28,   -99,   -99,   -99,   -21,   140,   -99,   145,   148,     1,
      25,    13,   -26,   -99,   -99,   -99,   -99,   -99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    12,    13,    14,    15,    16,    48,    49,
      50,   113,    99,   114,   115,   178,   117,   118,   164,   165,
     176,   119,   139,   120,   121,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,   116,    17,    51,     3,   124,    55,    56,    69,    70,
      71,   162,   163,    57,    19,    52,    61,    62,   143,    20,
      47,    67,    68,    25,    26,    27,    28,    29,    30,    31,
      53,   101,    77,   102,   103,   104,   105,   144,    24,   106,
     107,   108,   172,    91,    92,    93,    58,   152,   153,   162,
     163,    21,    32,    25,    26,    27,    28,    29,    30,    31,
      59,   167,    83,    84,    33,    34,    22,    94,    60,   111,
      23,   174,    47,    72,    63,    64,    73,   100,    65,    66,
      89,    90,    32,    74,    75,    53,    94,   130,    85,    86,
      87,    88,    80,    97,    33,    34,   122,   112,    98,   129,
     123,   134,   135,   125,   126,   140,   127,   131,     4,     5,
       6,     7,     8,     9,    10,    11,   128,   132,   148,   136,
     133,   141,   151,   112,   142,   145,   154,   146,   147,   157,
     149,   150,   156,   160,   161,    25,    26,    27,    28,    29,
      30,    31,   155,   101,   158,   102,   103,   104,   105,   159,
     169,   106,   107,   108,   109,     5,     6,     7,     8,     9,
      10,    11,   166,   170,    32,    25,    26,    27,    28,    29,
      30,    31,   168,   171,    96,   175,    33,    34,    18,    94,
     110,   111,    95,   173,   109,     5,     6,     7,     8,     9,
      10,    11,    76,   137,    32,    25,    26,    27,    28,    29,
      30,    31,   138,   177,    81,     0,    33,    34,    82,     0,
       0,   111,    54,    26,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,    32,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,     0,    33,    34,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34
};

static const yytype_int16 yycheck[] =
{
      21,    99,     4,    24,     0,   103,    32,    33,    33,    34,
      35,    17,    18,    34,     3,    30,    38,    39,    30,     3,
      22,    31,    32,     3,     4,     5,     6,     7,     8,     9,
      45,    11,    53,    13,    14,    15,    16,    49,    30,    19,
      20,    21,    48,    69,    70,    71,    49,   145,   146,    17,
      18,    30,    32,     3,     4,     5,     6,     7,     8,     9,
      43,   159,    61,    62,    44,    45,    45,    47,    42,    49,
      49,   169,    74,     3,    36,    37,    46,    98,    40,    41,
      67,    68,    32,    50,    49,    45,    47,   108,    63,    64,
      65,    66,    46,    46,    44,    45,    45,    99,    50,    49,
      45,   122,   123,    45,    45,   126,    49,   109,    22,    23,
      24,    25,    26,    27,    28,    29,    49,     3,   139,    13,
      49,    49,   143,   125,     3,    46,   147,    46,    45,   150,
      46,    30,    47,    46,   155,     3,     4,     5,     6,     7,
       8,     9,    49,    11,    49,    13,    14,    15,    16,    12,
      46,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    49,     4,    32,     3,     4,     5,     6,     7,
       8,     9,    49,    51,    74,    51,    44,    45,    12,    47,
      48,    49,    73,   164,    22,    23,    24,    25,    26,    27,
      28,    29,    52,   125,    32,     3,     4,     5,     6,     7,
       8,     9,   125,   175,    59,    -1,    44,    45,    60,    -1,
      -1,    49,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    32,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,    54,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    55,    56,    57,    58,    59,    58,    56,     3,
       3,    30,    45,    49,    30,     3,     4,     5,     6,     7,
       8,     9,    32,    44,    45,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    58,    60,    61,
      62,    76,    30,    45,     3,    84,    84,    76,    49,    43,
      42,    38,    39,    36,    37,    40,    41,    31,    32,    33,
      34,    35,     3,    46,    50,    49,    77,    76,    88,    89,
      46,    79,    80,    81,    81,    82,    82,    82,    82,    83,
      83,    84,    84,    84,    47,    63,    62,    46,    50,    64,
      76,    11,    13,    14,    15,    16,    19,    20,    21,    22,
      48,    49,    58,    63,    65,    66,    67,    68,    69,    73,
      75,    76,    45,    45,    67,    45,    45,    49,    49,    49,
      76,    58,     3,    49,    76,    76,    13,    66,    68,    74,
      76,    49,     3,    30,    49,    46,    46,    45,    76,    46,
      30,    76,    67,    67,    76,    49,    47,    76,    49,    12,
      46,    76,    17,    18,    70,    71,    49,    67,    49,    46,
       4,    51,    48,    71,    67,    51,    72,    72,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    54,    53,    55,    55,    56,    56,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    60,
      60,    61,    61,    62,    63,    64,    64,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    81,    82,    82,    82,    83,    83,    83,    83,    84,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    88,    88,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     3,     5,
       6,     1,     1,     1,     1,     1,     1,     1,     6,     1,
       0,     3,     1,     2,     3,     2,     0,     1,     1,     3,
       5,     6,     1,     1,     1,     1,     1,     2,     1,     5,
       7,     7,     2,     1,     4,     3,     2,     0,     5,     7,
       8,     1,     1,     3,     2,     2,     2,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     1,     0,     3,     1
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
  case 2: /* $@1: %empty  */
#line 91 "parser.y"
    { 
        // Initialize the quadruple system
        init_quads();
    }
#line 1345 "parser.tab.c"
    break;

  case 3: /* program: $@1 translation_unit  */
#line 96 "parser.y"
    {
        // Print the generated quadruples
        print_quads();
    }
#line 1354 "parser.tab.c"
    break;

  case 8: /* global_declaration: type_specifier ID SEMICOLON  */
#line 113 "parser.y"
                                {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].dtype), KIND_VAR, false);
        
        // Generate quadruple for allocation
        gen_quad(OP_ALLOCATE, (yyvsp[-1].sval), NULL, NULL);
        
        printf("Global Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1367 "parser.tab.c"
    break;

  case 9: /* global_declaration: type_specifier ID ASSIGN expression SEMICOLON  */
#line 121 "parser.y"
                                                    {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, false);
        set_initialized((yyvsp[-3].sval));
        
        // Generate quadruples - pass string version of expression
        gen_quad(OP_ALLOCATE, (yyvsp[-3].sval), NULL, NULL);
        gen_quad(OP_ASSIGN, (yyvsp[-1].sval), NULL, (yyvsp[-3].sval));
        
        printf("Global Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1382 "parser.tab.c"
    break;

  case 10: /* global_declaration: CONST type_specifier ID ASSIGN expression SEMICOLON  */
#line 131 "parser.y"
                                                          {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, true);
        set_initialized((yyvsp[-3].sval));
        
        // Generate quadruples - pass string version of expression
        gen_quad(OP_ALLOCATE, (yyvsp[-3].sval), NULL, NULL);
        gen_quad(OP_ASSIGN, (yyvsp[-1].sval), NULL, (yyvsp[-3].sval));
        
        printf("Global Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1397 "parser.tab.c"
    break;

  case 11: /* type_specifier: INT_TYPE  */
#line 144 "parser.y"
             { (yyval.dtype) = TYPE_INT; }
#line 1403 "parser.tab.c"
    break;

  case 12: /* type_specifier: FLOAT_TYPE  */
#line 145 "parser.y"
                 { (yyval.dtype) = TYPE_FLOAT; }
#line 1409 "parser.tab.c"
    break;

  case 13: /* type_specifier: DOUBLE_TYPE  */
#line 146 "parser.y"
                  { (yyval.dtype) = TYPE_DOUBLE; }
#line 1415 "parser.tab.c"
    break;

  case 14: /* type_specifier: STRING_TYPE  */
#line 147 "parser.y"
                  { (yyval.dtype) = TYPE_STRING; }
#line 1421 "parser.tab.c"
    break;

  case 15: /* type_specifier: CHAR_TYPE  */
#line 148 "parser.y"
                { (yyval.dtype) = TYPE_CHAR; }
#line 1427 "parser.tab.c"
    break;

  case 16: /* type_specifier: BOOL_TYPE  */
#line 149 "parser.y"
                { (yyval.dtype) = TYPE_BOOL; }
#line 1433 "parser.tab.c"
    break;

  case 17: /* type_specifier: VOID_TYPE  */
#line 150 "parser.y"
                { (yyval.dtype) = TYPE_VOID; }
#line 1439 "parser.tab.c"
    break;

  case 18: /* function_definition: type_specifier ID LPAREN parameters RPAREN compound_statement  */
#line 154 "parser.y"
                                                                  {
        // Insert function into global symbol table
        insert_symbol(current_scope, (yyvsp[-4].sval), (yyvsp[-5].dtype), KIND_FUNCTION, false);
        
        // Generate function label - DO THIS FIRST
        int first_quad = quad_count;
        gen_quad(OP_LABEL, (yyvsp[-4].sval), NULL, NULL);
        
        // Reorder this quad to be at the beginning
        if (first_quad > 0) {
            Quadruple temp = quads[first_quad];
            for (int i = first_quad; i > 0; i--) {
                quads[i] = quads[i-1];
            }
            quads[0] = temp;
        }
        
        printf("Function: %s\n", (yyvsp[-4].sval));

        // Set flag and create scope for parameters/body
        is_function_body = 1;            // Mark as function body
        current_scope = create_scope(current_scope);    // New scope for parameters + body
        
        // Only generate return if the last instruction is not already a return
        // This check prevents duplicate returns
        int last_quad_idx = quad_count - 1;
        if (last_quad_idx >= 0 && quads[last_quad_idx].op != OP_RETURN) {
            gen_quad(OP_RETURN, NULL, NULL, NULL);
        }
        
        is_function_body = 0;            // Reset flag after function body
        leave_scope(&current_scope);     // Return to parent scope
    }
#line 1477 "parser.tab.c"
    break;

  case 23: /* parameter: type_specifier ID  */
#line 200 "parser.y"
                      {
        insert_symbol(current_scope, (yyvsp[0].sval), (yyvsp[-1].dtype), KIND_PARAMETER, false);
        set_initialized((yyvsp[0].sval));
        printf("Parameter: %s\n", (yyvsp[0].sval));
    }
#line 1487 "parser.tab.c"
    break;

  case 24: /* compound_statement: LBRACE block_item_list RBRACE  */
#line 208 "parser.y"
                                  {
        if (!is_function_body) {
            // Only create a new scope for non-function blocks (loops/if)
            current_scope = create_scope(current_scope);
            leave_scope(&current_scope); // Leave scope after block
        }
    }
#line 1499 "parser.tab.c"
    break;

  case 29: /* declaration: type_specifier ID SEMICOLON  */
#line 228 "parser.y"
                                {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].dtype), KIND_VAR, false);
        
        // Generate allocation quadruple
        gen_quad(OP_ALLOCATE, (yyvsp[-1].sval), NULL, NULL);
        
        printf("Local Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1512 "parser.tab.c"
    break;

  case 30: /* declaration: type_specifier ID ASSIGN expression SEMICOLON  */
#line 236 "parser.y"
                                                    {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, false);
        set_initialized((yyvsp[-3].sval));
        
        // Generate quadruples
        gen_quad(OP_ALLOCATE, (yyvsp[-3].sval), NULL, NULL);
        gen_quad(OP_ASSIGN, (yyvsp[-1].sval), NULL, (yyvsp[-3].sval));
        
        printf("Local Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1527 "parser.tab.c"
    break;

  case 31: /* declaration: CONST type_specifier ID ASSIGN expression SEMICOLON  */
#line 246 "parser.y"
                                                          {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].dtype), KIND_VAR, true);
        set_initialized((yyvsp[-3].sval));
        
        // Generate quadruples
        gen_quad(OP_ALLOCATE, (yyvsp[-3].sval), NULL, NULL);
        gen_quad(OP_ASSIGN, (yyvsp[-1].sval), NULL, (yyvsp[-3].sval));
        
        printf("Local Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1542 "parser.tab.c"
    break;

  case 39: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 272 "parser.y"
                                                                {
        // Create label for false condition
        char* false_label = new_label();
        
        // Generate conditional jump
        gen_quad(OP_JMPF, (yyvsp[-2].sval), NULL, false_label);
        
        // Place label at the end
        gen_quad(OP_LABEL, false_label, NULL, NULL);
        
        printf("If statement\n");
    }
#line 1559 "parser.tab.c"
    break;

  case 40: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 284 "parser.y"
                                                           {
        // If-else statement
        // Create labels
        char* false_label = new_label();
        char* end_label = new_label();
        
        // Generate jumps for condition and after 'then'
        gen_quad(OP_JMPF, (yyvsp[-4].sval), NULL, false_label);
        gen_quad(OP_JMP, NULL, NULL, end_label);
        
        // Insert labels
        gen_quad(OP_LABEL, false_label, NULL, NULL);
        gen_quad(OP_LABEL, end_label, NULL, NULL);
        
        printf("If-else statement\n");
    }
#line 1580 "parser.tab.c"
    break;

  case 41: /* selection_statement: SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE  */
#line 300 "parser.y"
                                                              {
        char* end_switch = new_label();
        old_break_label = break_label;
        break_label = end_switch;

        // Case list will be generated with jump labels, etc.

        gen_quad(OP_LABEL, break_label, NULL, NULL);
        break_label = old_break_label;
        printf("Switch statement\n");
    }
#line 1596 "parser.tab.c"
    break;

  case 44: /* case: CASE INT COLON statement_list  */
#line 319 "parser.y"
                                  {
        // Generate case label
        char* case_label = new_label();
        char* int_str = int_to_str((yyvsp[-2].ival));
        gen_quad(OP_LABEL, case_label, NULL, NULL);
        free(int_str);

        printf("Case: %d\n", (yyvsp[-2].ival));
    }
#line 1610 "parser.tab.c"
    break;

  case 45: /* case: DEFAULT COLON statement_list  */
#line 328 "parser.y"
                                   {
        // Generate default label
        char* default_label = new_label();
        gen_quad(OP_LABEL, default_label, NULL, NULL);
        printf("Default case\n");
    }
#line 1621 "parser.tab.c"
    break;

  case 48: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 342 "parser.y"
                                             {
        // Create labels for loop
        char* start_label = new_label();
        char* end_label = new_label();
        
        // Generate quadruples
        gen_quad(OP_LABEL, start_label, NULL, NULL);
        gen_quad(OP_JMPF, (yyvsp[-2].sval), NULL, end_label);
        gen_quad(OP_JMP, NULL, NULL, start_label);
        gen_quad(OP_LABEL, end_label, NULL, NULL);
        
        printf("While loop\n");
    }
#line 1639 "parser.tab.c"
    break;

  case 49: /* iteration_statement: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 355 "parser.y"
                                                            {
        // Create labels for do-while loop
        char* start_label = new_label();
        char* end_label = new_label();
        
        // Generate quadruples
        gen_quad(OP_LABEL, start_label, NULL, NULL);
        gen_quad(OP_JMPT, (yyvsp[-2].sval), NULL, start_label);
        gen_quad(OP_LABEL, end_label, NULL, NULL);
        
        printf("Do-while loop\n");
    }
#line 1656 "parser.tab.c"
    break;

  case 50: /* iteration_statement: FOR LPAREN for_init_statement expression SEMICOLON expression RPAREN statement  */
#line 367 "parser.y"
                                                                                     {
        // Create labels for for loop
        char* cond_label = new_label();
        char* body_label = new_label();
        char* update_label = new_label();
        char* end_label = new_label();
        
        // Generate quadruples
        gen_quad(OP_LABEL, cond_label, NULL, NULL);
        gen_quad(OP_JMPF, (yyvsp[-4].sval), NULL, end_label);
        gen_quad(OP_LABEL, body_label, NULL, NULL);
        gen_quad(OP_LABEL, update_label, NULL, NULL);
        gen_quad(OP_JMP, NULL, NULL, cond_label);
        gen_quad(OP_LABEL, end_label, NULL, NULL);
        
        printf("For loop\n");
    }
#line 1678 "parser.tab.c"
    break;

  case 53: /* jump_statement: RETURN expression SEMICOLON  */
#line 392 "parser.y"
                                {
        gen_quad(OP_RETURN, (yyvsp[-1].sval), NULL, NULL);
        printf("Return statement\n");
    }
#line 1687 "parser.tab.c"
    break;

  case 54: /* jump_statement: RETURN SEMICOLON  */
#line 396 "parser.y"
                       {
        gen_quad(OP_RETURN, NULL, NULL, NULL);
        printf("Return void\n");
    }
#line 1696 "parser.tab.c"
    break;

  case 55: /* jump_statement: BREAK SEMICOLON  */
#line 400 "parser.y"
                      {
        if (break_label) {
            gen_quad(OP_JMP, NULL, NULL, break_label);
        }
        printf("Break statement\n");
    }
#line 1707 "parser.tab.c"
    break;

  case 56: /* jump_statement: CONTINUE SEMICOLON  */
#line 406 "parser.y"
                         {
        if (continue_label) {
            gen_quad(OP_JMP, NULL, NULL, continue_label);
        }
        printf("Continue statement\n");
    }
#line 1718 "parser.tab.c"
    break;

  case 57: /* expression: assignment_expression  */
#line 415 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1724 "parser.tab.c"
    break;

  case 58: /* assignment_expression: logical_or_expression  */
#line 419 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1730 "parser.tab.c"
    break;

  case 59: /* assignment_expression: ID ASSIGN assignment_expression  */
#line 420 "parser.y"
                                      {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].sval));
        if (sym == NULL) {
            fprintf(stderr, "Semantic Error: Undeclared variable %s\n", (yyvsp[-2].sval));
        } else {
            set_initialized((yyvsp[-2].sval));
        }
        
        // Generate assignment quadruple
        gen_quad(OP_ASSIGN, (yyvsp[0].sval), NULL, (yyvsp[-2].sval));
        
        (yyval.sval) = strdup((yyvsp[-2].sval));
        printf("Assignment to %s\n", (yyvsp[-2].sval));
    }
#line 1749 "parser.tab.c"
    break;

  case 60: /* logical_or_expression: logical_and_expression  */
#line 437 "parser.y"
                           { (yyval.sval) = (yyvsp[0].sval); }
#line 1755 "parser.tab.c"
    break;

  case 61: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 438 "parser.y"
                                                      { 
        // Generate OR operation
        char* temp = new_temp();
        gen_quad(OP_OR, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Logical OR\n"); 
    }
#line 1768 "parser.tab.c"
    break;

  case 62: /* logical_and_expression: equality_expression  */
#line 449 "parser.y"
                        { (yyval.sval) = (yyvsp[0].sval); }
#line 1774 "parser.tab.c"
    break;

  case 63: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 450 "parser.y"
                                                     { 
        // Generate AND operation
        char* temp = new_temp();
        gen_quad(OP_AND, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Logical AND\n"); 
    }
#line 1787 "parser.tab.c"
    break;

  case 64: /* equality_expression: relational_expression  */
#line 461 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1793 "parser.tab.c"
    break;

  case 65: /* equality_expression: equality_expression EQ relational_expression  */
#line 462 "parser.y"
                                                   { 
        // Generate equality comparison
        char* temp = new_temp();
        gen_quad(OP_EQ, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Equality\n");
    }
#line 1806 "parser.tab.c"
    break;

  case 66: /* equality_expression: equality_expression NEQ relational_expression  */
#line 470 "parser.y"
                                                    {
        // Generate inequality comparison
        char* temp = new_temp();
        gen_quad(OP_NEQ, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Not Equal\n");
    }
#line 1819 "parser.tab.c"
    break;

  case 67: /* relational_expression: additive_expression  */
#line 481 "parser.y"
                        { (yyval.sval) = (yyvsp[0].sval); }
#line 1825 "parser.tab.c"
    break;

  case 68: /* relational_expression: relational_expression LT additive_expression  */
#line 482 "parser.y"
                                                   { 
        // Generate less than comparison
        char* temp = new_temp();
        gen_quad(OP_LT, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Less than\n"); 
    }
#line 1838 "parser.tab.c"
    break;

  case 69: /* relational_expression: relational_expression GT additive_expression  */
#line 490 "parser.y"
                                                   { 
        // Generate greater than comparison
        char* temp = new_temp();
        gen_quad(OP_GT, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Greater than\n"); 
    }
#line 1851 "parser.tab.c"
    break;

  case 70: /* relational_expression: relational_expression LE additive_expression  */
#line 498 "parser.y"
                                                   { 
        // Generate less than or equal comparison
        char* temp = new_temp();
        gen_quad(OP_LE, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Less than or equal\n"); 
    }
#line 1864 "parser.tab.c"
    break;

  case 71: /* relational_expression: relational_expression GE additive_expression  */
#line 506 "parser.y"
                                                   { 
        // Generate greater than or equal comparison
        char* temp = new_temp();
        gen_quad(OP_GE, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Greater than or equal\n"); 
    }
#line 1877 "parser.tab.c"
    break;

  case 72: /* additive_expression: multiplicative_expr  */
#line 517 "parser.y"
                        { (yyval.sval) = (yyvsp[0].sval); }
#line 1883 "parser.tab.c"
    break;

  case 73: /* additive_expression: additive_expression ADD multiplicative_expr  */
#line 518 "parser.y"
                                                  { 
        // Generate addition
        char* temp = new_temp();
        gen_quad(OP_ADD, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Addition\n"); 
    }
#line 1896 "parser.tab.c"
    break;

  case 74: /* additive_expression: additive_expression SUB multiplicative_expr  */
#line 526 "parser.y"
                                                  { 
        // Generate subtraction
        char* temp = new_temp();
        gen_quad(OP_SUB, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Subtraction\n"); 
    }
#line 1909 "parser.tab.c"
    break;

  case 75: /* multiplicative_expr: unary_expr  */
#line 537 "parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 1915 "parser.tab.c"
    break;

  case 76: /* multiplicative_expr: multiplicative_expr MUL unary_expr  */
#line 538 "parser.y"
                                         { 
        // Generate multiplication
        char* temp = new_temp();
        gen_quad(OP_MUL, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Multiplication\n"); 
    }
#line 1928 "parser.tab.c"
    break;

  case 77: /* multiplicative_expr: multiplicative_expr DIV unary_expr  */
#line 546 "parser.y"
                                         { 
        // Generate division
        char* temp = new_temp();
        gen_quad(OP_DIV, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Division\n"); 
    }
#line 1941 "parser.tab.c"
    break;

  case 78: /* multiplicative_expr: multiplicative_expr MOD unary_expr  */
#line 554 "parser.y"
                                         { 
        // Generate modulo
        char* temp = new_temp();
        gen_quad(OP_MOD, (yyvsp[-2].sval), (yyvsp[0].sval), temp);
        (yyval.sval) = temp;
        
        printf("Modulo\n"); 
    }
#line 1954 "parser.tab.c"
    break;

  case 79: /* unary_expr: postfix_expression  */
#line 565 "parser.y"
                       { (yyval.sval) = (yyvsp[0].sval); }
#line 1960 "parser.tab.c"
    break;

  case 80: /* unary_expr: NOT unary_expr  */
#line 566 "parser.y"
                     { 
        // Generate logical NOT
        char* temp = new_temp();
        gen_quad(OP_NOT, (yyvsp[0].sval), NULL, temp);
        (yyval.sval) = temp;
        
        printf("Logical NOT\n"); 
    }
#line 1973 "parser.tab.c"
    break;

  case 81: /* unary_expr: SUB unary_expr  */
#line 574 "parser.y"
                     { 
        // Generate unary minus
        char* temp = new_temp();
        gen_quad(OP_NEG, (yyvsp[0].sval), NULL, temp);
        (yyval.sval) = temp;
        
        printf("Unary minus\n"); 
    }
#line 1986 "parser.tab.c"
    break;

  case 82: /* postfix_expression: primary_expr  */
#line 585 "parser.y"
                 { (yyval.sval) = (yyvsp[0].sval); }
#line 1992 "parser.tab.c"
    break;

  case 83: /* postfix_expression: function_call  */
#line 586 "parser.y"
                    { (yyval.sval) = (yyvsp[0].sval); }
#line 1998 "parser.tab.c"
    break;

  case 84: /* primary_expr: ID  */
#line 590 "parser.y"
       {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].sval));
        if (sym == NULL) {
            fprintf(stderr, "Semantic Error: Use of undeclared variable %s\n", (yyvsp[0].sval));
        } else if(!sym->initialized) {
            fprintf(stderr, "Semantic Error: Use of uninitialized variable %s\n", (yyvsp[0].sval));
        }
        (yyval.sval) = strdup((yyvsp[0].sval));
        printf("Primary ID: %s\n", (yyvsp[0].sval));
    }
#line 2013 "parser.tab.c"
    break;

  case 85: /* primary_expr: INT  */
#line 600 "parser.y"
          { 
        // Convert INT to string
        (yyval.sval) = int_to_str((yyvsp[0].ival));
        printf("Primary int: %d\n", (yyvsp[0].ival)); 
    }
#line 2023 "parser.tab.c"
    break;

  case 86: /* primary_expr: FLOAT  */
#line 605 "parser.y"
            { 
        // Convert FLOAT to string
        (yyval.sval) = float_to_str((yyvsp[0].fval));
        printf("Primary float: %f\n", (yyvsp[0].fval)); 
    }
#line 2033 "parser.tab.c"
    break;

  case 87: /* primary_expr: DOUBLE  */
#line 610 "parser.y"
             { 
        // Convert DOUBLE to string
        (yyval.sval) = double_to_str((yyvsp[0].fval));
        printf("Primary double: %f\n", (yyvsp[0].fval)); 
    }
#line 2043 "parser.tab.c"
    break;

  case 88: /* primary_expr: STRING  */
#line 615 "parser.y"
             { 
        (yyval.sval) = strdup((yyvsp[0].sval));
        printf("Primary string: %s\n", (yyvsp[0].sval)); 
    }
#line 2052 "parser.tab.c"
    break;

  case 89: /* primary_expr: CHAR  */
#line 619 "parser.y"
           { 
        (yyval.sval) = strdup((yyvsp[0].sval));
        printf("Primary char: %c\n", (yyvsp[0].sval)[1]); 
    }
#line 2061 "parser.tab.c"
    break;

  case 90: /* primary_expr: BOOL  */
#line 623 "parser.y"
           { 
        (yyval.sval) = bool_to_str((yyvsp[0].bval));
        printf("Primary bool: %s\n", (yyvsp[0].bval) ? "true" : "false"); 
    }
#line 2070 "parser.tab.c"
    break;

  case 91: /* primary_expr: LPAREN expression RPAREN  */
#line 627 "parser.y"
                               { (yyval.sval) = (yyvsp[-1].sval); }
#line 2076 "parser.tab.c"
    break;

  case 92: /* function_call: ID LPAREN argument_list RPAREN  */
#line 631 "parser.y"
                                   {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-3].sval));
        if (!sym || sym->kind != KIND_FUNCTION) {
            fprintf(stderr, "Semantic Error: Undefined function %s\n", (yyvsp[-3].sval));
        }
        
        // Generate call quadruple
        char* temp = new_temp();
        gen_quad(OP_CALL, (yyvsp[-3].sval), "0", temp);  // "0" is placeholder for arg count
        (yyval.sval) = temp;
        
        printf("Function call to: %s\n", (yyvsp[-3].sval));
    }
#line 2094 "parser.tab.c"
    break;

  case 95: /* argument_expr_list: argument_expr_list COMMA expression  */
#line 652 "parser.y"
                                        {
        // Generate parameter quadruple
        gen_quad(OP_PARAM, (yyvsp[0].sval), NULL, NULL);
    }
#line 2103 "parser.tab.c"
    break;

  case 96: /* argument_expr_list: expression  */
#line 656 "parser.y"
                 {
        // Generate parameter quadruple
        gen_quad(OP_PARAM, (yyvsp[0].sval), NULL, NULL);
    }
#line 2112 "parser.tab.c"
    break;


#line 2116 "parser.tab.c"

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

#line 662 "parser.y"


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
