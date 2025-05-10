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

Scope* global_scope = NULL;
Scope* current_scope = NULL;
int is_function_body = 0;

int yylex();
void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}

#line 88 "parser.tab.c"

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
  YYSYMBOL_translation_unit = 54,          /* translation_unit  */
  YYSYMBOL_external_declaration = 55,      /* external_declaration  */
  YYSYMBOL_global_declaration = 56,        /* global_declaration  */
  YYSYMBOL_type_specifier = 57,            /* type_specifier  */
  YYSYMBOL_function_definition = 58,       /* function_definition  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_parameters = 60,                /* parameters  */
  YYSYMBOL_parameter_list = 61,            /* parameter_list  */
  YYSYMBOL_parameter = 62,                 /* parameter  */
  YYSYMBOL_compound_statement = 63,        /* compound_statement  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_block_item_list = 65,           /* block_item_list  */
  YYSYMBOL_block_item = 66,                /* block_item  */
  YYSYMBOL_declaration = 67,               /* declaration  */
  YYSYMBOL_statement = 68,                 /* statement  */
  YYSYMBOL_expression_statement = 69,      /* expression_statement  */
  YYSYMBOL_selection_statement = 70,       /* selection_statement  */
  YYSYMBOL_case_list = 71,                 /* case_list  */
  YYSYMBOL_case = 72,                      /* case  */
  YYSYMBOL_statement_list = 73,            /* statement_list  */
  YYSYMBOL_iteration_statement = 74,       /* iteration_statement  */
  YYSYMBOL_75_3 = 75,                      /* $@3  */
  YYSYMBOL_for_clause = 76,                /* for_clause  */
  YYSYMBOL_for_init_statement = 77,        /* for_init_statement  */
  YYSYMBOL_jump_statement = 78,            /* jump_statement  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_assignment_expression = 80,     /* assignment_expression  */
  YYSYMBOL_logical_or_expression = 81,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 82,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 83,       /* equality_expression  */
  YYSYMBOL_relational_expression = 84,     /* relational_expression  */
  YYSYMBOL_additive_expression = 85,       /* additive_expression  */
  YYSYMBOL_multiplicative_expr = 86,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 87,                /* unary_expr  */
  YYSYMBOL_postfix_expression = 88,        /* postfix_expression  */
  YYSYMBOL_primary_expr = 89,              /* primary_expr  */
  YYSYMBOL_function_call = 90,             /* function_call  */
  YYSYMBOL_argument_list = 91              /* argument_list  */
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
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
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
       0,    55,    55,    59,    60,    64,    65,    69,    73,    79,
      88,    89,    90,    91,    92,    93,    94,    99,    98,   115,
     116,   120,   121,   125,   133,   132,   150,   151,   155,   156,
     160,   164,   170,   179,   180,   181,   182,   183,   187,   188,
     192,   195,   198,   204,   205,   209,   212,   218,   219,   223,
     226,   229,   229,   234,   238,   239,   243,   246,   249,   252,
     258,   262,   263,   276,   277,   281,   282,   286,   287,   288,
     292,   293,   294,   295,   296,   300,   301,   302,   306,   307,
     308,   309,   313,   314,   318,   319,   323,   332,   333,   334,
     335,   336,   337,   338,   343,   353,   354,   355
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
  "function_definition", "$@1", "parameters", "parameter_list",
  "parameter", "compound_statement", "$@2", "block_item_list",
  "block_item", "declaration", "statement", "expression_statement",
  "selection_statement", "case_list", "case", "statement_list",
  "iteration_statement", "$@3", "for_clause", "for_init_statement",
  "jump_statement", "expression", "assignment_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression", "multiplicative_expr",
  "unary_expr", "postfix_expression", "primary_expr", "function_call",
  "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,   154,   -97,   -97,   -97,   -97,   -97,   -97,   -97,     6,
     147,   -97,   -97,    12,   -97,    17,   -97,   -97,    57,    10,
      76,   154,   -97,    76,   -26,   -97,   -97,   -97,   -97,   -97,
     -97,   159,    76,    21,   -97,    23,    32,    29,   -27,    86,
      27,   -97,   -97,   -97,   -97,    75,    42,    47,   -97,    50,
      76,    76,    60,   -97,    62,   -97,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   -97,
     -97,   154,   -97,   -97,   -97,   -28,   -97,    32,    29,   -27,
     -27,    86,    86,    86,    86,    27,    27,   -97,   -97,   -97,
      56,   -97,   -97,    76,   -97,   -97,   -97,   -97,    28,    83,
      85,   140,    96,   105,    73,   103,    20,   154,   -97,   -97,
     183,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   139,
      76,    76,   179,   -97,    76,   -97,   -97,   -97,   144,   191,
     -19,   -97,   149,   150,   152,    87,   153,   -97,   168,    76,
     -97,   140,   140,    76,   -97,   -97,   155,    76,   158,    76,
     151,   190,   -97,   160,   140,   161,   116,   162,   -97,   140,
     163,   -97,    76,   203,   157,   -10,   -97,   -97,   -97,   -97,
     -97,   164,   -97,   -97,   -97,   -97,   140,   140,   -97
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,    12,    13,    14,    16,    15,     0,
       2,     4,     6,     0,     5,     0,     1,     3,     0,     0,
       0,    20,     7,     0,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    60,    61,    63,    65,    67,    70,
      75,    78,    82,    84,    85,     0,     0,    19,    22,     0,
       0,    97,    86,    83,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      17,     0,     9,    62,    95,     0,    93,    64,    66,    68,
      69,    71,    72,    73,    74,    76,    77,    79,    80,    81,
       0,    21,    94,     0,    24,    18,    96,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    39,
       0,    34,    26,    28,    29,    33,    35,    36,    37,     0,
       0,     0,     0,    51,     0,    58,    59,    57,     0,     0,
       0,    38,     0,     0,     0,     0,     0,    56,     0,     0,
      30,     0,     0,     0,    55,    54,     0,     0,     0,     0,
       0,    40,    49,     0,     0,     0,     0,     0,    31,     0,
       0,    52,     0,     0,     0,     0,    44,    32,    41,    50,
      53,     0,    48,    42,    43,    48,    46,    45,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   -97,   199,   -97,     0,   -97,   -97,   -97,   -97,
     142,   124,   -97,   -97,   -97,    81,   -96,    82,   -97,   -97,
      53,    44,   -97,   -97,   -97,   -97,   -97,   -20,   -34,   -97,
     165,   166,    99,    77,   126,    58,   -97,   -97,   -97,   -97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    14,    90,    46,    47,
      48,   111,    97,    98,   112,   113,   178,   115,   116,   165,
     166,   176,   117,   135,   146,   147,   118,   119,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    15,   114,    49,    50,   122,    16,   163,   164,    60,
      61,   139,    54,    62,    63,    18,    73,    74,    92,    51,
      19,    45,    93,    24,    25,    26,    27,    28,    29,    30,
     140,    24,    25,    26,    27,    28,    29,    30,   173,    99,
      23,   100,   101,   102,   103,   151,   152,   104,   105,   106,
     107,     2,     3,     4,     5,     6,     7,     8,   161,    96,
      66,    67,    68,   168,    31,    32,    56,    58,    59,   127,
      55,    45,    31,    32,    57,    94,   108,   109,    69,    24,
      25,    26,    27,    28,    29,    30,   128,    20,    70,    53,
      24,    25,    26,    27,    28,    29,    30,    71,   110,    72,
     132,   133,    21,    94,   136,    51,    22,   129,    76,   107,
       2,     3,     4,     5,     6,     7,     8,    64,    65,   150,
      31,    32,   125,   153,    87,    88,    89,   155,   120,   157,
     121,    31,    32,   163,   164,   110,   109,    81,    82,    83,
      84,   123,   170,    24,    25,    26,    27,    28,    29,    30,
     124,    99,   126,   100,   101,   102,   103,    79,    80,   104,
     105,   106,    52,    25,    26,    27,    28,    29,    30,     1,
       2,     3,     4,     5,     6,     7,     8,     2,     3,     4,
       5,     6,     7,     8,    31,    32,   130,    94,   131,   109,
      85,    86,   134,   137,   138,   141,   142,   143,   149,   148,
     158,   154,   159,    31,    32,   156,   160,   171,   172,    17,
     162,   167,   169,    91,    95,   175,   144,   145,   174,   177,
       0,    77,     0,    78
};

