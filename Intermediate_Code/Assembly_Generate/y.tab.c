/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<vector>
#include "SymbolTable.h"

using namespace std;
int yylex(void);
extern FILE *yyin;

extern int line_count;
extern int error_count;

vector<char *> vec;
vector<SymbolInfo *> param_list;


 FILE * logout = fopen("log.txt","w");
 FILE *error= fopen("error.txt","w");
 FILE *code = fopen("Code.asm","w");

string return_Type = "";
bool returnFlag = false;
SymbolTable * symboltable = new SymbolTable(30);


int labelCount=0;
int tempCount=0;


char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}

void yyerror(const char *s){
	fprintf(logout,"At line no: %d  %s\n",line_count,s);
  printf("At line no %d : %s\n",line_count,s);
}


#line 128 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 65 "parser.y" /* yacc.c:355  */

    struct node {
        char * mystr;
        char *code;
        char charvalue;
        int intvalue;
        float floatvalue;
        char * name;
        char * d_type;
        struct node * arg_list;
        char *VAR_NAME;
        char *DATA_TYPE;
    };

#line 173 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LOWER_THAN_ELSE = 258,
    ELSE = 259,
    DOUBLE = 260,
    CONST_FLOAT = 261,
    ADDOP = 262,
    MULOP = 263,
    ID = 264,
    LOGICOP = 265,
    RELOP = 266,
    CONST_CHAR = 267,
    CONST_INT = 268,
    NEWLINE = 269,
    PLUS = 270,
    MINUS = 271,
    SLASH = 272,
    ASTERISK = 273,
    LPAREN = 274,
    RPAREN = 275,
    IF = 276,
    FOR = 277,
    DO = 278,
    INT = 279,
    FLOAT = 280,
    VOID = 281,
    SWITCH = 282,
    DEFAULT = 283,
    WHILE = 284,
    BREAK = 285,
    CHAR = 286,
    RETURN = 287,
    CASE = 288,
    CONTINUE = 289,
    ASSIGNOP = 290,
    COMMA = 291,
    INCOP = 292,
    DECOP = 293,
    LCURL = 294,
    RCURL = 295,
    LTHIRD = 296,
    RTHIRD = 297,
    NOT = 298,
    PRINTLN = 299,
    SEMICOLON = 300
  };
#endif
/* Tokens.  */
#define LOWER_THAN_ELSE 258
#define ELSE 259
#define DOUBLE 260
#define CONST_FLOAT 261
#define ADDOP 262
#define MULOP 263
#define ID 264
#define LOGICOP 265
#define RELOP 266
#define CONST_CHAR 267
#define CONST_INT 268
#define NEWLINE 269
#define PLUS 270
#define MINUS 271
#define SLASH 272
#define ASTERISK 273
#define LPAREN 274
#define RPAREN 275
#define IF 276
#define FOR 277
#define DO 278
#define INT 279
#define FLOAT 280
#define VOID 281
#define SWITCH 282
#define DEFAULT 283
#define WHILE 284
#define BREAK 285
#define CHAR 286
#define RETURN 287
#define CASE 288
#define CONTINUE 289
#define ASSIGNOP 290
#define COMMA 291
#define INCOP 292
#define DECOP 293
#define LCURL 294
#define RCURL 295
#define LTHIRD 296
#define RTHIRD 297
#define NOT 298
#define PRINTLN 299
#define SEMICOLON 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 79 "parser.y" /* yacc.c:355  */

  struct node args;

#line 279 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 296 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   110,   130,   137,   142,   147,   154,   196,
     221,   221,   295,   385,   417,   444,   472,   493,   493,   526,
     526,   544,   564,   573,   582,   592,   606,   627,   642,   660,
     666,   681,   686,   692,   697,   714,   732,   747,   762,   780,
     840,   851,   873,   901,   983,   988,  1108,  1113,  1123,  1128,
    1138,  1144,  1200,  1205,  1285,  1295,  1305,  1311,  1316,  1356,
    1368,  1381,  1398,  1408,  1419,  1425,  1430,  1449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOWER_THAN_ELSE", "ELSE", "DOUBLE",
  "CONST_FLOAT", "ADDOP", "MULOP", "ID", "LOGICOP", "RELOP", "CONST_CHAR",
  "CONST_INT", "NEWLINE", "PLUS", "MINUS", "SLASH", "ASTERISK", "LPAREN",
  "RPAREN", "IF", "FOR", "DO", "INT", "FLOAT", "VOID", "SWITCH", "DEFAULT",
  "WHILE", "BREAK", "CHAR", "RETURN", "CASE", "CONTINUE", "ASSIGNOP",
  "COMMA", "INCOP", "DECOP", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "NOT",
  "PRINTLN", "SEMICOLON", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "$@1", "parameter_list",
  "compound_statement", "$@2", "$@3", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -20

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     101,   -68,   -68,   -68,     9,   101,   -68,   -68,   -68,   -68,
      13,   -68,   -68,   -15,   -11,    17,    39,    46,   -68,    25,
     -13,    53,    31,    36,   -68,    41,    -9,   101,   -68,   -68,
      65,    43,   -68,   -68,   -68,    72,    44,    78,    48,   -68,
     -68,   -68,    99,    -6,   -68,    99,    73,    77,    79,    99,
      99,    82,   -68,   -68,   -68,   102,    50,   -68,   -68,    16,
      68,   -68,   105,    10,   108,   -68,   -68,   -68,   -18,   -68,
      99,    99,   100,    99,     5,    99,    74,   -68,   119,    88,
     -68,   -68,    99,   -68,   -68,   -68,    99,    99,    99,    99,
     -68,   110,    95,    90,   -68,   113,     5,   114,   -68,   115,
     -68,   -68,   108,   130,   -68,   -68,    99,   -68,    78,    99,
      78,    93,   -68,   135,   120,   -68,   -68,    78,    78,   -68,
     -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,    23,    24,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    27,     0,     0,     0,     0,    21,    10,
       0,    16,     0,    25,     9,     0,     0,     0,    15,    28,
       0,    17,    11,     8,    12,    14,     0,     0,     0,    13,
      26,    61,     0,    42,    60,     0,     0,     0,     0,     0,
       0,     0,    40,    33,    31,     0,     0,    29,    32,    57,
       0,    44,    46,    48,    50,    52,    56,    20,    57,    54,
      65,     0,     0,     0,     0,     0,     0,    55,     0,    27,
      18,    30,     0,    62,    63,    41,     0,     0,     0,     0,
      67,     0,    64,     0,    59,     0,     0,     0,    39,     0,
      45,    47,    51,    49,    53,    58,     0,    43,     0,     0,
       0,     0,    66,    36,     0,    37,    38,     0,     0,    35,
      34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   136,   -68,   -68,   -68,   -68,     7,   -68,
     -68,    61,   109,   -68,   -68,   -50,   -58,   -42,   -44,   -67,
      57,    56,    58,   -40,   -68,   -68,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    25,    20,    53,    37,
      38,    54,    55,    14,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    91,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    72,    69,    90,    15,    76,    81,    26,    68,    11,
      77,    41,    42,    70,    43,   100,    96,    87,    44,    83,
      84,    88,    13,    27,    45,    17,    16,    93,    68,    95,
      31,    97,    32,    34,    18,    71,    33,    19,   109,   112,
      68,     1,     2,     3,    68,    68,    68,    68,    50,   104,
      52,    82,    22,    83,    84,    23,    41,    42,   113,    43,
     115,     9,    28,    44,    68,   114,     9,   119,   120,    45,
      24,    46,    47,    29,     1,     2,     3,    30,    36,    48,
      31,    39,    49,   -19,    41,    42,    40,    43,    67,    31,
      80,    44,    73,    50,    51,    52,    74,    45,    75,    46,
      47,    78,     1,     2,     3,    41,    42,    48,    43,    10,
      49,    79,    44,    85,    10,    86,    89,    31,    45,    98,
      94,    50,    51,    52,    21,     1,     2,     3,    99,    16,
     105,   106,   107,   108,   110,   111,    35,    87,   116,   117,
     118,    12,    50,   101,   103,   102
};

