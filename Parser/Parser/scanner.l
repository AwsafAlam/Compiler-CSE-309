%option noyywrap

%x MYSTATE
%x STR

%{
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
/* #include "SymbolTable.h" */
#include "y.tab.h"
extern YYSTYPE yylval;

using namespace std;

/* extern SymbolTable *symboltable; */
void yyerror(char *);

int line_count=1;
int error_count=0;
char chr[1000];
int chr_COUNT  = 0;

/* FILE *log; */

%}



WHITESPACE [ \t\f\r\v]+
LETTER [a-zA-Z]
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
						printf("\nNew Line %d\n", line_count);
						//

//            return NEWLINE;
					}
{WHITESPACE}	{
								//do nothing
							}

\" {
		BEGIN STR;
		printf("STR started at --\n %s",yytext);
	}

<STR>.	{
			printf("%s", yytext);
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

			// printf("<STRING,%s>",tmp);

	}

<STR>\n	{
					printf("Terminate\n");
					line_count++;
					error_count++;
					printf("Error at line %d: Unterminated string ", line_count );
					printf("Error at line %d: Unterminated string ", line_count );
					chr[chr_COUNT] = '\0';

					int j =0 ;
					while(chr[j]!= '\0'){
						printf("%c", chr[j]);
						printf("%c", chr[j]);
						j++;
					}
					chr_COUNT = 0;
					printf("\n\n");
					printf("\n\n");

					BEGIN INITIAL;
				}
<STR>\\\n	{
										BEGIN STR;
										printf("%s <--> ", yytext);
								}

<STR>[^\\\n]\"	{
										printf("%s --Ending\n",yytext);
										printf("Line No. %d: Token <STRING> Lexeme ",line_count);
										printf("Line No. %d: Token <STRING> Lexeme ",line_count);
										chr[chr_COUNT] = '\0';
										int j =0 ;
										while(chr[j]!= '\0'){
											printf("%c", chr[j]);
											printf("%c", chr[j]);
											j++;
										}
										chr_COUNT = 0;
										printf("\n\n");
										printf("\n\n");
										printf("<STRING,%s>",chr);
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
								printf("Line %d: Token <COMMENT> Lexeme ",line_count );
								printf("Line %d: Token <COMMENT> Lexeme ",line_count);

								int j =0 ;
								while(chr[j]!= '\0'){
									printf("%c", chr[j]);
									printf("%c", chr[j]);
									j++;
								}
								chr_COUNT = 0;
								printf("\n\n");
								printf("\n\n");


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
										printf("Error at line %d: Unterminated chr ",line_count );
										printf("Error at line %d: Unterminated chr ",line_count);
										int j =0 ;
										while(chr[j]!= '\0'){
											printf("%c", chr[j]);
											printf("%c", chr[j]);
											j++;
										}
										chr_COUNT = 0;
										printf("\n\n");
										printf("\n\n");

										BEGIN INITIAL;

									}

