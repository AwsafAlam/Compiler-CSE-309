%option noyywrap

%{
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SymbolTable.h"
#include "y.tab.h"

using namespace std;

extern SymbolTable *symboltable;
void yyerror(char *);

int line_count=1;
int error=0;

%}


WS [ \t]+
DIGIT [0-9]
NUMBER [-]?{DIGIT}+(\.{DIGIT}+)?

%%

{NUMBER}  {
            sscanf(yytext,"%lf", &yylval);
	          return NUMBER;
	         }

"+"       { return PLUS; }
"-"       { return MINUS; }
"/"       { return SLASH; }
"*"       { return ASTERISK; }
"("       { return LPAREN; }
")"       { return RPAREN; }
"\n"      { return NEWLINE; }
{WS} { /* No action and no return */}
"if"	{
				return IF;}

"else"	{
				return ELSE;
        }
"for"	{
				return FOR;
        }
"do"	{
				return DO;
      }
"int"	{
			 return INT;
       }
"float"	{
					return FLOAT;
          }
"void"	{
					return VOID;
        }
"switch"	{
						return SWITCH;
          }
"default"	{
						return DEFAULT;
          }
"while"	{
					return WHILE;
          }
"break"	{
					return BREAK;
          }
"char"	{
					return CHAR;
        }
"double"	{
						return DOUBLE;
          }
"return"	{
						return RETURN;
          }
"case"	{
					return CASE;
        }
"continue"	{
							return CONTINUE;
            }
