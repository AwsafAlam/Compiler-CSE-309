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
/* #define YYSTYPE double      /* yyparse() stack type */

using namespace std;

int yylex(void);
extern FILE *yyin;
extern int line_count;
extern int error_count;
vector<char *> vec;

 FILE * logout = fopen("log.txt","w");
 FILE *error= fopen("error.txt","w");
SymbolTable * symboltable = new SymbolTable(30);

void yyerror(const char *s){
	fprintf(logout,"At line no: %d  %s\n",line_count,s);
  printf("At line no %d : %s\n",line_count,s);

}



#line 97 "y.tab.c" /* yacc.c:339  */

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
#line 34 "parser.y" /* yacc.c:355  */

    struct node {
        char * mystr;
        char charvalue;
        int intvalue;
        float floatvalue;
        char * name;
        char * d_type;
        struct node * arg_list;
    };

#line 139 "y.tab.c" /* yacc.c:355  */

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
#line 45 "parser.y" /* yacc.c:355  */

  struct node args;

#line 245 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

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
       0,    63,    63,    73,    89,    97,   103,   108,   116,   141,
     165,   199,   250,   276,   298,   319,   333,   333,   356,   356,
     380,   402,   416,   431,   446,   464,   491,   507,   533,   540,
     554,   560,   566,   572,   596,   622,   644,   665,   689,   710,
     726,   746,   766,   795,   802,   826,   833,   849,   856,   873,
     881,   899,   906,   929,   943,   958,   966,   972,  1013,  1031,
    1049,  1074,  1089,  1107,  1118,  1123,  1147
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
  "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "$@1", "$@2", "var_declaration", "type_specifier",
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

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,   -67,   -67,   -67,    11,    30,   -67,   -67,   -67,   -67,
      15,   -67,   -67,    -7,    -9,    91,    31,    36,   -67,   -17,
     -13,    55,    33,    38,    32,   -67,   -67,    -4,    30,   -67,
     -67,    72,    80,    48,   -67,   -67,    81,    56,   -67,   101,
      -1,   -67,   101,    75,    84,    94,   101,   101,    99,   -67,
     -67,   -67,   112,    52,   -67,   -67,    45,    77,   -67,    90,
      46,   118,   -67,   -67,   -67,   -67,   -67,     0,   -67,   101,
     101,   107,   101,     7,   101,    83,   -67,   120,    89,   -67,
     -67,   101,   -67,   -67,   -67,   101,   101,   101,   101,   -67,
     111,    96,    92,   -67,   113,     7,   115,   -67,   116,   -67,
     -67,   118,   130,   -67,   -67,   101,   -67,    80,   101,    80,
      93,   -67,   135,   121,   -67,   -67,    80,    80,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,    22,    23,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    26,     0,     0,     0,     0,    20,     0,
       0,    15,     0,    24,    16,     9,    10,     0,     0,    14,
      27,     0,     0,     0,     8,    11,    13,     0,    60,     0,
      41,    59,     0,     0,     0,     0,     0,     0,     0,    39,
      32,    30,     0,     0,    28,    31,    56,     0,    43,    45,
      47,    49,    51,    55,    19,    12,    25,    56,    53,    64,
       0,     0,     0,     0,     0,     0,    54,     0,    26,    17,
      29,     0,    61,    62,    40,     0,     0,     0,     0,    66,
       0,    63,     0,    58,     0,     0,     0,    38,     0,    44,
      46,    50,    48,    52,    57,     0,    42,     0,     0,     0,
       0,    65,    35,     0,    36,    37,     0,     0,    34,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   137,   -67,   -67,   -67,    -2,   -67,   -67,
      63,     4,   -67,   -67,   -47,   -52,   -39,   -41,   -66,    58,
      53,    59,   -37,   -67,   -67,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    50,    32,    33,
      51,    52,    14,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    90,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    71,    68,    89,    10,    75,    80,    27,    67,    10,
      76,    11,    15,    38,    39,    99,    40,    26,    69,    21,
      41,    95,    24,    28,    13,    35,    42,    17,    25,    92,
      67,    94,    36,    96,    16,    24,    18,    82,    83,   111,
      70,    34,    67,   108,    22,    23,    67,    67,    67,    67,
      47,   103,    49,    86,     1,     2,     3,    87,    38,    39,
     112,    40,   114,     9,    29,    41,    67,   113,     9,   118,
     119,    42,   -18,    43,    44,    30,     1,     2,     3,    31,
      81,    45,    82,    83,    46,    37,    38,    39,    64,    40,
      65,    24,    79,    41,    72,    47,    48,    49,    66,    42,
      85,    43,    44,    73,     1,     2,     3,    38,    39,    45,
      40,    19,    46,    74,    41,     1,     2,     3,    77,    24,
      42,    78,    84,    47,    48,    49,    88,    93,    97,    98,
      16,   104,   105,   107,   106,   109,   110,    86,   115,   116,
     102,   117,    12,   100,    47,   101
};

