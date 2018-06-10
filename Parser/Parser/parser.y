%{
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<vector>
#include "SymbolTable.h"
/* #include "SymbolInfo.h" */
/* #define YYSTYPE double      /* yyparse() stack type */

using namespace std;

/* int yyparse(void); */
int yylex(void);
extern FILE *yyin;
extern int line_count;
vector<char *> vec;

 FILE * logout = fopen("log.txt","w");
 FILE *error= fopen("error.txt","w");

//int line_count=0;

void yyerror(char *s){
	fprintf(logout,"At line no: %d Error: %s\n",s);
}


%}

%union { double dval;float fval; int ivar; char cvar; char *strval; int line_count; }
%token <dval> DOUBLE
%token <strval> CONST_FLOAT
%token <cvar> ADDOP MULOP
%token <strval> ID LOGICOP RELOP
%token <strval> CONST_CHAR
%token <ivar> CONST_INT

%token NEWLINE PLUS MINUS SLASH ASTERISK LPAREN RPAREN IF ELSE FOR DO INT FLOAT VOID SWITCH DEFAULT WHILE BREAK CHAR RETURN CASE CONTINUE ASSIGNOP COMMA INCOP DECOP LCURL RCURL LTHIRD RTHIRD NOT PRINTLN SEMICOLON

%type <strval> variable factor term unary_expression simple_expression rel_expression expression_statement arguments argument_list statement statements compound_statement type_specifier parameter_list declaration_list func_declaration func_definition var_declaration logic_expression expression unit program start INT FLOAT

