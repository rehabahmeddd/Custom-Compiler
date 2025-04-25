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

int sym[26]; 
int yylex();
void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}

#line 84 "parser.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

    int ival;
    float fval;
    char* sval;
    bool  bval;

#line 189 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_function = 54,                  /* function  */
  YYSYMBOL_parameters = 55,                /* parameters  */
  YYSYMBOL_parameter_list = 56,            /* parameter_list  */
  YYSYMBOL_parameter = 57,                 /* parameter  */
  YYSYMBOL_parameter_type = 58,            /* parameter_type  */
  YYSYMBOL_function_type = 59,             /* function_type  */
  YYSYMBOL_declaration = 60,               /* declaration  */
  YYSYMBOL_block = 61,                     /* block  */
  YYSYMBOL_block_items = 62,               /* block_items  */
  YYSYMBOL_block_item = 63,                /* block_item  */
  YYSYMBOL_statements = 64,                /* statements  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_assignment = 66,                /* assignment  */
  YYSYMBOL_if_statement = 67,              /* if_statement  */
  YYSYMBOL_loop_statement = 68,            /* loop_statement  */
  YYSYMBOL_while_loop = 69,                /* while_loop  */
  YYSYMBOL_do_while_loop = 70,             /* do_while_loop  */
  YYSYMBOL_for_loop = 71,                  /* for_loop  */
  YYSYMBOL_for_init = 72,                  /* for_init  */
  YYSYMBOL_for_update = 73,                /* for_update  */
  YYSYMBOL_switch_statement = 74,          /* switch_statement  */
  YYSYMBOL_case_list = 75,                 /* case_list  */
  YYSYMBOL_case = 76,                      /* case  */
  YYSYMBOL_expression = 77,                /* expression  */
  YYSYMBOL_or_expr = 78,                   /* or_expr  */
  YYSYMBOL_and_expr = 79,                  /* and_expr  */
  YYSYMBOL_equality_expr = 80,             /* equality_expr  */
  YYSYMBOL_relational_expr = 81,           /* relational_expr  */
  YYSYMBOL_additive_expr = 82,             /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 83,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 84,                /* unary_expr  */
  YYSYMBOL_primary_expr = 85,              /* primary_expr  */
  YYSYMBOL_function_call = 86,             /* function_call  */
  YYSYMBOL_argument_list = 87              /* argument_list  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

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
       0,    49,    49,    50,    51,    55,    61,    62,    66,    67,
      71,    77,    78,    79,    80,    81,    82,    86,    87,    88,
      89,    90,    91,    92,    97,   100,   103,   109,   113,   114,
     118,   119,   123,   124,   128,   129,   130,   131,   132,   133,
     134,   135,   138,   139,   144,   150,   153,   161,   162,   165,
     171,   178,   184,   190,   191,   195,   199,   205,   206,   210,
     213,   219,   223,   224,   228,   229,   233,   234,   235,   239,
     240,   241,   242,   243,   247,   248,   249,   253,   254,   255,
     256,   260,   261,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   277,   283,   284,   285
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
  "COMMA", "COLON", "$accept", "program", "function", "parameters",
  "parameter_list", "parameter", "parameter_type", "function_type",
  "declaration", "block", "block_items", "block_item", "statements",
  "statement", "assignment", "if_statement", "loop_statement",
  "while_loop", "do_while_loop", "for_loop", "for_init", "for_update",
  "switch_statement", "case_list", "case", "expression", "or_expr",
  "and_expr", "equality_expr", "relational_expr", "additive_expr",
  "multiplicative_expr", "unary_expr", "primary_expr", "function_call",
  "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -70,    17,   -70,   -24,   -32,   -21,   112,    -6,    18,   -20,
      12,   131,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,    62,   -70,   -70,    23,   -70,   -70,   -70,   -70,
     -70,   -70,    33,   131,   131,   131,   131,    76,   126,   131,
     -70,   -70,    45,   -70,   -70,   -70,   -70,   -70,   -70,   131,
     131,    51,    59,    63,   -12,   -18,    24,    16,   -70,   -70,
     -70,    72,    65,   -70,   -70,   -70,   -70,   -34,    58,    66,
      69,    81,    44,   -70,   -70,   -70,   -70,   -70,   -70,   113,
     -70,    68,   131,    78,   -70,    84,   -70,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     -70,   -70,   -70,   -70,    44,   -70,   131,   112,   112,   131,
     115,   -15,   -70,    92,    95,   -70,    63,   -12,   -18,   -18,
      24,    24,    24,    24,    16,    16,   -70,   -70,   -70,    97,
     104,   -70,   142,   -70,   135,   -70,   110,   127,   131,   -70,
     155,    41,   116,    44,   -70,   112,   121,   131,   122,   -70,
     128,   168,   129,    30,   -70,   -70,   -70,   -70,   -70,   124,
     -70,   112,   130,   -70,   -70,   -70,   -70,   -70,   -70,   112,
     112,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    22,    19,    20,    23,    21,    29,
      43,     3,     0,    41,     2,     0,    35,    39,    36,    37,
      38,    40,     0,     0,    93,     0,     0,     0,     0,     0,
      48,    49,    89,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    61,    63,    65,    68,    73,    76,    80,    82,
      91,     0,     0,    34,    44,    45,    94,     0,     0,     0,
       0,     0,     0,    11,    12,    16,    13,    14,    15,     0,
      54,     0,     0,     0,    81,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    30,    28,    31,     7,    92,     0,     0,     0,     0,
       0,     0,    53,     0,     0,    90,    62,    64,    66,    67,
      69,    71,    70,    72,    74,    75,    77,    78,    79,     0,
       6,     9,     0,    95,    46,    50,     0,     0,     0,    24,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    55,
       0,     0,     0,     0,    58,     5,     8,    47,    51,     0,
      25,     0,     0,    33,    56,    57,    26,    52,    33,    60,
      59,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -70,    34,   -69,   -70,   117,    37,
     -70,   -70,    14,     1,   -37,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,    31,   -25,   -70,    96,    98,   -13,
      73,   -16,   -45,   -70,    -1,   -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    21,   129,   130,   131,    79,    22,    80,    23,
      61,   102,   169,   171,    25,    26,    27,    28,    29,    30,
      82,   150,    31,   153,   154,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    81,    24,   110,    84,    32,    33,    37,    65,    66,
      68,    69,   105,    35,    83,   138,   106,     2,    91,    92,
       3,    34,    93,    94,    36,    85,    89,    90,     4,    40,
       5,     6,     7,     8,   139,   132,     9,    10,    11,    38,
      12,    13,    14,    15,    16,    17,    18,   151,   152,    97,
      98,    99,   126,   127,   128,    95,    96,   113,   151,   152,
      32,    41,   103,    39,    19,    62,    20,    73,    74,    75,
      76,    77,    63,    78,   132,     3,   118,   119,   164,   124,
     125,   133,    64,     4,   136,     5,     6,     7,     8,    70,
      34,     9,    10,    11,    72,    73,    74,    75,    76,    77,
      86,    78,    87,   149,   107,    88,    32,    32,   134,   135,
     104,    33,   108,   148,   109,     3,   111,   112,   137,    19,
     100,    20,   159,     4,   114,     5,     6,     7,     8,    71,
     115,     9,    10,    11,    42,    43,    44,    45,    46,    47,
      48,   140,   141,   142,    32,   144,   157,   145,    72,    73,
      74,    75,    76,    77,   143,    78,   146,   147,    71,    19,
      32,    20,   167,    19,   120,   121,   122,   123,    32,    32,
     158,   160,   162,   166,   161,    49,    50,   156,   101,   155,
     163,   168,   170,   116,   165,     0,   117
};

static const yytype_int16 yycheck[] =
{
       1,    38,     1,    72,    49,     6,    30,     6,    33,    34,
      35,    36,    46,    45,    39,    30,    50,     0,    36,    37,
       3,    45,    40,    41,    45,    50,    38,    39,    11,    49,
      13,    14,    15,    16,    49,   104,    19,    20,    21,    45,
      23,    24,    25,    26,    27,    28,    29,    17,    18,    33,
      34,    35,    97,    98,    99,    31,    32,    82,    17,    18,
      61,    49,    61,    45,    47,     3,    49,    23,    24,    25,
      26,    27,    49,    29,   143,     3,    89,    90,    48,    95,
      96,   106,    49,    11,   109,    13,    14,    15,    16,    13,
      45,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      49,    29,    43,   140,    46,    42,   107,   108,   107,   108,
      45,    30,    46,   138,    45,     3,     3,    49,     3,    47,
      48,    49,   147,    11,    46,    13,    14,    15,    16,     3,
      46,    19,    20,    21,     3,     4,     5,     6,     7,     8,
       9,    49,    47,    46,   145,     3,   145,    12,    22,    23,
      24,    25,    26,    27,    50,    29,    46,    30,     3,    47,
     161,    49,   161,    47,    91,    92,    93,    94,   169,   170,
      49,    49,     4,    49,    46,    44,    45,   143,    61,   142,
      51,    51,   168,    87,   153,    -1,    88
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,     0,     3,    11,    13,    14,    15,    16,    19,
      20,    21,    23,    24,    25,    26,    27,    28,    29,    47,
      49,    54,    59,    61,    65,    66,    67,    68,    69,    70,
      71,    74,    86,    30,    45,    45,    45,    65,    45,    45,
      49,    49,     3,     4,     5,     6,     7,     8,     9,    44,
      45,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    62,     3,    49,    49,    77,    77,    87,    77,    77,
      13,     3,    22,    23,    24,    25,    26,    27,    29,    58,
      60,    66,    72,    77,    84,    77,    49,    43,    42,    38,
      39,    36,    37,    40,    41,    31,    32,    33,    34,    35,
      48,    60,    63,    65,    45,    46,    50,    46,    46,    45,
      58,     3,    49,    77,    46,    46,    79,    80,    81,    81,
      82,    82,    82,    82,    83,    83,    84,    84,    84,    55,
      56,    57,    58,    77,    65,    65,    77,     3,    30,    49,
      49,    47,    46,    50,     3,    12,    46,    30,    77,    66,
      73,    17,    18,    75,    76,    61,    57,    65,    49,    77,
      49,    46,     4,    51,    48,    76,    49,    65,    51,    64,
      64,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    54,    55,    55,    56,    56,
      57,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    60,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    67,    68,    68,
      69,    70,    71,    72,    72,    73,    74,    75,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    80,    81,
      81,    81,    81,    81,    82,    82,    82,    83,    83,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     1,     0,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     6,     3,     2,     0,
       1,     1,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     3,     5,     7,     2,     2,
       5,     7,     8,     2,     1,     1,     7,     2,     1,     4,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     0,     1,     3
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
  case 5: /* function: function_type ID LPAREN parameters RPAREN block  */
