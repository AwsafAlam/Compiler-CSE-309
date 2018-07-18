#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#define NULL_VALUE -999999
#define LEN 10000

using namespace std;

class SymbolInfo{
  int symbolscope;
  string name;
  string type;
  string datatype;
  string datastructure;
  vector<SymbolInfo *> argument_list;
public:
  //char * mystr;
  SymbolInfo *next;
  SymbolInfo(char * n , char *t){
    name = n;
    type = t;
  }
  SymbolInfo(){};
  void setName(string n){name = n;}
  void setType(string t){type = t;}
  void setDataType(string d){datatype = d;}
  void setDataStructure(string ds){datastructure = ds;}
  void addArgument(string name, string type, string datastructure){
    SymbolInfo *item;
    item = new SymbolInfo;
    item->setName(name);
    item->setType(type);
    item->setDataStructure(datastructure);
    item->next = NULL;

    argument_list.push_back(item);
  }
  int getCurrentScope(){return symbolscope;}
  void setScope(int s){symbolscope = s;}
  string getName(){return name;}
  string getType(){return type;}
  string getDataType(){return datatype;}
  string getDataStructure(){return datastructure;}
  SymbolInfo * getArgument(){
    SymbolInfo * tmp = argument_list.front();
    argument_list.erase(argument_list.begin());
    argument_list.push_back(tmp);
    return tmp;
  }
  int getArgNumber(){return argument_list.size();}

};