static const yytype_int16 yycheck[] =
{
      20,     1,    98,    23,    30,   101,     0,    17,    18,    36,
      37,    30,    32,    40,    41,     3,    50,    51,    46,    45,
       3,    21,    50,     3,     4,     5,     6,     7,     8,     9,
      49,     3,     4,     5,     6,     7,     8,     9,    48,    11,
      30,    13,    14,    15,    16,   141,   142,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,   154,    93,
      33,    34,    35,   159,    44,    45,    43,    38,    39,    49,
      49,    71,    44,    45,    42,    47,    48,    49,     3,     3,
       4,     5,     6,     7,     8,     9,   106,    30,    46,    31,
       3,     4,     5,     6,     7,     8,     9,    50,    98,    49,
     120,   121,    45,    47,   124,    45,    49,   107,    46,    22,
      23,    24,    25,    26,    27,    28,    29,    31,    32,   139,
      44,    45,    49,   143,    66,    67,    68,   147,    45,   149,
      45,    44,    45,    17,    18,   135,    49,    60,    61,    62,
      63,    45,   162,     3,     4,     5,     6,     7,     8,     9,
      45,    11,    49,    13,    14,    15,    16,    58,    59,    19,
      20,    21,     3,     4,     5,     6,     7,     8,     9,    22,
      23,    24,    25,    26,    27,    28,    29,    23,    24,    25,
      26,    27,    28,    29,    44,    45,     3,    47,    49,    49,
      64,    65,    13,    49,     3,    46,    46,    45,    30,    46,
      49,    46,    12,    44,    45,    47,    46,     4,    51,    10,
      49,    49,    49,    71,    90,    51,   135,   135,   165,   175,
      -1,    56,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    23,    24,    25,    26,    27,    28,    29,    53,
      54,    55,    56,    57,    58,    57,     0,    55,     3,     3,
      30,    45,    49,    30,     3,     4,     5,     6,     7,     8,
       9,    44,    45,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    57,    60,    61,    62,    79,
      30,    45,     3,    87,    79,    49,    43,    42,    38,    39,
      36,    37,    40,    41,    31,    32,    33,    34,    35,     3,
      46,    50,    49,    80,    80,    91,    46,    82,    83,    84,
      84,    85,    85,    85,    85,    86,    86,    87,    87,    87,
      59,    62,    46,    50,    47,    63,    80,    64,    65,    11,
      13,    14,    15,    16,    19,    20,    21,    22,    48,    49,
      57,    63,    66,    67,    68,    69,    70,    74,    78,    79,
      45,    45,    68,    45,    45,    49,    49,    49,    79,    57,
       3,    49,    79,    79,    13,    75,    79,    49,     3,    30,
      49,    46,    46,    45,    67,    69,    76,    77,    46,    30,
      79,    68,    68,    79,    46,    79,    47,    79,    49,    12,
      46,    68,    49,    17,    18,    71,    72,    49,    68,    49,
      79,     4,    51,    48,    72,    51,    73,    73,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    59,    58,    60,
      60,    61,    61,    62,    64,    63,    65,    65,    66,    66,
      67,    67,    67,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    74,    76,    77,    77,    78,    78,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      84,    84,    84,    84,    84,    85,    85,    85,    86,    86,
      86,    86,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    91,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     6,
       1,     1,     1,     1,     1,     1,     1,     0,     7,     1,
       0,     3,     1,     2,     0,     4,     2,     0,     1,     1,
       3,     5,     6,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     7,     2,     1,     4,     3,     2,     0,     5,
       7,     0,     6,     4,     1,     1,     3,     2,     2,     2,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     3,     0
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
#line 69 "parser.y"
                                {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].ival), KIND_VAR, false);
        printf("Global Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1305 "parser.tab.c"
    break;

  case 8: /* global_declaration: type_specifier ID ASSIGN expression SEMICOLON  */
#line 73 "parser.y"
                                                    {
        Symbol* sym = insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].ival), KIND_VAR, false);
        set_initialized((yyvsp[-3].sval));
        set_value((yyvsp[-3].sval), (yyvsp[-4].ival), &(yyvsp[-1].ival));
        printf("Global Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1316 "parser.tab.c"
    break;

  case 9: /* global_declaration: CONST type_specifier ID ASSIGN expression SEMICOLON  */
#line 79 "parser.y"
                                                          {
        Symbol* sym = insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].ival), KIND_VAR, true);
        set_initialized((yyvsp[-3].sval));
        set_value((yyvsp[-3].sval), (yyvsp[-4].ival), &(yyvsp[-1].ival));
        printf("Global Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1327 "parser.tab.c"
    break;

  case 10: /* type_specifier: INT_TYPE  */
#line 88 "parser.y"
             { (yyval.ival) = TYPE_INT; }
#line 1333 "parser.tab.c"
    break;

  case 11: /* type_specifier: FLOAT_TYPE  */
#line 89 "parser.y"
                 { (yyval.ival) = TYPE_FLOAT; }
#line 1339 "parser.tab.c"
    break;

  case 12: /* type_specifier: DOUBLE_TYPE  */
#line 90 "parser.y"
                  { (yyval.ival) = TYPE_DOUBLE; }
#line 1345 "parser.tab.c"
    break;

  case 13: /* type_specifier: STRING_TYPE  */
#line 91 "parser.y"
                  { (yyval.ival) = TYPE_STRING; }
#line 1351 "parser.tab.c"
    break;

  case 14: /* type_specifier: CHAR_TYPE  */
#line 92 "parser.y"
                { (yyval.ival) = TYPE_CHAR; }
#line 1357 "parser.tab.c"
    break;

  case 15: /* type_specifier: BOOL_TYPE  */
#line 93 "parser.y"
                { (yyval.ival) = TYPE_BOOL; }
#line 1363 "parser.tab.c"
    break;

  case 16: /* type_specifier: VOID_TYPE  */
#line 94 "parser.y"
                { (yyval.ival) = TYPE_VOID; }
#line 1369 "parser.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 99 "parser.y"
    {
        // Insert function into global symbol table
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].ival), KIND_FUNCTION, false);
        printf("Function: %s\n", (yyvsp[-3].sval));

        // Set flag and create scope for parameters/body
        is_function_body = 1;            // Mark as function body
        current_scope = create_scope(current_scope);    // New scope for parameters + body
    }
