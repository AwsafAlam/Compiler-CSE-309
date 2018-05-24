%option noyywrap

%{ 
#include <stdio.h>

int word = 0;
int line = 0;
%}

%%

[a-zA-Z0-9]+	{
			printf("Word Detected........\n");			
			word++;
		}
[\n]		{
			line++;
		}
"%"		{
			//Do Nothing
		}

%%


int main(int argc, char *argv[])
{
	if(argc!=2){
		printf("Provide input file name\n");
		return 0;
	}
	FILE *fin=fopen(argv[1],"r");
	yyin = fin;	
	yylex();
	printf("%d  %d\n", word, line);
	return 0;
}
