%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define YYSTYPE double      /* yyparse() stack type */

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

void yyerror(char *s){
	printf("Error: %s\n",s);
}

%}

%token NEWLINE NUMBER PLUS MINUS SLASH ASTERISK LPAREN RPAREN

%%

input:              /* empty string */
    | input line
    ;
line: NEWLINE
    | expr NEWLINE           { printf("\t%.10g\n",$1); }
    ;
expr: expr PLUS term         { $$ = $1 + $3; }
    | expr MINUS term        { $$ = $1 - $3; }
    | term
    ;
term: term ASTERISK factor   { $$ = $1 * $3; }
    | term SLASH factor      { $$ = $1 / $3; }
    | factor
    ;
factor:  LPAREN expr RPAREN  { $$ = $2; }
      | NUMBER
      ;



%%
int main(int argc,char *argv[])
{
  FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	// fp2= fopen(argv[2],"w");
	// fclose(fp2);
	// fp3= fopen(argv[3],"w");
	// fclose(fp3);
  //
	// fp2= fopen(argv[2],"a");
	// fp3= fopen(argv[3],"a");


	yyin=fp;
	yyparse();


	// fclose(fp2);
	// fclose(fp3);

	return 0;
}