#line 1383 "parser.tab.c"
    break;

  case 18: /* function_definition: type_specifier ID LPAREN parameters RPAREN $@1 compound_statement  */
#line 109 "parser.y"
    {
        is_function_body = 0;            // Reset flag after function body
    }
#line 1391 "parser.tab.c"
    break;

  case 23: /* parameter: type_specifier ID  */
#line 125 "parser.y"
                      {
        insert_symbol(current_scope, (yyvsp[0].sval), (yyvsp[-1].ival), KIND_PARAMETER, false);
        printf("Parameter: %s\n", (yyvsp[0].sval));
    }
#line 1400 "parser.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 133 "parser.y"
    {
        if (!is_function_body) {
            // Only create a new scope for non-function blocks (loops/if)
            current_scope = create_scope(current_scope);
        }
    }
#line 1411 "parser.tab.c"
    break;

  case 25: /* compound_statement: LBRACE $@2 block_item_list RBRACE  */
#line 141 "parser.y"
    {
        if (!is_function_body) {
            // Only leave scope for non-function blocks
            leave_scope(&current_scope);
        }
    }
#line 1422 "parser.tab.c"
    break;

  case 30: /* declaration: type_specifier ID SEMICOLON  */
#line 160 "parser.y"
                                {
        insert_symbol(current_scope, (yyvsp[-1].sval), (yyvsp[-2].ival), KIND_VAR, false);
        printf("Local Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1431 "parser.tab.c"
    break;

  case 31: /* declaration: type_specifier ID ASSIGN expression SEMICOLON  */
#line 164 "parser.y"
                                                    {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].ival), KIND_VAR, false);
        set_value((yyvsp[-3].sval), (yyvsp[-4].ival), &(yyvsp[-1].ival));
        set_initialized((yyvsp[-3].sval));
        printf("Local Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1442 "parser.tab.c"
    break;

  case 32: /* declaration: CONST type_specifier ID ASSIGN expression SEMICOLON  */
#line 170 "parser.y"
                                                          {
        insert_symbol(current_scope, (yyvsp[-3].sval), (yyvsp[-4].ival), KIND_VAR, true);
        set_initialized((yyvsp[-3].sval));
        set_value((yyvsp[-3].sval), (yyvsp[-4].ival), &(yyvsp[-1].ival));
        printf("Local Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1453 "parser.tab.c"
    break;

  case 40: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 192 "parser.y"
                                                                {
        printf("If statement\n"); 
    }
#line 1461 "parser.tab.c"
    break;

  case 41: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 195 "parser.y"
                                                           {
        printf("If-else statement\n");
    }
#line 1469 "parser.tab.c"
    break;

  case 42: /* selection_statement: SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE  */
#line 198 "parser.y"
                                                              {
        printf("Switch statement\n");
    }
#line 1477 "parser.tab.c"
    break;

  case 45: /* case: CASE INT COLON statement_list  */
#line 209 "parser.y"
                                  {
        printf("Case: %d\n", (yyvsp[-2].ival));
    }
#line 1485 "parser.tab.c"
    break;

  case 46: /* case: DEFAULT COLON statement_list  */
#line 212 "parser.y"
                                   {
        printf("Default case\n");
    }
#line 1493 "parser.tab.c"
    break;

  case 49: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 223 "parser.y"
                                             {
        printf("While loop\n");
    }
#line 1501 "parser.tab.c"
    break;

  case 50: /* iteration_statement: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 226 "parser.y"
                                                            {
        printf("Do-while loop\n");
    }
#line 1509 "parser.tab.c"
    break;

  case 51: /* $@3: %empty  */
#line 229 "parser.y"
                 { is_function_body = 1; current_scope = create_scope(current_scope);}
#line 1515 "parser.tab.c"
    break;

  case 52: /* iteration_statement: FOR LPAREN $@3 for_clause RPAREN statement  */
#line 230 "parser.y"
                                    { is_function_body = 0;  printf("For loop\n"); }
#line 1521 "parser.tab.c"
    break;

  case 56: /* jump_statement: RETURN expression SEMICOLON  */
#line 243 "parser.y"
                                {
        printf("Return statement\n");
    }
#line 1529 "parser.tab.c"
    break;

  case 57: /* jump_statement: RETURN SEMICOLON  */
#line 246 "parser.y"
                       {
        printf("Return void\n");
    }
#line 1537 "parser.tab.c"
    break;

  case 58: /* jump_statement: BREAK SEMICOLON  */
#line 249 "parser.y"
                      {
        printf("Break statement\n");
    }
#line 1545 "parser.tab.c"
    break;

  case 59: /* jump_statement: CONTINUE SEMICOLON  */
#line 252 "parser.y"
                         {
        printf("Continue statement\n");
    }
#line 1553 "parser.tab.c"
    break;

  case 62: /* assignment_expression: ID ASSIGN assignment_expression  */
#line 263 "parser.y"
                                      {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-2].sval));
        if (sym == NULL) {
            fprintf(stderr, "Semantic Error: Undeclared variable %s\n", (yyvsp[-2].sval));
        } else {
            set_initialized((yyvsp[-2].sval));
            set_value((yyvsp[-2].sval), sym->type, &(yyvsp[0].ival));
        }
        printf("Assignment to %s\n", (yyvsp[-2].sval));
    }
