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
#line 1 "onto.y"

/* analisador sintático para reconhecer onto em português */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string>
#include <list>
using std::cout;

int yylex(void);
int yyparse(void);
void yyerror(const char *);
extern int yylineno;    
extern char * yytext;   

bool individual = false;
bool equiva = false;
bool bolProper = false;

std::list<char*> prop{};


// Adcionar as property que encontrar na lista
void addProp(char* proper) {
    prop.push_back(strdup(proper));
}

// Para a classe axioma de fechamento, ele verifica se ele está utilizando um object propertie que já foi declarado 
void declaracoes(char* obj){
	for (const auto& property :prop){
		if (obj == property){
			bolProper = true;
		}
		yyerror("Erro: Está sendo declarado object property que não foi declarado'");
	}
}


// Verifica se a ordem de precedência está correta
void precedencia(char* prec){

	if(strcmp(prec, "Disjoint:") == 0){
		if (individual == true){
				yyerror("Erro: 'Disjoint' não é permitido após 'individuals'");
                            
			}
	}

	if(strcmp(prec, "SubClassOf:") == 0){
			if (equiva == true){
				yyerror("Erro: 'Subclass' não é permitido após 'EquivalentTo'");
                            
			}
	}
	if(strcmp(prec, "EquivalentTo:") == 0){
			equiva = true;
	}

	if(strcmp(prec, "Disjoint:") == 0){
		if (individual == true){
				yyerror("Erro: 'Disjoint' não é permitido após 'individuals'");
                            
			}
	}
	if(strcmp(prec, "Individuals:") == 0){
		individual = true;
	}

// Verifica se o valor é 

}



#line 148 "onto.tab.c"

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

