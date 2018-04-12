#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#define NULL_VALUE -999999
#define LEN 10000
#define WHITE 0
#define GREY 1
#define BLACK -1
#define INFINITY 99999

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii , ii> pop;
typedef vector<ii> vii;
typedef vector<pop> vec;
typedef vector<char> charArr;

class SymbolInfo{
  string name;
  string type;
public:
  SymbolInfo *next;
  // int index;

  void setName(string n){name = n;}
  void setType(string t){type = t;}
  string getName(){return name;}
  string getType(){return type;}

};

class ScopeTable
{
    int length , collision;
    SymbolInfo **array;
public:
	ScopeTable(int length = 0);
	~ScopeTable();
	int hash(string key);

  int Insert(string name , string type);
  bool Lookup(string name );
  void Delete(string name );

  int getCollision(){return collision;}
  void printHash();

};

ScopeTable::ScopeTable(int len )
{
    length = len;
    collision = 0;
    array = new SymbolInfo*[len];
    for(int i=0 ; i< len ; i++){
        array[i] = new SymbolInfo;
        array[i]->setName("empty");
        array[i]->setType("empty");
        // array[i]->index = 0;
        array[i]->next = NULL;
    }
}

void ScopeTable::printHash(){
    for(int i=0 ; i< length ; i++){
      cout<<i<<" -->  ";
      SymbolInfo *head;
      head = array[i];
      while(head->next != NULL){
        if(head->next->getName() != "empty" ){
            cout<<"< "<<head->next->getName()<<" : "<<head->next->getType()<<"> ";
        }
        head = head->next;
      }
      cout<<endl;
    }
}

int ScopeTable::hash(string key){
    int h=7 ;
    for(int i=0 ; i< key.length() ; i++){
        h = (h*31 + (int)key[i]) % INFINITY;
    }
    return h%length;

}

int ScopeTable::Insert(string name , string type )
{
    int index;
    index = hash(name);
    // cout<<name<<" "<<type<<endl;

   SymbolInfo *item;
   item = new SymbolInfo;
   item->setName(name);
   item->setType(type);
   // item->index = index;
   item->next = NULL;

   cout<<item->getName()<<" "<<item->getType()<<endl;

   SymbolInfo *head;
   head = array[index];

   if(head->next == NULL)
   {
       head->next = item;
       cout<<"inserted"<<endl;
   }
   else{

   //Discarding repeating values
    if( head->next->getName() ==  name){
      cout<<"Name already Exists ( Redeclaration of ) "<<name<<endl;
      return NULL_VALUE;
    }
    else{
        collision++;
        while(head->next != NULL){
            head = head->next;
        }
        head->next = item;
    }

   }
   // cout<<"inserted"<<endl;

//    cout<<index<<" "<<collision<<endl;
    return collision;
}
bool ScopeTable::Lookup(string name)
{
    int index;
    index = hash(name);

    int idx = index;
    SymbolInfo *head;
    head = array[index];

    while(head->next !=NULL){
        head = head->next;
        if(head->getName() == name)
            return true;

    }
    return false;

}
void ScopeTable::Delete(string name)
{
    int index;
    index = hash(name);

    SymbolInfo *head;
    head = array[index];

    if(head->next == NULL)
        return;
    while(head->next != NULL){
        if(head->next->getName() == name){
           SymbolInfo *temp;
           temp = head->next;
            head->next = temp->next;
            free(temp);
            return;
        }

        head = head->next;
    }


}

ScopeTable::~ScopeTable()
{
    if(array) delete [] array;
    array = 0;

}


class SymbolTable{
  ScopeTable *CurrentScope;
  vector<ScopeTable> scopelist;
  int buckets;
public:
  SymbolTable(int length = 0);
	~SymbolTable();
  void EnterScope();
  void ExitScope();
  bool Insert(string name ,string type);
  bool Remove(string name);
  SymbolInfo * Lookup(string name);
  void PrintCurrentScope();
  void PrintAllScopes();

};

SymbolTable::SymbolTable(int length){
    buckets = length;
    CurrentScope = NULL;
}

SymbolTable::~SymbolTable(){

}

void SymbolTable::EnterScope() {
  /* code */
  ScopeTable *newScope;
  newScope = new ScopeTable(buckets);
  CurrentScope = newScope;
  // scopelist.push_back(newScope);

}

void SymbolTable::ExitScope() {
  /* code */


}

bool SymbolTable::Insert(string name , string type) {
  /* code */
  if(CurrentScope == NULL ){
    EnterScope();
  }
  CurrentScope->Insert(name , type);

}

bool SymbolTable::Remove(string name) {
  /* code */


}

SymbolInfo * SymbolTable::Lookup(string name) {
  /* code */


}

void SymbolTable::PrintCurrentScope() {
  /* code */
  CurrentScope->printHash();

}

void SymbolTable::PrintAllScopes() {
  /* code */
  CurrentScope->printHash();


}

int main(){

//input from file
  int n ;
  char cmd;
  string name , type;

  // scanf("%d",&n);
  // ScopeTable scope(n);

  fstream filein , fileout;
  filein.open ("input.txt", ios::in );
  fileout.open ("output.txt", ios::out );

  filein>>n;
  SymbolTable symboltable(n);

  while (filein >> cmd) {
    /* code */
    // cin>>cmd;

    if (cmd == 'I') {
      /* code */
      filein>>name>>type;
      symboltable.Insert(name , type);

    } else if (cmd == 'L') {
      filein>>name;
      symboltable.Lookup(name);

    } else if (cmd == 'P') {
      filein>>cmd;
      if(cmd == 'A'){
        symboltable.PrintAllScopes();
      }
      else if(cmd == 'C'){
        symboltable.PrintCurrentScope();
      }

    } else if (cmd == 'D') {
      filein>>name;
      symboltable.Remove(name);

    }  else if (cmd == 'S') {
      /* code */
      //Different ScopeTable


    }else {
      /* code */
      cout<<"Not a recognised instruction."<<endl;
    }



  }

  filein.close();
  fileout.close();


  return 0;

}