#line 1568 "parser.tab.c"
    break;

  case 64: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 277 "parser.y"
                                                      { printf("Logical OR\n"); }
#line 1574 "parser.tab.c"
    break;

  case 66: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 282 "parser.y"
                                                     { printf("Logical AND\n"); }
#line 1580 "parser.tab.c"
    break;

  case 68: /* equality_expression: equality_expression EQ relational_expression  */
#line 287 "parser.y"
                                                   { printf("Equality\n");}
#line 1586 "parser.tab.c"
    break;

  case 69: /* equality_expression: equality_expression NEQ relational_expression  */
#line 288 "parser.y"
                                                    {printf("Not Equal\n");}
#line 1592 "parser.tab.c"
    break;

  case 71: /* relational_expression: relational_expression LT additive_expression  */
#line 293 "parser.y"
                                                   { printf("Less than\n"); }
#line 1598 "parser.tab.c"
    break;

  case 72: /* relational_expression: relational_expression GT additive_expression  */
#line 294 "parser.y"
                                                   { printf("Greater than\n"); }
#line 1604 "parser.tab.c"
    break;

  case 73: /* relational_expression: relational_expression LE additive_expression  */
#line 295 "parser.y"
                                                   { printf("Less than or equal\n"); }
#line 1610 "parser.tab.c"
    break;

  case 74: /* relational_expression: relational_expression GE additive_expression  */
