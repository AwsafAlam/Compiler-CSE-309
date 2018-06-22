%option noyywrap

%x MYSTATE
%x STR

%{
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
extern YYSTYPE yylval;
extern FILE * error;
extern FILE * logout;

using namespace std;

void yyerror(char *);

int line_count=1;
int error_count=0;
char chr[1000];
int chr_COUNT  = 0;

%}



LETTER [a-zA-Z]
WHITESPACE [ \t\f\r\v]+
DIGIT [0-9]

NUMBER [-]?{DIGIT}+(\.{DIGIT}+)?

ID [a-zA-Z_][a-zA-Z0-9_]*
CHAR \'(\\)?[a-zA-Z0-9"]\'
FLOAT [0-9]*(\.[0-9]+)?(E[+-]?[0-9]+)?

ERR_TOO_MANY_DECIMAL_PTS [0-9]*((\.)*[0-9E]*(\.)*)*
ERR_ILL_FORMED_NUMBER [0-9]*(\.[0-9]+)?(E[+-]*[0-9\.]+)*
ERR_INVALID_ID [0-9]+[^[]0-9\.E;].*
ERR_CHAR	[''](\\)?[a-zA-Z0-9]?['']?
ERR_MULT_CHAR_CONSTANT \'[^\n\'][^\n\']+\'
ERR_EMPTY_CHAR	\'\'
ERR_COMMENT	"/*"(.*[^.][^"*/"])*
ERR_UNFINISHED_STR \"[^\n\"]*([^\\\"])

STRING_SINGLE \"[^"\n]*[^\\\n]\"
STRING_MULT  \"([^"\n]*"\\"[^.][^"\n]*)*\"

NEWLINE \n
SINGLE_COMMENT (\/\/)+.*
SINGLE_MULTI_COMMENT (\/\/)+(.*"\\"[^.][^.].*)+
MULTI_SINGLE_COMMENT "/*".*"*/"
MULTI_MULTI_COMMENT (\/\*)([^"*/"]*[^.])*(\*\/)


%%

{NEWLINE} {
						line_count++;
					}
{WHITESPACE}	{
								//do nothing
							}

\" {
		BEGIN STR;
		//printf("STR started at -- %s\n",yytext);
	}

<STR>.	{
			chr[chr_COUNT] = yytext[0];

			int j = chr_COUNT-1;
				if(chr[j]=='\\' && chr[j+1]=='n'){
					chr[j] = '\n';
					chr_COUNT--;
				}
				else if(chr[j]=='\\' && chr[j+1]=='t'){
					chr[j] = '\t';
					chr_COUNT--;
				}
				else if(chr[j]=='\\' && chr[j+1]=='r'){
					chr[j] = '\r';
					chr_COUNT--;
				}
				else if(chr[j]=='\\' && chr[j+1]=='a'){
					chr[j] = '\a';
					chr_COUNT--;
				}
				else if(chr[j]=='\\' && chr[j+1]=='b'){
					chr[j] = '\b';
					chr_COUNT--;
				}
				else if(chr[j]=='\\' && chr[j+1]=='\\'){
					chr[j] = '\\';
					chr_COUNT--;
				}

				chr_COUNT++;

	}

<STR>\n	{
					//printf("Terminate\n");
					line_count++;
					error_count++;
					fprintf(error ,"Error %d at line %d: Unterminated string ",error_count, line_count );
					//printf("Error at line %d: Unterminated string ", line_count );
					chr[chr_COUNT] = '\0';

					int j =0 ;
					while(chr[j]!= '\0'){
						//printf("%c", chr[j]);
						//printf("%c", chr[j]);
						j++;
					}
					chr_COUNT = 0;

					BEGIN INITIAL;
				}
<STR>\\\n		{
										BEGIN STR;
						}

<STR>[^\\\n]\"	{
										//printf("%s --Ending\n",yytext);
										//printf("Line No. %d: Token <STRING> Lexeme ",line_count);
										//printf("Line No. %d: Token <STRING> Lexeme ",line_count);
										chr[chr_COUNT] = '\0';
										int j =0 ;
										while(chr[j]!= '\0'){
											//printf("%c", chr[j]);
											//printf("%c", chr[j]);
											j++;
										}
										chr_COUNT = 0;
										//printf("<STRING,%s>\n",chr);
										BEGIN INITIAL;
									}


"/*" {
		BEGIN MYSTATE;
		chr[0] = '/';
		chr[1] = '*';
		chr_COUNT = 2;
		// printf("MYSTATE started at %s\n",yytext);
	}

<MYSTATE>"*/" {
								// printf("- %s \nEnding Comment--\n", yytext);
								chr[chr_COUNT] = '*';
								chr_COUNT++;
								chr[chr_COUNT] = '/';
								chr[chr_COUNT+1] = '\0';
								chr_COUNT= 0;
								//printf("Line %d: Token <COMMENT> Lexeme ",line_count);

								int j =0 ;
								while(chr[j]!= '\0'){
									printf("%c", chr[j]);
									printf("%c", chr[j]);
									j++;
								}
								chr_COUNT = 0;

								BEGIN INITIAL;
							}
<MYSTATE>\n	{
						line_count++;
						// printf("New line %s\n",yytext );
						chr[chr_COUNT] = '\n';
						chr_COUNT++;
						}

