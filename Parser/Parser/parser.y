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

int yylex(void);
extern FILE *yyin;
extern int line_count;
extern int error_count;
vector<char *> vec;
SymbolInfo *param;
string storedatatype;

 FILE * logout = fopen("log.txt","w");
 FILE *error= fopen("error.txt","w");
 char * temp;
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
        char * name;
        char * d_type;
        struct node * arg_list;
    };
}
%union {
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
					$$ = $1;

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

					$$.mystr = tmp;
					fprintf(logout,"%s \n\n",tmp);

				}
				| unit	{
					fprintf(logout,"At line no: %d program : | unit\n\n",line_count);
					$$ = $1;
					fprintf(logout,"%s\n\n",$1.mystr);

				}
				;

			unit : var_declaration	{
						fprintf(logout,"At line no: %d unit : var_declaration\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s\n\n",$1.mystr);

					 }
			     | func_declaration		  {
						 fprintf(logout,"At line no: %d unit : func_declaration\n\n",line_count);
						 $$ = $1;
						 fprintf(logout,"%s \n\n",$1.mystr);
					 }
			     | func_definition	{
						 fprintf(logout,"At line no: %d unit : func_definition\n\n",line_count);
						 $$ = $1;
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

               $$.mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);
               if(symboltable->Lookup($2.mystr) != NULL){
                  error_count++;
                 fprintf(error,"Error %d at line %d: Multiple declaration of %s\n\n",error_count,line_count,$2.mystr);

               }
               else{
                 symboltable->Insert($2.mystr , "ID","FUNCTION.DEC");
                 SymbolInfo *s = symboltable->Lookup($2.mystr);
                 s->setDataType($1.mystr);

                 struct node * head = $4.arg_list;

                  while(head!= NULL){
                    if(head->name == NULL){
                      s->addArgument("" , head->d_type , "");
                    }
                    else{
                      ////cout<<head->name<<" - "<<head->d_type<<endl;
                      s->addArgument(head->name , head->d_type , "");
                    }

                    head = head->arg_list;
                  }

               }

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

               $$.mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);
               if(symboltable->Lookup($2.mystr) != NULL){
                  error_count++;
                 fprintf(error,"Error %d at line %d: Multiple declaration of %s\n\n",error_count,line_count,$2.mystr);
               }
               else{
                 symboltable->Insert($2.mystr , "ID", "FUNCTION.DEC");
                 SymbolInfo *s = symboltable->Lookup($2.mystr);
                 s->setDataType($1.mystr);
               }

             }
             ;

			 func_definition : type_specifier ID LPAREN RPAREN compound_statement {

				 		fprintf(logout,"At line no: %d func_definition : type_specifier ID LPAREN  RPAREN compound_statement\n\n",line_count);
						char tmp[2];
 						tmp[0]='(';tmp[1]='\0';

 						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+4+strlen($5.mystr));

 						strcpy(tmp2 , $1.mystr);
 						strcat(tmp2 , $2.mystr);
 						strcat(tmp2 , tmp);
 						tmp[0] = ')';
 						strcat(tmp2 , tmp);
 						strcat(tmp2 , $5.mystr);


 						$$.mystr = tmp2;

 						fprintf(logout,"%s \n\n",tmp2);
            int flag = 1;

            if(symboltable->Lookup($2.mystr) != NULL){
              if(symboltable->Lookup($2.mystr)->getDataStructure()=="FUNCTION.DEC"){
                SymbolInfo *s = symboltable->Lookup($2.mystr);
                s->setDataStructure("FUNCTION.DEF");
              }
              else if(symboltable->Lookup($2.mystr)->getDataStructure()=="FUNCTION.DEF"){
                flag = 0;
                error_count++;
                fprintf(error,"Error %d at line %d: Redefinition of  %s\n\n",error_count,line_count,$2.mystr);
              }
              if(symboltable->Lookup($2.mystr)->getDataType() != $1.mystr){
                  error_count++;
                  fprintf(error,"Error %d at line %d: Conflicting return-type for %s\n\n",error_count,line_count,$2.mystr);
                }
            }
            else{

              symboltable->Insert($2.mystr , "ID","FUNCTION.DEF");

              symboltable->Lookup($2.mystr)->setDataType($1.mystr);
            }


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


						 $$.mystr = tmp2;
						 fprintf(logout,"%s \n\n",tmp2);
             //SymbolInfo *s = symboltable->Lookup($2.mystr);
             if(storedatatype != "" && storedatatype != $1.mystr){
               fprintf(error,"Warning at line %d: Return type does not match\n\n",line_count);
               storedatatype = "";
             }
             int flag = 1;
             SymbolInfo *s;
             if(symboltable->Lookup($2.mystr)!= NULL){

                 if(symboltable->Lookup($2.mystr)->getDataStructure()=="FUNCTION.DEC"){
                   flag = 0;
                   s = symboltable->Lookup($2.mystr);
                   s->setDataStructure("FUNCTION.DEF");
                   //checking parameters
                   struct node * head = $4.arg_list;
                   int arg_no = s->getArgNumber();

                   while(head!= NULL){
                     if(arg_no == 0){
                       flag = 0;
                       error_count++;
                       fprintf(error,"Error %d at line %d: Conflicting arguments  %s\n\n",error_count,line_count,$2.mystr);
                       break;
                     }
                     SymbolInfo *sym = s->getArgument();

                     //cout<<head->name<<" - "<<head->d_type<<endl;
                     if(head->d_type != sym->getType()){
                       flag = 0;
                       error_count++;
                       fprintf(error,"Error %d at line %d: Conflicting arguments  %s\n\n",error_count,line_count,$2.mystr);
                       break;
                    }
                      //cout<<"Ekbar\n\n";
                     arg_no--;
                     head = head->arg_list;
                   }

                 }
                 else if(symboltable->Lookup($2.mystr)->getDataStructure()=="FUNCTION.DEF"){
                   flag = 0;
                   error_count++;
                   fprintf(error,"Error %d at line %d: Redefinition of  %s\n\n",error_count,line_count,$2.mystr);
                 }
                 if(symboltable->Lookup($2.mystr)->getDataType() != $1.mystr){
                   error_count++;
                   fprintf(error,"Error %d at line %d: Conflicting return-type for %s\n\n",error_count,line_count,$2.mystr);
                   //yyerror("Conflicting return-type for");
                 }
             }
             else{
               symboltable->Insert($2.mystr , "ID","FUNCTION.DEF");
               //SymbolInfo *sym = symboltable->Lookup($2.mystr);
               s = symboltable->Lookup($2.mystr);

               ////cout<<s->getName();
               s->setDataType($1.mystr);
             }
             if(flag == 1){
               struct node * head = $4.arg_list;

               while(head!= NULL){
                 ////cout<<head->name<<" - "<<head->d_type<<endl;
                 if(head->name == NULL){
                   s->addArgument("" , head->d_type , "");
                 }
                 else{
                   s->addArgument(head->name , head->d_type , "");
                 }

                 head = head->arg_list;
               }
             }

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

              symboltable->Insert($4.mystr , "ID","PARAM");
              SymbolInfo *s = symboltable->Lookup($4.mystr);
              s->setDataType($3.mystr);

              $$.mystr = tmp2;
              param->addArgument($4.mystr , $3.mystr, "");

              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = $4.mystr;
              item->d_type = $3.mystr;
              item->arg_list = $1.arg_list;

              $$.arg_list = item;


              fprintf(logout,"%s \n\n",tmp2);
            }
            | parameter_list COMMA type_specifier  {

              fprintf(logout,"At line no: %d parameter_list : parameter_list COMMA type_specifier\n\n",line_count);
              char tmp[2];
              tmp[0]=',';tmp[1]='\0';

              char * tmp2 = (char *) malloc(1+strlen($1.mystr)+1+strlen($3.mystr));

              strcpy(tmp2 , $1.mystr);
              strcat(tmp2 , tmp);
              strcat(tmp2 , $3.mystr);
              $$.mystr = tmp2;
              param->addArgument("" , $3.mystr, "");

              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = "";
              item->d_type = $3.mystr;
              item->arg_list = $1.arg_list;

              $$.arg_list = item;

              fprintf(logout,"%s \n\n",tmp2);

            }
            | type_specifier ID  {

              fprintf(logout,"At line no: %d parameter_list : type_specifier ID\n\n",line_count);
              char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr));

              strcpy(tmp2 , $1.mystr);
              strcat(tmp2 , $2.mystr);

              symboltable->Insert($2.mystr , "ID","PARAM");
              SymbolInfo *s = symboltable->Lookup($2.mystr);
              s->setDataType($1.mystr);

              $$.mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);
              if(param == NULL)
                param = new SymbolInfo;
              param->addArgument($2.mystr , $1.mystr, "");
              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              item->name = $2.mystr;
              item->d_type = $1.mystr;
              item->arg_list = NULL;
              $$.arg_list = item;

            }
            | type_specifier  {
              fprintf(logout,"At line no: %d parameter_list : type_specifier\n\n",line_count);
              fprintf(logout,"%s \n\n",$1.mystr);
              $$.mystr = $1.mystr;

              struct node * item = (struct node *) malloc(1+sizeof(struct node));
              if(param == NULL)
                param = new SymbolInfo;

              param->addArgument("" , $1.mystr, "");

              item->name = "";
              item->d_type = $1.mystr;
              item->arg_list = NULL;

              $$.arg_list = item;
            }
            ;

			compound_statement : LCURL {
        symboltable->EnterScope();
        if(param != NULL){
          int arg_no = param->getArgNumber();
          cout<<"symboltable->EnterScope()  - "<<arg_no<<endl;
          for(int i=0 ; i< arg_no; i++){
            SymbolInfo * sym = param->getArgument();
            symboltable->Insert(sym->getName(), sym->getType(), "");
            cout<<sym->getName()<<endl;  
          }

        }
        param = NULL;
        } statements RCURL  {

							fprintf(logout,"At line no: %d compound_statement : LCURL statements RCURL\n\n",line_count);
							char tmp[2];
							tmp[0]='{';tmp[1]='\0';

							char * tmp2 = (char *) malloc(1+strlen($3.mystr)+5);

							strcpy(tmp2 , tmp);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							strcat(tmp2 , $3.mystr);
							tmp[0] = '\n';
							strcat(tmp2 , tmp);
							tmp[0] = '}';
							strcat(tmp2 , tmp);


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

        for(int i=0 ; i< vec.size() ; i++){
            symboltable->Lookup(vec[i])->setDataType($1.mystr);
        }
				fprintf(logout,"%s\n\n",tmp);
				$$.mystr = tmp;
				////cout<<"--- > "<<vec.size()<<endl;
        vec.clear();
			}
      |error {
        //cout<<" err\n";
        //yyclearin;
        yyerrok;

      }
      ;

			type_specifier	: INT {

				fprintf(logout,"At line no: %d type_specifier:INT\n\n",line_count);

				char tmp[5];
				tmp[0]='i';tmp[1]='n';tmp[2]='t';tmp[3]=' ';tmp[4]='\0';

				char * tmp2 = (char *) malloc(1+strlen(tmp));
				strcat(tmp2 , tmp);

				$$.mystr = tmp2;
				fprintf(logout,"%s \n\n",tmp2);

				}
		 		| FLOAT {

					fprintf(logout,"At line no: %d type_specifier : FLOAT\n\n",line_count);

					char tmp[7];
					tmp[0]='f';tmp[1]='l';tmp[2]='o';tmp[3]='a';tmp[4]='t';tmp[5]='   ';tmp[6]='\0';

					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);


					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
		 		| VOID {

					fprintf(logout,"At line no: %d type_specifier : VOID\n\n",line_count);
					char tmp[6];
					tmp[0]='v';tmp[1]='o';tmp[2]='i';tmp[3]='d';tmp[4]=' ';tmp[5]='\0';

					char * tmp2 = (char *) malloc(1+strlen(tmp));
					strcat(tmp2 , tmp);


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

            SymbolInfo *s = symboltable->LookupCurrentScope($3.mystr);
            if(s != NULL && strcmp(s->getDataStructure().c_str() , "PARAM")){
              error_count++;
              ////cout<<endl<<s->getDataStructure().c_str();
              fprintf(error, "Error %d at Line %d: Multiple declarations of the same variable: %s\n\n",error_count , line_count,$3.mystr);
            }
            else{
              symboltable->Insert($3.mystr , "ID","");
              vec.push_back($3.mystr);

            }

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

            SymbolInfo *s = symboltable->LookupCurrentScope($3.mystr);
            if(s != NULL && strcmp(s->getDataStructure().c_str() , "PARAM")){
              error_count++;
              ////cout<<endl<<s->getDataStructure().c_str();
              fprintf(error, "Error %d at Line %d: Multiple declarations of the same variable: %s\n\n",error_count , line_count,$3.mystr);
            }
            else{
              symboltable->Insert($3.mystr , "ID","ARRAY");
              vec.push_back($3.mystr);

            }

					}
		 		  | ID {

						fprintf(logout,"At line no: %d declaration_list : ID\n\n",line_count);
						fprintf(logout,"%s\n\n",$1.mystr);

						$$ = $1;
            SymbolInfo *s = symboltable->LookupCurrentScope($1.mystr);
            if(s != NULL && strcmp(s->getDataStructure().c_str() , "PARAM")){
              error_count++;
              ////cout<<endl<<s->getDataStructure().c_str();
              fprintf(error, "Error %d at Line %d: Multiple declarations of the same variable: %s\n\n",error_count , line_count,$1.mystr);
            }
            else{
              symboltable->Insert($$.mystr , "ID","");
              vec.push_back($1.mystr);
              //cout<<"\n -- DEBUG--\n";
            }
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

 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);

            SymbolInfo *s = symboltable->LookupCurrentScope($1.mystr);
            if(s != NULL && strcmp(s->getDataStructure().c_str() , "PARAM")){
              error_count++;
              ////cout<<endl<<s->getDataStructure().c_str();
              fprintf(error, "Error %d at Line %d: Multiple declarations of the same variable: %s\n\n",error_count , line_count,$1.mystr);
            }
            else{
              symboltable->Insert($1.mystr , "ID","ARRAY");
              vec.push_back($1.mystr);

            }

					}
		 		  ;

			statements : statement {
						//
						fprintf(logout,"At line no: %d statements : statement \n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1.mystr);

					 }
				   | statements statement {
						 fprintf(logout,"At line no: %d statements :| statements statement \n\n",line_count);

 						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr));

 						strcpy(tmp2 , $1.mystr);
 						strcat(tmp2 , $2.mystr);

 						$$.mystr = tmp2;

 						fprintf(logout,"%s \n\n",tmp2);

					 }
				   ;

			statement : var_declaration	{
					fprintf(logout,"At line no: %d statement : var_declaration\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1.mystr);

					}
					| expression_statement	{
						 fprintf(logout,"At line no: %d statement : expression_statement\n\n",line_count);
						 $$ = $1;

 						fprintf(logout,"%s \n\n",$1.mystr);

					 }
				  | compound_statement	{
						fprintf(logout,"At line no: %d statement : compound_statement\n\n",line_count);
						$$ = $1;
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

						$$.mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

            int flag = 1;

            if(symboltable->Lookup($2.mystr) == NULL){
              if(strchr($2.mystr, '[')!= NULL){
                char *tmp = $2.mystr;
                int i = 0;
                while(tmp[i] != '['){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                $2.mystr[i] = '\0';
                if(symboltable->Lookup($2.mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }

              }
              else if(strchr($2.mystr, '(')!= NULL){
                char *tmp = $2.mystr;
                int i = 0;
                while(tmp[i] != '('){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                $2.mystr[i] = '\0';
                if(symboltable->Lookup($2.mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }

              }
              else{
                flag = 0;
              }
            }


            if(flag==1){
              SymbolInfo *s = symboltable->Lookup($2.mystr);
              storedatatype = s->getDataType();
              //cout<<"\n stored -"<<storedatatype<<endl;
            }

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


              $$.mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);

            }
            | expression SEMICOLON	{

              fprintf(logout,"At line no: %d expression_statement 	: expression SEMICOLON\n\n",line_count);
              char tmp[2];
              tmp[0]=';';tmp[1]='\0';

              char * tmp2 = (char *) malloc(1+strlen($1.mystr)+5);

              strcpy(tmp2 , $1.mystr);
              strcat(tmp2 , tmp);
              tmp[0]='\n';tmp[1]='\0';
              strcat(tmp2 , tmp);


              $$.mystr = tmp2;
              fprintf(logout,"%s \n\n",tmp2);

            }
            ;

          variable : ID	{
              //symboltable->Insert($1.mystr , "ID");
              fprintf(logout,"At line no: %d variable : ID\n\n",line_count);
              $$ = $1;
              $$.intvalue = NULL;
              $$.floatvalue = NULL;

              fprintf(logout,"%s\n\n",$1.mystr);
              if(symboltable->Lookup($1.mystr) == NULL){
                error_count++;
                fprintf(error, "Error %d at Line %d: Undeclared Variable: %s\n\n",error_count , line_count,$1.mystr);

              }
              else if(symboltable->Lookup($1.mystr)->getDataStructure() == "ARRAY"){
                error_count++;
                fprintf(error, "Error %d at Line %d: Expected [ after Array type\n\n",error_count , line_count);

              }
              else{
                  //cout<<"\n-->"<<symboltable->Lookup($1.mystr)->getName()<<" Data types  "<<symboltable->Lookup($1.mystr)->getDataType()<<endl;
              }

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
             int flag = 1;
             if(symboltable->Lookup($3.mystr) == NULL){
               if(strchr($3.mystr, '[')!= NULL){
                 char *tmp = $3.mystr;
                 int i = 0;
                 while(tmp[i] != '['){
                   //cout<<tmp[i]<<endl;
                   i++;
                 }
                 $3.mystr[i] = '\0';
                 if(symboltable->Lookup($3.mystr) == NULL){
                   ////cout<<endl<<i<<" -- HELOE\n";
                   flag = 0;
                 }

               }
               else if(strchr($3.mystr, '(')!= NULL){
                 char *tmp = $3.mystr;
                 int i = 0;
                 while(tmp[i] != '('){
                   //cout<<tmp[i]<<endl;
                   i++;
                 }
                 $3.mystr[i] = '\0';
                 if(symboltable->Lookup($3.mystr) == NULL){
                   ////cout<<endl<<i<<" -- HELOE\n";
                   flag = 0;
                 }

               }
               else{
                 flag = 0;
               }
             }
             if(flag == 1){
               SymbolInfo *s= symboltable->Lookup($3.mystr);
               if(s!=NULL ){
                 //cout<<s->getDataType()<<"-- <>\n";
                 if(s->getDataType() != "int "){
                   error_count++;
                   fprintf(error, "Error %d at Line %d: Non-integer Array Index \n\n",error_count , line_count);
                 }
               }
             }

             if(symboltable->Lookup($1.mystr)->getDataStructure() == ""){
                error_count++;
                fprintf(error, "Error %d at Line %d: %s value is not an array\n\n",error_count , line_count,$1.mystr);

              }
               $$.mystr = tmp2;
               fprintf(logout,"%s \n\n",tmp2);

           }
           ;

			expression : logic_expression	{
						fprintf(logout,"At line no: %d expression : logic_expression\n\n",line_count);
						$$ = $1;
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
            int flag = 1;

            if(symboltable->Lookup($1.mystr) == NULL){
              if(strchr($1.mystr, '[')!= NULL){
                char *tmp = $1.mystr;
                int i = 0;
                while(tmp[i] != '['){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                $1.mystr[i] = '\0';
                if(symboltable->Lookup($1.mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }

              }
              else{
                flag = 0;
              }
            }

            if(symboltable->Lookup($3.mystr) == NULL){
              if(strchr($3.mystr, '(')!= NULL){
                char *tmp = $3.mystr;
                int i = 0;
                while(tmp[i] != '('){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                $3.mystr[i] = '\0';
                if(symboltable->Lookup($3.mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }

              }
              else if(strchr($3.mystr, '[')!= NULL){
                char *tmp = $3.mystr;
                int i = 0;
                while(tmp[i] != '['){
                  //cout<<tmp[i]<<endl;
                  i++;
                }
                $3.mystr[i] = '\0';
                if(symboltable->Lookup($3.mystr) == NULL){
                  ////cout<<endl<<i<<" -- HELOE\n";
                  flag = 0;
                }

              }
              else{
                flag = 0;
                //cout<<"\n\n--DEBUG-- "<<$1.mystr;
              }
            }

            if(flag == 1){

              SymbolInfo *sym = symboltable->Lookup($1.mystr);
              SymbolInfo *sym2 = symboltable->Lookup($3.mystr);
              //cout<<"\n func datatype -> "<<sym2->getDataType().c_str()<<"--";
              if(!strcmp(sym2->getDataType().c_str(), "void ")){
                error_count++;
                fprintf(error, "Error %d at Line %d: void cannot be part of an expression\n\n",error_count , line_count);
              }
              else if($3.intvalue == NULL && $3.floatvalue == NULL){
                if(sym->getDataType() != sym2->getDataType()){
                  /* error_count++; */
                  /* fprintf(error, "Error %d at Line %d: Type Mismatch\n\n",error_count , line_count); */
                  cout<<"Type conversion";
                }
              }
            }
              ////cout<<"\n  -- sth"<<$3.floatvalue<<endl;
          if($3.floatvalue !=NULL && symboltable->Lookup($1.mystr)->getDataType() != "float "){
                /* error_count++;
                fprintf(error, "Error %d at Line %d: Type Mismatch cannot assign float value to non-float variable\n\n",error_count , line_count); */
                $$.intvalue = $3.floatvalue;
              }
          if($3.intvalue !=NULL && symboltable->Lookup($1.mystr)->getDataType() != "int "){
                /* error_count++;
                fprintf(error, "Error %d at Line %d: Type Mismatch cannot assign integer value to non-integer variable\n\n",error_count , line_count); */
                $$.floatvalue = $3.intvalue;
              }

            $$.mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
					;

			logic_expression : rel_expression	{
				 			fprintf(logout,"At line no: %d logic_expression : rel_expression\n\n",line_count);
							$$ = $1;
              //cout<<" \n\n-- "<<$1.mystr;
              //$$.floatvalue = $1.floatvalue;
 						 fprintf(logout,"%s \n\n",$1.mystr);
						}
					 | rel_expression LOGICOP rel_expression	{

						 fprintf(logout,"At line no: %d logic_expression : rel_expression LOGICOP rel_expression\n\n",line_count);

 						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+strlen($3.mystr));

 						strcpy(tmp2 , $1.mystr);
 						strcat(tmp2 , $2.mystr);
 						strcat(tmp2 , $3.mystr);


 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					 }
					 ;

			rel_expression	: simple_expression	{
							fprintf(logout,"At line no: %d rel_expression	: simple_expression\n\n",line_count);
							$$ = $1;
              //$$.floatvalue = $1.floatvalue;

 						 fprintf(logout,"%s \n\n",$1.mystr);
					}
					| simple_expression RELOP simple_expression	{

						fprintf(logout,"At line no: %d rel_expression	: simple_expression RELOP simple_expression\n\n",line_count);

						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+strlen($2.mystr)+strlen($3.mystr));

						strcpy(tmp2 , $1.mystr);
						strcat(tmp2 , $2.mystr);
						strcat(tmp2 , $3.mystr);


						$$.mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);

					}
					;

			simple_expression : term {
						fprintf(logout,"At line no: %d simple_expression : term\n\n",line_count);
						$$ = $1;
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


						$$.mystr = tmp2;
						fprintf(logout,"%s \n\n",tmp2);
					}
				  ;

			term :	unary_expression	{
						fprintf(logout,"At line no: %d term :	unary_expression\n\n",line_count);
						$$ = $1;
            $$.floatvalue = $1.floatvalue;
            $$.intvalue = $1.intvalue;
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

           if($2.charvalue == '%'){
             if(($1.intvalue != NULL && $3.intvalue == NULL) || ($1.intvalue == NULL && $3.intvalue != NULL)){
              error_count++;
              fprintf(error, "Error %d at Line %d: Integer operands on modulus operator\n\n",error_count , line_count);

             }
          }
          else if($2.charvalue == '*'){
              if($1.intvalue !=NULL && $3.intvalue != NULL){
                $$.intvalue = $1.intvalue *$3.intvalue;
              }
              else if($1.floatvalue !=NULL && $3.floatvalue != NULL){
                $$.floatvalue = $1.floatvalue *$3.floatvalue;
              }
              else if($1.intvalue !=NULL && $3.intvalue == NULL){
                $$.floatvalue = $1.intvalue * $3.floatvalue;
              }
              else{
                $$.floatvalue = $1.floatvalue * $3.floatvalue;
              }
          }
          else if($2.charvalue == '/'){
              if($1.intvalue !=NULL && $3.intvalue != NULL){
                $$.intvalue = $1.intvalue / $3.intvalue;
              }
              else if($1.floatvalue !=NULL && $3.floatvalue != NULL){
                $$.floatvalue = $1.floatvalue / $3.floatvalue;
              }
              else if($1.intvalue !=NULL && $3.intvalue == NULL){
                $$.floatvalue = $1.intvalue / $3.floatvalue;
              }
              else{
                $$.floatvalue = $1.floatvalue / $3.floatvalue;
              }
          }


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


 						$$.mystr = tmp2;
 						fprintf(logout,"%s \n\n",tmp2);
					 }
					 | factor	{
						 fprintf(logout,"At line no: %d unary_expression : factor\n\n",line_count);
						 $$ = $1;
             fprintf(logout,"%s \n\n",$1.mystr);

					 }
					 ;

			factor	: variable	{
					fprintf(logout,"At line no: %d factor	: variable\n\n",line_count);
					$$ = $1;
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

          SymbolInfo* sym = symboltable->Lookup($1.mystr);

          struct node * head = $3.arg_list;
          if(symboltable->Lookup($1.mystr) == NULL){
              error_count ++;
              fprintf(error, "Error %d at Line %d: Undefined function %s\n\n",error_count , line_count, $1.mystr);
          }
          int arg_no = sym->getArgNumber();
          //cout<<endl<<arg_no<<" -- argno \n\n";
          while(head!= NULL){
            if(arg_no==0){
              error_count ++;
              fprintf(error, "Error %d at Line %d: Too many arguments\n\n",error_count , line_count);
              break;
            }
            SymbolInfo* s = sym->getArgument();
            //cout<<s->getName()<<"-"<<s->getType()<<endl;
            //cout<<head->name<<"  - name - "<<head->d_type<<endl;
            if(symboltable->Lookup(head->name) != NULL){
              if(symboltable->Lookup(head->name)->getDataType() != s->getType()){
                error_count ++;
                fprintf(error, "Error %d at Line %d: Wrong type of parameters\n\n",error_count , line_count);
              }
            }
            //cout<<head->d_type<<"-"<<symboltable->Lookup(head->name)->getDataType()<<" -- matches -- ";
            head = head->arg_list;
            arg_no--;
          }
					$$.mystr = tmp2;
          $$.intvalue = NULL;
          $$.floatvalue = NULL;
					fprintf(logout,"%s \n\n",tmp2);
          temp = $1.mystr;
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


					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| CONST_INT	{

					fprintf(logout,"At line no: %d factor : CONST_INT\n\n",line_count);

					char tmp[2];
					sprintf(tmp, "%d", $1.intvalue);
					char * tmp2 = (char *) malloc(1+strlen(tmp));

					strcat(tmp2 , tmp);
          $$.floatvalue = NULL;
          $$.intvalue = $1.intvalue;
          $$.charvalue =  NULL;
          $$.arg_list = NULL;
	        $$.mystr = tmp2;
          $$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				| CONST_FLOAT	{

					fprintf(logout,"At line no: %d factor : CONST_FLOAT\n\n",line_count);
          ////cout<<$1.mystr<<" ------\n";
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
					/* $$ = $1; */
          $$.floatvalue = $1.floatvalue;
          $$.intvalue = NULL;
          $$.charvalue =  NULL;
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


					$$.mystr = tmp2;
					fprintf(logout,"%s \n\n",tmp2);

				}
				;

			argument_list : arguments	{
						fprintf(logout,"At line no: %d argument_list : arguments\n\n",line_count);
						$$ = $1;
						fprintf(logout,"%s \n\n",$1.mystr);

            /* struct node * head = $1.arg_list;
            while(head!= NULL){
              //cout<<head->d_type<<"-"<<head->name<<" -- matches -- \n";
              head = head->arg_list;
            } */
					}
				  |	{
						fprintf(logout,"At line no: %d argument_list :\n\n",line_count);
					}
				  ;

			arguments : arguments COMMA logic_expression	{

						fprintf(logout,"At line no: %d arguments : arguments COMMA logic_expression\n\n",line_count);
						char tmp[2];
						tmp[0] = ',';tmp[1] = '\0';
						char * tmp2 = (char *) malloc(1+strlen($1.mystr)+2+strlen($3.mystr));

						strcpy(tmp2 , $1.mystr);
						strcat(tmp2 , tmp);
						strcat(tmp2 , $3.mystr);
            $$.mystr = tmp2;
            fprintf(logout,"%s \n\n",tmp2);

            struct node * item = (struct node *) malloc(1+sizeof(struct node));
            item->name = $3.mystr;
            if(symboltable->Lookup($3.mystr) != NULL){
              item->d_type = (char *) symboltable->Lookup($3.mystr)->getDataType().c_str();
            }
            item->arg_list = $1.arg_list;
            //cout<<symboltable->Lookup($3.mystr)->getDataType().c_str()<<" <ARGUMENT>\n\n";
            $$.arg_list = item;



					}
		      | logic_expression	{
						fprintf(logout,"At line no: %d arguments : logic_expression\n\n",line_count);

            //struct node * item = (struct node *) malloc(1+sizeof(struct node));
            $$.arg_list  = (struct node *) malloc(1+sizeof(struct node));

            $$.arg_list->name = $1.mystr;

            if(symboltable->Lookup($1.mystr) != NULL){
              $$.arg_list->d_type = (char *) symboltable->Lookup($1.mystr)->getDataType().c_str();
              ////cout<<item->d_type<<" datatype \n";
            }
            else{
              if($1.floatvalue != NULL){
                $$.arg_list->d_type = "float";
              }
              else if($1.intvalue != NULL){
                $$.arg_list->d_type = "int";
                ////cout<<item->d_type<<" datatype \n";
              }
            }
            // //cout<<symboltable->Lookup($1.mystr)->getDataType().c_str()<<" <ARGUMENT>\n\n";
            $$.arg_list->arg_list = NULL;

            $$.mystr = $1.mystr;
            $$.intvalue = $1.intvalue;
            $$.floatvalue = $1.floatvalue;
            $$.charvalue = $1.charvalue;

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
