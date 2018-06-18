/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 36 "parser.y" /* yacc.c:1909  */

    struct node {
        char * mystr;
        char charvalue;
        int intvalue;
        float floatvalue;
        char * name;
        char * d_type;
        struct node * arg_list;
    };

#line 56 "y.tab.h" /* yacc.c:1909  */

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
#line 47 "parser.y" /* yacc.c:1909  */

  struct node args;

#line 162 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