static const yytype_uint8 yycheck[] =
{
      42,    45,    42,    70,    19,    49,    56,    20,    50,     0,
      50,     6,     7,    19,     9,    82,    74,     7,    13,    37,
      38,    11,     9,    36,    19,    36,    41,    71,    70,    73,
      39,    75,    25,    26,    45,    41,    45,    20,    96,   106,
      82,    24,    25,    26,    86,    87,    88,    89,    43,    89,
      45,    35,    13,    37,    38,     9,     6,     7,   108,     9,
     110,     0,     9,    13,   106,   109,     5,   117,   118,    19,
      45,    21,    22,    42,    24,    25,    26,    41,    13,    29,
      39,     9,    32,    40,     6,     7,    42,     9,    40,    39,
      40,    13,    19,    43,    44,    45,    19,    19,    19,    21,
      22,    19,    24,    25,    26,     6,     7,    29,     9,     0,
      32,     9,    13,    45,     5,    10,     8,    39,    19,    45,
      20,    43,    44,    45,    15,    24,    25,    26,     9,    41,
      20,    36,    42,    20,    20,    20,    27,     7,    45,     4,
      20,     5,    43,    86,    88,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    26,    47,    48,    49,    50,    51,    57,
      58,     0,    49,     9,    59,    19,    41,    36,    45,    20,
      53,    58,    13,     9,    45,    52,    20,    36,     9,    42,
      41,    39,    54,    45,    54,    58,    13,    55,    56,     9,
      42,     6,     7,     9,    13,    19,    21,    22,    29,    32,
      43,    44,    45,    54,    57,    58,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    40,    63,    69,
      19,    41,    64,    19,    19,    19,    64,    69,    19,     9,
      40,    61,    35,    37,    38,    45,    10,     7,    11,     8,
      65,    71,    72,    64,    20,    64,    62,    64,    45,     9,
      65,    66,    68,    67,    69,    20,    36,    42,    20,    62,
      20,    20,    65,    61,    64,    61,    45,     4,    20,    61,
      61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      52,    51,    51,    53,    53,    53,    53,    55,    54,    56,
      54,    57,    58,    58,    58,    59,    59,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     6,     6,     4,     3,     2,     1,     0,     4,     0,
       3,     3,     1,     1,     1,     3,     6,     1,     4,     1,
       2,     1,     1,     1,     7,     7,     5,     5,     5,     3,
       1,     2,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     4,     3,
       1,     1,     2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 95 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d start : program\n\n",line_count);
					(yyval.args) = (yyvsp[0].args);
					fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);
          char * init = ".MODEL SMALL\n.STACK 100H\n.DATA";
          fprintf(code,"%s\n",init);
          //fprintf(code,"%s\n\n",$1.mystr);
          fprintf(code,"%s",(yyvsp[0].args).code);

          init = "\nEND MAIN";
          fprintf(code,"%s\n",init);

          fprintf(error,"Total Errors: %d\n\n",error_count);
				}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d program : program unit\n\n",line_count);
					char * tmp = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));
					char tmp2[2];
					tmp2[0]='\n';tmp2[1]='\0';
					strcpy(tmp , (yyvsp[-1].args).mystr);
					strcat(tmp , tmp2);
					strcat(tmp , (yyvsp[0].args).mystr);
					(yyval.args).mystr = tmp;

          char * ctmp = (char *) malloc(1+strlen((yyvsp[-1].args).code)+strlen((yyvsp[0].args).code));
          char ctmp2[2];
          ctmp2[0]='\n';ctmp2[1]='\0';
          strcpy(ctmp , (yyvsp[-1].args).code);
          strcat(ctmp , ctmp2);
          strcat(ctmp , (yyvsp[0].args).code);

          (yyval.args).code = ctmp;
					fprintf(logout,"%s \n\n",tmp);
				}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 130 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d program : | unit\n\n",line_count);
					(yyval.args) = (yyvsp[0].args);

					fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);
				}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 137 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d unit : var_declaration\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);
					 }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 142 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d unit : func_declaration\n\n",line_count);
						 (yyval.args) = (yyvsp[0].args);
						 fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					 }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 147 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d unit : func_definition\n\n",line_count);
						 (yyval.args) = (yyvsp[0].args);

						 fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					 }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 154 "parser.y" /* yacc.c:1646  */
    {
               fprintf(logout,"At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n",line_count);

               char tmp[2];
               tmp[0]='(';tmp[1]='\0';
               char * tmp2 = (char *)
               malloc(1+strlen((yyvsp[-5].args).mystr)+strlen((yyvsp[-4].args).mystr)+1+strlen((yyvsp[-2].args).mystr)+2);
               strcpy(tmp2 , (yyvsp[-5].args).mystr);
               strcat(tmp2 , (yyvsp[-4].args).mystr);
               strcat(tmp2 , tmp);
               strcat(tmp2 , (yyvsp[-2].args).mystr);
               tmp[0] = ')';
               strcat(tmp2 , tmp);
               tmp[0] = ';';
               strcat(tmp2 , tmp);
               (yyval.args).mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);

               if(symboltable->Lookup((yyvsp[-4].args).mystr) != NULL){
                  error_count++;
                 fprintf(error,"Error %d at line %d: Multiple declaration of %s\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
               }
               else{
                 symboltable->Insert((yyvsp[-4].args).mystr , "ID","FUNCTION.DEC");
                 SymbolInfo *s = symboltable->Lookup((yyvsp[-4].args).mystr);
                 s->setDataType((yyvsp[-5].args).mystr);

                 struct node * head = (yyvsp[-2].args).arg_list;

                  while(head!= NULL){
                    if(head->name == NULL){
                      s->addArgument("" , head->d_type , "");
                    }
                    else{
                      ////cout<<head->name<<" - "<<head->d_type<<endl;
                      s->addArgument(head->name , head->d_type , "");
                    }
                    head = head->arg_list;
                  }
               }
               param_list.clear();
             }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 196 "parser.y" /* yacc.c:1646  */
    {
               fprintf(logout,"At line no: %d func_declaration :type_specifier ID LPAREN RPAREN SEMICOLON\n\n",line_count);
               char tmp[2];
               tmp[0]='(';tmp[1]='\0';
               char * tmp2 = (char *) malloc(1+strlen((yyvsp[-4].args).mystr)+strlen((yyvsp[-3].args).mystr)+3);
               strcpy(tmp2 , (yyvsp[-4].args).mystr);
               strcat(tmp2 , (yyvsp[-3].args).mystr);
               strcat(tmp2 , tmp);
               tmp[0] = ')';
               strcat(tmp2 , tmp);
               tmp[0] = ';';
               strcat(tmp2 , tmp);
               (yyval.args).mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);
               if(symboltable->Lookup((yyvsp[-3].args).mystr) != NULL){
                  error_count++;
                 fprintf(error,"Error %d at line %d: Multiple declaration of %s\n\n",error_count,line_count,(yyvsp[-3].args).mystr);
               }
               else{
                 symboltable->Insert((yyvsp[-3].args).mystr , "ID", "FUNCTION.DEC");
                 SymbolInfo *s = symboltable->Lookup((yyvsp[-3].args).mystr);
                 s->setDataType((yyvsp[-4].args).mystr);
               }
             }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 221 "parser.y" /* yacc.c:1646  */
    {
         cout<<"NEED TO INS FUNC NAME FOR RECURSION "<<(yyvsp[-2].args).mystr<<endl;

         //$<args>$.code += " PROC\n";
       }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 225 "parser.y" /* yacc.c:1646  */
    {
				 		fprintf(logout,"At line no: %d func_definition : type_specifier ID LPAREN  RPAREN compound_statement\n\n",line_count);
						char tmp[2];
 						tmp[0]='(';tmp[1]='\0';
 						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-5].args).mystr)+strlen((yyvsp[-4].args).mystr)+4+strlen((yyvsp[0].args).mystr));
 						strcpy(tmp2 , (yyvsp[-5].args).mystr);
 						strcat(tmp2 , (yyvsp[-4].args).mystr);
 						strcat(tmp2 , tmp);
 						tmp[0] = ')';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[0].args).mystr);
 						(yyval.args).mystr = tmp2;

            char ctmp[7];

            char * ctmp2 = (char *) malloc(1+strlen((yyvsp[-4].args).mystr)+15+strlen((yyvsp[0].args).code));
            strcat(ctmp2 , (yyvsp[-4].args).mystr);
            ctmp[0]=' ';ctmp[1]='\0';
            strcat(ctmp2 , ctmp);
            ctmp[0]='P';ctmp[1]='R';ctmp[2]='O';ctmp[3]='C';ctmp[4]='\n';ctmp[5]='\0';

            strcat(ctmp2 , ctmp);
            strcat(ctmp2 , (yyvsp[0].args).code);
            ctmp[0]='\n';ctmp[1]='\0';
            strcat(ctmp2 , ctmp);
            strcat(ctmp2 , (yyvsp[-4].args).mystr);
            ctmp[0]=' ';ctmp[1]='\0';
            strcat(ctmp2 , ctmp);

            ctmp[0]='E';ctmp[1]='N';ctmp[2]='D';ctmp[3]='P';ctmp[4]='\0';ctmp[5]='\0';ctmp[6]='\0';
            strcat(ctmp2 , ctmp);

            (yyval.args).code = ctmp2;

 						fprintf(logout,"%s \n\n",tmp2);
            int flag = 1;

            if(symboltable->Lookup((yyvsp[-4].args).mystr) != NULL){
              if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataType() != return_Type && return_Type != "" && returnFlag){
                error_count++;
                fprintf(error,"Error %d at line %d: Return Type does not match\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
              }
              if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataStructure()=="FUNCTION.DEC"){
                SymbolInfo *s = symboltable->Lookup((yyvsp[-4].args).mystr);
                s->setDataStructure("FUNCTION.DEF");
              }
              else if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataStructure()=="FUNCTION.DEF"){
                flag = 0;
                error_count++;
                fprintf(error,"Error %d at line %d: Redefinition of  %s\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
              }
              if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataType() != (yyvsp[-5].args).mystr){
                  error_count++;
                  fprintf(error,"Error %d at line %d: Conflicting return-type for %s\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
                }
            }
            else{
              symboltable->Insert((yyvsp[-4].args).mystr , "ID","FUNCTION.DEF");
              symboltable->Lookup((yyvsp[-4].args).mystr)->setDataType((yyvsp[-5].args).mystr);

              //cout<<return_Type<<" FUNC-RET--"<<symboltable->Lookup($2.mystr)->getDataType()<<"--\n\n";
              if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataType() != return_Type && return_Type != "" && returnFlag){
                error_count++;
                fprintf(error,"Error %d at line %d: Return Type does not match\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
              }
            }
            return_Type = "";
            returnFlag = false;

					 }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 295 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n",line_count);
						 char tmp[2];
						 tmp[0]='(';tmp[1]='\0';
						 char * tmp2 = (char *) malloc(1+strlen((yyvsp[-5].args).mystr)+strlen((yyvsp[-4].args).mystr)+1+strlen((yyvsp[-2].args).mystr)+1+strlen((yyvsp[0].args).mystr));
						 strcpy(tmp2 , (yyvsp[-5].args).mystr);
						 strcat(tmp2 , (yyvsp[-4].args).mystr);
						 strcat(tmp2 , tmp);
						 strcat(tmp2 , (yyvsp[-2].args).mystr);
						 tmp[0] = ')';
						 strcat(tmp2 , tmp);
						 strcat(tmp2 , (yyvsp[0].args).mystr);
						 (yyval.args).mystr = tmp2;
						 fprintf(logout,"%s \n\n",tmp2);
             //SymbolInfo *s = symboltable->Lookup($2.mystr);
             int flag = 1;
             SymbolInfo *s;
             if(symboltable->Lookup((yyvsp[-4].args).mystr)!= NULL){
               cout<<return_Type<<"- FUNC-RET--"<<symboltable->Lookup((yyvsp[-4].args).mystr)->getDataType()<<"--\n\n";
               if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataType() != return_Type && return_Type != "" && returnFlag){
                 error_count++;
                 fprintf(error,"Error %d at line %d: Return Type does not match\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
               }
                 if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataStructure()=="FUNCTION.DEC"){
                   flag = 0;
                   s = symboltable->Lookup((yyvsp[-4].args).mystr);
                   s->setDataStructure("FUNCTION.DEF");
                   //checking parameters
                   struct node * head = (yyvsp[-2].args).arg_list;
                   int arg_no = s->getArgNumber();
                   while(head!= NULL){
                     if(arg_no == 0){
                       flag = 0;
                       error_count++;
                       fprintf(error,"Error %d at line %d: Conflicting arguments  %s\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
                       break;
                     }
                     SymbolInfo *sym = s->getArgument();
                     //cout<<head->name<<" - "<<head->d_type<<endl;
                     if(head->d_type != sym->getType()){
                       flag = 0;
                       error_count++;
                       fprintf(error,"Error %d at line %d: Conflicting arguments  %s\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
                       break;
                    }
                      //cout<<"Ekbar\n\n";
                     arg_no--;
                     head = head->arg_list;
                   }
                 }
                 else if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataStructure()=="FUNCTION.DEF"){
                   flag = 0;
                   error_count++;
                   fprintf(error,"Error %d at line %d: Redefinition of  %s\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
                 }
                 if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataType() != (yyvsp[-5].args).mystr){
                   error_count++;
                   fprintf(error,"Error %d at line %d: Conflicting return-type for %s\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
                   //yyerror("Conflicting return-type for");
                 }
             }
             else{
               symboltable->Insert((yyvsp[-4].args).mystr , "ID","FUNCTION.DEF");
               s = symboltable->Lookup((yyvsp[-4].args).mystr);
               s->setDataType((yyvsp[-5].args).mystr);

               //cout<<"\n\nHERE-"<<return_Type<<"--FUNC-RET--"<<symboltable->Lookup($2.mystr)->getDataType()<<"--\n\n";
               if(symboltable->Lookup((yyvsp[-4].args).mystr)->getDataType() != return_Type&& return_Type != "" && returnFlag){
                 error_count++;
                 fprintf(error,"Error %d at line %d: Return Type does not match\n\n",error_count,line_count,(yyvsp[-4].args).mystr);
               }
             }
             if(flag == 1){
               struct node * head = (yyvsp[-2].args).arg_list;
               while(head!= NULL){
                 ////cout<<head->name<<" - "<<head->d_type<<endl;
                 if(head->name == NULL){
                   s->addArgument("" , head->d_type , "");
                 }
                 else{
                   s->addArgument(head->name , head->d_type , "");
                 }
                 head = head->arg_list;
               }
             }
             return_Type = "";
             returnFlag = false;

			 		}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 385 "parser.y" /* yacc.c:1646  */
    {
              fprintf(logout,"At line no: %d parameter_list  : parameter_list COMMA type_specifier ID\n\n",line_count);
              char tmp[2];
              tmp[0]=',';tmp[1]='\0';
              char * tmp2 = (char *) malloc(1+strlen((yyvsp[-3].args).mystr)+1+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));
              strcpy(tmp2 , (yyvsp[-3].args).mystr);
              strcat(tmp2 , tmp);
              strcat(tmp2 , (yyvsp[-1].args).mystr);
              strcat(tmp2 , (yyvsp[0].args).mystr);

              (yyval.args).mystr = tmp2;
              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = (yyvsp[0].args).mystr;
              item->d_type = (yyvsp[-1].args).mystr;
              item->arg_list = (yyvsp[-3].args).arg_list;
              (yyval.args).arg_list = item;
              fprintf(logout,"%s \n\n",tmp2);

              /* symboltable->Insert($4.mystr , "ID","PARAM");
              SymbolInfo *s = symboltable->Lookup($4.mystr);
              s->setDataType($3.mystr); */

              SymbolInfo *it;
              it = new SymbolInfo;
              it->setName((yyvsp[0].args).mystr);
              it->setType((yyvsp[-1].args).mystr);
              it->setDataStructure("");
              it->next = NULL;

              param_list.push_back(it);

            }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 417 "parser.y" /* yacc.c:1646  */
    {
              fprintf(logout,"At line no: %d parameter_list : parameter_list COMMA type_specifier\n\n",line_count);
              char tmp[2];
              tmp[0]=',';tmp[1]='\0';
              char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+1+strlen((yyvsp[0].args).mystr));
              strcpy(tmp2 , (yyvsp[-2].args).mystr);
              strcat(tmp2 , tmp);
              strcat(tmp2 , (yyvsp[0].args).mystr);
              (yyval.args).mystr = tmp2;

              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = "";
              item->d_type = (yyvsp[0].args).mystr;
              item->arg_list = (yyvsp[-2].args).arg_list;
              (yyval.args).arg_list = item;
              fprintf(logout,"%s \n\n",tmp2);

              /* SymbolInfo *item;
              item = new SymbolInfo;
              item->setName("");
              item->setType($3.mystr);
              item->setDataStructure("");
              item->next = NULL;

              param_list.push_back(item); */

            }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 444 "parser.y" /* yacc.c:1646  */
    {
              fprintf(logout,"At line no: %d parameter_list : type_specifier ID\n\n",line_count);
              char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));
              strcpy(tmp2 , (yyvsp[-1].args).mystr);
              strcat(tmp2 , (yyvsp[0].args).mystr);

              /* symboltable->Insert($2.mystr , "ID","PARAM");
              SymbolInfo *s = symboltable->Lookup($2.mystr);
              s->setDataType($1.mystr); */

              (yyval.args).mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);
              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = (yyvsp[0].args).mystr;
              item->d_type = (yyvsp[-1].args).mystr;
              item->arg_list = NULL;
              (yyval.args).arg_list = item;

              SymbolInfo *it;
              it = new SymbolInfo;
              it->setName((yyvsp[0].args).mystr);
              it->setType((yyvsp[-1].args).mystr);
              it->setDataStructure("");
              it->next = NULL;

              param_list.push_back(it);

            }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 472 "parser.y" /* yacc.c:1646  */
    {
              fprintf(logout,"At line no: %d parameter_list : type_specifier\n\n",line_count);
              fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
              (yyval.args).mystr = (yyvsp[0].args).mystr;
              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = "";
              item->d_type = (yyvsp[0].args).mystr;
              item->arg_list = NULL;
              (yyval.args).arg_list = item;

              /* SymbolInfo *item;
              item = new SymbolInfo;
              item->setName("");
              item->setType($1.mystr);
              item->setDataStructure("");
              item->next = NULL;

              param_list.push_back(item); */

            }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 493 "parser.y" /* yacc.c:1646  */
    {
        symboltable->EnterScope();
        //cout<<"\nNew Scope-"<<param_list.size()<<endl;
        for(int i = 0 ; i< param_list.size() ; i++){
            SymbolInfo * s = param_list[i];
            symboltable->Insert(s->getName(), "ID" , "");
            SymbolInfo * sym = symboltable->Lookup(s->getName());
            sym->setDataType(s->getType());
        }
        param_list.clear();
        return_Type = "";
        }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 504 "parser.y" /* yacc.c:1646  */
    {
							fprintf(logout,"At line no: %d compound_statement : LCURL statements RCURL\n\n",line_count);
							char tmp[2];
							tmp[0]='{';tmp[1]='\0';
							char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+5);
							strcpy(tmp2 , tmp);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							strcat(tmp2 , (yyvsp[-1].args).mystr);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							tmp[0] = '}';
							strcat(tmp2 , tmp);
							(yyval.args).mystr = tmp2;
              (yyval.args).d_type = (yyvsp[-1].args).d_type;

              (yyval.args).code = (yyvsp[-1].args).code;

							fprintf(logout,"%s \n\n",tmp2);
							symboltable->PrintAllScopes();
							symboltable->ExitScope();
						}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 526 "parser.y" /* yacc.c:1646  */
    {symboltable->EnterScope();}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 526 "parser.y" /* yacc.c:1646  */
    {
							 fprintf(logout,"At line no: %d compound_statement : LCURL RCURL\n\n",line_count);
							 char tmp[2];
							 tmp[0]='{';tmp[1]='\0';
							 char * tmp2 = (char *) malloc(1+2);
							 tmp[0] = '\n';
 							 strcat(tmp2 , tmp);
 							strcat(tmp2 , tmp);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							 tmp[0] = '}';
							 strcat(tmp2 , tmp);
							 (yyval.args).mystr = tmp2;
							 fprintf(logout,"%s \n\n",tmp2);
               symboltable->PrintAllScopes();
               symboltable->ExitScope();
						 }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 544 "parser.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n\n",line_count);
				char * tmp = (char *) malloc(1 + strlen((yyvsp[-2].args).mystr) + 1 + strlen((yyvsp[-1].args).mystr));
				strcpy(tmp, (yyvsp[-2].args).mystr);
				char tmp2[2];
				tmp2[1] = '\0';
				tmp2[0] = ';';
				strcat(tmp, (yyvsp[-1].args).mystr);
				strcat(tmp , tmp2);
				tmp2[0] = '\n';
				strcat(tmp , tmp2);
        for(int i=0 ; i< vec.size() ; i++){
            symboltable->Lookup(vec[i])->setDataType((yyvsp[-2].args).mystr);
        }
				fprintf(logout,"%s\n\n",tmp);
				(yyval.args).mystr = tmp;
        (yyval.args).code = "";
				////cout<<"--- > "<<vec.size()<<endl;
        vec.clear();
			}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 564 "parser.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no: %d type_specifier:INT\n\n",line_count);
				char tmp[5];
				tmp[0]='i';tmp[1]='n';tmp[2]='t';tmp[3]=' ';tmp[4]='\0';
				char * tmp2 = (char *) malloc(1+strlen(tmp));
				strcat(tmp2 , tmp);
				(yyval.args).mystr = tmp2;
				fprintf(logout,"%s \n\n",tmp2);
				}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 573 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d type_specifier : FLOAT\n\n",line_count);
					char tmp[7];
					tmp[0]='f';tmp[1]='l';tmp[2]='o';tmp[3]='a';tmp[4]='t';tmp[5]='   ';tmp[6]='\0';
					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);
					(yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);
				}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 582 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d type_specifier : VOID\n\n",line_count);
					char tmp[6];
					tmp[0]='v';tmp[1]='o';tmp[2]='i';tmp[3]='d';tmp[4]=' ';tmp[5]='\0';
					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);
					(yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);
				}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 592 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d declaration_list : declaration_list COMMA ID\n\n",line_count);
						char * tmp = (char *) malloc(1 + strlen((yyvsp[-2].args).mystr)+ 1+strlen((yyvsp[0].args).mystr) );
			      strcpy(tmp, (yyvsp[-2].args).mystr);
						char tmp2[2];
						tmp2[1] = '\0';
						tmp2[0] = ',';
			      strcat(tmp, tmp2);
						strcat(tmp , (yyvsp[0].args).mystr);
						fprintf(logout,"%s\n\n",tmp);
						(yyval.args).mystr = tmp;
            vec.push_back((yyvsp[0].args).mystr);
						symboltable->Insert((yyvsp[0].args).mystr , "ID","");
					}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 606 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n",line_count);
						char integer[2];
						sprintf(integer, "%d", (yyvsp[-1].args).intvalue);
						char * tmp = (char *) malloc(1 + strlen((yyvsp[-5].args).mystr)+ 1+strlen((yyvsp[-3].args).mystr)+3 );
						strcpy(tmp, (yyvsp[-5].args).mystr);
						char tmp2[2];
						tmp2[1] = '\0';
						tmp2[0] = ',';
			      strcat(tmp, tmp2);
						strcat(tmp , (yyvsp[-3].args).mystr);
						tmp2[0] = '[';
			      strcat(tmp, tmp2);
						strcat(tmp, integer);
						tmp2[0] = ']';
			      strcat(tmp, tmp2);
						fprintf(logout,"%s\n\n",tmp);
						(yyval.args).mystr = tmp;
            symboltable->Insert((yyvsp[-3].args).mystr , "ID","ARRAY");
            vec.push_back((yyvsp[-3].args).mystr);
					}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 627 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d declaration_list : ID\n\n",line_count);
						fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);
						(yyval.args) = (yyvsp[0].args);
            SymbolInfo *s = symboltable->Lookup((yyvsp[0].args).mystr);
            if(s != NULL && strcmp(s->getDataStructure().c_str() , "PARAM")){
              error_count++;
              ////cout<<endl<<s->getDataStructure().c_str();
              fprintf(error, "Error %d at Line %d: Multiple declarations of the same variable: %s\n\n",error_count , line_count,(yyvsp[0].args).mystr);
            }
            else{
              symboltable->Insert((yyval.args).mystr , "ID","");
              vec.push_back((yyvsp[0].args).mystr);
            }
					}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 642 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n",line_count);
						char tmp[2];
 						tmp[0]='[';tmp[1]='\0';
						char integer[2];
						sprintf(integer, "%d", (yyvsp[-1].args).intvalue);
 						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-3].args).mystr)+1+strlen(integer)+1);
 						strcpy(tmp2 , (yyvsp[-3].args).mystr);
 						strcat(tmp2 , tmp);
						strcat(tmp2 , integer);
						tmp[0]=']';
						strcat(tmp2 , tmp);
            vec.push_back((yyvsp[-3].args).mystr);
 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
						symboltable->Insert((yyvsp[-3].args).mystr , "ID","ARRAY");
					 }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 660 "parser.y" /* yacc.c:1646  */
    {
						//
						fprintf(logout,"At line no: %d statements : statement \n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					 }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 666 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d statements :| statements statement \n\n",line_count);
 						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));
 						strcpy(tmp2 , (yyvsp[-1].args).mystr);
 						strcat(tmp2 , (yyvsp[0].args).mystr);
            (yyval.args) = (yyvsp[0].args);
 						(yyval.args).mystr = tmp2;

            char * ctmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).code)+strlen((yyvsp[0].args).code));
            strcpy(ctmp2 , (yyvsp[-1].args).code);
            strcat(ctmp2 , (yyvsp[0].args).code);

            fprintf(logout,"%s \n\n",tmp2);
					 }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 681 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d statement : var_declaration\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 686 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d statement : expression_statement\n\n",line_count);
						 (yyval.args) = (yyvsp[0].args);

 						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					 }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 692 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d statement : compound_statement\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 697 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d statement :  FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",line_count);
						char tmp[4];
 						tmp[0]='f';tmp[1]='o';tmp[2]='r';tmp[3]='\0';
 						char * tmp2 = (char *) malloc(1+strlen(tmp)+1+strlen((yyvsp[-4].args).mystr)+strlen((yyvsp[-4].args).mystr)+strlen((yyvsp[-4].args).mystr)+1+strlen((yyvsp[0].args).mystr));
 						strcpy(tmp2 , tmp);
						tmp[0]='(';tmp[1]='\0';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[-4].args).mystr);
						strcat(tmp2 , (yyvsp[-3].args).mystr);
						strcat(tmp2 , (yyvsp[-2].args).mystr);
 						tmp[0] = ')';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[0].args).mystr);
 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 714 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d statement : IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count);
						char tmp[5];
 						tmp[0]='i';tmp[1]='f';tmp[2]='\0';
 						char * tmp2 = (char *) malloc(1+strlen(tmp)+strlen(tmp)+strlen((yyvsp[-4].args).mystr)+1+strlen((yyvsp[-2].args).mystr)+strlen(tmp)+strlen((yyvsp[0].args).mystr));
 						strcpy(tmp2 , tmp);
						tmp[0]='(';tmp[1]='\0';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[-4].args).mystr);
						tmp[0] = ')';
 						strcat(tmp2 , tmp);
						strcat(tmp2 , (yyvsp[-2].args).mystr);
						tmp[0]='e';tmp[1]='l';tmp[2]='s';tmp[3]='e';tmp[4]='\0';
						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[0].args).mystr);
 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 732 "parser.y" /* yacc.c:1646  */
    {
							fprintf(logout,"At line no: %d statement : IF LPAREN expression RPAREN statement\n\n",line_count);
							char tmp[5];
							tmp[0]='i';tmp[1]='f';tmp[2]='\0';
							char * tmp2 = (char *) malloc(1+strlen(tmp)+2+strlen((yyvsp[-2].args).mystr)+1+strlen((yyvsp[0].args).mystr));
							strcpy(tmp2 , tmp);
							tmp[0]='(';tmp[1]='\0';
							strcat(tmp2 , tmp);
							strcat(tmp2 , (yyvsp[-2].args).mystr);
							tmp[0] = ')';
							strcat(tmp2 , tmp);
							strcat(tmp2 , (yyvsp[0].args).mystr);
							(yyval.args).mystr = tmp2;
							fprintf(logout,"%s \n\n",tmp2);
					}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 747 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d statement : WHILE LPAREN expression RPAREN statement\n\n",line_count);
						char tmp[6];
						tmp[0]='w';tmp[1]='h';tmp[2]='i';tmp[3]='l';tmp[4]='e';tmp[5]='\0';
 						char * tmp2 = (char *) malloc(1+strlen(tmp)+1+strlen((yyvsp[-2].args).mystr)+1+strlen((yyvsp[0].args).mystr));
 						strcpy(tmp2 , tmp);
						tmp[0]='(';tmp[1]='\0';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[-2].args).mystr);
						tmp[0] = ')';
 						strcat(tmp2 , tmp);
						strcat(tmp2 , (yyvsp[0].args).mystr);
 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 762 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count);
						char tmp[8];
						tmp[0]='p';tmp[1]='r';tmp[2]='i';tmp[3]='n';tmp[4]='t';tmp[5]='l';tmp[6]='n';tmp[7]='\0';
 						char * tmp2 = (char *) malloc(1+strlen(tmp)+1+strlen((yyvsp[-2].args).mystr)+2);
 						strcpy(tmp2 , tmp);
						tmp[0]='(';tmp[1]='\0';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[-2].args).mystr);
						tmp[0] = ')';
 						strcat(tmp2 , tmp);
						tmp[0] = ';';
						strcat(tmp2 , tmp);
						tmp[0] = '\n';
 						strcat(tmp2 , tmp);
 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 780 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d statement : RETURN expression SEMICOLON\n\n",line_count);
						char tmp[8];
						tmp[0]='r';tmp[1]='e';tmp[2]='t';tmp[3]='u';tmp[4]='r';tmp[5]='n';tmp[6]=' ';tmp[7]='\0';
						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+9);
						strcpy(tmp2 , tmp);
						strcat(tmp2 , (yyvsp[-1].args).mystr);
						tmp[0]=';';tmp[1]='\0';
						strcat(tmp2 , tmp);
						tmp[0]='\n';tmp[1]='\0';
						strcat(tmp2 , tmp);
						(yyval.args).mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
            returnFlag = true;
            int flag = 1;
            (yyval.args).d_type = (yyvsp[-1].args).d_type;

            if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
              if((yyvsp[-1].args).intvalue != NULL){
                (yyval.args).d_type = "int";
                return_Type = "int ";
              }
              else if((yyvsp[-1].args).floatvalue != NULL){
                return_Type = "float";
                (yyval.args).d_type = "float ";
              }
              else if(strchr((yyvsp[-1].args).mystr, '[')!= NULL){
                char *tmp = (yyvsp[-1].args).mystr;
                int i = 0;
                while(tmp[i] != '['){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                (yyvsp[-1].args).mystr[i] = '\0';
                if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }

              }
              else if(strchr((yyvsp[-1].args).mystr, '(')!= NULL){
                char *tmp = (yyvsp[-1].args).mystr;
                int i = 0;
                while(tmp[i] != '('){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                (yyvsp[-1].args).mystr[i] = '\0';
                if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }

              }
              else{
                flag = 0;
              }
            }
					}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 840 "parser.y" /* yacc.c:1646  */
    {
              fprintf(logout,"At line no: %d expression_statement 	: SEMICOLON\n\n",line_count);
              char tmp[2];
              tmp[0]=';';tmp[1]='\0';
              char * tmp2 = (char *) malloc(1+1);
              strcpy(tmp2 , tmp);
              tmp[0]='\n';tmp[1]='\0';
              strcpy(tmp2 , tmp);
              (yyval.args).mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);
            }
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 851 "parser.y" /* yacc.c:1646  */
    {
              fprintf(logout,"At line no: %d expression_statement 	: expression SEMICOLON\n\n",line_count);
              char tmp[2];
              tmp[0]=';';tmp[1]='\0';
              char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+5);
              strcpy(tmp2 , (yyvsp[-1].args).mystr);
              strcat(tmp2 , tmp);
              tmp[0]='\n';tmp[1]='\0';
              strcat(tmp2 , tmp);
              (yyval.args).mystr = tmp2;

              tmp[0]='\n';tmp[1]='\0';
              char * ctmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).code)+5);

              strcpy(ctmp2 , (yyvsp[-1].args).code);
              tmp[0]='\n';tmp[1]='\0';
              strcat(ctmp2 , tmp);
              (yyval.args).code = ctmp2;

              fprintf(logout,"%s \n\n",(yyval.args).mystr);
            }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 873 "parser.y" /* yacc.c:1646  */
    {
              //symboltable->Insert($1.mystr , "ID");
              fprintf(logout,"At line no: %d variable : ID\n\n",line_count);
              (yyval.args) = (yyvsp[0].args);
              (yyval.args).code = "";

              (yyval.args).intvalue = NULL;
              (yyval.args).floatvalue = NULL;
              fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);
              if(symboltable->Lookup((yyvsp[0].args).mystr) == NULL){
                error_count++;
                fprintf(error, "Error %d at Line %d: Undeclared Variable: %s\n\n",error_count , line_count,(yyvsp[0].args).mystr);
              }
              else if(symboltable->Lookup((yyvsp[0].args).mystr)->getDataStructure() == "ARRAY"){
                error_count++;
                fprintf(error, "Error %d at Line %d: Expected [ after Array type\n\n",error_count , line_count);
              }
              else{
                  //cout<<"\n-->"<<symboltable->Lookup($1.mystr)->getName()<<" Data types  "<<symboltable->Lookup($1.mystr)->getDataType()<<endl;
                  if(symboltable->Lookup((yyvsp[0].args).mystr)->getDataType() == "int"){
                    (yyval.args).d_type = "int";
                  }
                  else if(symboltable->Lookup((yyvsp[0].args).mystr)->getDataType() == "float"){
                    (yyval.args).d_type = "float";
                  }
                  //return_Type = symboltable->Lookup($1.mystr)->getDataType();
              }
            }
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 901 "parser.y" /* yacc.c:1646  */
    {
             fprintf(logout,"At line no: %d variable : ID LTHIRD expression RTHIRD\n\n",line_count);
             (yyval.args).code = "";

             char tmp[2];
             tmp[0]='[';tmp[1]='\0';
             char * tmp2 = (char *) malloc(1+strlen((yyvsp[-3].args).mystr)+1+strlen((yyvsp[-1].args).mystr)+1);
             strcpy(tmp2 , (yyvsp[-3].args).mystr);
             strcat(tmp2 , tmp);
             strcat(tmp2 , (yyvsp[-1].args).mystr);
             tmp[0]=']';
             strcat(tmp2 , tmp);

             if((yyvsp[-1].args).floatvalue != NULL){
               error_count++;
               fprintf(error, "Error %d at Line %d: Non-integer Array Index \n\n",error_count , line_count);
             }
             if(symboltable->Lookup((yyvsp[-3].args).mystr)->getDataStructure() == ""){
                error_count++;
                fprintf(error, "Error %d at Line %d: %s value is not an array\n\n",error_count , line_count,(yyvsp[-3].args).mystr);
              }
              int flag = 1;
              if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
                if(strchr((yyvsp[-1].args).mystr, '[')!= NULL){
                  char *tmp = (yyvsp[-1].args).mystr;
                  int i = 0;
                  while(tmp[i] != '['){
                    //cout<<tmp[i]<<endl;
                    i++;
                  }
                  (yyvsp[-1].args).mystr[i] = '\0';
                  if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
                    ////cout<<endl<<i<<" -- HELOE\n";
                    flag = 0;
                  }
                  else{
                    if(symboltable->Lookup((yyvsp[-1].args).mystr)->getDataType() != "int "){
                      error_count++;
                      fprintf(error, "Error %d at Line %d: Non-integer Array Index \n\n",error_count , line_count);
                     }
                  }
                }
                else{
                  flag = 0;
                }
              }
              if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
                if(strchr((yyvsp[-1].args).mystr, '(')!= NULL){
                  char *tmp = (yyvsp[-1].args).mystr;
                  int i = 0;
                  while(tmp[i] != '('){
                    //cout<<tmp[i]<<endl;
                    i++;
                  }
                  (yyvsp[-1].args).mystr[i] = '\0';
                  if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
                    ////cout<<endl<<i<<" -- HELOE\n";
                    flag = 0;
                  }
                  else{
                    if(symboltable->Lookup((yyvsp[-1].args).mystr)->getDataType() == "void "){
                      error_count++;
                      fprintf(error, "Error %d at Line %d: Cannot call void function \n\n",error_count , line_count);
                     }
                    else if(symboltable->Lookup((yyvsp[-1].args).mystr)->getDataType() != "int "){
                      error_count++;
                      fprintf(error, "Error %d at Line %d: Non-integer Array Index \n\n",error_count , line_count);
                     }
                  }
                }
              }
              else{
                if(symboltable->Lookup((yyvsp[-1].args).mystr)->getDataType() != "int "){
                  error_count++;
                  fprintf(error, "Error %d at Line %d: Non-integer Array Index \n\n",error_count , line_count);
                 }
              }

               (yyval.args).mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);
           }
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 983 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d expression : logic_expression\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
            fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 988 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d expression : variable ASSIGNOP logic_expression\n\n",line_count);
            //$$.code  = $3.code;
            //$$.code += "MOV AX , "+$3.mystr+"\n";

            char ctmp[8];
            ctmp[0]='M';ctmp[1]='O';ctmp[2]='V';ctmp[3]=' ';ctmp[4]='A';ctmp[5]='X';ctmp[6]=',';ctmp[7]='\0';

            char * ctmp2 = (char *) malloc(1+16+strlen((yyvsp[-2].args).code)+strlen((yyvsp[0].args).code)+1);
            strcpy(ctmp2 , (yyvsp[0].args).code);
            strcat(ctmp2 , (yyvsp[-2].args).code);

            strcat(ctmp2 , ctmp);
            strcat(ctmp2 , (yyvsp[0].args).mystr);
            ctmp[0]='\n';ctmp[1]='\0';
            strcat(ctmp2 , ctmp);

            ctmp[0]='M';ctmp[1]='O';ctmp[2]='V';ctmp[3]=' ';ctmp[4]='\0';
            strcat(ctmp2 , ctmp);
            strcat(ctmp2 , (yyvsp[-2].args).mystr);
            ctmp[0]=',';ctmp[1]='A';ctmp[2]='X';ctmp[3]='\n';ctmp[4]='\0';
            strcat(ctmp2 , ctmp);


            (yyval.args).code = ctmp2;

            char tmp[2];
						tmp[0]='=';tmp[1]='\0';
						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+strlen((yyvsp[0].args).mystr)+1);
						strcpy(tmp2 , (yyvsp[-2].args).mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , (yyvsp[0].args).mystr);
            int flag = 1;

            if(symboltable->Lookup((yyvsp[-2].args).mystr) == NULL){
              if(strchr((yyvsp[-2].args).mystr, '[')!= NULL){
                char *tmp = (yyvsp[-2].args).mystr;
                int i = 0;
                while(tmp[i] != '['){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                (yyvsp[-2].args).mystr[i] = '\0';
                if(symboltable->Lookup((yyvsp[-2].args).mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }
              }
              else{
                flag = 0;
              }
            }
            if(symboltable->Lookup((yyvsp[0].args).mystr) == NULL){
              if(strchr((yyvsp[0].args).mystr, '(')!= NULL){
                char *tmp = (yyvsp[0].args).mystr;
                int i = 0;
                while(tmp[i] != '('){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                (yyvsp[0].args).mystr[i] = '\0';
                if(symboltable->Lookup((yyvsp[0].args).mystr) == NULL){
                  //cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }
                else{
                  //cout<<"\n FOUND VOID FUNC -"<<symboltable->Lookup($3.mystr)->getDataType()<<"\n\n";
                  if(symboltable->Lookup((yyvsp[0].args).mystr)->getDataType() == "void "){
                    error_count++;
                    fprintf(error, "Error %d at Line %d: Cannot Call void Function for assignment\n\n",error_count , line_count);
                   }
                }
              }
              else if(strchr((yyvsp[0].args).mystr, '[')!= NULL){
                char *tmp = (yyvsp[0].args).mystr;
                int i = 0;
                while(tmp[i] != '['){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                (yyvsp[0].args).mystr[i] = '\0';
                if(symboltable->Lookup((yyvsp[0].args).mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }
              }
              else{
                flag = 0;
              }
            }
            if(flag == 1){
              SymbolInfo *sym = symboltable->Lookup((yyvsp[-2].args).mystr);
              SymbolInfo *sym2 = symboltable->Lookup((yyvsp[0].args).mystr);
              if((yyvsp[0].args).intvalue == NULL && (yyvsp[0].args).floatvalue == NULL){
                if(sym->getDataType()== "int " && sym2->getDataType() == "float "){
                  error_count++;
                  fprintf(error, "Error %d at Line %d: Type Mismatch\n\n",error_count , line_count);
                }
              }
              ////cout<<"\n  -- sth"<<$3.floatvalue<<endl;
              if((yyvsp[0].args).floatvalue !=NULL && symboltable->Lookup((yyvsp[-2].args).mystr)->getDataType() != "float "){
                error_count++;
                fprintf(error, "Error %d at Line %d: Type Mismatch\n\n",error_count , line_count);
              }
              if((yyvsp[0].args).intvalue !=NULL && symboltable->Lookup((yyvsp[-2].args).mystr)->getDataType() != "int "){
                error_count++;
                fprintf(error, "Error %d at Line %d: Type Mismatch\n\n",error_count , line_count);
              }
            }
            else{
                //cout<<"Flag set to 0\n";
                if((yyvsp[0].args).floatvalue != NULL && symboltable->Lookup((yyvsp[-2].args).mystr)!= NULL && symboltable->Lookup((yyvsp[-2].args).mystr)->getDataType() != "int"){
                  error_count++;
                  fprintf(error, "Error %d at Line %d: Type Mismatch\n\n",error_count , line_count);
                }
            }
          	(yyval.args).mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1108 "parser.y" /* yacc.c:1646  */
    {
				 			fprintf(logout,"At line no: %d logic_expression : rel_expression\n\n",line_count);
							(yyval.args) = (yyvsp[0].args);
            fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
						}
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1113 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d logic_expression : rel_expression LOGICOP rel_expression\n\n",line_count);
 						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));
 						strcpy(tmp2 , (yyvsp[-2].args).mystr);
 						strcat(tmp2 , (yyvsp[-1].args).mystr);
 						strcat(tmp2 , (yyvsp[0].args).mystr);
 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					 }
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1123 "parser.y" /* yacc.c:1646  */
    {
							fprintf(logout,"At line no: %d rel_expression	: simple_expression\n\n",line_count);
							(yyval.args) = (yyvsp[0].args);
          	 fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					}
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1128 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d rel_expression	: simple_expression RELOP simple_expression\n\n",line_count);
						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));
						strcpy(tmp2 , (yyvsp[-2].args).mystr);
						strcat(tmp2 , (yyvsp[-1].args).mystr);
						strcat(tmp2 , (yyvsp[0].args).mystr);
						(yyval.args).mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1138 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d simple_expression : term\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);

            fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					}
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1144 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d simple_expression : simple_expression ADDOP term\n\n",line_count);
						char tmp[2];
						tmp[0]=(yyvsp[-1].args).charvalue; tmp[1]='\0';
						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+1+strlen((yyvsp[0].args).mystr));
						strcpy(tmp2 , (yyvsp[-2].args).mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , (yyvsp[0].args).mystr);
						(yyval.args).mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
            (yyval.args).d_type = (yyvsp[-2].args).d_type;

            int flag = 1;
            if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
              if((yyvsp[-1].args).intvalue != NULL){
                return_Type = "int";
                flag = 0;
              }
              else if((yyvsp[-1].args).floatvalue != NULL){
                return_Type = "float";
                flag = 0;
              }
              else if(strchr((yyvsp[-1].args).mystr, '[')!= NULL){
                char *tmp = (yyvsp[-1].args).mystr;
                int i = 0;
                while(tmp[i] != '['){
                  i++;
                }
                (yyvsp[-1].args).mystr[i] = '\0';
                if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
                  flag = 0;
                }

              }
              else if(strchr((yyvsp[-1].args).mystr, '(')!= NULL){
                char *tmp = (yyvsp[-1].args).mystr;
                int i = 0;
                while(tmp[i] != '('){
                  i++;
                }
                (yyvsp[-1].args).mystr[i] = '\0';
                if(symboltable->Lookup((yyvsp[-1].args).mystr) == NULL){
                  flag = 0;
                }

              }
              else{
                flag = 0;
              }
            }
            else{
              return_Type = symboltable->Lookup((yyvsp[-1].args).mystr)->getDataType();
            }

          }
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1200 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d term :	unary_expression\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
            fprintf(logout,"%s \n\n",(yyval.args).mystr);
          }
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1205 "parser.y" /* yacc.c:1646  */
    {

           fprintf(logout,"At line no: %d term :	term MULOP unary_expression\n\n",line_count);
					 char tmp[2];
					 tmp[0]=(yyvsp[-1].args).charvalue ;tmp[1]='\0';
					 char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+1+strlen((yyvsp[0].args).mystr));
					 strcpy(tmp2 , (yyvsp[-2].args).mystr);
					 strcat(tmp2 , tmp);
					 strcat(tmp2 , (yyvsp[0].args).mystr);

           if((yyvsp[-1].args).charvalue == '%'){
             if(((yyvsp[-2].args).intvalue != NULL && (yyvsp[0].args).intvalue == NULL) || ((yyvsp[-2].args).intvalue == NULL && (yyvsp[0].args).intvalue != NULL)){
              error_count++;
              fprintf(error, "Error %d at Line %d: Integer operands on modulus operator\n\n",error_count , line_count);

             }
          }
          else if((yyvsp[-1].args).charvalue == '*'){

            /* if(symboltable->Lookup($1.mystr) != NULL){
              cout<<$1.mystr<<"--HERE--"<<$3.mystr<<endl;
            }
            else{ */
              char ctmp[8];
              ctmp[0]='M';ctmp[1]='O';ctmp[2]='V';ctmp[3]=' ';ctmp[4]='A';ctmp[5]='X';ctmp[6]=',';ctmp[7]='\0';

              char * ctmp2 = (char *) malloc(1+strlen(ctmp)*4+strlen((yyvsp[-2].args).mystr)+strlen((yyvsp[0].args).mystr)+1);

              strcat(ctmp2 , ctmp);
              strcat(ctmp2 , (yyvsp[-2].args).mystr);
              ctmp[0]='\n';ctmp[1]='\0';
              strcat(ctmp2 , ctmp);

              ctmp[0]='M';ctmp[1]='O';ctmp[2]='V';ctmp[3]=' ';ctmp[4]='B';ctmp[5]='X';ctmp[6]=',';ctmp[7]='\0';
              strcat(ctmp2 , ctmp);
              strcat(ctmp2 , (yyvsp[0].args).mystr);
              ctmp[0]='\n';ctmp[1]='\0';
              strcat(ctmp2 , ctmp);

              ctmp[0]='M';ctmp[1]='U';ctmp[2]='L';ctmp[3]=' ';ctmp[4]='B';ctmp[5]='X';ctmp[6]='\0';ctmp[7]='\0';
              strcat(ctmp2 , ctmp);
              ctmp[0]='\n';ctmp[1]='\0';
              strcat(ctmp2 , ctmp);

              ctmp[0]='M';ctmp[1]='O';ctmp[2]='V';ctmp[3]=' ';ctmp[4]='\0';
              strcat(ctmp2 , ctmp);
              strcat(ctmp2 , newTemp());

              /* char *t = new char[4];
              strcpy(t,"t");
            	char b[3];
            	sprintf(b,"%d", tempCount);
            	tempCount++;
            	strcat(t,b);
              //$$.code = tvar;
              strcat(ctmp2 , t); */

              ctmp[0]=',';ctmp[1]='A';ctmp[2]='X';ctmp[3]='\n';ctmp[4]='\0';
              strcat(ctmp2 , ctmp);
              ctmp[0]='\n';ctmp[1]='\0';
              strcat(ctmp2 , ctmp);

              (yyval.args).code = ctmp2;
              cout<<(yyval.args).code;
              cout<<"---here---\n";

            //}




          }
          else if((yyvsp[-1].args).charvalue == '/'){

          }

					 (yyval.args).mystr = tmp2;
					 fprintf(logout,"%s \n\n",tmp2);
				 }
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1285 "parser.y" /* yacc.c:1646  */
    {
							fprintf(logout,"At line no: %d unary_expression : ADDOP unary_expression\n\n",line_count);
							char tmp[2];
							tmp[0]=(yyvsp[-1].args).charvalue;tmp[1]='\0';
							char * tmp2 = (char *) malloc(1+strlen((yyvsp[0].args).mystr));
							strcat(tmp2 , tmp);
							strcat(tmp2 , (yyvsp[0].args).mystr);
							(yyval.args).mystr = tmp2;
							fprintf(logout,"%s \n\n",tmp2);
					}
