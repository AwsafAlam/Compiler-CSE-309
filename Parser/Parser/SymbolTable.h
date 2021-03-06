#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "SymbolInfo.h"
#define NULL_VALUE -999999
#define LEN 10000

using namespace std;
extern FILE *logout;
extern FILE *error;

extern int error_count;
extern int line_count;


class ScopeTable
{
    int length , collision , scope;
    SymbolInfo **array;
public:
	ScopeTable(int length = 0 , int num = 1);
	~ScopeTable();
	int hash(string key);
  bool Insert(string name , string type,string datastructure);
  SymbolInfo* Lookup(string name );
  bool Delete(string name );

  int getCollision(){return collision;}
  void printHash();
};

ScopeTable::ScopeTable(int len , int num)
{
    length = len;
    scope = num;
    collision = 0;
    array = new SymbolInfo*[len];
    for(int i=0 ; i< len ; i++){
        array[i] = new SymbolInfo;
        array[i]->setName("");
        array[i]->setType("");
        array[i]->setDataType("");
        array[i]->setDataStructure("");

        // array[i]->index = 0;
        array[i]->next = NULL;
    }
}

void ScopeTable::printHash(){
     fprintf(logout,"ScopeTable # %d\n",scope);

    //cout<<"ScopeTable # "<<scope<<endl;
    fprintf(logout,"----------------------\n");
    //cout<<"----------------------"<<endl;
    for(int i=0 ; i< length ; i++){
      SymbolInfo *head;
      head = array[i];
      if(head->next == NULL){
        continue;
      }
       fprintf(logout,"%d -->  ",i);
      //cout<<i<<" -->  ";
      while(head->next != NULL){
        // if( head->next->getType() == "ID" ){
           fprintf(logout,"<%s : %s> ", head->next->getName().c_str(),head->next->getType().c_str());
        //  cout<<"< "<<head->next->getName()<<" : "<<head->next->getType()<<"> ";
        // }
        head = head->next;
      }
       fprintf(logout,"\n");

    //  cout<<endl;
    }
   fprintf(logout,"\n");

}

int ScopeTable::hash(string key){
    int h=7 ;
    for(int i=0 ; i< key.length() ; i++){
        h = (h*31 + (int)key[i]) % length;
    }
    return h%length;

}

bool ScopeTable::Insert(string name , string type ,string datastructure)
{
    int position = 0;
    int index;
    index = hash(name);

   SymbolInfo *item;
   item = new SymbolInfo;
   item->setName(name);
   item->setType(type);
   item->setDataStructure(datastructure);
   // item->index = index;
   item->next = NULL;

   SymbolInfo *head;
   head = array[index];

   if(head->next == NULL)
   {
       head->next = item;
       // //cout<<"Inserted in ScopeTable# "<<scope<<" at position ";
       // //cout<<index<<", 0"<<endl;
   }
   else{

   //Discarding repeating values
   while(head->next != NULL){
     if( head->next->getName() ==  name && head->next->getType() == type && head->next->getDataStructure() != "PARAM"){
        cout<<"<"<<name<<","<<type<<"> already exists in current ScopeTable#"<<scope<<endl;
        error_count++;
        fprintf(error, "Error %d at Line %d: Multiple Declaration of %s\n\n",error_count,line_count,head->next->getName().c_str());
        return false;
      }
      head = head->next;

      }
      head = array[index];
      collision++;
      while(head->next != NULL){
          head = head->next;
          position++;
      }
      head->next = item;
      // //cout<<"Inserted in ScopeTable# "<<scope<<" at position ";
      // //cout<<index<<", "<<position<<endl;
   }
   // printHash();
   //cout<<index<<" "<<collision<<endl;
    return true;
}

SymbolInfo* ScopeTable::Lookup(string name)
{
    int position = 0;
    int index;
    index = hash(name);

    int idx = index;
    SymbolInfo *head;
    head = array[index];

    while(head->next !=NULL){
        head = head->next;
        if(head->getName() == name){
          // //cout<<"   Found in Scopetable# "<<scope<<" at position ";
          // //cout<<index<<" , "<<position<<endl;
          return head;
        }
        position++;
    }
    return NULL;

}