#line 296 "parser.y"
                                                   { printf("Greater than or equal\n"); }
#line 1616 "parser.tab.c"
    break;

  case 76: /* additive_expression: additive_expression ADD multiplicative_expr  */
#line 301 "parser.y"
                                                  { printf("Addition\n"); }
#line 1622 "parser.tab.c"
    break;

  case 77: /* additive_expression: additive_expression SUB multiplicative_expr  */
#line 302 "parser.y"
                                                  { printf("Subtraction\n"); }
#line 1628 "parser.tab.c"
    break;

  case 79: /* multiplicative_expr: multiplicative_expr MUL unary_expr  */
#line 307 "parser.y"
                                         { printf("Multiplication\n"); }
#line 1634 "parser.tab.c"
    break;

  case 80: /* multiplicative_expr: multiplicative_expr DIV unary_expr  */
#line 308 "parser.y"
                                         { printf("Division\n"); }
#line 1640 "parser.tab.c"
    break;

  case 81: /* multiplicative_expr: multiplicative_expr MOD unary_expr  */
#line 309 "parser.y"
                                         { printf("Modulo\n"); }
#line 1646 "parser.tab.c"
    break;

  case 83: /* unary_expr: NOT unary_expr  */
#line 314 "parser.y"
                     { printf("Logical NOT\n"); }