{SINGLE_MULTI_COMMENT}		{
															// printf("SIngle--Muiltiline--Comment in line %s\n", yytext);
															printf("Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);

													}

{SINGLE_COMMENT}		{
									// printf("Comment in line %s\n", yytext);
									printf("Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);

							}


"if"	{
				printf("At line no: %d ",line_count);
				//
				return IF;
			}

"else"	{
				printf("At line no: %d ",line_count);
				//
				return ELSE;
        }
"for"	{
				printf("At line no: %d ",line_count);
				//
				return FOR;
        }
"do"	{
				printf("At line no: %d ",line_count);
				//
				return DO;
      }
"int"	{
				printf("At line no: %d ",line_count);
				//
			 return INT;
       }
"float"	{
					printf("At line no: %d ",line_count);
					//
					return FLOAT;
          }
"void"	{
					printf("At line no: %d ",line_count);
					//
					return VOID;
        }
"switch"	{
						printf("At line no: %d ",line_count);
						//
						return SWITCH;
          }
"default"	{
						//
						return DEFAULT;
          }
"while"	{
					//
					return WHILE;
          }
"break"	{
					//
					return BREAK;
          }
"char"	{
					//
					return CHAR;
        }
"double"	{
						//
						return DOUBLE;
          }
"return"	{	return RETURN;}
"case"	{
					//
					return CASE;
        }
"continue"	{
							//
							return CONTINUE;
            }


"+"|"-"   {yylval.cvar = *yytext; return ADDOP;}

"*"|"/" { yylval.cvar =*yytext;cout<<"MULOP"<<endl;return MULOP;}
"%" 		{ yylval.cvar =*yytext;cout<<"MULOP"<<endl;return MULOP;}

"("       { //printf("\nLPAREN lex\n");
						//
 						return LPAREN;
					}
")"       { //printf("\nRPAREN lex\n");
						return RPAREN;
					}
"!"       { return NOT;}
"{"	      { //printf("\n\nLCURL lex\n\n");
						//
						return LCURL;}
"}"	      { //printf("RCURL lex\n");
						return RCURL;}
"["	      { return LTHIRD;}
"]"	      { return RTHIRD;}
","	      {	return COMMA;}
";"	      {	return SEMICOLON;}
"="				{	return ASSIGNOP;}
"++"			{
						printf("Line no %d: TOKEN <DECOP> Lexeme %s found\n\n",line_count,yytext);
						yylval.strval =strdup(yytext);
						return DECOP;
					}

"--"		{
					printf("Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
					yylval.strval =strdup(yytext);
					return INCOP;
				}

"<"		|

"<="		|

">"		|

">="		|

"=="		|

"!="	{

			printf("Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
			yylval.strval =strdup(yytext);
			//
			return RELOP;
		}

"&&"		|

"||"		{
					printf("Line no %d: TOKEN <LOGICOP> Lexeme %s found\n\n",line_count,yytext);
					yylval.strval =strdup(yytext);
					//
					return LOGICOP;
				}


{ERR_EMPTY_CHAR}	{
										error_count++;
										printf("Error at line %d: Empty character constant error %s\n\n", line_count , yytext);
										/* fprintf(logout,"Error at line %d: Empty character constant error %s\n\n", line_count , yytext); */

										}

{CHAR}		{
							// printf("CharACTER found %s\n",yytext );
							/* fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext); */
							/* symboltable.Insert(yytext , "CONST_CHAR"); */

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
							/* fprintf(tokenout,"<CONST_CHAR,%s>",tmp); */
              /* SymbolInfo *s= new  SymbolInfo(tmp, (char *)"CONST_CHAR");
              yylval = (YYSTYPE)s; */

							yylval.strval =strdup(tmp);
			        return CONST_CHAR;
					}

{ERR_MULT_CHAR_CONSTANT}	{
														error_count++;
														printf("Error at line %d: Multi character constant error %s\n\n", line_count , yytext);
														/* fprintf(logout,"Error at line %d: Multi character constant error %s\n\n", line_count , yytext); */
													}

{ERR_CHAR}		{
									error_count++;
									printf("Error at line %d: Unterminated character %s\n\n", line_count , yytext);
									/* fprintf(logout,"Error at line %d: Unterminated character %s\n\n", line_count , yytext); */
							}


{DIGIT}+  {
						/* sscanf(yytext,"%lf", &yylval); */
						printf("INT %s\n\n",yytext);
						yylval.ivar = atoi(yytext);
						return CONST_INT;
	         }

{FLOAT}	{
					printf("<CONST_FLOAT,%s>\n\n",yytext);
					/* fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext); */
					yylval.strval = yytext;
					return CONST_FLOAT;
        }

{ERR_TOO_MANY_DECIMAL_PTS}	{
																error_count++;
																printf("Error at line %d: Too many decimal point  %s\n\n",line_count , yytext );
																/* fprintf(logout,"Error at line %d: Too many decimal point  %s\n\n",line_count,yytext); */

														}


{ERR_ILL_FORMED_NUMBER}		{
															error_count++;
															printf("Error at Line: %d Ill formed number %s\n\n", line_count , yytext);
															/* fprintf(logout,"Error at Line: %d  Ill formed number %s\n\n", line_count , yytext); */
													}


{ID}  {
				/* printf("Line %d : - %s", line_count , yytext); */
				printf("At line no: %d - id %s\n",line_count,yytext);
      	yylval.strval =strdup(yytext);
				//
        return ID;
      }

{ERR_INVALID_ID}	{
											error_count++;
											printf("Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count , yytext );
											/* fprintf(logout,"Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count , yytext ); */

									}
