%option noyywrap

%x MYSTATE
%x STR

%{
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SymbolTable.h"
/* #include "SymbolInfo.h" */
#include "y.tab.h"

/* FILE *logout;
FILE *tokenout; */

using namespace std;

/* extern YYSTYPE yylval; */
extern SymbolTable *symboltable;
extern FILE *logout = fopen("log.txt","w");
extern FILE *tokenout= fopen("token.txt","w");

void yyerror(char *);

int line_count=1;
int error_count = 0;
char chr[1000];
int chr_COUNT  = 0;

/* SymbolTable symboltable(10); */

%}

WHITESPACE [ \t\f\r\v]+
LETTER [a-zA-Z]
DIGIT [0-9]
ID [a-zA-Z_]([a-zA-Z0-9_]+)?
CHAR \'(\\)?[a-zA-Z0-9"]\'
FLOAT [0-9]*(\.[0-9]+)?(E[+-]?[0-9]+)?

ERR_TOO_MANY_DECIMAL_PTS [0-9]*((\.)*[0-9E]*(\.)*)*
ERR_ILL_FORMED_NUMBER [0-9]*(\.[0-9]+)?(E[+-]*[0-9\.]+)*
ERR_INVALID_ID [0-9]+[^0-9\.E;].*
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
						// printf("Line %d\n", line_count);
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

			// fprintf(tokenout,"<STRING,%s>",tmp);

	}

<STR>\n	{
					printf("Terminate\n");
					line_count++;
					error_count++;
					printf("Error at line %d: Unterminated string ", line_count );
					fprintf(logout,"Error at line %d: Unterminated string ", line_count );
					chr[chr_COUNT] = '\0';

					int j =0 ;
					while(chr[j]!= '\0'){
						printf("%c", chr[j]);
						fprintf(logout,"%c", chr[j]);
						j++;
					}
					chr_COUNT = 0;
					printf("\n\n");
					fprintf(logout,"\n\n");

					BEGIN INITIAL;
				}
<STR>\\\n	{
										BEGIN STR;
										printf("%s <--> ", yytext);
								}

<STR>[^\\\n]\"	{
										printf("%s --Ending\n",yytext);
										printf("Line No. %d: Token <STRING> Lexeme ",line_count);
										fprintf(logout,"Line No. %d: Token <STRING> Lexeme ",line_count);
										chr[chr_COUNT] = '\0';
										int j =0 ;
										while(chr[j]!= '\0'){
											printf("%c", chr[j]);
											fprintf(logout,"%c", chr[j]);
											j++;
										}
										chr_COUNT = 0;
										printf("\n\n");
										fprintf(logout,"\n\n");
										fprintf(tokenout,"<STRING,%s>",chr);
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
								fprintf(logout,"Line %d: Token <COMMENT> Lexeme ",line_count);

								int j =0 ;
								while(chr[j]!= '\0'){
									printf("%c", chr[j]);
									fprintf(logout,"%c", chr[j]);
									j++;
								}
								chr_COUNT = 0;
								printf("\n\n");
								fprintf(logout,"\n\n");


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
							// fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);

						}

<MYSTATE><<EOF>>	{
										error_count++;
										chr[chr_COUNT] = '\0';
										printf("Error at line %d: Unterminated chr ",line_count );
										fprintf(logout,"Error at line %d: Unterminated chr ",line_count);
										int j =0 ;
										while(chr[j]!= '\0'){
											printf("%c", chr[j]);
											fprintf(logout,"%c", chr[j]);
											j++;
										}
										chr_COUNT = 0;
										printf("\n\n");
										fprintf(logout,"\n\n");

										BEGIN INITIAL;

									}

{SINGLE_MULTI_COMMENT}		{
															// printf("SIngle--Muiltiline--Comment in line %s\n", yytext);
															fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);

													}

{SINGLE_COMMENT}		{
									// printf("Comment in line %s\n", yytext);
									fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);

							}


"if"	{
				fprintf(tokenout,"<IF>");
				fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n\n",line_count,yytext);
        return IF;
      }
"else"	{
				fprintf(tokenout,"<ELSE>");
				fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
        return ELSE;
      }
"for"	{
				fprintf(tokenout,"<FOR>");
				fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n\n",line_count,yytext);
        return FOR;
      }
"do"	{
				fprintf(tokenout,"<DO>");
				fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);
        return DO;
      }
"int"	{
				fprintf(tokenout,"<INT>");
				fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);
        return INT;
      }
"float"	{
					fprintf(tokenout,"<FLOAT>");
					fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);
          return FLOAT;
        }
"void"	{
					fprintf(tokenout,"<VOID>");
					fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);
          return VOID;
        }
"switch"	{
						fprintf(tokenout,"<SWITCH>");
						fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);
            return SWITCH;
          }
"default"	{
						fprintf(tokenout,"<DEFAULT>");
						fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);
            return DEFAULT;
          }
"while"	{
					fprintf(tokenout,"<WHILE>");
					fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);
          return WHILE;
        }
"break"	{
					fprintf(tokenout,"<BREAK>");
					fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext);
          return BREAK;
        }
"char"	{
					fprintf(tokenout,"<CHAR>");
					fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);
          return CHAR;
        }
"double"	{
						fprintf(tokenout,"<DOUBLE>");
						fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);
            return DOUBLE;
          }
"return"	{
						fprintf(tokenout,"<RETURN>");
						fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);
            return RETURN;
          }
"case"	{
					fprintf(tokenout,"<CASE>");
					fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);
          return CASE;
        }
"continue"	{
							fprintf(tokenout,"<CONTINUE>");
							fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);
              return CONTINUE;
            }