static const yytype_uint8 yycheck[] =
{
      39,    42,    39,    69,     0,    46,    53,    20,    47,     5,
      47,     0,    19,     6,     7,    81,     9,    19,    19,    15,
      13,    73,    39,    36,     9,    27,    19,    36,    45,    70,
      69,    72,    28,    74,    41,    39,    45,    37,    38,   105,
      41,    45,    81,    95,    13,     9,    85,    86,    87,    88,
      43,    88,    45,     7,    24,    25,    26,    11,     6,     7,
     107,     9,   109,     0,     9,    13,   105,   108,     5,   116,
     117,    19,    40,    21,    22,    42,    24,    25,    26,    41,
      35,    29,    37,    38,    32,    13,     6,     7,    40,     9,
       9,    39,    40,    13,    19,    43,    44,    45,    42,    19,
      10,    21,    22,    19,    24,    25,    26,     6,     7,    29,
       9,    20,    32,    19,    13,    24,    25,    26,    19,    39,
      19,     9,    45,    43,    44,    45,     8,    20,    45,     9,
      41,    20,    36,    20,    42,    20,    20,     7,    45,     4,
      87,    20,     5,    85,    43,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    26,    47,    48,    49,    50,    51,    56,
      57,     0,    49,     9,    58,    19,    41,    36,    45,    20,
      52,    57,    13,     9,    39,    45,    53,    20,    36,     9,
      42,    41,    54,    55,    45,    53,    57,    13,     6,     7,
       9,    13,    19,    21,    22,    29,    32,    43,    44,    45,
      53,    56,    57,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    40,     9,    42,    62,    68,    19,
      41,    63,    19,    19,    19,    63,    68,    19,     9,    40,
      60,    35,    37,    38,    45,    10,     7,    11,     8,    64,
      70,    71,    63,    20,    63,    61,    63,    45,     9,    64,
      65,    67,    66,    68,    20,    36,    42,    20,    61,    20,
      20,    64,    60,    63,    60,    45,     4,    20,    60,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    54,    53,    55,    53,
      56,    57,    57,    57,    58,    58,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       5,     6,     4,     3,     2,     1,     0,     4,     0,     3,
       3,     1,     1,     1,     3,     6,     1,     4,     1,     2,
       1,     1,     1,     7,     7,     5,     5,     5,     3,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
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
#line 64 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d start : program\n\n",line_count);
					(yyval.args) = (yyvsp[0].args);
					fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);
          fprintf(error,"Total Errors: %d\n\n",error_count);

				}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d program : program unit\n\n",line_count);

					char * tmp = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));
					char tmp2[2];
					tmp2[0]='\n';tmp2[1]='\0';

					strcpy(tmp , (yyvsp[-1].args).mystr);
					strcat(tmp , tmp2);
					strcat(tmp , (yyvsp[0].args).mystr);

					(yyval.args).mystr = tmp;
					fprintf(logout,"%s \n\n",tmp);


				}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d program : | unit\n\n",line_count);
					(yyval.args) = (yyvsp[0].args);
					fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);

				}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d unit : var_declaration\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);

					 }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 103 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d unit : func_declaration\n\n",line_count);
						 (yyval.args) = (yyvsp[0].args);
						 fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					 }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 108 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d unit : func_definition\n\n",line_count);
						 (yyval.args) = (yyvsp[0].args);
						 fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

					 }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "parser.y" /* yacc.c:1646  */
    {

               fprintf(logout,"At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n",line_count);

               char tmp[2];
               tmp[0]='(';tmp[1]='\0';

               char * tmp2 = (char *) malloc(1+strlen((yyvsp[-5].args).mystr)+strlen((yyvsp[-4].args).mystr)+1+strlen((yyvsp[-2].args).mystr)+2);

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
               symboltable->Insert((yyvsp[-4].args).mystr , "ID","FUNCTION");
               SymbolInfo *s = symboltable->Lookup((yyvsp[-4].args).mystr);
               s->setDataType((yyvsp[-5].args).mystr);

             }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 141 "parser.y" /* yacc.c:1646  */
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
               symboltable->Insert((yyvsp[-3].args).mystr , "ID", "FUNCTION");
               SymbolInfo *s = symboltable->Lookup((yyvsp[-3].args).mystr);
               s->setDataType((yyvsp[-4].args).mystr);
             }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 165 "parser.y" /* yacc.c:1646  */
    {
				 		fprintf(logout,"At line no: %d func_definition : type_specifier ID LPAREN  RPAREN compound_statement\n\n",line_count);
						char tmp[2];
 						tmp[0]='(';tmp[1]='\0';

 						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-4].args).mystr)+strlen((yyvsp[-3].args).mystr)+2+strlen((yyvsp[0].args).mystr));

 						strcpy(tmp2 , (yyvsp[-4].args).mystr);
 						strcat(tmp2 , (yyvsp[-3].args).mystr);
 						strcat(tmp2 , tmp);
 						tmp[0] = ')';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , (yyvsp[0].args).mystr);


 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
            SymbolInfo *s = symboltable->Lookup((yyvsp[-3].args).mystr);
            if(s != NULL){
                if(s->getDataType() != (yyvsp[-4].args).mystr){
                  error_count++;
                  fprintf(error,"Error %d at line %d: Conflicting return-type for %s\n\n",error_count,line_count,(yyvsp[-3].args).mystr);

                }
            }
            else{
              symboltable->Insert((yyvsp[-3].args).mystr , "ID","FUNCTION");
              SymbolInfo *sym = symboltable->Lookup((yyvsp[-3].args).mystr);
              //cout<<sym->getName();
              sym->setDataType((yyvsp[-4].args).mystr);
            }


					 }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 199 "parser.y" /* yacc.c:1646  */
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
						 symboltable->Insert((yyvsp[-4].args).mystr , "ID","FUNCTION");
             SymbolInfo *s = symboltable->Lookup((yyvsp[-4].args).mystr);
             if(s != NULL){
                 if(s->getDataType() != (yyvsp[-5].args).mystr){
                   error_count++;
                   fprintf(error,"Error %d at line %d: Conflicting return-type for %s\n\n",error_count,line_count,(yyvsp[-4].args).mystr);

                 }
             }
             else{
               symboltable->Insert((yyvsp[-4].args).mystr , "ID","FUNCTION");
               SymbolInfo *sym = symboltable->Lookup((yyvsp[-4].args).mystr);
               cout<<sym->getName();
               sym->setDataType((yyvsp[-5].args).mystr);
             }

             struct node * head = (yyvsp[-2].args).arg_list;

              while(head!= NULL){
                cout<<head->name<<" - "<<head->d_type<<endl;
                if(head->name == NULL){
                  s->addArgument("" , head->d_type , "");
                }
                else{
                  s->addArgument(head->name , head->d_type , "");
                }

                head = head->arg_list;
              }
			 		}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 250 "parser.y" /* yacc.c:1646  */
    {
              fprintf(logout,"At line no: %d parameter_list  : parameter_list COMMA type_specifier ID\n\n",line_count);
              char tmp[2];
              tmp[0]=',';tmp[1]='\0';

              char * tmp2 = (char *) malloc(1+strlen((yyvsp[-3].args).mystr)+1+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));

              strcpy(tmp2 , (yyvsp[-3].args).mystr);
              strcat(tmp2 , tmp);
              strcat(tmp2 , (yyvsp[-1].args).mystr);
              strcat(tmp2 , (yyvsp[0].args).mystr);

              symboltable->Insert((yyvsp[0].args).mystr , "ID","PARAMETER");
              SymbolInfo *s = symboltable->Lookup((yyvsp[0].args).mystr);
              s->setDataType((yyvsp[-1].args).mystr);

              (yyval.args).mystr = tmp2;
              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = (yyvsp[0].args).mystr;
              item->d_type = (yyvsp[-1].args).mystr;
              item->arg_list = (yyvsp[-3].args).arg_list;

              (yyval.args).arg_list = item;

              fprintf(logout,"%s \n\n",tmp2);
            }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 276 "parser.y" /* yacc.c:1646  */
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

            }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 298 "parser.y" /* yacc.c:1646  */
    {

              fprintf(logout,"At line no: %d parameter_list : type_specifier ID\n\n",line_count);
              char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));

              strcpy(tmp2 , (yyvsp[-1].args).mystr);
              strcat(tmp2 , (yyvsp[0].args).mystr);
              symboltable->Insert((yyvsp[0].args).mystr , "ID","PARAM");
              SymbolInfo *s = symboltable->Lookup((yyvsp[0].args).mystr);
              s->setDataType((yyvsp[-1].args).mystr);

              (yyval.args).mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);

              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = (yyvsp[0].args).mystr;
              item->d_type = (yyvsp[-1].args).mystr;
              item->arg_list = NULL;
              (yyval.args).arg_list = item;

            }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 319 "parser.y" /* yacc.c:1646  */
    {
              fprintf(logout,"At line no: %d parameter_list : type_specifier\n\n",line_count);
              fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
              (yyval.args).mystr = (yyvsp[0].args).mystr;

              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = "";
              item->d_type = (yyvsp[0].args).mystr;
              item->arg_list = NULL;

              (yyval.args).arg_list = item;
            }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 333 "parser.y" /* yacc.c:1646  */
    {symboltable->EnterScope();}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 333 "parser.y" /* yacc.c:1646  */
    {

							fprintf(logout,"At line no: %d compound_statement : LCURL statements RCURL\n\n",line_count);
							char tmp[2];
							tmp[0]='{';tmp[1]='\0';

							char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+2);

							strcat(tmp2 , tmp);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							strcat(tmp2 , (yyvsp[-1].args).mystr);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							tmp[0] = '}';
							strcat(tmp2 , tmp);


							(yyval.args).mystr = tmp2;
							fprintf(logout,"%s \n\n",tmp2);
							symboltable->PrintAllScopes();
							symboltable->ExitScope();
						}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 356 "parser.y" /* yacc.c:1646  */
    {symboltable->EnterScope();}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 356 "parser.y" /* yacc.c:1646  */
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
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 380 "parser.y" /* yacc.c:1646  */
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
				//cout<<"--- > "<<vec.size()<<endl;
        vec.clear();
			}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 402 "parser.y" /* yacc.c:1646  */
    {

				fprintf(logout,"At line no: %d type_specifier:INT\n\n",line_count);

				char tmp[5];
				tmp[0]='i';tmp[1]='n';tmp[2]='t';tmp[3]=' ';tmp[4]='\0';

				char * tmp2 = (char *) malloc(1+strlen(tmp));
				strcat(tmp2 , tmp);

				(yyval.args).mystr = tmp2;
				fprintf(logout,"%s \n\n",tmp2);

				}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 416 "parser.y" /* yacc.c:1646  */
    {

					fprintf(logout,"At line no: %d type_specifier : FLOAT\n\n",line_count);

					char tmp[7];
					tmp[0]='f';tmp[1]='l';tmp[2]='o';tmp[3]='a';tmp[4]='t';tmp[5]='   ';tmp[6]='\0';

					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);


					(yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 431 "parser.y" /* yacc.c:1646  */
    {

					fprintf(logout,"At line no: %d type_specifier : VOID\n\n",line_count);
					char tmp[6];
					tmp[0]='v';tmp[1]='o';tmp[2]='i';tmp[3]='d';tmp[4]=' ';tmp[5]='\0';

					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);


					(yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);
				}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 446 "parser.y" /* yacc.c:1646  */
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
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 464 "parser.y" /* yacc.c:1646  */
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
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 491 "parser.y" /* yacc.c:1646  */
    {

						fprintf(logout,"At line no: %d declaration_list : ID\n\n",line_count);
						fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);

						(yyval.args) = (yyvsp[0].args);
            if(symboltable->Lookup((yyval.args).mystr) != NULL){
              error_count++;
              fprintf(error, "Error %d at Line %d: Multiple declarations of the same variable: %s\n\n",error_count , line_count,(yyvsp[0].args).mystr);
            }
            else{
              symboltable->Insert((yyval.args).mystr , "ID","");
              vec.push_back((yyvsp[0].args).mystr);

            }
					}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 507 "parser.y" /* yacc.c:1646  */
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
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 533 "parser.y" /* yacc.c:1646  */
    {
						//
						fprintf(logout,"At line no: %d statements : statement \n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

					 }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 540 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d statements :| statements statement \n\n",line_count);

 						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));

 						strcpy(tmp2 , (yyvsp[-1].args).mystr);
 						strcat(tmp2 , (yyvsp[0].args).mystr);

 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					 }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 554 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d statement : var_declaration\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

					}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 560 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d statement : expression_statement\n\n",line_count);
						 (yyval.args) = (yyvsp[0].args);
 						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

					 }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 566 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d statement : compound_statement\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

					}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 572 "parser.y" /* yacc.c:1646  */
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
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 596 "parser.y" /* yacc.c:1646  */
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
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 622 "parser.y" /* yacc.c:1646  */
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
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 644 "parser.y" /* yacc.c:1646  */
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
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 665 "parser.y" /* yacc.c:1646  */
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
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 689 "parser.y" /* yacc.c:1646  */
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
					}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 710 "parser.y" /* yacc.c:1646  */
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
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 726 "parser.y" /* yacc.c:1646  */
    {

              fprintf(logout,"At line no: %d expression_statement 	: expression SEMICOLON\n\n",line_count);
              char tmp[2];
              tmp[0]=';';tmp[1]='\0';

              char * tmp2 = (char *) malloc(1+strlen((yyvsp[-1].args).mystr)+1);

              strcpy(tmp2 , (yyvsp[-1].args).mystr);
              strcat(tmp2 , tmp);
              tmp[0]='\n';tmp[1]='\0';
              strcat(tmp2 , tmp);


              (yyval.args).mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);

            }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 746 "parser.y" /* yacc.c:1646  */
    {
              //symboltable->Insert($1.mystr , "ID");
              fprintf(logout,"At line no: %d variable : ID\n\n",line_count);
              (yyval.args) = (yyvsp[0].args);
              fprintf(logout,"%s\n\n",(yyvsp[0].args).mystr);
              if(symboltable->Lookup((yyvsp[0].args).mystr) == NULL){
                error_count++;
                fprintf(error, "Error %d at Line %d: Undeclared Variable: %s\n\n",error_count , line_count,(yyvsp[0].args).mystr);

              }
              else if(symboltable->Lookup((yyvsp[0].args).mystr)->getDataStructure() == "ARRAY"){
                error_count++;
                fprintf(error, "Error %d at Line %d: Type Mismatch\n\n",error_count , line_count);

              }
              else{
                  cout<<"Data types  "<<symboltable->Lookup((yyvsp[0].args).mystr)->getDataType()<<endl;
              }

            }
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 766 "parser.y" /* yacc.c:1646  */
    {

             fprintf(logout,"At line no: %d variable : ID LTHIRD expression RTHIRD\n\n",line_count);
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
                fprintf(error, "Error %d at Line %d: Type Mismatch\n\n",error_count , line_count);

              }
               (yyval.args).mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);

           }
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 795 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d expression : logic_expression\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
            (yyval.args).floatvalue = (yyvsp[0].args).floatvalue;

						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					}
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 802 "parser.y" /* yacc.c:1646  */
    {

						fprintf(logout,"At line no: %d expression : variable ASSIGNOP logic_expression\n\n",line_count);
						char tmp[2];
						tmp[0]='=';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+strlen((yyvsp[0].args).mystr)+1);

						strcpy(tmp2 , (yyvsp[-2].args).mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , (yyvsp[0].args).mystr);
            if(symboltable->Lookup((yyvsp[-2].args).mystr) != NULL){
              //cout<<" <> "<<$1.mystr<<" "<<symboltable->Lookup($1.mystr)->getDataType()<<" "<<symboltable->Lookup($1.mystr)->getDataStructure()<<endl;
              if((yyvsp[0].args).floatvalue !=NULL && symboltable->Lookup((yyvsp[-2].args).mystr)->getDataType() != "float"){
                error_count++;
                fprintf(error, "Error %d at Line %d: Type Mismatch\n\n",error_count , line_count);

              }
            }
          	(yyval.args).mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 826 "parser.y" /* yacc.c:1646  */
    {
				 			fprintf(logout,"At line no: %d logic_expression : rel_expression\n\n",line_count);
							(yyval.args) = (yyvsp[0].args);
              //$$.floatvalue = $1.floatvalue;

 						 fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
						}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 833 "parser.y" /* yacc.c:1646  */
    {

						 fprintf(logout,"At line no: %d logic_expression : rel_expression LOGICOP rel_expression\n\n",line_count);

 						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));

 						strcpy(tmp2 , (yyvsp[-2].args).mystr);
 						strcat(tmp2 , (yyvsp[-1].args).mystr);
 						strcat(tmp2 , (yyvsp[0].args).mystr);


 						(yyval.args).mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					 }
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 849 "parser.y" /* yacc.c:1646  */
    {
							fprintf(logout,"At line no: %d rel_expression	: simple_expression\n\n",line_count);
							(yyval.args) = (yyvsp[0].args);
              //$$.floatvalue = $1.floatvalue;

 						 fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);
					}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 856 "parser.y" /* yacc.c:1646  */
    {

						fprintf(logout,"At line no: %d rel_expression	: simple_expression RELOP simple_expression\n\n",line_count);

						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+strlen((yyvsp[-1].args).mystr)+strlen((yyvsp[0].args).mystr));

						strcpy(tmp2 , (yyvsp[-2].args).mystr);
						strcat(tmp2 , (yyvsp[-1].args).mystr);
						strcat(tmp2 , (yyvsp[0].args).mystr);


						(yyval.args).mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 873 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d simple_expression : term\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
            (yyval.args).floatvalue = (yyvsp[0].args).floatvalue;

            fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

					}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 881 "parser.y" /* yacc.c:1646  */
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
					}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 899 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d term :	unary_expression\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
            (yyval.args).floatvalue = (yyvsp[0].args).floatvalue;
            fprintf(logout,"%s \n\n",(yyval.args).mystr);

          }
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 906 "parser.y" /* yacc.c:1646  */
    {
					 fprintf(logout,"At line no: %d term :	term MULOP unary_expression\n\n",line_count);

					 char tmp[2];
					 tmp[0]=(yyvsp[-1].args).charvalue ;tmp[1]='\0';

					 char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+1+strlen((yyvsp[0].args).mystr));

					 strcpy(tmp2 , (yyvsp[-2].args).mystr);
					 strcat(tmp2 , tmp);
					 strcat(tmp2 , (yyvsp[0].args).mystr);
           //HAVE A LOOK
           if(((yyvsp[-2].args).intvalue != NULL && (yyvsp[0].args).intvalue == NULL) || ((yyvsp[-2].args).intvalue == NULL && (yyvsp[0].args).intvalue != NULL)){
            error_count++;
            fprintf(error, "Error %d at Line %d: Invalid operands to %s\n\n",error_count , line_count,tmp);

          }

					 (yyval.args).mystr = tmp2;
					 fprintf(logout,"%s \n\n",tmp2);
				 }
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 929 "parser.y" /* yacc.c:1646  */
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
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 943 "parser.y" /* yacc.c:1646  */
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
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 958 "parser.y" /* yacc.c:1646  */
    {
						 fprintf(logout,"At line no: %d unary_expression : factor\n\n",line_count);
						 (yyval.args) = (yyvsp[0].args);
             fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

					 }
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 966 "parser.y" /* yacc.c:1646  */
    {
					fprintf(logout,"At line no: %d factor	: variable\n\n",line_count);
					(yyval.args) = (yyvsp[0].args);
					fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

				}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 972 "parser.y" /* yacc.c:1646  */
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
          while(head!= NULL){
            //cout<<"HAVE A LOOK\n";

            SymbolInfo* s = sym->getArgument();
            cout<<s->getName()<<"-"<<s->getType()<<endl;

            if(symboltable->Lookup(head->name) != NULL){
              if(symboltable->Lookup(head->name)->getDataType() != s->getType()){
                error_count ++;
                fprintf(error, "Error %d at Line %d: Wrong type of parameters\n\n",error_count , line_count);
              }
            }
            /* cout<<head->d_type<<"-"<<symboltable->Lookup(head->name)->getDataType()<<" -- matches -- "; */

          //  s->addArgument(head->name , head->d_type , "");
            head = head->arg_list;
          }
					(yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1013 "parser.y" /* yacc.c:1646  */
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
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1031 "parser.y" /* yacc.c:1646  */
    {

					fprintf(logout,"At line no: %d factor : CONST_INT\n\n",line_count);

					char tmp[2];
					sprintf(tmp, "%d", (yyvsp[0].args).intvalue);
					char * tmp2 = (char *) malloc(1+strlen(tmp));

					strcat(tmp2 , tmp);
          (yyval.args).floatvalue = NULL;
          (yyval.args).intvalue = (yyvsp[0].args).intvalue;
          (yyval.args).charvalue =  NULL;
          (yyval.args).arg_list = NULL;
	        (yyval.args).mystr = tmp2;
          (yyval.args).mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1049 "parser.y" /* yacc.c:1646  */
    {

					fprintf(logout,"At line no: %d factor : CONST_FLOAT\n\n",line_count);
          //cout<<$1.mystr<<" ------\n";
          /* char array[10];
          sprintf(array, "%f", $1.mystr); */

          char* str=NULL;
          int len = asprintf(&str, "%g", (yyvsp[0].args).floatvalue);
          if (len == -1)
            fprintf(error, "Error %d at Line %d: Error converting float: %m\n",error_count , line_count);
          else
            fprintf(logout,"%s \n\n",str);

          char * tmp2 = (char *) malloc(1+strlen(str));

					strcpy(tmp2 , str);
					/* $$ = $1; */
          (yyval.args).floatvalue = (yyvsp[0].args).floatvalue;
          (yyval.args).intvalue = NULL;
          (yyval.args).charvalue =  NULL;
          (yyval.args).mystr = tmp2;
          free(str);

				}
#line 2692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1074 "parser.y" /* yacc.c:1646  */
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
#line 2712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1089 "parser.y" /* yacc.c:1646  */
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
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1107 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d argument_list : arguments\n\n",line_count);
						(yyval.args) = (yyvsp[0].args);
						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

            /* struct node * head = $1.arg_list;
            while(head!= NULL){
              cout<<head->d_type<<"-"<<head->name<<" -- matches -- \n";
              head = head->arg_list;
            } */
					}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1118 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d argument_list :\n\n",line_count);
					}