#line 2911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1295 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d unary_expression : NOT unary_expression\n\n",line_count);
						 char tmp[2];
 						 tmp[0]='!';tmp[1]='\0';
 						char * tmp2 = (char *) malloc(1+strlen((yyvsp[0].args).mystr)+1);
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[0].args).mystr);
 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					 }
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1305 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d unary_expression : factor\n\n",line_count);
						 (yyval.args) = (yyvsp[0].args);
             fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					 }
#line 2936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1311 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d factor	: variable\n\n",line_count);
					(yyval.args) = (yyvsp[0].args);
					fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
				}
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1316 "parser.y" /* yacc.c:1646  */
    {

					fprintf(logout,"At line no: %d factor	: ID LPAREN argument_list RPAREN\n\n",line_count);
					char tmp[2];
					tmp[0]='(';tmp[1]='\0';
					char * tmp2 = (char *) malloc(1+strlen((yyvsp[-3].args).mystr)+1+strlen((yyvsp[-1].args).mystr)+1);
					strcpy(tmp2 , (yyvsp[-3].args).mystr);
					strcat(tmp2 , tmp);
					strcat(tmp2 , (yyvsp[-1].args).mystr);
					tmp[0] = ')';
					strcat(tmp2 , tmp);
          SymbolInfo* sym = symboltable->Lookup((yyvsp[-3].args).mystr);
          struct node * head = (yyvsp[-1].args).arg_list;
          if(symboltable->Lookup((yyvsp[-3].args).mystr) == NULL){
              error_count ++;
              fprintf(error, "Error %d at Line %d: Undefined function %s\n\n",error_count , line_count, (yyvsp[-3].args).mystr);
          }
          else{
            int arg_no = sym->getArgNumber();
            while(head!= NULL){
              if(arg_no==0){
                error_count ++;
                fprintf(error, "Error %d at Line %d: Too many arguments\n\n",error_count , line_count);
                break;
              }
              SymbolInfo* s = sym->getArgument();
              if(symboltable->Lookup(head->name) != NULL){
                if(symboltable->Lookup(head->name)->getDataType() != s->getType()){
                  error_count ++;
                  fprintf(error, "Error %d at Line %d: Wrong type of parameters\n\n",error_count , line_count);
                }
              }
              head = head->arg_list;
              arg_no--;
            }
          }

					(yyval.args).mystr = tmp2;
          fprintf(logout,"%s \n\n",tmp2);
        }