"+"		|

"-"		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "ADDOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
      /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ADDOP");
			yylval = (YYSTYPE)s; */
			return ADDOP;
    }

"*"		|

"/"		|

"%"		{
			fprintf(tokenout,"<MULOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "MULOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
      /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"MULOP");
      yylval = (YYSTYPE)s; */
      return MULOP;
    }

"++"		{
			fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "INCOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
      /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"INCOP");
      yylval = (YYSTYPE)s; */
      return INCOP;
    }

"--"		{
			fprintf(tokenout,"<DECOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <DECOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "INCOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
      /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"DECOP");
      yylval = (YYSTYPE)s; */
      return DECOP;
    }

"<"		|

"<="		|

">"		|

">="		|

"=="		|

"!="	{
			fprintf(tokenout,"<RELOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "RELOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
      /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RELOP");
  		yylval = (YYSTYPE)s; */
  		return RELOP;
		}

"="	{
			fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n\n",line_count,yytext);

      return ASSIGNOP;
		}

"&&"		|

"||"		{
			fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n\n",line_count,yytext);

      /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LOGICOP");
			yylval = (YYSTYPE)s; */
			return LOGICOP;
		}

"&"		|

"|"		|

"^"		|

"<<"		|

">>"		{
			fprintf(tokenout,"<BITOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <BITOP> Lexeme %s found\n\n",line_count,yytext);

      /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"BITOP");
      yylval = (YYSTYPE)s; */
      return BITOP;
		}

"!"	{
			fprintf(tokenout,"<NOT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
			return NOT;
		}

"("	{
			fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
			return LPAREN;
		}

")"	{
			fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
      return RPAREN;
		}

"{"	{
			fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
			return LCURL;
		}

"}"	{
			fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
			return RCURL;
		}

"["	{
			fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n\n",line_count,yytext);
			return LTHIRD;
		}

"]"	{
			fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
			return RTHIRD;
		}

","	{
			fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);
			return COMMA;
		}

";"	{
			fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
			return SEMICOLON;
		}


{ERR_EMPTY_CHAR}	{
										error_count++;
										printf("Error at line %d: Empty character constant error %s\n\n", line_count , yytext);
										fprintf(logout,"Error at line %d: Empty character constant error %s\n\n", line_count , yytext);

										}

{CHAR}		{
							// printf("CharACTER found %s\n",yytext );
							fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext);
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
							fprintf(tokenout,"<CONST_CHAR,%s>",tmp);
              /* SymbolInfo *s= new  SymbolInfo(tmp, (char *)"CONST_CHAR");
              yylval = (YYSTYPE)s; */
              return CONST_CHAR;
					}

{ERR_MULT_CHAR_CONSTANT}	{
														error_count++;
														printf("Error at line %d: Multi character constant error %s\n\n", line_count , yytext);
														fprintf(logout,"Error at line %d: Multi character constant error %s\n\n", line_count , yytext);
													}

{ERR_CHAR}		{
									error_count++;
									printf("Error at line %d: Unterminated character %s\n\n", line_count , yytext);
									fprintf(logout,"Error at line %d: Unterminated character %s\n\n", line_count , yytext);
							}


{ERR_INVALID_ID}	{
											error_count++;
											printf("Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count , yytext );
											fprintf(logout,"Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count , yytext );

									}

{DIGIT}+ {
						fprintf(tokenout,"<CONST_INT,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);

						//symboltable.Insert(yytext , "CONST_INT");
            /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONST_INT");
            yylval = (YYSTYPE)s; */
            return CONST_INT;	//insert in symbol table and print symbol table content(only non empty buckets)
					// SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");

          }

{FLOAT}	{
					fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
					fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext);
					//insert in symbol table and print symbol table content(only non empty buckets)
					// SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
					/* symboltable.Insert(yytext , "CONST_FLOAT"); */
          /* SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONST_FLOAT");
          yylval = (YYSTYPE)s; */
          return CONST_FLOAT;
        }

{ERR_TOO_MANY_DECIMAL_PTS}	{
																error_count++;
																printf("Error at line %d: Too many decimal point  %s\n\n",line_count , yytext );
																fprintf(logout,"Error at line %d: Too many decimal point  %s\n\n",line_count,yytext);

														}


{ERR_ILL_FORMED_NUMBER}		{
															error_count++;
															printf("Error at Line: %d Ill formed number %s\n\n", line_count , yytext);
															fprintf(logout,"Error at Line: %d  Ill formed number %s\n\n", line_count , yytext);
													}





{ID} {
				fprintf(tokenout,"<ID,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)

				//symboltable.Insert(string(yytext) , "ID");
				// symboltable.PrintAllScopes();
        /* SymbolInfo *s= table->lookup(yytext);
        if(s==NULL)
        {
          s= new SymbolInfo(yytext, (char *)"ID");
        }
        yylval = (YYSTYPE)s; */

        return ID;
      }


.										{
											error_count++;
											fprintf(logout,"Error at line %d: Unrecognized character %s\n\n",line_count,yytext);
											printf("Error at line %d: Unrecognized character %s\n\n",line_count,yytext);
										}

%%
/* int yywrap()
{
	return 1;
} */

/* int main(int argc,char *argv[]){

	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}

	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}

	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");

	yyin= fin;
	yylex();
	// st.print();
	symboltable.PrintAllScopes();
	fprintf(logout,"Total Lines : %d\n",line_count);
	fprintf(logout,"Total Errors: %d\n",error_count);

	printf("Total Lines : %d\n",line_count);
	printf("Total Errors: %d\n",error_count);

	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
} */
