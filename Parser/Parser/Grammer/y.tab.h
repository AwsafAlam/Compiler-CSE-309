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
    NEWLINE = 258,
    NUMBER = 259,
    PLUS = 260,
    MINUS = 261,
    SLASH = 262,
    ASTERISK = 263,
    LPAREN = 264,
    RPAREN = 265,
    IF = 266,
    ELSE = 267,
    FOR = 268,
    DO = 269,
    INT = 270,
    FLOAT = 271,
    VOID = 272,
    SWITCH = 273,
    DEFAULT = 274,
    WHILE = 275,
    BREAK = 276,
    CHAR = 277,
    DOUBLE = 278,
    RETURN = 279,
    CASE = 280,
    CONTINUE = 281,
    ADDOP = 282,
    ASSIGNOP = 283,
    COMMA = 284,
    CONST_FLOAT = 285,
    CONST_INT = 286,
    INCOP = 287,
    DECOP = 288,
    ID = 289,
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
    BITOP = 300,
    CONST_CHAR = 301
  };
#endif
/* Tokens.  */
#define NEWLINE 258
#define NUMBER 259
#define PLUS 260
#define MINUS 261
#define SLASH 262
#define ASTERISK 263
#define LPAREN 264
#define RPAREN 265
#define IF 266
#define ELSE 267
#define FOR 268
#define DO 269
#define INT 270
#define FLOAT 271
#define VOID 272
#define SWITCH 273
#define DEFAULT 274
#define WHILE 275
#define BREAK 276
#define CHAR 277
#define DOUBLE 278
#define RETURN 279
#define CASE 280
#define CONTINUE 281
#define ADDOP 282
#define ASSIGNOP 283
#define COMMA 284
#define CONST_FLOAT 285
#define CONST_INT 286
#define INCOP 287
#define DECOP 288
#define ID 289
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
#define CONST_CHAR 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
