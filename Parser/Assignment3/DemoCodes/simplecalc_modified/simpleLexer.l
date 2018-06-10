%option noyywrap

%{
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "SymbolTable.h"
#include "y.tab.h"

using namespace std;

//extern SymbolTable *symboltable;
void yyerror(char *);

int line_count=1;
int error=0;

%}

NAME	[a-z]+
DOUBLE	(([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+))
%%
[ \t]+ 	{}
(([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+)) 	{
						yylval.dval = atof(yytext);
						return DOUBLE;
					}
[-+*/=] {
		return *yytext;
	}
"(" 	{
		return *yytext;
	}
")" 	{
		return *yytext;
	}
[a-z]+ 	{
		yylval.ivar = *yytext;
		return NAME;
	}
\n 	{
		return *yytext;
	}
. 	{
		char msg[25];
		sprintf(msg,"%s <%s>","invalid character",yytext);
		yyerror(msg);
	}
%%
