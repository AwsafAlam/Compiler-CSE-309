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

  void setName(string n){name = n;}
  void setType(string t){type = t;}
  string getName(){return name;}
  string getType(){return type;}

};

class ScopeTable
{
    int length , collision , scope;
    SymbolInfo **array;
public:
	ScopeTable(int length = 0 , int num = 1);
	~ScopeTable();
	int hash(string key);
  int Insert(string name , string type);
  SymbolInfo* Lookup(string name );
  void Delete(string name );

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
        array[i]->setName("empty");
        array[i]->setType("empty");
        // array[i]->index = 0;
        array[i]->next = NULL;
    }
}

void ScopeTable::printHash(){
    cout<<"ScopeTable # "<<scope<<endl;
    cout<<"----------------------"<<endl;
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
    int position = 0;
    int index;
    index = hash(name);
    // cout<<name<<" "<<type<<endl;

   SymbolInfo *item;
   item = new SymbolInfo;
   item->setName(name);
   item->setType(type);
   // item->index = index;
   item->next = NULL;

   SymbolInfo *head;
   head = array[index];

   if(head->next == NULL)
   {
       head->next = item;
       cout<<"   Inserted in ScopeTable# "<<scope<<" at position ";
       cout<<index<<", 0"<<endl;
   }
   else{

   //Discarding repeating values
    if( head->next->getName() ==  name){
      cout<<"<"<<name<<","<<type<<"> already exists in current ScopeTable#"<<scope<<endl;
      return NULL_VALUE;
    }
    else{
        collision++;
        while(head->next != NULL){
            head = head->next;
            position++;
        }
        head->next = item;
        cout<<"   Inserted in ScopeTable# "<<scope<<" at position ";
        cout<<index<<", "<<position<<endl;

    }

   }

//    cout<<index<<" "<<collision<<endl;
    return collision;
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
          cout<<"   Found in Scopetable# "<<scope<<" at position ";
          cout<<index<<" , "<<position<<endl;
          return head;
        }
        position++;
    }
    return NULL;

}

void ScopeTable::Delete(string name)
{
    int position =0 ;
    int index;
    index = hash(name);

    SymbolInfo *head;
    head = array[index];

    if(head->next == NULL){
      cout<<name<<" Not found"<<endl;
      return;
    }

    while(head->next != NULL){
        if(head->next->getName() == name){
           SymbolInfo *temp;
           temp = head->next;
           cout<<"Deleted entry <"<<temp->getName()<<" "<<temp->getType()<<" > at position "<<index<<" , "<<position<<endl;
            head->next = temp->next;
            free(temp);
            return;
        }

        head = head->next;
        position++;
    }

    cout<<name<<" Not found"<<endl;

    // SymbolInfo* element;
    // element = Lookup(name);
    //
    // if(element == NULL){
    //   cout<<name<<" Not found"<<endl;
    // }
    // else{
    //   SymbolInfo *temp;
    //   temp = head->next;
    //   cout<<"Deleted entry <"<<temp->getName()<<" "<<temp->getType()<<" > at position "<<index<<" , "<<position<<endl;
    //   head->next = temp->next;
    //   free(temp);
    //   return;
    // }


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
  vector<const ScopeTable*> scopelist;
  int buckets , scopeNumber;
  ScopeNode * head;
  ScopeNode * tail;
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
  cout<<"New ScopeTable with id "<<scopeNumber<<" created"<<endl;
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

  scopelist.push_back(CurrentScope);

}

void SymbolTable::ExitScope() {
  /* code */
  scopelist.pop_back();
  // CurrentScope scopelist.back();
  scopeNumber--;
  if( head == 0 ){
    cout<<"No items to delete "<<endl;
    return;
  }
      struct ScopeNode *temp, *pre ;
      temp = head ; //Delete First Element

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
    CurrentScope = head->CurrentNode;

}

bool SymbolTable::Insert(string name , string type) {
  /* code */
  if(CurrentScope == NULL ){
    EnterScope();
  }
  cout<<"I "<<name<<" "<<type<<endl;

  CurrentScope->Insert(name , type);

}

bool SymbolTable::Remove(string name) {
  /* code */
  cout<<"D "<<name<<endl;
    CurrentScope->Delete(name);

}

SymbolInfo * SymbolTable::Lookup(string name) {
  cout<<"L "<<name<<endl;
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

  cout<<"  Not found"<<endl;

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

int main(){

//input from file
  int n ;
  char cmd;
  string name , type;

  // scanf("%d",&n);
  // ScopeTable scope(n);

  fstream filein , fileout;
  filein.open ("input.txt", ios::in );
  fileout.open ("1505114.txt", ios::out );

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
      symboltable.EnterScope();
      std::cout << "inside new Scope" << '\n';
    }
    else if (cmd == 'E') {
     /* code */
     //Different ScopeTable
     symboltable.ExitScope();
     // std::cout << "inside new Scope" << '\n';
   }
    else {
      /* code */
      cout<<"Not a recognised instruction."<<endl;
    }

  }

  filein.close();
  fileout.close();


  return 0;

}