#line 55 "parser.y"
                                                    {
        printf("Function: %s\n", (yyvsp[-4].sval));
    }
#line 1382 "parser.tab.c"
    break;

  case 10: /* parameter: parameter_type ID  */
#line 71 "parser.y"
                      {
        printf("Parameter: type and name = [type], %s\n", (yyvsp[0].sval));
    }
#line 1390 "parser.tab.c"
    break;

  case 24: /* declaration: parameter_type ID SEMICOLON  */
#line 97 "parser.y"
                                {
        printf("Declaration: %s\n", (yyvsp[-1].sval));
    }
#line 1398 "parser.tab.c"
    break;

  case 25: /* declaration: parameter_type ID ASSIGN expression SEMICOLON  */
#line 100 "parser.y"
                                                    {
        printf("Declaration with assignment: %s\n", (yyvsp[-3].sval));
    }
#line 1406 "parser.tab.c"
    break;

  case 26: /* declaration: CONST parameter_type ID ASSIGN expression SEMICOLON  */
#line 103 "parser.y"
                                                          {
        printf("Constant declaration: %s\n", (yyvsp[-3].sval));
    }
#line 1414 "parser.tab.c"
    break;

  case 41: /* statement: RETURN expression SEMICOLON  */
#line 135 "parser.y"
                                  {
        printf("Return statement\n");
    }