%%

			start : program
				{
					//write your code in this block in all the similar blocks below
					fprintf(logout,"At line no: %d start : program\n\n",line_count);
					$$ = $1;
					fprintf(logout,"%s\n\n",$1);

				}
				;

			program : program unit	{
					fprintf(logout,"At line no: %d program : program unit\n\n",line_count);

					char * tmp = (char *) malloc(1+strlen($1)+strlen($2));
					char tmp2[2];
					tmp2[0]='\n';tmp2[1]='\0';

					strcpy(tmp , $1);
					strcat(tmp , tmp2);
					strcat(tmp , $2);

					vec.push_back(tmp);
					$$ = tmp;
					fprintf(logout,"%s \n\n",tmp);


				}
				| unit	{
					fprintf(logout,"At line no: %d program : | unit\n\n",line_count);
					$$ = $1;
					fprintf(logout,"%s\n\n",$1);

				}
				;

			unit : var_declaration	{
						fprintf(logout,"At line no: %d unit : var_declaration\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s\n\n",$1);

					 }
			     | func_declaration		  {fprintf(logout,"At line no: %d unit : func_declaration\n\n",line_count);}
			     | func_definition	{ fprintf(logout,"At line no: %d unit : func_definition\n\n",line_count);}
			     ;

			 func_definition : type_specifier ID LPAREN RPAREN compound_statement {
				 		 fprintf(logout,"At line no: %d func_definition : type_specifier ID LPAREN  RPAREN compound_statement\n\n",line_count);
						 char tmp[2];
 						tmp[0]='(';tmp[1]='\0';

 						char * tmp2 = (char *) malloc(1+strlen($1)+strlen($2)+2+strlen($5));

 						strcpy(tmp2 , $1);
 						strcat(tmp2 , $2);
 						strcat(tmp2 , tmp);
 						tmp[0] = ')';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $5);

 						vec.push_back(tmp2);
 						$$ = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					 }
					 |type_specifier ID LPAREN parameter_list RPAREN compound_statement{

						 fprintf(logout,"At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n",line_count);
						 char tmp[2];
						 tmp[0]='(';tmp[1]='\0';

						 char * tmp2 = (char *) malloc(1+strlen($1)+strlen($2)+1+strlen($4)+1+strlen($6));

						 strcpy(tmp2 , $1);
						 strcat(tmp2 , $2);
						 strcat(tmp2 , tmp);
						 strcat(tmp2 , $4);
						 tmp[0] = ')';
						 strcat(tmp2 , tmp);
						 strcat(tmp2 , $6);

						 vec.push_back(tmp2);
						 $$ = tmp2;
						 fprintf(logout,"%s \n\n",tmp2);

			 		}
					;

			compound_statement : LCURL statements RCURL  {

							fprintf(logout,"At line no: %d compound_statement : LCURL statements RCURL\n\n",line_count);
							char tmp[2];
							tmp[0]='{';tmp[1]='\0';

							char * tmp2 = (char *) malloc(1+strlen($2)+2);

							strcat(tmp2 , tmp);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							strcat(tmp2 , $2);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							tmp[0] = '}';
							strcat(tmp2 , tmp);

							vec.push_back(tmp2);
							$$ = tmp2;
							fprintf(logout,"%s \n\n",tmp2);

						}
						| LCURL RCURL  {

							 fprintf(logout,"At line no: %d compound_statement : LCURL RCURL\n\n",line_count);
							 char tmp[2];
							 tmp[0]='{';tmp[1]='\0';

							 char * tmp2 = (char *) malloc(1+2);

							 tmp[0] = '\n';
 							 strcat(tmp2 , tmp);
 							strcat(tmp2 , tmp);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							 tmp[0] = '}';
							 strcat(tmp2 , tmp);

							 vec.push_back(tmp2);
							 $$ = tmp2;
							 fprintf(logout,"%s \n\n",tmp2);

						 }
						;

			func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON	{

						fprintf(logout,"At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n",line_count);

						char tmp[2];
						tmp[0]='(';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1)+strlen($2)+1+strlen($4)+2);

						strcpy(tmp2 , $1);
						strcat(tmp2 , $2);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $4);
						tmp[0] = ')';
						strcat(tmp2 , tmp);
						tmp[0] = ';';
						strcat(tmp2 , tmp);


						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

				  }
					| type_specifier ID LPAREN RPAREN SEMICOLON	{

						fprintf(logout,"At line no: %d func_declaration :type_specifier ID LPAREN RPAREN SEMICOLON\n\n",line_count);
						char tmp[2];
						tmp[0]='(';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1)+strlen($2)+3);

						strcpy(tmp2 , $1);
						strcat(tmp2 , $2);
						strcat(tmp2 , tmp);
						tmp[0] = ')';
						strcat(tmp2 , tmp);
						tmp[0] = ';';
						strcat(tmp2 , tmp);


						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
					;



			parameter_list  : parameter_list COMMA type_specifier ID  {
						fprintf(logout,"At line no: %d parameter_list  : parameter_list COMMA type_specifier ID\n\n",line_count);
						char tmp[2];
						tmp[0]=',';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1)+1+strlen($3)+strlen($4));

						strcpy(tmp2 , $1);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $3);
						strcat(tmp2 , $4);


						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
					| parameter_list COMMA type_specifier  {

						fprintf(logout,"At line no: %d parameter_list : parameter_list COMMA type_specifier\n\n",line_count);
						char tmp[2];
						tmp[0]=',';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1)+1+strlen($3));

						strcpy(tmp2 , $1);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $3);

						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
			 		| type_specifier ID  {

						fprintf(logout,"At line no: %d parameter_list : type_specifier ID\n\n",line_count);
						char * tmp2 = (char *) malloc(1+strlen($1)+strlen($2));

						strcpy(tmp2 , $1);
						strcat(tmp2 , $2);

						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

						vec.push_back($2);

					}
					| type_specifier  {
						fprintf(logout,"At line no: %d parameter_list : type_specifier\n\n",line_count);
						fprintf(logout,"%s \n\n",$1);
						$$ = $1;
					}
			 		;



			var_declaration : type_specifier declaration_list SEMICOLON  {
				fprintf(logout,"At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n\n",line_count);

				char * tmp = (char *) malloc(1 + strlen($1) + 1 + strlen($2));
				strcpy(tmp, $1);
				char tmp2[2];
				tmp2[1] = '\0';
				tmp2[0] = ';';
				strcat(tmp, $2);
				strcat(tmp , tmp2);
				tmp2[0] = '\n';
				strcat(tmp , tmp2);

				fprintf(logout,"%s\n\n",tmp);
				$$ = tmp;
				//vec.push_back($3);

				cout<<vec.size()<<endl;

			};

			type_specifier	: INT {

				fprintf(logout,"At line no: %d type_specifier:INT\n\n",line_count);

				char tmp[5];
				tmp[0]='i';tmp[1]='n';tmp[2]='t';tmp[3]=' ';tmp[4]='\0';

				char * tmp2 = (char *) malloc(1+strlen(tmp));
				strcat(tmp2 , tmp);

				vec.push_back(tmp2);
				$$ = tmp2;
				fprintf(logout,"%s \n\n",tmp2);

				}
		 		| FLOAT {

					fprintf(logout,"At line no: %d type_specifier : FLOAT\n\n",line_count);

					char tmp[7];
					tmp[0]='f';tmp[1]='l';tmp[2]='o';tmp[3]='a';tmp[4]='t';tmp[5]='   ';tmp[6]='\0';

					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$ = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
		 		| VOID {

					fprintf(logout,"At line no: %d type_specifier : VOID\n\n",line_count);
					char tmp[6];
					tmp[0]='v';tmp[1]='o';tmp[2]='i';tmp[3]='d';tmp[4]=' ';tmp[5]='\0';

					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$ = tmp2;
					fprintf(logout,"%s \n\n",tmp2);


				}
		 		;

			declaration_list : declaration_list COMMA ID {

						fprintf(logout,"At line no: %d declaration_list : declaration_list COMMA ID\n\n",line_count);

						char * tmp = (char *) malloc(1 + strlen($1)+ 1+strlen($3) );
			      strcpy(tmp, $1);
						char tmp2[2];
						tmp2[1] = '\0';
						tmp2[0] = ',';
			      strcat(tmp, tmp2);
						strcat(tmp , $3);

						fprintf(logout,"%s\n\n",tmp);
						$$ = tmp;
						vec.push_back($3);

						cout<<vec.size()<<endl;

					}
		 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {

						fprintf(logout,"At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n",line_count);
						/* fprintf(logout,"At line no: %d , %s[%c]",$3 , $5); */
					}
		 		  | ID {

						fprintf(logout,"At line no: %d declaration_list : ID\n\n",line_count);
						fprintf(logout,"%s\n\n",$1);
						vec.push_back($1);
						$$ = $1;
					}
		 		  | ID LTHIRD CONST_INT RTHIRD {

						fprintf(logout,"At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n",line_count);

						char tmp[2];
 						tmp[0]='[';tmp[1]='\0';

						char integer[2];
						sprintf(integer, "%d", $3);

 						char * tmp2 = (char *) malloc(1+strlen($1)+1+strlen(integer)+1);

 						strcpy(tmp2 , $1);
 						strcat(tmp2 , tmp);
						strcat(tmp2 , integer);
						tmp[0]=']';
						strcat(tmp2 , tmp);

 						vec.push_back(tmp2);
 						$$ = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					 }
		 		  ;

			statements : statement {
						//
						fprintf(logout,"At line no: %d statements : statement \n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1);

					 }
				   | statements statement {
						 fprintf(logout,"At line no: %d statements :| statements statement \n\n",line_count);

 						char * tmp2 = (char *) malloc(1+strlen($1)+strlen($2));

 						strcpy(tmp2 , $1);
 						strcat(tmp2 , $2);

 						vec.push_back(tmp2);
 						$$ = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					 }
				   ;

			statement : var_declaration	{
					fprintf(logout,"At line no: %d statement : var_declaration\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1);

					}
					| expression_statement	{
						 fprintf(logout,"At line no: %d statement : expression_statement\n\n",line_count);
						 $$ = $1;
 						fprintf(logout,"%s \n\n",$1);

					 }
				  | compound_statement	{
						fprintf(logout,"At line no: %d statement : compound_statement\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1);

					}
				  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{

						fprintf(logout,"At line no: %d statement :  FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",line_count);
					}
				  | IF LPAREN expression RPAREN statement ELSE statement	{

						fprintf(logout,"At line no: %d statement : IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count);
					}
					| IF LPAREN expression RPAREN statement	{

							fprintf(logout,"At line no: %d statement : IF LPAREN expression RPAREN statement\n\n",line_count);
					}
				  | WHILE LPAREN expression RPAREN statement	{

						fprintf(logout,"At line no: %d statement : WHILE LPAREN expression RPAREN statement\n\n",line_count);
					}
				  | PRINTLN LPAREN ID RPAREN SEMICOLON	{
						fprintf(logout,"At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count);
					}
				  | RETURN expression SEMICOLON	{

						fprintf(logout,"At line no: %d statement : RETURN expression SEMICOLON\n\n",line_count);
						char tmp[8];
						tmp[0]='r';tmp[1]='e';tmp[2]='t';tmp[3]='u';tmp[4]='r';tmp[5]='n';tmp[6]=' ';tmp[7]='\0';

						char * tmp2 = (char *) malloc(1+strlen($2)+9);

						strcpy(tmp2 , tmp);
						strcat(tmp2 , $2);
						tmp[0]=';';tmp[1]='\0';
						strcat(tmp2 , tmp);
						tmp[0]='\n';tmp[1]='\0';
						strcat(tmp2 , tmp);

						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
				  ;
			expression : logic_expression	{
						fprintf(logout,"At line no: %d expression : logic_expression\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1);
					}
					| variable ASSIGNOP logic_expression	{

						fprintf(logout,"At line no: %d expression : variable ASSIGNOP logic_expression\n\n",line_count);
						char tmp[2];
						tmp[0]='=';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1)+strlen($3)+1);

						strcpy(tmp2 , $1);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $3);

						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
					;

			expression_statement 	: SEMICOLON	{

						fprintf(logout,"At line no: %d expression_statement 	: SEMICOLON\n\n",line_count);
						char tmp[2];
						tmp[0]=';';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+1);

						strcpy(tmp2 , tmp);
						tmp[0]='\n';tmp[1]='\0';
						strcpy(tmp2 , tmp);

						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
					| expression SEMICOLON	{

						fprintf(logout,"At line no: %d expression_statement 	: expression SEMICOLON\n\n",line_count);
						char tmp[2];
						tmp[0]=';';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1)+1);

						strcpy(tmp2 , $1);
						strcat(tmp2 , tmp);
						tmp[0]='\n';tmp[1]='\0';
						strcat(tmp2 , tmp);

						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
					;

			variable : ID	{

					fprintf(logout,"At line no: %d variable : ID\n\n",line_count);
					$$ = $1;
					fprintf(logout,"%s\n\n",$1);

					vec.push_back($1);

				}
			 | ID LTHIRD expression RTHIRD	{

				 fprintf(logout,"At line no: %d variable : ID LTHIRD expression RTHIRD\n\n",line_count);
				 char tmp[2];
				 tmp[0]='[';tmp[1]='\0';

			 	 char * tmp2 = (char *) malloc(1+strlen($1)+1+strlen($3)+1);

				 strcpy(tmp2 , $1);
				 strcat(tmp2 , tmp);
				 strcat(tmp2 , $3);
				 tmp[0]=']';
				 strcat(tmp2 , tmp);

					 vec.push_back(tmp2);
					 $$ = tmp2;
					 fprintf(logout,"%s \n\n",tmp2);

			 }
			 ;



			logic_expression : rel_expression	{
				 			fprintf(logout,"At line no: %d logic_expression : rel_expression\n\n",line_count);
							$$ = $1;
 						 fprintf(logout,"%s \n\n",$1);
						}
					 | rel_expression LOGICOP rel_expression	{

						 fprintf(logout,"At line no: %d logic_expression : rel_expression LOGICOP rel_expression\n\n",line_count);

 						char * tmp2 = (char *) malloc(1+strlen($1)+strlen($2)+strlen($3));

 						strcpy(tmp2 , $1);
 						strcat(tmp2 , $2);
 						strcat(tmp2 , $3);

 						vec.push_back(tmp2);
 						$$ = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					 }
					 ;

			rel_expression	: simple_expression	{
							fprintf(logout,"At line no: %d rel_expression	: simple_expression\n\n",line_count);
							$$ = $1;
 						 fprintf(logout,"%s \n\n",$1);
					}
					| simple_expression RELOP simple_expression	{

						fprintf(logout,"At line no: %d rel_expression	: simple_expression RELOP simple_expression\n\n",line_count);

						char * tmp2 = (char *) malloc(1+strlen($1)+strlen($2)+strlen($3));

						strcpy(tmp2 , $1);
						strcat(tmp2 , $2);
						strcat(tmp2 , $3);

						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
					;

			simple_expression : term	{
						fprintf(logout,"At line no: %d simple_expression : term\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1);
					}
				  | simple_expression ADDOP term	{

						fprintf(logout,"At line no: %d simple_expression : simple_expression ADDOP term\n\n",line_count);
						char tmp[2];
						tmp[0]=$2;tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1)+1+strlen($3));

						strcpy(tmp2 , $1);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $3);

						vec.push_back(tmp2);
						$$ = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
				  ;

			term :	unary_expression	{
						fprintf(logout,"At line no: %d term :	unary_expression\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1);
					}
		     |  term MULOP unary_expression	{
					 fprintf(logout,"At line no: %d term :	term MULOP unary_expression\n\n",line_count);

					 char tmp[2];
					 tmp[0]=$2;tmp[1]='\0';

					 char * tmp2 = (char *) malloc(1+strlen($1)+1+strlen($3));

					 strcpy(tmp2 , $1);
					 strcat(tmp2 , tmp);
					 strcat(tmp2 , $3);

					 vec.push_back(tmp2);
					 $$ = tmp2;
					 fprintf(logout,"%s \n\n",tmp2);
				 }
		     ;

			unary_expression : ADDOP unary_expression	{

							fprintf(logout,"At line no: %d unary_expression : ADDOP unary_expression\n\n",line_count);
					}
					 | NOT unary_expression	{

						 fprintf(logout,"At line no: %d unary_expression : NOT unary_expression\n\n",line_count);
					 }
					 | factor	{
						 fprintf(logout,"At line no: %d unary_expression : factor\n\n",line_count);
						 $$ = $1;
						 fprintf(logout,"%s \n\n",$1);

					 }
					 ;

			factor	: variable	{
					fprintf(logout,"At line no: %d factor	: variable\n\n",line_count);
					$$ = $1;
					fprintf(logout,"%s \n\n",$1);

				}
				| ID LPAREN argument_list RPAREN	{

					fprintf(logout,"At line no: %d factor	: ID LPAREN argument_list RPAREN\n\n",line_count);
					char tmp[2];
					tmp[0]='(';tmp[1]='\0';

					char * tmp2 = (char *) malloc(1+strlen($1)+1+strlen($3)+1);

					strcpy(tmp2 , $1);
					strcat(tmp2 , tmp);
					strcat(tmp2 , $3);
					tmp[0] = ')';
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$ = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| LPAREN expression RPAREN	{

					fprintf(logout,"At line no: %d factor : LPAREN expression RPAREN\n\n",line_count);
					char tmp[2];
					tmp[0]='(';tmp[1]='\0';

					char * tmp2 = (char *) malloc(1+strlen($2)+2);

					strcat(tmp2 , tmp);
					strcat(tmp2 , $2);
					tmp[0] = ')';
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$ = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| CONST_INT	{

					fprintf(logout,"At line no: %d factor : CONST_INT\n\n",line_count);

					char tmp[2];
					sprintf(tmp, "%d", $1);
					char * tmp2 = (char *) malloc(1+strlen(tmp));

					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$ = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| CONST_FLOAT	{

					fprintf(logout,"At line no: %d factor : CONST_FLOAT\n\n",line_count);

					/* char * tmp2 = (char *) malloc(1+strlen($1)); */

					/* strcat(tmp2 , $1); */

					$$ = $1;
					fprintf(logout,"%s \n\n",$1);
				}
				| variable INCOP	{

					fprintf(logout,"At line no: %d factor : variable INCOP\n\n",line_count);
				}
				| variable DECOP	{

					fprintf(logout,"At line no: %d factor : variable DECOP\n\n",line_count);
				}
				;

			argument_list : arguments	{
						fprintf(logout,"At line no: %d argument_list : arguments\n\n",line_count);
					}
				  |	{
						fprintf(logout,"At line no: %d argument_list :\n\n",line_count);
					}
				  ;

			arguments : arguments COMMA logic_expression	{

						fprintf(logout,"At line no: %d arguments : arguments COMMA logic_expression\n\n",line_count);
					}
		      | logic_expression	{
						fprintf(logout,"At line no: %d arguments : logic_expression\n\n",line_count);
					}
		      ;

%%
int main(int argc,char *argv[])
{
  FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		fprintf(logout,"At line no: %d Cannot Open Input File.\n\n",line_count);
		exit(1);
	}

	/* FILE * log = fopen("log.txt","w"); */
	// fclose(fp2);
	// fclose(fp3);
  //
	// fp2= fopen(argv[2],"a");
	// fp3= fopen(argv[3],"a");

	yyin=fp;
	yyparse();


	 fclose(logout);
	 fclose(error);

	return 0;
}
