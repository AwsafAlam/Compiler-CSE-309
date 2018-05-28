#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#define NULL_VALUE -999999
#define LEN 10000

using namespace std;

class SymbolInfo{
  string name;
  string type;
public:
  SymbolInfo *next;
  SymbolInfo(char * n , char *t){
    name = n;
    type = t;
  }
  SymbolInfo(){};
  void setName(string n){name = n;}
  void setType(string t){type = t;}
  string getName(){return name;}
  string getType(){return type;}
};