#line 1652 "parser.tab.c"
    break;

  case 86: /* primary_expr: ID  */
#line 323 "parser.y"
       {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[0].sval));
        if (sym == NULL)
         { fprintf(stderr, "Semantic Error: Use of undeclared variable %s\n", (yyvsp[0].sval));}
        else if(!sym->initialized)
        {fprintf(stderr, "Semantic Error: Use of uninitialized variable %s\n", (yyvsp[0].sval));}
        else 
        {(yyval.ival) = sym && sym->value ? *((int*)sym->value) : 0;  // Assuming TYPE_INT for now
        printf("Primary ID: %s\n", (yyvsp[0].sval));}}
#line 1666 "parser.tab.c"
    break;

  case 87: /* primary_expr: INT  */
#line 332 "parser.y"
          { (yyval.ival) = (yyvsp[0].ival); printf("Primary int: %d\n", (yyvsp[0].ival)); }
#line 1672 "parser.tab.c"
    break;

  case 88: /* primary_expr: FLOAT  */
#line 333 "parser.y"
            { (yyval.ival) = (int)(yyvsp[0].fval); printf("Primary float: %f\n", (yyvsp[0].fval)); }
#line 1678 "parser.tab.c"
    break;

  case 89: /* primary_expr: DOUBLE  */
#line 334 "parser.y"
             { (yyval.ival) = (int)(yyvsp[0].fval); printf("Primary double: %f\n", (yyvsp[0].fval)); }
#line 1684 "parser.tab.c"
    break;

  case 90: /* primary_expr: STRING  */
#line 335 "parser.y"
             { (yyval.ival) = 0; printf("Primary string: %s\n", (yyvsp[0].sval)); }
#line 1690 "parser.tab.c"
    break;

  case 91: /* primary_expr: CHAR  */
#line 336 "parser.y"
           { (yyval.ival) = (yyvsp[0].sval)[1]; printf("Primary char: %c\n", (yyvsp[0].sval)[1]); }
#line 1696 "parser.tab.c"
    break;

  case 92: /* primary_expr: BOOL  */
#line 337 "parser.y"
           { (yyval.ival) = (yyvsp[0].bval); printf("Primary bool: %s\n", (yyvsp[0].bval) ? "true" : "false"); }
#line 1702 "parser.tab.c"
    break;

  case 93: /* primary_expr: LPAREN expression RPAREN  */
#line 338 "parser.y"
                               { (yyval.ival) = (yyvsp[-1].ival); }
#line 1708 "parser.tab.c"
    break;

  case 94: /* function_call: ID LPAREN argument_list RPAREN  */
#line 343 "parser.y"
                                   {
        Symbol* sym = lookup_symbol(current_scope, (yyvsp[-3].sval));
        if (!sym || sym->kind != KIND_FUNCTION) {
            fprintf(stderr, "Semantic Error: Undefined function %s\n", (yyvsp[-3].sval));
        }
        printf("Function call to: %s\n", (yyvsp[-3].sval));
    }
#line 1720 "parser.tab.c"
    break;


#line 1724 "parser.tab.c"

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

#line 358 "parser.y"


int main() {
    global_scope = create_scope(NULL);
    current_scope = global_scope;
    return yyparse();
}