#line 2757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1123 "parser.y" /* yacc.c:1646  */
    {

						fprintf(logout,"At line no: %d arguments : arguments COMMA logic_expression\n\n",line_count);
						char tmp[2];
						tmp[0] = ',';tmp[0] = '\0';
						char * tmp2 = (char *) malloc(1+strlen((yyvsp[-2].args).mystr)+1+strlen((yyvsp[0].args).mystr));

						strcpy(tmp2 , (yyvsp[-2].args).mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , (yyvsp[0].args).mystr);

            struct node * item = (struct node *) malloc(1+sizeof(struct node));
            item->name = (yyvsp[0].args).mystr;
            if(symboltable->Lookup((yyvsp[0].args).mystr) != NULL){
              item->d_type = (char *) symboltable->Lookup((yyvsp[0].args).mystr)->getDataType().c_str();
            }
            item->arg_list = (yyvsp[-2].args).arg_list;
            /* cout<<symboltable->Lookup($1.mystr)->getDataType().c_str()<<" <ARGUMENT>\n\n"; */
            (yyval.args).arg_list = item;

						(yyval.args).mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1147 "parser.y" /* yacc.c:1646  */
    {
						fprintf(logout,"At line no: %d arguments : logic_expression\n\n",line_count);

            //struct node * item = (struct node *) malloc(1+sizeof(struct node));
            (yyval.args).arg_list  = (struct node *) malloc(1+sizeof(struct node));

            (yyval.args).arg_list->name = (yyvsp[0].args).mystr;

            if(symboltable->Lookup((yyvsp[0].args).mystr) != NULL){
              (yyval.args).arg_list->d_type = (char *) symboltable->Lookup((yyvsp[0].args).mystr)->getDataType().c_str();
              //cout<<item->d_type<<" datatype \n";
            }
            else{
              if((yyvsp[0].args).floatvalue != NULL){
                (yyval.args).arg_list->d_type = "float";
              }
              else if((yyvsp[0].args).intvalue != NULL){
                (yyval.args).arg_list->d_type = "int";
                //cout<<item->d_type<<" datatype \n";
              }
            }
            // cout<<symboltable->Lookup($1.mystr)->getDataType().c_str()<<" <ARGUMENT>\n\n";
            (yyval.args).arg_list->arg_list = NULL;

            (yyval.args).mystr = (yyvsp[0].args).mystr;
            (yyval.args).intvalue = (yyvsp[0].args).intvalue;
            (yyval.args).floatvalue = (yyvsp[0].args).floatvalue;
            (yyval.args).charvalue = (yyvsp[0].args).charvalue;

						fprintf(logout,"%s \n\n",(yyvsp[0].args).mystr);

					}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2827 "y.tab.c" /* yacc.c:1646  */
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
#line 1181 "parser.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
  FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		fprintf(logout,"At line no: %d Cannot Open Input File.\n\n",line_count);
		exit(1);
	}

	/* FILE * log = fopen("log.txt","w"); */
	// fclose(fp2);
	// fclose(fp3);
  //
	// fp2= fopen(argv[2],"a");
	// fp3= fopen(argv[3],"a");

	yyin=fp;
	yyparse();


	 fclose(logout);
	 fclose(error);

	return 0;
}
