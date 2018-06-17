%{
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<vector>
#include "SymbolTable.h"
/* #define YYSTYPE double      /* yyparse() stack type */

using namespace std;

/* int yyparse(void); */
int yylex(void);
extern FILE *yyin;
extern int line_count;
extern int error_count;
vector<char *> vec;

 FILE * logout = fopen("log.txt","w");
 FILE *error= fopen("error.txt","w");
SymbolTable * symboltable = new SymbolTable(30);

void yyerror(const char *s){
	fprintf(logout,"At line no: %d  %s\n",line_count,s);
  printf("At line no %d : %s\n",line_count,s);

}


%}
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%error-verbose
%code requires {
    struct node {
        char * mystr;
        char charvalue;
        int intvalue;
        float floatvalue;
        double doublevalue;
        struct node * next;
    };
}
%union {
  double dval;
  float fval;
  int ivar;
  char cvar;
  char *strval;
  int line_count;
  struct node args;
}

%token <args> DOUBLE
%token <args> CONST_FLOAT
%token <args> ADDOP MULOP
%token <args> ID LOGICOP RELOP
%token <args> CONST_CHAR
%token <args> CONST_INT

%token NEWLINE PLUS MINUS SLASH ASTERISK LPAREN RPAREN IF ELSE FOR DO INT FLOAT VOID SWITCH DEFAULT WHILE BREAK CHAR RETURN CASE CONTINUE ASSIGNOP COMMA INCOP DECOP LCURL RCURL LTHIRD RTHIRD NOT PRINTLN SEMICOLON

%type <args> factor  variable term unary_expression simple_expression rel_expression expression_statement arguments argument_list statement statements compound_statement type_specifier parameter_list declaration_list func_declaration func_definition var_declaration logic_expression expression unit program start INT FLOAT


