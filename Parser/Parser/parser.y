%{
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "SymbolTable.h"
/* #define YYSTYPE double      /* yyparse() stack type */

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

void yyerror(char *s){
	printf("Error: %s\n",s);
}


%}

%union { double dval; int ivar; char *strval; }
%token <dval> DOUBLE
%token <dval> CONST_FLOAT

%token <strval> ID
%token <strval> CONST_CHAR
%token <ivar> CONST_INT

%token NEWLINE PLUS MINUS SLASH ASTERISK LPAREN RPAREN IF ELSE FOR DO INT FLOAT VOID SWITCH DEFAULT WHILE BREAK CHAR RETURN CASE CONTINUE ADDOP ASSIGNOP COMMA INCOP DECOP LCURL RCURL LOGICOP LTHIRD RTHIRD MULOP NOT PRINTLN RELOP SEMICOLON BITOP


%%

			start : program
				{
					//write your code in this block in all the similar blocks below
					printf("start : program\n");
				}
				;

			program : program unit	{ cout<<"--Another rule"<<endl;}
				| unit	{ printf("program : | unit\n");}
				;

			unit : var_declaration	{ printf(" unit \n");}
			     | func_declaration		  {printf("Function dec\n");}
			     | func_definition	{ cout<<"unit : var_declaration"<<endl;}
			     ;

			func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON	{ cout<<"Another rule"<<endl;}
					| type_specifier ID LPAREN RPAREN SEMICOLON	{ printf("\nfunc_declaration :type_specifier ID LPAREN RPAREN SEMICOLON\n");}
					;

			func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement  { cout<<"Another rule"<<endl;}
					| type_specifier ID LPAREN RPAREN compound_statement  {
													/* printf("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"); */
													cout<<$2<<"()";
												}
			 		;


			parameter_list  : parameter_list COMMA type_specifier ID  { cout<<"Another rule"<<endl;}
					| parameter_list COMMA type_specifier  { cout<<"Another rule"<<endl;}
			 		| type_specifier ID  { cout<<"Another rule"<<endl;}
					| type_specifier  { cout<<"Another rule"<<endl;}
			 		;


			compound_statement : LCURL statements RCURL  { cout<<"{ \n}\n"<<endl;}
			 		    | LCURL RCURL  { cout<<"\n{}\n"<<endl;}
			 		    ;

			var_declaration : type_specifier declaration_list SEMICOLON  {cout<<";"<<endl;};

			type_specifier	: INT { printf("int "); }
			 		| FLOAT { cout<<"float ";}
			 		| VOID { cout<<"void ";}
			 		;

			declaration_list : declaration_list COMMA ID { cout<<","<<endl;}
			 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD { printf(", %s[%c]",$3 , $5);}
			 		  | ID { cout<<$1; }
			 		  | ID LTHIRD CONST_INT RTHIRD { cout<<$1<<"["<<$3<<"]";}
			 		  ;

			statements : statement { cout<<"statements : statement "<<endl;}
				   | statements statement { cout<<"statements :| statements statement "<<endl;}
				   ;

			statement : var_declaration	{
					cout<<"statement : var_declaration"<<endl;
						/* fprintf(log,"statement : var_declaration\n"); */
					}

				  | expression_statement	{ cout<<"statement : expression_statement"<<endl;}
				  | compound_statement	{ cout<<"statement : compound_statement"<<endl;}
				  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{ cout<<"statement :  FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;}
				  | IF LPAREN expression RPAREN statement	{
							cout<<"statement : IF LPAREN expression RPAREN statement"<<endl;}
				  | IF LPAREN expression RPAREN statement ELSE statement	{
						cout<<"statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl;}
				  | WHILE LPAREN expression RPAREN statement	{
						cout<<"statement : WHILE LPAREN expression RPAREN statement"<<endl;}
				  | PRINTLN LPAREN ID RPAREN SEMICOLON	{ cout<<"statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl;}
				  | RETURN expression SEMICOLON	{ cout<<"statement : RETURN expression SEMICOLON"<<endl;}
				  ;

			expression_statement 	: SEMICOLON	{ cout<<"Another rule"<<endl;}
						| expression SEMICOLON	{ cout<<"Another rule"<<endl;}
						;

			variable : ID	{ cout<<"-ID-"<<endl;}
				 | ID LTHIRD expression RTHIRD	{ cout<<"Another rule"<<endl;}
				 ;

			 expression : logic_expression	{ cout<<"Another rule"<<endl;}
				   | variable ASSIGNOP logic_expression	{ cout<<"Another rule"<<endl;}
				   ;

			logic_expression : rel_expression	{ cout<<"Another rule"<<endl;}
					 | rel_expression LOGICOP rel_expression	{ cout<<"Another rule"<<endl;}
					 ;

			rel_expression	: simple_expression	{ cout<<"Another rule"<<endl;}
					| simple_expression RELOP simple_expression	{ cout<<"Another rule"<<endl;}
					;

			simple_expression : term	{ cout<<"Another rule"<<endl;}
					  | simple_expression ADDOP term	{ cout<<"Another rule"<<endl;}
					  ;

			term :	unary_expression	{ cout<<"Another rule"<<endl;}
			     |  term MULOP unary_expression	{ cout<<"Another rule"<<endl;}
			     ;

			unary_expression : ADDOP unary_expression	{ cout<<"Another rule"<<endl;}
					 | NOT unary_expression	{ cout<<"Another rule"<<endl;}
					 | factor	{ cout<<"Another rule"<<endl;}
					 ;

			factor	: variable	{ cout<<"Another rule"<<endl;}
				| ID LPAREN argument_list RPAREN	{ cout<<"Another rule"<<endl;}
				| LPAREN expression RPAREN	{ cout<<"Another rule"<<endl;}
				| CONST_INT	{ cout<<"Another rule"<<endl;}
				| CONST_FLOAT	{ cout<<"Another rule"<<endl;}
				| variable INCOP	{ cout<<"Another rule"<<endl;}
				| variable DECOP	{ cout<<"Another rule"<<endl;}
				;

			argument_list : arguments	{ cout<<"Another rule"<<endl;}
						  |	{ cout<<"Another rule"<<endl;}
						  ;

			arguments : arguments COMMA logic_expression	{ cout<<"Another rule"<<endl;}
				      | logic_expression	{ cout<<"Another rule"<<endl;}
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

	FILE *log= fopen("log.txt","w");
	// fclose(fp2);
	FILE *error= fopen("error.txt","w");
	// fclose(fp3);
  //
	// fp2= fopen(argv[2],"a");
	// fp3= fopen(argv[3],"a");


	yyin=fp;
	yyparse();


	 fclose(log);
	 fclose(error);

	return 0;
}
