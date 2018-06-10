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
					printf("start : program\n\n");
				}
				;

			program : program unit	{ printf("program : program unit\n\n");}
				| unit	{ printf("program : | unit\n\n");}
				;

			unit : var_declaration	{ printf("unit : var_declaration\n\n");}
			     | func_declaration		  {printf("unit : func_declaration\n\n");}
			     | func_definition	{ printf("unit : var_declaration\n\n");}
			     ;

			 func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement  {
			 			printf("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n");

			 		}
			 		| type_specifier ID LPAREN RPAREN compound_statement  {
			 										printf("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n");
			 										/* cout<<$2<<"()"; */
			 									}
			 		;

			compound_statement : LCURL statements RCURL  {
							printf("compound_statement : LCURL statements RCURL\n\n");
						}
						| LCURL RCURL  {
							 printf("compound_statement : LCURL RCURL\n\n");
						 }
						;

			func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON	{
		 			 	printf("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n");
				  }
					| type_specifier ID LPAREN RPAREN SEMICOLON	{ printf("func_declaration :type_specifier ID LPAREN RPAREN SEMICOLON\n\n");}
					;



			parameter_list  : parameter_list COMMA type_specifier ID  {
						printf("parameter_list  : parameter_list COMMA type_specifier ID\n\n");
					}
					| parameter_list COMMA type_specifier  {
						printf("parameter_list : parameter_list COMMA type_specifier\n\n");
					}
			 		| type_specifier ID  {
						printf("parameter_list : type_specifier ID\n\n");
					}
					| type_specifier  { printf("parameter_list : type_specifier\n\n");}
			 		;



			var_declaration : type_specifier declaration_list SEMICOLON  {
				printf("var_declaration : type_specifier declaration_list SEMICOLON\n\n");
			};

			type_specifier	: INT { printf("type_specifier:INT\n\n"); }
			 		| FLOAT { printf("type_specifier : FLOAT\n\n");}
			 		| VOID { printf("type_specifier : VOID\n\n");}
			 		;

			declaration_list : declaration_list COMMA ID {
						printf("declaration_list : declaration_list COMMA ID\n\n");
					}
		 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
						printf("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n");
						/* printf(", %s[%c]",$3 , $5); */
					}
		 		  | ID {
						printf("declaration_list : ID\n\n");
						 /* cout<<$1;  */
					}
		 		  | ID LTHIRD CONST_INT RTHIRD {
						printf("declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n");
						 /* cout<<$1<<"["<<$3<<"]"; */
					 }
		 		  ;

			statements : statement { printf("statements : statement \n\n");}
				   | statements statement { printf("statements :| statements statement \n\n");}
				   ;

			statement : var_declaration	{
					printf("statement : var_declaration\n\n");
						/* fprintf(log,"statement : var_declaration\n\n"); */
					}
					| expression_statement	{
						 printf("statement : expression_statement\n\n");
					 }
				  | compound_statement	{
						printf("statement : compound_statement\n\n");
					}
				  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{
						printf("statement :  FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n");
					}
				  | IF LPAREN expression RPAREN statement	{
							printf("statement : IF LPAREN expression RPAREN statement\n\n");
					}
				  | IF LPAREN expression RPAREN statement ELSE statement	{
						printf("statement : IF LPAREN expression RPAREN statement ELSE statement\n\n");
					}
				  | WHILE LPAREN expression RPAREN statement	{
						printf("statement : WHILE LPAREN expression RPAREN statement\n\n");
					}
				  | PRINTLN LPAREN ID RPAREN SEMICOLON	{
						printf("statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n");
					}
				  | RETURN expression SEMICOLON	{
						printf("statement : RETURN expression SEMICOLON\n\n");
					}
				  ;

			expression_statement 	: SEMICOLON	{
						printf("expression_statement 	: SEMICOLON\n\n");
					}
					| expression SEMICOLON	{
						printf("expression_statement 	: expression SEMICOLON\n\n");
					}
					;

			variable : ID	{
					printf("variable : ID\n\n");
				}
			 | ID LTHIRD expression RTHIRD	{
				 printf("variable : ID LTHIRD expression RTHIRD\n\n");
			 }
			 ;

			 expression : logic_expression	{
						 printf("expression : logic_expression\n\n");
					 }
				   | variable ASSIGNOP logic_expression	{
						 printf("expression : variable ASSIGNOP logic_expression\n\n");
					 }
				   ;

			logic_expression : rel_expression	{
				 			printf("logic_expression : rel_expression\n\n");
						}
					 | rel_expression LOGICOP rel_expression	{
						 printf("logic_expression : rel_expression LOGICOP rel_expression\n\n");
					 }
					 ;

			rel_expression	: simple_expression	{
							printf("rel_expression	: simple_expression\n\n");
					}
					| simple_expression RELOP simple_expression	{
						printf("rel_expression	: simple_expression RELOP simple_expression\n\n");
					}
					;

			simple_expression : term	{
						printf("simple_expression : term\n\n");
					}
				  | simple_expression ADDOP term	{
						printf("simple_expression : simple_expression ADDOP term\n\n");
					}
				  ;

			term :	unary_expression	{
						printf("term :	unary_expression\n\n");
					}
		     |  term MULOP unary_expression	{
					 printf("term :	term MULOP unary_expression\n\n");
				 }
		     ;

			unary_expression : ADDOP unary_expression	{
							printf("unary_expression : ADDOP unary_expression\n\n");
					}
					 | NOT unary_expression	{
						 printf("unary_expression : NOT unary_expression\n\n");
					 }
					 | factor	{ printf("unary_expression : factor\n\n");}
					 ;

			factor	: variable	{
					printf("factor	: variable\n\n");
				}
				| ID LPAREN argument_list RPAREN	{
					printf("factor	: ID LPAREN argument_list RPAREN\n\n");
				}
				| LPAREN expression RPAREN	{
					printf("factor : LPAREN expression RPAREN\n\n");
				}
				| CONST_INT	{
					printf("factor : CONST_INT\n\n");
				}
				| CONST_FLOAT	{
					printf("factor : CONST_FLOAT\n\n");
				}
				| variable INCOP	{
					printf("factor : variable INCOP\n\n");
				}
				| variable DECOP	{
					printf("factor : variable DECOP\n\n");
				}
				;

			argument_list : arguments	{
						printf("argument_list : arguments\n\n");
					}
				  |	{
						printf("argument_list :\n\n");
					}
				  ;

			arguments : arguments COMMA logic_expression	{
						printf("arguments : arguments COMMA logic_expression\n\n");
					}
		      | logic_expression	{
						printf("arguments : logic_expression\n\n");
					}
		      ;

%%
int main(int argc,char *argv[])
{
  FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n\n");
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
