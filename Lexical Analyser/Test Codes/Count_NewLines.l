%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>

FILE *logout;
FILE *tokenout;
int linecount = 1;

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NEWLINE \n

%%

{NEWLINE} 	{
			linecount++;
			fprintf(logout , "Line number %d\n	", linecount);
			printf("New line... %d\n" , linecount);
		}

.+ 		{ //do Noting 
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
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