#include "onto.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS = 3,                      /* CLASS  */
  YYSYMBOL_INDI = 4,                       /* INDI  */
  YYSYMBOL_DEFIN = 5,                      /* DEFIN  */
  YYSYMBOL_EQUIV = 6,                      /* EQUIV  */
  YYSYMBOL_SUB = 7,                        /* SUB  */
  YYSYMBOL_DISJ = 8,                       /* DISJ  */
  YYSYMBOL_SOME = 9,                       /* SOME  */
  YYSYMBOL_ALL = 10,                       /* ALL  */
  YYSYMBOL_VALUE = 11,                     /* VALUE  */
  YYSYMBOL_NUM = 12,                       /* NUM  */
  YYSYMBOL_MIN = 13,                       /* MIN  */
  YYSYMBOL_OPERA = 14,                     /* OPERA  */
  YYSYMBOL_MAX = 15,                       /* MAX  */
  YYSYMBOL_AUX = 16,                       /* AUX  */
  YYSYMBOL_COLCH = 17,                     /* COLCH  */
  YYSYMBOL_EXACTLY = 18,                   /* EXACTLY  */
  YYSYMBOL_THAT = 19,                      /* THAT  */
  YYSYMBOL_ONLY = 20,                      /* ONLY  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_PROPERTY = 24,                  /* PROPERTY  */
  YYSYMBOL_PARENTHESIS = 25,               /* PARENTHESIS  */
  YYSYMBOL_CHAVES = 26,                    /* CHAVES  */
  YYSYMBOL_VIRGULA = 27,                   /* VIRGULA  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_sint = 29,                      /* sint  */
  YYSYMBOL_owl = 30,                       /* owl  */
  YYSYMBOL_opt0 = 31,                      /* opt0  */
  YYSYMBOL_op1 = 32,                       /* op1  */
  YYSYMBOL_op2 = 33,                       /* op2  */
  YYSYMBOL_definida = 34,                  /* definida  */
  YYSYMBOL_primitiva = 35,                 /* primitiva  */
  YYSYMBOL_closureAxiom = 36,              /* closureAxiom  */
  YYSYMBOL_closureAxiom2 = 37,             /* closureAxiom2  */
  YYSYMBOL_classeAninhada = 38,            /* classeAninhada  */
  YYSYMBOL_enumerada = 39,                 /* enumerada  */
  YYSYMBOL_coberta = 40,                   /* coberta  */
  YYSYMBOL_reservado = 41,                 /* reservado  */
  YYSYMBOL_INDIVIDUALS = 42,               /* INDIVIDUALS  */
  YYSYMBOL_CARD = 43,                      /* CARD  */
  YYSYMBOL_CARD2 = 44                      /* CARD2  */
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   115,   115,   116,   119,   122,   123,   125,   126,   127,
     130,   131,   132,   136,   137,   138,   139,   140,   141,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     158,   159,   160,   161,   164,   165,   166,   167,   168,   169,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   186,   187,   188,   191,   192,   193,   194,   195,   196,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   212,   213,   214,   217,   218,   219,   221,   222
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
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "INDI",
  "DEFIN", "EQUIV", "SUB", "DISJ", "SOME", "ALL", "VALUE", "NUM", "MIN",
  "OPERA", "MAX", "AUX", "COLCH", "EXACTLY", "THAT", "ONLY", "NOT", "AND",
  "OR", "PROPERTY", "PARENTHESIS", "CHAVES", "VIRGULA", "$accept", "sint",
  "owl", "opt0", "op1", "op2", "definida", "primitiva", "closureAxiom",
  "closureAxiom2", "classeAninhada", "enumerada", "coberta", "reservado",
  "INDIVIDUALS", "CARD", "CARD2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    -3,     7,    11,    13,  -118,   463,  -118,  -118,   488,
       9,   530,    80,    12,  -118,  -118,     5,    15,    25,     3,
       8,    27,  -118,  -118,  -118,    17,  -118,  1499,  1105,   555,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    1130,  -118,    23,  -118,   580,  1155,   286,    28,  1499,   605,
     630,  -118,  -118,  -118,  1180,  -118,     9,  -118,  1205,  1230,
      70,  1514,  1155,    48,  1155,  -118,  -118,  -118,   655,   109,
     136,    56,  1514,   295,  -118,  -118,  -118,   335,  -118,  -118,
    -118,  -118,    53,  -118,  1155,    41,  -118,   680,  1255,    65,
    -118,  -118,  -118,  -118,  -118,  -118,  1155,  1155,  -118,  -118,
     605,   705,   295,  -118,    47,   109,  -118,  -118,   730,   705,
    1514,   605,  -118,  -118,   755,   780,  -118,   605,  -118,    50,
    1280,  1280,  1155,    51,    55,   805,  -118,  1405,   295,   301,
    1430,  -118,  1455,  1499,   335,  -118,  -118,  -118,    68,  -118,
     109,   830,  -118,  -118,   222,  1305,  1330,  1514,    66,  -118,
    1155,  -118,   109,   855,   228,  -118,  -118,  1255,     6,   360,
    1499,  -118,  -118,   295,    87,   372,    67,   295,  -118,  -118,
      73,   880,  1514,   905,  -118,  -118,  -118,   409,  -118,  1155,
    1355,  1380,    75,   930,  -118,    74,    76,   955,   980,   295,
     253,    22,  1005,  -118,    81,    89,  1514,   106,  -118,  -118,
    1255,    85,  -118,  1030,     6,     9,  1055,  1480,    22,   111,
      97,    22,  -118,  -118,  1080,  -118,    96,    44,   409,  -118,
      22,    41,  -118,    98,   409,   100,   409,   409
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,    29,     1,     2,    29,
      73,    59,    29,     0,    60,    61,     0,     0,     0,    76,
       0,     0,    67,    70,    68,    62,    69,     0,    73,    29,
       4,     5,     6,     7,     8,     9,    32,    12,    10,    11,
      73,    18,     0,    75,    29,    73,    29,    69,     0,    16,
      29,    25,    37,    42,    73,    28,    73,    71,    57,    59,
      59,     0,    73,     0,    73,    40,    55,    50,    29,    59,
      29,     0,     0,    29,    19,    54,    28,    29,    63,    64,
      65,    74,     0,    66,    73,    70,    62,    73,    73,     0,
      47,    50,    24,    36,    48,    28,    73,    73,    43,    49,
      29,    29,    29,    28,    57,    59,    56,    58,    73,    29,
       0,    29,    27,    28,    29,    73,    52,    29,    72,    62,
      57,    57,    73,     0,    50,    29,    41,    29,    29,    76,
      29,    28,    29,     0,    29,    20,    35,    28,     0,    44,
      59,    29,    46,    23,    29,    73,    73,     0,     0,    18,
      73,    45,    59,    29,    29,    28,    26,    73,     0,    29,
       0,    30,    28,    29,     0,    29,     0,    29,    28,    77,
       0,    29,     0,    29,    14,    21,    18,    49,    22,    16,
      73,    73,     0,    29,    13,    53,     0,    29,    73,    29,
      29,    39,    73,    31,     0,     0,     0,     0,    15,    18,
      73,     0,    17,    29,     0,    73,    29,    29,    39,     0,
       0,    39,    34,    38,    29,    16,     0,    76,     0,    51,
      39,     0,    38,     0,    73,     0,    73,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,   123,   129,  -118,  -118,  -118,     1,   167,  -117,    -5,
     343,    46,    10,   214,    -6,    62,  -118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    30,    31,    32,   174,    51,    35,    52,
      53,   116,    75,    40,    91,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    36,     2,    55,    57,    67,    76,    33,   161,   185,
       6,     7,   166,    10,     1,    77,    39,    78,     2,    19,
      20,    66,    82,    95,    93,   208,    10,    79,   -59,   -59,
     209,   104,    10,   -59,    69,   105,    56,    80,    55,    83,
     103,   107,    84,   113,    95,    93,   210,   224,    99,   211,
     118,   123,    38,    67,   107,    56,   193,   106,   124,   128,
      19,    20,   113,   107,    76,   138,   140,   131,   150,    66,
     152,   137,   136,   121,    10,   157,    69,   105,   158,    66,
     -72,    81,   149,    68,    10,   169,    69,    70,    71,   148,
     189,   182,   216,    63,   113,   113,   103,    56,   191,   107,
     202,   204,   205,   113,    72,   155,   215,    73,    55,   218,
     177,   113,   104,    10,   220,    69,   105,   221,   223,   162,
      36,   103,   103,   226,   103,   227,   137,     8,   168,    93,
       5,     0,     0,   143,   107,   176,    56,     0,   103,   127,
      10,     0,    69,    70,    71,     0,   107,   113,   103,   144,
     170,   149,     0,   103,   143,     0,     0,   103,   184,   103,
      72,   103,   106,    73,     0,   113,     0,   162,    36,     0,
     154,   199,     0,    34,     0,   143,     0,   155,   198,    74,
       0,   113,     0,   103,   131,   213,   212,     0,     0,     0,
       0,   167,     0,     0,   149,     0,    92,   113,     0,   219,
     113,   103,   213,     0,   186,   222,    93,     0,   176,     0,
       0,     0,   199,    74,   213,   136,   112,    92,   199,   148,
     199,   199,     0,    54,     0,   130,    10,   184,   198,   102,
      71,   130,    10,     0,   143,   102,    71,    74,   143,     0,
      92,    87,     0,   201,   135,     0,    72,   177,     0,    73,
     154,     0,    72,    99,   144,    73,   207,    10,    54,   166,
     102,    71,   108,     0,     0,     0,     0,   112,     0,    74,
       0,     0,     0,     0,     0,   122,     0,    72,    92,   225,
      73,     0,    54,     0,   156,     0,   129,     0,     0,   101,
      10,     0,    92,   102,    71,   135,     0,     0,   130,    10,
       0,    92,   102,    71,   165,     0,     0,   166,   175,     0,
      72,   178,     0,    73,     0,    54,     0,    19,    20,    72,
     175,   178,    73,    54,   108,     0,    74,     0,    54,     0,
     112,     0,   175,     0,   178,     0,     0,     0,   132,    10,
      92,   164,   102,    13,   164,     0,   164,   129,     0,    37,
      92,     0,     0,     0,    65,     0,   156,    92,     0,   133,
       0,   181,   134,   187,    10,     0,     0,   102,    71,     0,
       0,    90,    94,   175,   188,   130,    10,     0,     0,   102,
      71,   175,     0,    98,    72,    54,   192,    73,    65,     0,
       0,     0,    90,    94,     0,     0,    72,    98,     0,   190,
       0,    54,    65,     0,     0,    90,     0,    94,     0,     0,
     217,   126,   194,    10,     0,   195,     0,    54,     0,     0,
       0,   164,     0,     0,     0,     0,     0,   139,     0,     0,
     142,     0,     0,   196,   197,     0,    56,     0,     0,     0,
     151,     0,     0,    90,   126,     0,     0,     0,     0,     0,
       0,   142,     0,     0,    94,     0,     0,     0,    65,     0,
       0,     0,     0,     0,   126,   142,     9,    10,    94,    11,
      12,    13,    14,    15,    16,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    65,
      29,    44,    10,   126,    45,    46,    13,    14,    15,    16,
     139,    17,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    47,    48,    49,     0,    50,    94,     0,     0,     0,
       0,     0,    90,     0,   142,     0,    94,     0,     0,     0,
     126,   142,     0,    58,    10,   142,    59,    60,     0,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    62,    63,    64,    44,    10,
       0,    45,    46,    13,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    48,
      62,     0,    29,    44,    10,     0,    45,    46,    13,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    48,   100,     0,    29,   109,    10,
       0,    45,    46,    71,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   110,
      62,     0,   111,   114,    10,     0,   115,    46,    13,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    48,    62,     0,    29,   109,    10,
       0,    45,    46,    71,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    47,   110,
     100,     0,   125,   141,    10,     0,   115,    89,   -76,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    62,     0,    64,   109,    10,
       0,    45,    46,    71,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   110,
     100,     0,   111,   153,    10,     0,   115,    89,   -76,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    62,     0,    64,    44,    10,
       0,    45,    46,    13,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    48,
     100,     0,    50,    96,    10,     0,    45,    89,     0,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    62,    63,    64,    44,    10,
       0,    45,   159,    13,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   160,
      62,     0,    29,   171,    10,     0,   146,    46,    71,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   172,    28,     0,   173,   109,    10,
       0,    45,    46,    71,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   110,
      62,     0,   183,   109,    10,     0,    45,    46,    71,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   110,    49,     0,   111,   114,    10,
       0,   115,   159,    13,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   160,
      62,     0,    29,   203,    10,     0,   115,    46,    71,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   110,    62,     0,   111,   109,    10,
       0,    45,    46,    71,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   110,
     100,     0,   125,   206,    10,     0,   115,    89,   -76,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    62,     0,    64,   214,    10,
       0,   115,    89,   -76,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    61,
      62,     0,    64,   109,    10,     0,    45,    46,    71,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   110,   100,     0,   183,   109,    10,
       0,    45,    46,    71,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   110,
      62,     0,   173,   171,    10,     0,   146,    46,    71,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   172,    28,     0,   183,    88,    10,
       0,    45,    89,     0,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    61,
      62,     0,    64,    96,    10,     0,    45,    89,     0,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    97,     0,    64,    96,    10,
       0,    45,    89,     0,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    61,
      62,     0,    64,   117,    10,     0,    45,    89,     0,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    97,     0,    64,    96,    10,
       0,    45,    89,     0,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,   119,    47,    61,
      62,     0,    64,   120,    10,     0,    59,    60,     0,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    62,     0,    64,   145,    10,
       0,   146,    89,     0,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   147,
      28,     0,    64,    96,    10,     0,    45,    89,     0,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    47,    61,    62,     0,    64,    96,    10,
       0,    45,    89,     0,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    61,
     179,     0,    64,   180,    10,     0,    45,    89,     0,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    62,     0,    64,    96,    10,
       0,    45,    89,     0,    14,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,   119,    26,    61,
      62,     0,    64,   200,    10,     0,    45,    89,     0,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,    62,     0,    64,   130,    10,
       0,     0,   102,    71,    14,    15,    16,     0,    17,     0,
      18,     0,     0,    21,    22,    23,    24,    86,    47,    72,
     163,     0,    73,   130,    10,     0,     0,   102,    71,    14,
      15,    16,     0,    17,     0,    18,     0,     0,    21,    22,
      23,    24,    86,    26,    72,   163,     0,    73,   132,    10,
       0,     0,   102,    13,    14,    15,    16,     0,    17,     0,
      18,     0,     0,    21,    22,    23,    24,    86,    26,   133,
     163,     0,   134,   130,    10,     0,     0,   102,    71,    14,
      15,    16,     0,    17,     0,    18,     0,     0,    21,    22,
      23,    24,    86,    26,    72,   163,     0,   190,    14,    15,
      16,     0,    17,     0,    18,     0,     0,    21,    22,    85,
      24,    86,    26,    14,    15,    16,     0,    17,     0,    18,
       0,     0,    21,    22,    23,    24,    86,    26
};