#line 1422 "parser.tab.c"
    break;

  case 43: /* statement: function_call SEMICOLON  */
#line 139 "parser.y"
                              {fprintf(stderr, "Function call handling not implemented statement\n"); }
#line 1428 "parser.tab.c"
    break;

  case 44: /* assignment: ID ASSIGN expression  */
#line 144 "parser.y"
                          {
        printf("Assignment to %s\n", (yyvsp[-2].sval));
    }
#line 1436 "parser.tab.c"
    break;

  case 45: /* if_statement: IF LPAREN expression RPAREN statement  */
#line 150 "parser.y"
                                                                {
        printf("If statement\n");
    }
#line 1444 "parser.tab.c"
    break;

  case 46: /* if_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 153 "parser.y"
                                                           {
        printf("If-else statement\n");
    }
#line 1452 "parser.tab.c"
    break;

  case 48: /* loop_statement: BREAK SEMICOLON  */
#line 162 "parser.y"
                      {
        printf("Break statement\n");
    }
#line 1460 "parser.tab.c"
    break;

  case 49: /* loop_statement: CONTINUE SEMICOLON  */
#line 165 "parser.y"
                         {
        printf("Continue statement\n");
    }
#line 1468 "parser.tab.c"
    break;

  case 50: /* while_loop: WHILE LPAREN expression RPAREN loop_statement  */