#line 2991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1356 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d factor : LPAREN expression RPAREN\n\n",line_count);
					char tmp[2];
					tmp[0]='(';tmp[1]='\0';
					char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+2);
					strcat(tmp2 , tmp);
					strcat(tmp2 , (yyvsp[-1].args).mystr);
					tmp[0] = ')';
					strcat(tmp2 , tmp);
					(yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);
				}
#line 3008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1368 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d factor : CONST_INT\n\n",line_count);
					char tmp[2];
					sprintf(tmp, "%d", (yyvsp[0].args).intvalue);
					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);
          (yyval.args).d_type = "int";

          (yyval.args).arg_list = NULL;
	        (yyval.args).mystr = tmp2;
          (yyval.args).code = "";
					fprintf(logout,"%s \n\n",tmp2);
				}
#line 3026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1381 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d factor : CONST_FLOAT\n\n",line_count);

          char* str=NULL;
          int len = asprintf(&str, "%g", (yyvsp[0].args).floatvalue);
          if (len == -1)
            fprintf(error, "Error %d at Line %d: Error converting float: %m\n",error_count , line_count);
          else
            fprintf(logout,"%s \n\n",str);
          char * tmp2 = (char *) malloc(1+strlen(str));
					strcpy(tmp2 , str);
					(yyval.args) = (yyvsp[0].args);

          (yyval.args).mystr = tmp2;
          (yyval.args).code = tmp2;
          free(str);
				}