%%

			start : program
				{
					fprintf(logout,"At line no: %d start : program\n\n",line_count);
					$$.mystr = $1.mystr;
					fprintf(logout,"%s\n\n",$1.mystr);
          fprintf(error,"Total Errors: %d\n\n",error_count);

				}
				;

			program : program unit	{
					fprintf(logout,"At line no: %d program : program unit\n\n",line_count);

					char * tmp = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr));
					char tmp2[2];
					tmp2[0]='\n';tmp2[1]='\0';

					strcpy(tmp , $1.mystr);
					strcat(tmp , tmp2);
					strcat(tmp , $2.mystr);

					vec.push_back(tmp);
					$$.mystr = tmp;
					fprintf(logout,"%s \n\n",tmp);


				}
				| unit	{
					fprintf(logout,"At line no: %d program : | unit\n\n",line_count);
					$$.mystr = $1.mystr;
					fprintf(logout,"%s\n\n",$1.mystr);

				}
				;

			unit : var_declaration	{
						fprintf(logout,"At line no: %d unit : var_declaration\n\n",line_count);
						$$.mystr = $1.mystr;
						fprintf(logout,"%s\n\n",$1.mystr);

					 }
			     | func_declaration		  {
						 fprintf(logout,"At line no: %d unit : func_declaration\n\n",line_count);
						 $$.mystr = $1.mystr;
						 fprintf(logout,"%s \n\n",$1.mystr);
					 }
			     | func_definition	{
						 fprintf(logout,"At line no: %d unit : func_definition\n\n",line_count);
						 $$.mystr = $1.mystr;
						 fprintf(logout,"%s \n\n",$1.mystr);

					 }
			     ;

         func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON	{

               fprintf(logout,"At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n",line_count);

               char tmp[2];
               tmp[0]='(';tmp[1]='\0';

               char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+1+strlen($4.mystr)+2);

               strcpy(tmp2 , $1.mystr);
               strcat(tmp2 , $2.mystr);
               strcat(tmp2 , tmp);
               strcat(tmp2 , $4.mystr);
               tmp[0] = ')';
               strcat(tmp2 , tmp);
               tmp[0] = ';';
               strcat(tmp2 , tmp);


               vec.push_back(tmp2);
               $$.mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);

             }
             | type_specifier ID LPAREN RPAREN SEMICOLON	{

               fprintf(logout,"At line no: %d func_declaration :type_specifier ID LPAREN RPAREN SEMICOLON\n\n",line_count);
               char tmp[2];
               tmp[0]='(';tmp[1]='\0';

               char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+3);

               strcpy(tmp2 , $1.mystr);
               strcat(tmp2 , $2.mystr);
               strcat(tmp2 , tmp);
               tmp[0] = ')';
               strcat(tmp2 , tmp);
               tmp[0] = ';';
               strcat(tmp2 , tmp);


               vec.push_back(tmp2);
               $$.mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);
               symboltable->Insert($2.mystr , "ID", "FUNCTION");
             }
             ;

			 func_definition : type_specifier ID LPAREN RPAREN compound_statement {
				 		 fprintf(logout,"At line no: %d func_definition : type_specifier ID LPAREN  RPAREN compound_statement\n\n",line_count);
						char tmp[2];
 						tmp[0]='(';tmp[1]='\0';

 						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+2+strlen($5.mystr));

 						strcpy(tmp2 , $1.mystr);
 						strcat(tmp2 , $2.mystr);
 						strcat(tmp2 , tmp);
 						tmp[0] = ')';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $5.mystr);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
						symboltable->Insert($2.mystr , "ID","FUNCTION");
					 }
					 |type_specifier ID LPAREN parameter_list RPAREN compound_statement{

						 fprintf(logout,"At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n",line_count);
						 char tmp[2];
						 tmp[0]='(';tmp[1]='\0';

						 char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+1+strlen($4.mystr)+1+strlen($6.mystr));

						 strcpy(tmp2 , $1.mystr);
						 strcat(tmp2 , $2.mystr);
						 strcat(tmp2 , tmp);
						 strcat(tmp2 , $4.mystr);
						 tmp[0] = ')';
						 strcat(tmp2 , tmp);
						 strcat(tmp2 , $6.mystr);

						 vec.push_back(tmp2);
						 $$.mystr = tmp2;
						 fprintf(logout,"%s \n\n",tmp2);
						 symboltable->Insert($2.mystr , "ID","FUNCTION");

			 		}
					;

        parameter_list  : parameter_list COMMA type_specifier ID  {
              fprintf(logout,"At line no: %d parameter_list  : parameter_list COMMA type_specifier ID\n\n",line_count);
              char tmp[2];
              tmp[0]=',';tmp[1]='\0';

              char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen($3.mystr)+strlen($4.mystr));

              strcpy(tmp2 , $1.mystr);
              strcat(tmp2 , tmp);
              strcat(tmp2 , $3.mystr);
              strcat(tmp2 , $4.mystr);


              vec.push_back(tmp2);
              $$.mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);
              //symboltable->EnterScope();

            }
            | parameter_list COMMA type_specifier  {

              fprintf(logout,"At line no: %d parameter_list : parameter_list COMMA type_specifier\n\n",line_count);
              char tmp[2];
              tmp[0]=',';tmp[1]='\0';

              char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen($3.mystr));

              strcpy(tmp2 , $1.mystr);
              strcat(tmp2 , tmp);
              strcat(tmp2 , $3.mystr);

              vec.push_back(tmp2);
              $$.mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);

            }
            | type_specifier ID  {

              fprintf(logout,"At line no: %d parameter_list : type_specifier ID\n\n",line_count);
              char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr));

              strcpy(tmp2 , $1.mystr);
              strcat(tmp2 , $2.mystr);

              vec.push_back(tmp2);
              $$.mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);

              vec.push_back($2.mystr);

            }
            | type_specifier  {
              fprintf(logout,"At line no: %d parameter_list : type_specifier\n\n",line_count);
              fprintf(logout,"%s \n\n",$1.mystr);
              $$.mystr = $1.mystr;
            }
            ;

			compound_statement : LCURL {symboltable->EnterScope();} statements RCURL  {

							fprintf(logout,"At line no: %d compound_statement : LCURL statements RCURL\n\n",line_count);
							char tmp[2];
							tmp[0]='{';tmp[1]='\0';

							char * tmp2 = (char *) malloc(1+strlen($3.mystr)+2);

							strcat(tmp2 , tmp);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							strcat(tmp2 , $3.mystr);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							tmp[0] = '}';
							strcat(tmp2 , tmp);

							vec.push_back(tmp2);
							$$.mystr = tmp2;
							fprintf(logout,"%s \n\n",tmp2);
							symboltable->PrintAllScopes();
							symboltable->ExitScope();
						}
						| LCURL {symboltable->EnterScope();} RCURL  {

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
							 $$.mystr = tmp2;
							 fprintf(logout,"%s \n\n",tmp2);
               symboltable->PrintAllScopes();
               symboltable->ExitScope();
						 }
						;

			var_declaration : type_specifier declaration_list SEMICOLON  {
				fprintf(logout,"At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n\n",line_count);

				char * tmp = (char *) malloc(1 + strlen($1.mystr) + 1 + strlen($2.mystr));
				strcpy(tmp, $1.mystr);
				char tmp2[2];
				tmp2[1] = '\0';
				tmp2[0] = ';';
				strcat(tmp, $2.mystr);
				strcat(tmp , tmp2);
				tmp2[0] = '\n';
				strcat(tmp , tmp2);

				fprintf(logout,"%s\n\n",tmp);
				$$.mystr = tmp;
				/* cout<<vec.size()<<endl; */

			};

			type_specifier	: INT {

				fprintf(logout,"At line no: %d type_specifier:INT\n\n",line_count);

				char tmp[5];
				tmp[0]='i';tmp[1]='n';tmp[2]='t';tmp[3]=' ';tmp[4]='\0';

				char * tmp2 = (char *) malloc(1+strlen(tmp));
				strcat(tmp2 , tmp);

				vec.push_back(tmp2);
				$$.mystr = tmp2;
				fprintf(logout,"%s \n\n",tmp2);

				}
		 		| FLOAT {

					fprintf(logout,"At line no: %d type_specifier : FLOAT\n\n",line_count);

					char tmp[7];
					tmp[0]='f';tmp[1]='l';tmp[2]='o';tmp[3]='a';tmp[4]='t';tmp[5]='   ';tmp[6]='\0';

					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
		 		| VOID {

					fprintf(logout,"At line no: %d type_specifier : VOID\n\n",line_count);
					char tmp[6];
					tmp[0]='v';tmp[1]='o';tmp[2]='i';tmp[3]='d';tmp[4]=' ';tmp[5]='\0';

					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);
				}
		 		;

			declaration_list : declaration_list COMMA ID {

						fprintf(logout,"At line no: %d declaration_list : declaration_list COMMA ID\n\n",line_count);

						char * tmp = (char *) malloc(1 + strlen($1.mystr)+ 1+strlen($3.mystr) );
			      strcpy(tmp, $1.mystr);
						char tmp2[2];
						tmp2[1] = '\0';
						tmp2[0] = ',';
			      strcat(tmp, tmp2);
						strcat(tmp , $3.mystr);

						fprintf(logout,"%s\n\n",tmp);
						$$.mystr = tmp;
						vec.push_back($3.mystr);
						symboltable->Insert($3.mystr , "ID","");

						/* cout<<vec.size()<<endl; */

					}
		 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {

						fprintf(logout,"At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n",line_count);
						char integer[2];
						sprintf(integer, "%d", $5.intvalue);

						char * tmp = (char *) malloc(1 + strlen($1.mystr)+ 1+strlen($3.mystr)+3 );

						strcpy(tmp, $1.mystr);
						char tmp2[2];
						tmp2[1] = '\0';
						tmp2[0] = ',';
			      strcat(tmp, tmp2);
						strcat(tmp , $3.mystr);
						tmp2[0] = '[';
			      strcat(tmp, tmp2);
						strcat(tmp, integer);
						tmp2[0] = ']';
			      strcat(tmp, tmp2);


						fprintf(logout,"%s\n\n",tmp);
						$$.mystr = tmp;
            symboltable->Insert($3.mystr , "ID","ARRAY");

					}
		 		  | ID {

						fprintf(logout,"At line no: %d declaration_list : ID\n\n",line_count);
						fprintf(logout,"%s\n\n",$1.mystr);
						vec.push_back($1.mystr);
						$$.mystr = $1.mystr;
						symboltable->Insert($$.mystr , "ID","");
					}
		 		  | ID LTHIRD CONST_INT RTHIRD {

						fprintf(logout,"At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n",line_count);

						char tmp[2];
 						tmp[0]='[';tmp[1]='\0';

						char integer[2];
						sprintf(integer, "%d", $3.intvalue);

 						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen(integer)+1);

 						strcpy(tmp2 , $1.mystr);
 						strcat(tmp2 , tmp);
						strcat(tmp2 , integer);
						tmp[0]=']';
						strcat(tmp2 , tmp);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
						symboltable->Insert($1.mystr , "ID","ARRAY");

					 }
		 		  ;

			statements : statement {
						//
						fprintf(logout,"At line no: %d statements : statement \n\n",line_count);
						$$.mystr = $1.mystr;
						fprintf(logout,"%s \n\n",$1.mystr);

					 }
				   | statements statement {
						 fprintf(logout,"At line no: %d statements :| statements statement \n\n",line_count);

 						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr));

 						strcpy(tmp2 , $1.mystr);
 						strcat(tmp2 , $2.mystr);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					 }
				   ;

			statement : var_declaration	{
					fprintf(logout,"At line no: %d statement : var_declaration\n\n",line_count);
						$$.mystr = $1.mystr;
						fprintf(logout,"%s \n\n",$1.mystr);

					}
					| expression_statement	{
						 fprintf(logout,"At line no: %d statement : expression_statement\n\n",line_count);
						 $$.mystr = $1.mystr;
 						fprintf(logout,"%s \n\n",$1.mystr);

					 }
				  | compound_statement	{
						fprintf(logout,"At line no: %d statement : compound_statement\n\n",line_count);
						$$.mystr = $1.mystr;
						fprintf(logout,"%s \n\n",$1.mystr);

					}
				  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{

						fprintf(logout,"At line no: %d statement :  FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",line_count);

						char tmp[4];
 						tmp[0]='f';tmp[1]='o';tmp[2]='r';tmp[3]='\0';

 						char * tmp2 = (char *) malloc(1+strlen(tmp)+1+strlen($3.mystr)+strlen($3.mystr)+strlen($3.mystr)+1+strlen($7.mystr));

 						strcpy(tmp2 , tmp);
						tmp[0]='(';tmp[1]='\0';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $3.mystr);
						strcat(tmp2 , $4.mystr);
						strcat(tmp2 , $5.mystr);

 						tmp[0] = ')';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $7.mystr);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					}
				  | IF LPAREN expression RPAREN statement ELSE statement	{

						fprintf(logout,"At line no: %d statement : IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count);

						char tmp[5];
 						tmp[0]='i';tmp[1]='f';tmp[2]='\0';

 						char * tmp2 = (char *) malloc(1+strlen(tmp)+strlen(tmp)+strlen($3.mystr)+1+strlen($5.mystr)+strlen(tmp)+strlen($7.mystr));

 						strcpy(tmp2 , tmp);
						tmp[0]='(';tmp[1]='\0';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $3.mystr);
						tmp[0] = ')';
 						strcat(tmp2 , tmp);

						strcat(tmp2 , $5.mystr);
						tmp[0]='e';tmp[1]='l';tmp[2]='s';tmp[3]='e';tmp[4]='\0';
						strcat(tmp2 , tmp);

 						strcat(tmp2 , $7.mystr);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					}
					| IF LPAREN expression RPAREN statement	%prec LOWER_THAN_ELSE{

							fprintf(logout,"At line no: %d statement : IF LPAREN expression RPAREN statement\n\n",line_count);
							char tmp[5];
							tmp[0]='i';tmp[1]='f';tmp[2]='\0';

							char * tmp2 = (char *) malloc(1+strlen(tmp)+2+strlen($3.mystr)+1+strlen($5.mystr));

							strcpy(tmp2 , tmp);
							tmp[0]='(';tmp[1]='\0';
							strcat(tmp2 , tmp);
							strcat(tmp2 , $3.mystr);
							tmp[0] = ')';
							strcat(tmp2 , tmp);

							strcat(tmp2 , $5.mystr);

							vec.push_back(tmp2);
							$$.mystr = tmp2;
							fprintf(logout,"%s \n\n",tmp2);

					}
				  | WHILE LPAREN expression RPAREN statement	{

						fprintf(logout,"At line no: %d statement : WHILE LPAREN expression RPAREN statement\n\n",line_count);
						char tmp[6];
						tmp[0]='w';tmp[1]='h';tmp[2]='i';tmp[3]='l';tmp[4]='e';tmp[5]='\0';

 						char * tmp2 = (char *) malloc(1+strlen(tmp)+1+strlen($3.mystr)+1+strlen($5.mystr));

 						strcpy(tmp2 , tmp);
						tmp[0]='(';tmp[1]='\0';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $3.mystr);
						tmp[0] = ')';
 						strcat(tmp2 , tmp);
						strcat(tmp2 , $5.mystr);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					}
				  | PRINTLN LPAREN ID RPAREN SEMICOLON	{
						fprintf(logout,"At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count);

						char tmp[8];
						tmp[0]='p';tmp[1]='r';tmp[2]='i';tmp[3]='n';tmp[4]='t';tmp[5]='l';tmp[6]='n';tmp[7]='\0';

 						char * tmp2 = (char *) malloc(1+strlen(tmp)+1+strlen($3.mystr)+2);

 						strcpy(tmp2 , tmp);
						tmp[0]='(';tmp[1]='\0';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $3.mystr);
						tmp[0] = ')';
 						strcat(tmp2 , tmp);
						tmp[0] = ';';
						strcat(tmp2 , tmp);
						tmp[0] = '\n';
 						strcat(tmp2 , tmp);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

					}
				  | RETURN expression SEMICOLON	{

						fprintf(logout,"At line no: %d statement : RETURN expression SEMICOLON\n\n",line_count);
						char tmp[8];
						tmp[0]='r';tmp[1]='e';tmp[2]='t';tmp[3]='u';tmp[4]='r';tmp[5]='n';tmp[6]=' ';tmp[7]='\0';

						char * tmp2 = (char *) malloc(1+strlen($2.mystr)+9);

						strcpy(tmp2 , tmp);
						strcat(tmp2 , $2.mystr);
						tmp[0]=';';tmp[1]='\0';
						strcat(tmp2 , tmp);
						tmp[0]='\n';tmp[1]='\0';
						strcat(tmp2 , tmp);

						vec.push_back(tmp2);
						$$.mystr = tmp2;
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
              $$.mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);

            }
            | expression SEMICOLON	{

              fprintf(logout,"At line no: %d expression_statement 	: expression SEMICOLON\n\n",line_count);
              char tmp[2];
              tmp[0]=';';tmp[1]='\0';

              char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1);

              strcpy(tmp2 , $1.mystr);
              strcat(tmp2 , tmp);
              tmp[0]='\n';tmp[1]='\0';
              strcat(tmp2 , tmp);

              vec.push_back(tmp2);
              $$.mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);

            }
            ;

          variable : ID	{
              //symboltable->Insert($1.mystr , "ID");
              fprintf(logout,"At line no: %d variable : ID\n\n",line_count);
              $$.mystr = $1.mystr;
              fprintf(logout,"%s\n\n",$1.mystr);

              vec.push_back($1.mystr);

            }
           | ID LTHIRD expression RTHIRD	{

             fprintf(logout,"At line no: %d variable : ID LTHIRD expression RTHIRD\n\n",line_count);
             char tmp[2];
             tmp[0]='[';tmp[1]='\0';

             char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen($3.mystr)+1);

             strcpy(tmp2 , $1.mystr);
             strcat(tmp2 , tmp);
             strcat(tmp2 , $3.mystr);
             tmp[0]=']';
             strcat(tmp2 , tmp);
             if($3.floatvalue != NULL){
               error_count++;
               fprintf(error, "Error %d at Line %d: Non-integer Array Index \n\n",error_count , line_count);

             }
               vec.push_back(tmp2);
               $$.mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);

           }
           ;

			expression : logic_expression	{
						fprintf(logout,"At line no: %d expression : logic_expression\n\n",line_count);
						$$.mystr = $1.mystr;
            $$.floatvalue = $1.floatvalue;

						fprintf(logout,"%s \n\n",$1.mystr);
					}
					| variable ASSIGNOP logic_expression	{

						fprintf(logout,"At line no: %d expression : variable ASSIGNOP logic_expression\n\n",line_count);
						char tmp[2];
						tmp[0]='=';tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($3.mystr)+1);

						strcpy(tmp2 , $1.mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $3.mystr);

						vec.push_back(tmp2);
						$$.mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
					;

			logic_expression : rel_expression	{
				 			fprintf(logout,"At line no: %d logic_expression : rel_expression\n\n",line_count);
							$$.mystr = $1.mystr;
              $$.floatvalue = $1.floatvalue;

 						 fprintf(logout,"%s \n\n",$1.mystr);
						}
					 | rel_expression LOGICOP rel_expression	{

						 fprintf(logout,"At line no: %d logic_expression : rel_expression LOGICOP rel_expression\n\n",line_count);

 						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+strlen($3.mystr));

 						strcpy(tmp2 , $1.mystr);
 						strcat(tmp2 , $2.mystr);
 						strcat(tmp2 , $3.mystr);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					 }
					 ;

			rel_expression	: simple_expression	{
							fprintf(logout,"At line no: %d rel_expression	: simple_expression\n\n",line_count);
							$$.mystr = $1.mystr;
              $$.floatvalue = $1.floatvalue;

 						 fprintf(logout,"%s \n\n",$1.mystr);
					}
					| simple_expression RELOP simple_expression	{

						fprintf(logout,"At line no: %d rel_expression	: simple_expression RELOP simple_expression\n\n",line_count);

						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+strlen($3.mystr));

						strcpy(tmp2 , $1.mystr);
						strcat(tmp2 , $2.mystr);
						strcat(tmp2 , $3.mystr);

						vec.push_back(tmp2);
						$$.mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
					;

			simple_expression : term {
						fprintf(logout,"At line no: %d simple_expression : term\n\n",line_count);
						$$.mystr = $1.mystr;
            $$.floatvalue = $1.floatvalue;

            fprintf(logout,"%s \n\n",$1.mystr);

					}
				  | simple_expression ADDOP term	{

						fprintf(logout,"At line no: %d simple_expression : simple_expression ADDOP term\n\n",line_count);
						char tmp[2];
						tmp[0]=$2.charvalue; tmp[1]='\0';

						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen($3.mystr));

						strcpy(tmp2 , $1.mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $3.mystr);

						vec.push_back(tmp2);
						$$.mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
				  ;

			term :	unary_expression	{
						fprintf(logout,"At line no: %d term :	unary_expression\n\n",line_count);
						$$.mystr = $1.mystr;
            $$.floatvalue = $1.floatvalue;
            fprintf(logout,"%s \n\n",$$.mystr);

          }
		     |  term MULOP unary_expression	{
					 fprintf(logout,"At line no: %d term :	term MULOP unary_expression\n\n",line_count);

					 char tmp[2];
					 tmp[0]=$2.charvalue ;tmp[1]='\0';

					 char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen($3.mystr));

					 strcpy(tmp2 , $1.mystr);
					 strcat(tmp2 , tmp);
					 strcat(tmp2 , $3.mystr);

					 vec.push_back(tmp2);
					 $$.mystr = tmp2;
					 fprintf(logout,"%s \n\n",tmp2);
				 }
		     ;

			unary_expression : ADDOP unary_expression	{

							fprintf(logout,"At line no: %d unary_expression : ADDOP unary_expression\n\n",line_count);
							char tmp[2];
							tmp[0]=$1.charvalue;tmp[1]='\0';

							char * tmp2 = (char *) malloc(1+strlen($2.mystr));

							strcat(tmp2 , tmp);
							strcat(tmp2 , $2.mystr);

							vec.push_back(tmp2);
							$$.mystr = tmp2;
							fprintf(logout,"%s \n\n",tmp2);
					}
					 | NOT unary_expression	{

						 fprintf(logout,"At line no: %d unary_expression : NOT unary_expression\n\n",line_count);
						 char tmp[2];
 						 tmp[0]='!';tmp[1]='\0';

 						char * tmp2 = (char *) malloc(1+strlen($2.mystr)+1);

 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $2.mystr);

 						vec.push_back(tmp2);
 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					 }
					 | factor	{
						 fprintf(logout,"At line no: %d unary_expression : factor\n\n",line_count);
						 $$.mystr = $1.mystr;
             $$.floatvalue = $1.floatvalue;

             //cout<<$1.floatvalue<<" ---\n";
             //cout<<$1.mystr<<" ---\n";

						 fprintf(logout,"%s \n\n",$1.mystr);

					 }
					 ;

			factor	: variable	{
					fprintf(logout,"At line no: %d factor	: variable\n\n",line_count);
					$$.mystr = $1.mystr;
					fprintf(logout,"%s \n\n",$1.mystr);

				}
				| ID LPAREN argument_list RPAREN	{

					fprintf(logout,"At line no: %d factor	: ID LPAREN argument_list RPAREN\n\n",line_count);
					char tmp[2];
					tmp[0]='(';tmp[1]='\0';

					char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen($3.mystr)+1);

					strcpy(tmp2 , $1.mystr);
					strcat(tmp2 , tmp);
					strcat(tmp2 , $3.mystr);
					tmp[0] = ')';
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| LPAREN expression RPAREN	{

					fprintf(logout,"At line no: %d factor : LPAREN expression RPAREN\n\n",line_count);
					char tmp[2];
					tmp[0]='(';tmp[1]='\0';

					char * tmp2 = (char *) malloc(1+strlen($2.mystr)+2);

					strcat(tmp2 , tmp);
					strcat(tmp2 , $2.mystr);
					tmp[0] = ')';
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| CONST_INT	{

					fprintf(logout,"At line no: %d factor : CONST_INT\n\n",line_count);

					char tmp[2];
					sprintf(tmp, "%d", $1.intvalue);
					char * tmp2 = (char *) malloc(1+strlen(tmp));

					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| CONST_FLOAT	{

					fprintf(logout,"At line no: %d factor : CONST_FLOAT\n\n",line_count);
          //cout<<$1.mystr<<" ------\n";
          /* char array[10];
          sprintf(array, "%f", $1.mystr); */

          char* str=NULL;
          int len = asprintf(&str, "%g", $1.floatvalue);
          if (len == -1)
            fprintf(error, "Error %d at Line %d: Error converting float: %m\n",error_count , line_count);
          else
            fprintf(logout,"%s \n\n",str);

          char * tmp2 = (char *) malloc(1+strlen(str));

					strcpy(tmp2 , str);
					/* $$.mystr = $1.mystr; */
          $$.floatvalue = $1.floatvalue;
          $$.mystr = tmp2;
          free(str);

				}
				| variable INCOP	{

					fprintf(logout,"At line no: %d factor : variable INCOP\n\n",line_count);
					char tmp[3];
					tmp[0] = '+';tmp[1]='+';tmp[2]='\0';
					char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1);

					strcpy(tmp2 , $1.mystr);
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| variable DECOP	{

					fprintf(logout,"At line no: %d factor : variable DECOP\n\n",line_count);
					char tmp[3];
					tmp[0] = '-';tmp[1]='-';tmp[2]='\0';

					char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1);

					strcpy(tmp2 , $1.mystr);
					strcat(tmp2 , tmp);

					vec.push_back(tmp2);
					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				;

			argument_list : arguments	{
						fprintf(logout,"At line no: %d argument_list : arguments\n\n",line_count);
						$$.mystr = $1.mystr;
						fprintf(logout,"%s \n\n",$1.mystr);

					}
				  |	{
						fprintf(logout,"At line no: %d argument_list :\n\n",line_count);
					}
				  ;

			arguments : arguments COMMA logic_expression	{

						fprintf(logout,"At line no: %d arguments : arguments COMMA logic_expression\n\n",line_count);
						char tmp[2];
						tmp[0] = ',';tmp[0] = '\0';
						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen($3.mystr));

						strcpy(tmp2 , $1.mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $3.mystr);

						vec.push_back(tmp2);
						$$.mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
		      | logic_expression	{
						fprintf(logout,"At line no: %d arguments : logic_expression\n\n",line_count);
						$$.mystr = $1.mystr;
						fprintf(logout,"%s \n\n",$1.mystr);

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