<MYSTATE>.  {
							// printf("%s" , yytext);
							chr[chr_COUNT] = yytext[0];
							chr_COUNT++;
							// printf("Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);

						}

<MYSTATE><<EOF>>	{
										error_count++;
										chr[chr_COUNT] = '\0';
										fprintf(error , "Error %d at line %d: Unterminated character ",error_count,line_count);
										int j =0 ;
										while(chr[j]!= '\0'){
											//printf("%c", chr[j]);
											//printf("%c", chr[j]);
											j++;
										}
										chr_COUNT = 0;
										BEGIN INITIAL;

									}

{SINGLE_MULTI_COMMENT}		{
															//printf("Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);

													}

{SINGLE_COMMENT}		{
									//printf("Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);

							}


"if"	 {return IF;}
"else"	{return ELSE;}
"for"	{return FOR;}
"do"	{return DO;}
"int"	{return INT;}
"float"	{	return FLOAT;}
"void"	{return VOID;}
"switch"	{	return SWITCH;}
"default"	{return DEFAULT;}
"while"	{	return WHILE;}
"break"	{	return BREAK;}
"char"	{return CHAR;}
"double"	{	return DOUBLE;}
"return"	{	return RETURN;}
"case"		{return CASE;}
"continue"	{	return CONTINUE;}
"println"	  {return PRINTLN;}

"+"|"-"   {yylval.args.charvalue = *yytext; return ADDOP;}

"*"|"/"   {yylval.args.charvalue =*yytext;return MULOP;}
"%" 		  {yylval.args.charvalue =*yytext;return MULOP;}

"("       { return LPAREN;}
")"       { return RPAREN;}
"!"       { return NOT;}
"{"	      { return LCURL;}
"}"	      { return RCURL;}
"["	      { return LTHIRD;}
"]"	      { return RTHIRD;}
","	      {	return COMMA;}
";"	      {	return SEMICOLON;}
"="				{	return ASSIGNOP;}
"++"			{
						yylval.args.mystr =strdup(yytext);
						return INCOP;
					}

"--"		{
					yylval.args.mystr =strdup(yytext);
					return DECOP;
				}

"<"		|

"<="	|

">"		|

">="	|

"=="	|

"!="	{
				yylval.args.mystr =strdup(yytext);
				return RELOP;
		  }

"&&"	|

"||"	{
				yylval.args.mystr =strdup(yytext);
				return LOGICOP;
			}

{ERR_EMPTY_CHAR}	{
										error_count++;
										fprintf(error ,"Error %d at line %d: Empty character constant error %s\n\n",error_count, line_count , yytext);
										}

{CHAR}		{
							char tmp[2];
							if (yytext[3] != '\0') {
								if(yytext[2]=='n'){
									tmp[0] = 10;
								}
								else if (yytext[2]=='t'){
									tmp[0] = 9;

								}
								else if (yytext[2]=='\\'){
									tmp[0] = '\\';

								}else if (yytext[2]=='a'){
									tmp[0] = '\a';

								}else if (yytext[2]=='f'){
									tmp[0] = '\f';

								}else if (yytext[2]=='r'){
									tmp[0] = '\r';

								}else if (yytext[2]=='b'){
									tmp[0] = '\b';

								}else if (yytext[2]=='v'){
									tmp[0] = '\v';

								}else if (yytext[2]=='0'){
									tmp[0] = '\0';

								}else if (yytext[2]=='"'){
									tmp[0] = '\"';

								}

							}
							else{
								tmp[0] = yytext[1];
							}
							yylval.args.mystr =strdup(tmp);
			        return CONST_CHAR;
					}

{ERR_MULT_CHAR_CONSTANT}	{
														error_count++;
														printf("Error at line %d: Multi character constant error %s\n\n", line_count , yytext);
														fprintf(error,"Error at line %d: Multi character constant error %s\n\n", line_count , yytext);
													}

{ERR_CHAR}		{
									error_count++;
									printf("Error at line %d: Unterminated character %s\n\n", line_count , yytext);
									fprintf(error,"Error at line %d: Unterminated character %s\n\n", line_count , yytext);
							}


{DIGIT}+  {
						yylval.args.intvalue = atoi(yytext);
						return CONST_INT;
	         }

{FLOAT}	{
					/* yylval.args.mystr = yytext; */
					yylval.args.floatvalue = atof(yytext);
					return CONST_FLOAT;
        }

{ERR_TOO_MANY_DECIMAL_PTS}	{
																error_count++;
																printf("Error at line %d: Too many decimal point  %s\n\n",line_count , yytext );
																fprintf(error,"Error at line %d: Too many decimal point  %s\n\n",line_count,yytext);

														}


{ERR_ILL_FORMED_NUMBER}		{
															error_count++;
															printf("Error at Line: %d Ill formed number %s\n\n", line_count , yytext);
															fprintf(error,"Error at Line: %d  Ill formed number %s\n\n", line_count , yytext);
													}


{ID}  {
				yylval.args.mystr =strdup(yytext);
				return ID;
      }

{ERR_INVALID_ID}	{
											error_count++;
											printf("Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count , yytext );
											fprintf(error,"Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count , yytext );

									}