bool ScopeTable::Delete(string name)
{
    int position =0 ;
    int index;
    index = hash(name);

    SymbolInfo *head;
    head = array[index];

    if(head->next == NULL){
      // //cout<<name<<" Not found"<<endl;
      return false;
    }

    while(head->next != NULL){
        if(head->next->getName() == name){
           SymbolInfo *temp;
           temp = head->next;
           //cout<<"Deleted entry <"<<temp->getName()<<" "<<temp->getType()<<" > at position "<<index<<" , "<<position<<endl;
            head->next = temp->next;
            free(temp);
            return true;
        }

        head = head->next;
        position++;
    }

    //cout<<name<<" Not found"<<endl;

    // SymbolInfo* element;
    // element = Lookup(name);
    //
    // if(element == NULL){
    //   //cout<<name<<" Not found"<<endl;
    // }
    // else{
    //   SymbolInfo *temp;
    //   temp = head->next;
    //   //cout<<"Deleted entry <"<<temp->getName()<<" "<<temp->getType()<<" > at position "<<index<<" , "<<position<<endl;
    //   head->next = temp->next;
    //   free(temp);
    //   return;
    // }

    return false;
}

ScopeTable::~ScopeTable()
{
    if(array) delete [] array;
    array = 0;

}

struct ScopeNode{
  ScopeTable* CurrentNode;
  ScopeNode * next;
  ScopeNode * prev;
};


class SymbolTable{
  ScopeTable *CurrentScope;

  int buckets , scopeNumber;
  ScopeNode * head;
  ScopeNode * tail;
public:
  SymbolTable(int length = 0);
	~SymbolTable();
  void EnterScope();
  void ExitScope();
  bool Insert(string name ,string type,string datastructure);
  bool Remove(string name);
  SymbolInfo * Lookup(string name);
  SymbolInfo * LookupCurrentScope(string name);

  void PrintCurrentScope();
  void PrintAllScopes();

};

SymbolTable::SymbolTable(int length){
    buckets = length;
    CurrentScope = NULL;
    head = 0;
    tail = 0;
    scopeNumber = 0;
}

SymbolTable::~SymbolTable(){
}

void SymbolTable::EnterScope() {
  /* code */
  ScopeTable *newScope;
  scopeNumber++;
  newScope = new ScopeTable(buckets , scopeNumber);
  CurrentScope = newScope;
  //cout<<"New ScopeTable with id "<<scopeNumber<<" created"<<endl;
  fprintf(logout,"  New ScopeTable with id %d created\n\n",scopeNumber);

  struct ScopeNode * newNode ;
	newNode = (struct ScopeNode*) malloc (sizeof(struct ScopeNode)) ;
	newNode->CurrentNode = CurrentScope ;

	if(head==0) //inserting the first item
  {
      newNode->next = 0;
      newNode->prev = 0;
      head = newNode;
      tail = newNode;
  }
  else
  {
      newNode->next = head;
      head->prev = newNode;
      newNode->prev = 0;
      head = newNode;
  }

}

void SymbolTable::ExitScope() {
  /* code */
  // scopelist.pop_back();
  // CurrentScope scopelist.back();
  if( head == 0 ){
    //cout<<"No items to delete "<<endl;
    CurrentScope = NULL;
    return;
  }
  fprintf(logout, "ScopeTable with id %d removed\n\n",scopeNumber);
      struct ScopeNode *temp, *pre ;
      temp = head ; //Delete First Element
      //scopeNumber--;

    if (temp == tail) //has only one node
  	{
  		head = 0;
  		tail = 0;
  		free(temp) ;

  	}
    else{
      head = head->next;
    	head->prev = 0;
      free(temp);
    }
    if(head != 0 ){
      CurrentScope = head->CurrentNode;
    }

}

bool SymbolTable::Insert(string name , string type, string datastructure) {
  /* code */
  if(CurrentScope == NULL ){
    EnterScope();
  }
  // //cout<<"I "<<name<<" "<<type<<endl;
  return CurrentScope->Insert(name , type , datastructure);
}

bool SymbolTable::Remove(string name) {
  /* code */
    // //cout<<"D "<<name<<endl;
    return CurrentScope->Delete(name);

}

SymbolInfo * SymbolTable::Lookup(string name) {
  // //cout<<"L "<<name<<endl;
  ScopeNode * tmp;
  SymbolInfo * element;

  tmp = head;

  while (tmp != NULL) {
    /* code */
    element = tmp->CurrentNode->Lookup(name);
    if(element == NULL){
        tmp = tmp->next;
    }
    else
      return element;

  }

  //cout<<"  Not found"<<endl;
  return NULL;
}

SymbolInfo * SymbolTable::LookupCurrentScope(string name) {
  if(CurrentScope == NULL ){
    EnterScope();
  }
  return CurrentScope->Lookup(name);
}

void SymbolTable::PrintCurrentScope() {
  /* code */
  CurrentScope->printHash();

}

void SymbolTable::PrintAllScopes() {
  /* code */
  ScopeNode* tmp;
  tmp = head;

  while(tmp!= NULL){
    tmp->CurrentNode->printHash();
    tmp = tmp->next;
  }

}
