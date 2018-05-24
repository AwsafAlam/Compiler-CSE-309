%option noyywrap

%x MYSTATE
%x STR

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<vector>
FILE *logout;
FILE *tokenout;

#include "SymbolTable.h"

using namespace std;

int line_count=1;
int error_count = 0;
char chr[1000];
int chr_COUNT  = 0;

SymbolTable symboltable(10);

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

HEXA "0x"[a-fA-F0-9]+;

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
			}
"else"	{
				fprintf(tokenout,"<ELSE>");
				fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
			}
"for"	{
				fprintf(tokenout,"<FOR>");
				fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n\n",line_count,yytext);
			}
"do"	{
				fprintf(tokenout,"<DO>");
				fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);
			}
"int"	{
				fprintf(tokenout,"<INT>");
				fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);
			}
"float"	{
					fprintf(tokenout,"<FLOAT>");
					fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);
				}
"void"	{
					fprintf(tokenout,"<VOID>");
					fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);
				}
"switch"	{
						fprintf(tokenout,"<SWITCH>");
						fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);
					}
"default"	{
						fprintf(tokenout,"<DEFAULT>");
						fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);
					}
"while"	{
					fprintf(tokenout,"<WHILE>");
					fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);
				}
"break"	{
					fprintf(tokenout,"<BREAK>");
					fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext);
				}
"char"	{
					fprintf(tokenout,"<CHAR>");
					fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);
				}
"double"	{
						fprintf(tokenout,"<DOUBLE>");
						fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);
					}
"return"	{
						fprintf(tokenout,"<RETURN>");
						fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);
					}
"case"	{
					fprintf(tokenout,"<CASE>");
					fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);
				}
"continue"	{
							fprintf(tokenout,"<CONTINUE>");
							fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);
						}

"+"		|

"-"		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "ADDOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"*"		|

"/"		|

"%"		{
			fprintf(tokenout,"<MULOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "MULOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"++"		|

"--"		{
			fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "INCOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
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
		}

"="	{
			fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "ASSIGNOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"&&"		|

"||"		{
			fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "LOGICOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"&"		|

"|"		|

"^"		|

"<<"		|

">>"		{
			fprintf(tokenout,"<BITOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <BITOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "BITOP");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"!"	{
			fprintf(tokenout,"<NOT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "NOT");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"("	{
			fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "LPAREN");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

")"	{
			fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
		}

"{"	{
			fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "LCURL");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"}"	{
			fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "RCURL");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"["	{
			fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "LTHIRD");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"]"	{
			fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "RTHIRD");

			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

","	{
			fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "COMMA");
		}

";"	{
			fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// symboltable.Insert(yytext , "SEMICOLON");
		}


{ERR_EMPTY_CHAR}	{
										error_count++;
										printf("Error at line %d: Empty character constant error %s\n\n", line_count , yytext);
										fprintf(logout,"Error at line %d: Empty character constant error %s\n\n", line_count , yytext);

										}

{CHAR}		{
							// printf("CharACTER found %s\n",yytext );
							fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext);
							symboltable.Insert(yytext , "CONST_CHAR");

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

{HEXA}        {
                printf("--- HEXA --\n");
                int j = 2;
                int num = 0;
                while(yytext[j]!= '\0'){
                  printf("%c", yytext[j]);
                  if(yytext[j] == '0'){
                    num += 0;
                  }
                  else if(yytext[j] == '1'){
                    num += 1;
                  }
                  else if(yytext[j] == '2'){
                    num += 2;
                  }
                  else if(yytext[j] == '3'){
                    num += 3;
                  }
                  else if(yytext[j] == '4'){
                    num += 4;
                  }
                  else if(yytext[j] == '5'){
                    num += 5;
                  }
                  else if(yytext[j] == '6'){
                    num += 6;
                  }
                  else if(yytext[j] == '7'){
                    num += 7;
                  }
                  else if(yytext[j] == '8'){
                    num += 8;
                  }
                  else if(yytext[j] == '9'){
                    num += 9;
                  }
                  else if(yytext[j] == 'A' || yytext[j] == 'a'){
                    num += 10;
                  }
                  else if(yytext[j] == 'B' || yytext[j] == 'b'){
                    num += 11;
                  }
                  else if(yytext[j] == 'C' || yytext[j] == 'c'){
                    num += 12;
                  }
                  else if(yytext[j] == 'D' || yytext[j] == 'd'){
                    num += 13;
                  }
                  else if(yytext[j] == 'E' || yytext[j] == 'e'){
                    num += 14;
                  }
                  else if(yytext[j] == 'F' || yytext[j] == 'f'){
                    num += 15;
                  }

                  j++;
                }
                int tmp = num;
                while(tmp%10 != 0 ){
                  printf("%d", tmp%10);
                  tmp = tmp/10;
                }
                fprintf(tokenout,"<CONST_INT,%d>",num);
                fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %d found\n\n",line_count,num);
                symboltable.Insert(yytext , "CONST_INT");

              }

{ERR_INVALID_ID}	{
											error_count++;
											printf("Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count , yytext );
											fprintf(logout,"Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count , yytext );

									}

{DIGIT}+ {
						fprintf(tokenout,"<CONST_INT,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
						//insert in symbol table and print symbol table content(only non empty buckets)
						// SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
						symboltable.Insert(yytext , "CONST_INT");
					}

{FLOAT}	{
					fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
					fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext);
					//insert in symbol table and print symbol table content(only non empty buckets)
					// SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
					symboltable.Insert(yytext , "CONST_FLOAT");
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

				symboltable.Insert(string(yytext) , "ID");
				// symboltable.PrintAllScopes();
			}


.										{
											error_count++;
											fprintf(logout,"Error at line %d: Unrecognized character %s\n\n",line_count,yytext);
											printf("Error at line %d: Unrecognized character %s\n\n",line_count,yytext);
										}

%%

int main(int argc,char *argv[]){

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
}