static const yytype_int16 yycheck[] =
{
       6,     6,     5,     9,    10,    11,    12,     6,   125,     3,
       3,     0,     6,     4,     1,     3,     6,    12,     5,    16,
      17,    11,    14,    29,    29,     3,     4,    12,     0,     1,
       8,     3,     4,     5,     6,     7,    27,    12,    44,    12,
      46,    47,    25,    49,    50,    50,    24,     3,    25,    27,
      56,     3,     6,    59,    60,    27,   173,    47,    64,     3,
      16,    17,    68,    69,    70,    12,    25,    73,     3,    59,
      23,    77,    77,     3,     4,    25,     6,     7,    27,    69,
      25,    19,    88,     3,     4,    17,     6,     7,     8,    88,
       3,    25,     3,    26,   100,   101,   102,    27,    25,   105,
      25,    27,    26,   109,    24,   111,    25,    27,   114,     3,
      25,   117,     3,     4,     3,     6,     7,    20,    22,   125,
     125,   127,   128,    25,   130,    25,   132,     4,   134,   134,
       1,    -1,    -1,    87,   140,   141,    27,    -1,   144,     3,
       4,    -1,     6,     7,     8,    -1,   152,   153,   154,    87,
     140,   157,    -1,   159,   108,    -1,    -1,   163,   157,   165,
      24,   167,   152,    27,    -1,   171,    -1,   173,   173,    -1,
     108,   177,    -1,     6,    -1,   129,    -1,   183,   177,    12,
      -1,   187,    -1,   189,   190,   191,   191,    -1,    -1,    -1,
      -1,   129,    -1,    -1,   200,    -1,    29,   203,    -1,   205,
     206,   207,   208,    -1,   158,   211,   211,    -1,   214,    -1,
      -1,    -1,   218,    46,   220,   220,    49,    50,   224,   218,
     226,   227,    -1,     9,    -1,     3,     4,   226,   227,     7,
       8,     3,     4,    -1,   188,     7,     8,    70,   192,    -1,
      73,    27,    -1,   181,    77,    -1,    24,    25,    -1,    27,
     188,    -1,    24,    25,   192,    27,     3,     4,    44,     6,
       7,     8,    48,    -1,    -1,    -1,    -1,   100,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    24,   111,   217,
      27,    -1,    68,    -1,   117,    -1,    72,    -1,    -1,     3,
       4,    -1,   125,     7,     8,   128,    -1,    -1,     3,     4,
      -1,   134,     7,     8,     3,    -1,    -1,     6,   141,    -1,
      24,   144,    -1,    27,    -1,   101,    -1,    16,    17,    24,
     153,   154,    27,   109,   110,    -1,   159,    -1,   114,    -1,
     163,    -1,   165,    -1,   167,    -1,    -1,    -1,     3,     4,
     173,   127,     7,     8,   130,    -1,   132,   133,    -1,     6,
     183,    -1,    -1,    -1,    11,    -1,   189,   190,    -1,    24,
      -1,   147,    27,     3,     4,    -1,    -1,     7,     8,    -1,
      -1,    28,    29,   206,   160,     3,     4,    -1,    -1,     7,
       8,   214,    -1,    40,    24,   171,   172,    27,    45,    -1,
      -1,    -1,    49,    50,    -1,    -1,    24,    54,    -1,    27,
      -1,   187,    59,    -1,    -1,    62,    -1,    64,    -1,    -1,
     196,    68,     3,     4,    -1,     6,    -1,   203,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,
      97,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,   121,   122,     3,     4,   125,     6,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   146,
      27,     3,     4,   150,     6,     7,     8,     9,    10,    11,
     157,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,   173,    -1,    -1,    -1,
      -1,    -1,   179,    -1,   181,    -1,   183,    -1,    -1,    -1,
     187,   188,    -1,     3,     4,   192,     6,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,     6,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,     6,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,    -1,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,    -1,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     3,     4,
      -1,    -1,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,     3,     4,    -1,    -1,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,     9,    10,
      11,    -1,    13,    -1,    15,    -1,    -1,    18,    19,    20,
      21,    22,    23,     9,    10,    11,    -1,    13,    -1,    15,
      -1,    -1,    18,    19,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    29,    30,    30,     3,     0,    29,     3,
       4,     6,     7,     8,     9,    10,    11,    13,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    27,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     3,     6,     7,    23,    24,    25,
      27,    35,    37,    38,    41,    42,    27,    42,     3,     6,
       7,    24,    25,    26,    27,    38,    40,    42,     3,     6,
       7,     8,    24,    27,    35,    40,    42,     3,    12,    12,
      12,    43,    14,    12,    25,    20,    22,    41,     3,     7,
      38,    42,    35,    37,    38,    42,     3,    25,    38,    25,
      25,     3,     7,    42,     3,     7,    40,    42,    41,     3,
      24,    27,    35,    42,     3,     6,    39,     3,    42,    22,
       3,     3,    41,     3,    42,    27,    38,     3,     3,    41,
       3,    42,     3,    24,    27,    35,    37,    42,    12,    38,
      25,     3,    38,    39,    43,     3,     6,    24,    34,    42,
       3,    38,    23,     3,    43,    42,    35,    25,    27,     7,
      24,    36,    42,    25,    41,     3,     6,    43,    42,    17,
      40,     3,    24,    27,    34,    35,    42,    25,    35,    25,
       3,    41,    25,    27,    34,     3,    39,     3,    41,     3,
      27,    25,    41,    36,     3,     6,    24,    25,    34,    42,
       3,    43,    25,     3,    27,    26,     3,     3,     3,     8,
      24,    27,    37,    42,     3,    25,     3,    41,     3,    42,
       3,    20,    42,    22,     3,    43,    25,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    29,    30,    31,    31,    32,    32,    32,
      33,    33,    33,    34,    34,    34,    34,    34,    34,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      36,    36,    36,    36,    37,    37,    37,    37,    37,    37,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    39,    39,    39,    40,    40,    40,    40,    40,    40,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    42,    42,    42,    43,    43,    43,    44,    44
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     5,     2,     5,     1,     2,
       3,     4,     4,     3,     2,     2,     4,     3,     1,     0,
       4,     5,     1,     1,     6,     3,     2,     2,     1,     0,
       2,     3,     2,     2,     3,     3,     3,     2,     2,     2,
       1,     7,     3,     1,     2,     2,     3,     1,     1,     0,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     2,     2,     0,     2,     1,     0,     4,     0
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
  case 3: /* sint: error owl  */
#line 116 "onto.y"
                     { yyerrok; yyclearin; }
#line 1568 "onto.tab.c"
    break;

  case 4: /* owl: DEFIN CLASS opt0  */
#line 119 "onto.y"
                      { printf("Classe: %s\n", (yyvsp[-1].text));}
#line 1574 "onto.tab.c"
    break;

  case 7: /* op1: definida  */
#line 125 "onto.y"
                        { cout << "\n>>>>>Classe Definida.<<<<<\n" + CLASS ;}
#line 1580 "onto.tab.c"
    break;

  case 8: /* op1: primitiva  */
#line 126 "onto.y"
                        { cout << "\n>>>>>Classe Primitiva.<<<<<\n"; }
#line 1586 "onto.tab.c"
    break;

  case 9: /* op1: closureAxiom  */
#line 127 "onto.y"
                        { cout << "\n>>>>>Classe Axioma de fechamento.<<<<<\n"; }
#line 1592 "onto.tab.c"
    break;

  case 10: /* op2: enumerada  */
#line 130 "onto.y"
                        { cout << "\n>>>>>Classe Enumerada.<<<<<\n"; }
#line 1598 "onto.tab.c"
    break;

  case 11: /* op2: coberta  */
#line 131 "onto.y"
                                { cout << "\n>>>>>Classe Coberta.<<<<<\n"; }
#line 1604 "onto.tab.c"
    break;

  case 12: /* op2: classeAninhada  */
#line 132 "onto.y"
                          { cout << "\n>>>>>Classe Aninhada.<<<<<\n"; }
#line 1610 "onto.tab.c"
    break;

  case 13: /* definida: EQUIV CLASS AND PARENTHESIS definida  */
#line 136 "onto.y"
                                                  {precedencia((yyvsp[-4].text));}
#line 1616 "onto.tab.c"
    break;

  case 19: /* primitiva: SUB primitiva  */
#line 145 "onto.y"
                            {precedencia((yyvsp[-1].text));}
#line 1622 "onto.tab.c"
    break;

  case 20: /* primitiva: DISJ CLASS primitiva  */
#line 146 "onto.y"
                                {precedencia((yyvsp[-2].text));}
#line 1628 "onto.tab.c"
    break;

  case 30: /* closureAxiom: SUB CLASS VIRGULA closureAxiom  */
#line 158 "onto.y"
                                              {precedencia((yyvsp[-3].text));}
#line 1634 "onto.tab.c"
    break;

  case 31: /* closureAxiom: PROPERTY reservado CLASS VIRGULA closureAxiom  */
#line 159 "onto.y"
                                                         {addProp((yyvsp[-4].text));}
#line 1640 "onto.tab.c"
    break;

  case 35: /* closureAxiom2: DISJ CLASS closureAxiom2  */
#line 165 "onto.y"
                                    {precedencia((yyvsp[-2].text));}
#line 1646 "onto.tab.c"
    break;

  case 40: /* classeAninhada: EQUIV classeAninhada  */
#line 172 "onto.y"
                                      {precedencia((yyvsp[-1].text));}
#line 1652 "onto.tab.c"
    break;

  case 41: /* classeAninhada: SUB CLASS classeAninhada  */
#line 173 "onto.y"
                                   {precedencia((yyvsp[-2].text));}
#line 1658 "onto.tab.c"
    break;

  case 51: /* enumerada: EQUIV CHAVES CLASS VIRGULA enumerada CHAVES INDIVIDUALS  */
#line 186 "onto.y"
                                                                        {precedencia((yyvsp[-6].text));}
#line 1664 "onto.tab.c"
    break;

  case 54: /* coberta: SUB coberta  */
#line 191 "onto.y"
                     {precedencia((yyvsp[-1].text));}
#line 1670 "onto.tab.c"
    break;

  case 56: /* coberta: CLASS OR coberta  */
#line 193 "onto.y"
                             {declaracoes((yyvsp[-2].text));}
#line 1676 "onto.tab.c"
    break;

  case 71: /* INDIVIDUALS: INDI INDIVIDUALS  */
#line 212 "onto.y"
                              {precedencia((yyvsp[-1].text));}
#line 1682 "onto.tab.c"
    break;


#line 1686 "onto.tab.c"

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

#line 226 "onto.y"


/* definido pelo analisador léxico */
extern FILE * yyin;  

int main(int argc, char ** argv)
{
	/* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}
		
		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();
}

void yyerror(const char * s)
{
	/* variáveis definidas no analisador léxico */
	

	/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
    cout << "Erro disparado: \"" << yytext << "\" (linha " << yylineno << ")\n";
}