#line 3048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1398 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d factor : variable INCOP\n\n",line_count);
					char tmp[3];
					tmp[0] = '+';tmp[1]='+';tmp[2]='\0';
					char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+1);
					strcpy(tmp2 , (yyvsp[-1].args).mystr);
					strcat(tmp2 , tmp);
					(yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);
				}
#line 3063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1408 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d factor : variable DECOP\n\n",line_count);
					char tmp[3];
					tmp[0] = '-';tmp[1]='-';tmp[2]='\0';
					char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+1);
					strcpy(tmp2 , (yyvsp[-1].args).mystr);
					strcat(tmp2 , tmp);
					(yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);
				}
#line 3078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1419 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d argument_list : arguments\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

          }
#line 3089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1425 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d argument_list :\n\n",line_count);
            (yyval.args).mystr = "";
					}
#line 3098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1430 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d arguments : arguments COMMA logic_expression\n\n",line_count);
						char tmp[2];
						tmp[0] = ',';tmp[1] = '\0';
						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+2+strlen((yyvsp[0].args).mystr));
						strcpy(tmp2 , (yyvsp[-2].args).mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , (yyvsp[0].args).mystr);
            (yyval.args).mystr = tmp2;
            fprintf(logout,"%s \n\n",tmp2);
            struct node * item = (struct node *) malloc(1+sizeof(struct node));
            item->name = (yyvsp[0].args).mystr;

            if(symboltable->Lookup((yyvsp[0].args).mystr) != NULL){
              item->d_type = (char *) symboltable->Lookup((yyvsp[0].args).mystr)->getDataType().c_str();
            }
            item->arg_list = (yyvsp[-2].args).arg_list;
            (yyval.args).arg_list = item;
					}
#line 3122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1449 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d arguments : logic_expression\n\n",line_count);

            (yyval.args).arg_list  = (struct node *) malloc(1+sizeof(struct node));
            (yyval.args).arg_list->name = (yyvsp[0].args).mystr;

            if(symboltable->Lookup((yyvsp[0].args).mystr) != NULL){
              (yyval.args).arg_list->d_type = (char *) symboltable->Lookup((yyvsp[0].args).mystr)->getDataType().c_str();
            }
            else{
              if((yyvsp[0].args).floatvalue != NULL){
                (yyval.args).arg_list->d_type = "float";
              }
              else if((yyvsp[0].args).intvalue != NULL){
                (yyval.args).arg_list->d_type = "int";
              }
            }

            (yyval.args).arg_list->arg_list = NULL;
            (yyval.args).mystr = (yyvsp[0].args).mystr;
            fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					}
#line 3149 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3153 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1472 "parser.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
  symboltable->EnterScope();
  FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		fprintf(logout,"At line no: %d Cannot Open Input File.\n\n",line_count);
		exit(1);
	}

	yyin=fp;
	yyparse();
 fclose(logout);
 fclose(error);
 fclose(code);

	return 0;
}