#line 171 "parser.y"
                                                  {
        printf("While loop\n");
    }
#line 1476 "parser.tab.c"
    break;

  case 51: /* do_while_loop: DO loop_statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 178 "parser.y"
                                                               {
        printf("Do-while loop\n");
    }
#line 1484 "parser.tab.c"
    break;

  case 52: /* for_loop: FOR LPAREN for_init expression SEMICOLON for_update RPAREN statement  */
#line 184 "parser.y"
                                                                         {
        printf("For loop\n");
    }
#line 1492 "parser.tab.c"
    break;

  case 56: /* switch_statement: SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE  */
#line 199 "parser.y"
                                                            {
        printf("Switch statement\n");
    }
#line 1500 "parser.tab.c"
    break;

  case 59: /* case: CASE INT COLON statements  */
#line 210 "parser.y"
                              {
        printf("Case: %d\n", (yyvsp[-2].ival));
    }
#line 1508 "parser.tab.c"
    break;

  case 60: /* case: DEFAULT COLON statements  */
#line 213 "parser.y"
                               {
        printf("Default case\n");
    }
#line 1516 "parser.tab.c"
    break;

  case 62: /* or_expr: or_expr OR and_expr  */
#line 223 "parser.y"
                             { (yyval.ival) = (yyvsp[-2].ival) || (yyvsp[0].ival); printf("Logical OR\n"); }
#line 1522 "parser.tab.c"
    break;

  case 64: /* and_expr: and_expr AND equality_expr  */
#line 228 "parser.y"
                                    { (yyval.ival) = (yyvsp[-2].ival) && (yyvsp[0].ival); printf("Logical AND\n"); }
#line 1528 "parser.tab.c"
    break;

  case 66: /* equality_expr: equality_expr EQ relational_expr  */
#line 233 "parser.y"
                                             { (yyval.ival) = (yyvsp[-2].ival) == (yyvsp[0].ival); printf("Equality\n"); }
#line 1534 "parser.tab.c"
    break;

  case 67: /* equality_expr: equality_expr NEQ relational_expr  */
#line 234 "parser.y"
                                                { (yyval.ival) = (yyvsp[-2].ival) != (yyvsp[0].ival); printf("Not Equal\n"); }
#line 1540 "parser.tab.c"
    break;

  case 69: /* relational_expr: relational_expr LT additive_expr  */
#line 239 "parser.y"
                                                 { (yyval.ival) = (yyvsp[-2].ival) < (yyvsp[0].ival); printf("Less than\n"); }
#line 1546 "parser.tab.c"
    break;

  case 70: /* relational_expr: relational_expr LE additive_expr  */
#line 240 "parser.y"
                                                   { (yyval.ival) = (yyvsp[-2].ival) <= (yyvsp[0].ival); printf("Less than or equal\n"); }
#line 1552 "parser.tab.c"
    break;

  case 71: /* relational_expr: relational_expr GT additive_expr  */
#line 241 "parser.y"
                                                   { (yyval.ival) = (yyvsp[-2].ival) > (yyvsp[0].ival); printf("Greater than\n"); }
#line 1558 "parser.tab.c"
    break;

  case 72: /* relational_expr: relational_expr GE additive_expr  */
#line 242 "parser.y"
                                                   { (yyval.ival) = (yyvsp[-2].ival) >= (yyvsp[0].ival); printf("Greater than or equal\n"); }
#line 1564 "parser.tab.c"
    break;

  case 74: /* additive_expr: additive_expr ADD multiplicative_expr  */
