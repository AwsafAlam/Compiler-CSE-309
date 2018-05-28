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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DOUBLE = 258,
    CONST_FLOAT = 259,
    ID = 260,
    CONST_CHAR = 261,
    CONST_INT = 262,
    NEWLINE = 263,
    PLUS = 264,
    MINUS = 265,
    SLASH = 266,
    ASTERISK = 267,
    LPAREN = 268,
    RPAREN = 269,
    IF = 270,
    ELSE = 271,
    FOR = 272,
    DO = 273,
    INT = 274,
    FLOAT = 275,
    VOID = 276,
    SWITCH = 277,
    DEFAULT = 278,
    WHILE = 279,
    BREAK = 280,
    CHAR = 281,
    RETURN = 282,
    CASE = 283,
    CONTINUE = 284,
    ADDOP = 285,
    ASSIGNOP = 286,
    COMMA = 287,
    INCOP = 288,
    DECOP = 289,
    LCURL = 290,
    RCURL = 291,
    LOGICOP = 292,
    LTHIRD = 293,
    RTHIRD = 294,
    MULOP = 295,
    NOT = 296,
    PRINTLN = 297,
    RELOP = 298,
    SEMICOLON = 299,
    BITOP = 300
  };
#endif
/* Tokens.  */
#define DOUBLE 258
#define CONST_FLOAT 259
#define ID 260
#define CONST_CHAR 261
#define CONST_INT 262
#define NEWLINE 263
#define PLUS 264
#define MINUS 265
#define SLASH 266
#define ASTERISK 267
#define LPAREN 268
#define RPAREN 269
#define IF 270
#define ELSE 271
#define FOR 272
#define DO 273
#define INT 274
#define FLOAT 275
#define VOID 276
#define SWITCH 277
#define DEFAULT 278
#define WHILE 279
#define BREAK 280
#define CHAR 281
#define RETURN 282
#define CASE 283
#define CONTINUE 284
#define ADDOP 285
#define ASSIGNOP 286
#define COMMA 287
#define INCOP 288
#define DECOP 289
#define LCURL 290
#define RCURL 291
#define LOGICOP 292
#define LTHIRD 293
#define RTHIRD 294
#define MULOP 295
#define NOT 296
#define PRINTLN 297
#define RELOP 298
#define SEMICOLON 299
#define BITOP 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "parser.y" /* yacc.c:1909  */
 double dval; int ivar; char *strval; 

#line 147 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
