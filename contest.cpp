#include<stdio.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

  int n,m ,a;
  int lcounter = 0 , wcounter = 0;


  cin>>n>>m>>a;
  // int a;

  if(m>a && n>a){
    lcounter = ceil(m/(a*1.0));
    wcounter = ceil(n/(a*1.0));
    // std::cout << "lcounter :" <<lcounter<< '\n';
  }
  else if( m>a ){
    lcounter = ceil(m/(a*1.0));
  }
  else if(n>a){
    wcounter = ceil(n/(a*1.0));
  }
  else{
    lcounter++;
  }

std::cout <<(lcounter+wcounter);
  // cout<<n<<m<<a<<endl;

  return 0;

}