#line 247 "parser.y"
                                                       { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); printf("Addition\n"); }
#line 1570 "parser.tab.c"
    break;

  case 75: /* additive_expr: additive_expr SUB multiplicative_expr  */
#line 248 "parser.y"
                                                         { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); printf("Subtraction\n"); }
#line 1576 "parser.tab.c"
    break;

  case 77: /* multiplicative_expr: multiplicative_expr MUL unary_expr  */
#line 253 "parser.y"
                                                    { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); printf("Multiplication\n"); }
#line 1582 "parser.tab.c"
    break;

  case 78: /* multiplicative_expr: multiplicative_expr DIV unary_expr  */
#line 254 "parser.y"
                                                      { (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); printf("Division\n"); }
#line 1588 "parser.tab.c"
    break;

  case 79: /* multiplicative_expr: multiplicative_expr MOD unary_expr  */
#line 255 "parser.y"
                                                      { (yyval.ival) = (yyvsp[-2].ival) % (yyvsp[0].ival); printf("Modulo\n"); }
#line 1594 "parser.tab.c"
    break;

  case 81: /* unary_expr: NOT unary_expr  */
#line 260 "parser.y"
                         { (yyval.ival) = !(yyvsp[0].ival); printf("Logical NOT\n"); }
#line 1600 "parser.tab.c"
    break;

  case 82: /* unary_expr: primary_expr  */
#line 261 "parser.y"
                         { (yyval.ival) = (yyvsp[0].ival); }
#line 1606 "parser.tab.c"
    break;

  case 83: /* primary_expr: INT  */
#line 265 "parser.y"
             { (yyval.ival) = (yyvsp[0].ival); printf("Primary int: %d\n", (yyvsp[0].ival)); }
#line 1612 "parser.tab.c"
    break;

  case 84: /* primary_expr: FLOAT  */
#line 266 "parser.y"
             { (yyval.ival) = (int)(yyvsp[0].fval); printf("Primary float: %f\n", (yyvsp[0].fval)); }
#line 1618 "parser.tab.c"
    break;

  case 85: /* primary_expr: DOUBLE  */
#line 267 "parser.y"
             { (yyval.ival) = (int)(yyvsp[0].fval); printf("Primary double: %f\n", (yyvsp[0].fval)); }
#line 1624 "parser.tab.c"
    break;

  case 86: /* primary_expr: STRING  */
#line 268 "parser.y"
             { (yyval.ival) = 0; fprintf(stderr, "Warning: string in expression not supported\n"); }
#line 1630 "parser.tab.c"
    break;

  case 87: /* primary_expr: CHAR  */
#line 269 "parser.y"
             { (yyval.ival) = (yyvsp[0].sval)[0]; printf("Primary char: %c\n", (yyvsp[0].sval)[0]); }
#line 1636 "parser.tab.c"
    break;

  case 88: /* primary_expr: BOOL  */
#line 270 "parser.y"
             { (yyval.ival) = (yyvsp[0].bval) ? 1 : 0; printf("Primary bool: %s\n", (yyvsp[0].bval) ? "true" : "false"); }
#line 1642 "parser.tab.c"
    break;

  case 89: /* primary_expr: ID  */
#line 271 "parser.y"
             { (yyval.ival) = sym[(yyvsp[0].sval)[0] - 'a']; printf("Primary ID: %s = %d\n", (yyvsp[0].sval), (yyval.ival)); }
#line 1648 "parser.tab.c"
    break;

  case 90: /* primary_expr: LPAREN expression RPAREN  */
#line 272 "parser.y"
                               { (yyval.ival) = (yyvsp[-1].ival); }
#line 1654 "parser.tab.c"
    break;

  case 91: /* primary_expr: function_call  */
#line 273 "parser.y"
                    { (yyval.ival) = 0; fprintf(stderr, "Function call handling not implemented\n"); }
#line 1660 "parser.tab.c"
    break;

  case 92: /* function_call: ID LPAREN argument_list RPAREN  */
#line 277 "parser.y"
                                             {
                  printf("Function call to: %s\n", (yyvsp[-3].sval));
              }
#line 1668 "parser.tab.c"
    break;


#line 1672 "parser.tab.c"

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

#line 288 "parser.y"


int main() {
    return yyparse();
}
