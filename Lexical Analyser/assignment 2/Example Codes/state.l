%option noyywrap

%x STR

%{
#include<stdio.h>
#include<stdlib.h>

%}

AlphaNumeric [a-zA-Z0-9]

%%

[ \t\n]+ {}

\" {
		BEGIN STR;
		printf("STR started at --\n %s",yytext);
	}

<STR>.	{printf("%s", yytext);}
<STR>\n	{printf("Terminate\n");}
<STR>\\\n	{
										BEGIN STR;
										printf("\n%s", yytext);
								}

<STR>[^\\]\"	{
										printf("%s --\n Ending\n",yytext);
										BEGIN INITIAL;
									}

[a-z]+ 	{
			//printf("- %s \n",yytext);
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


	yyin= fin;
	yylex();
	fclose(yyin);
	return 0;
}
