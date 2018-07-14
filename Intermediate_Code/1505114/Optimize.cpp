#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
  int line_count = 0;
 std::ifstream infile("Code.asm");
 std::ofstream outfile("Code_Optmised.asm");

 string line;
 vector<string> compare;
 int consecutive = 0;

 while (std::getline(infile, line))
 {
   line_count++;
     std::istringstream iss(line);
     string a, b;
     iss>>a>>b;
     if(a == "MOV"){
       //cout<<b<<endl;
       consecutive++;
       //cout<<consecutive<<endl;
       vector<string> vect;
       std::stringstream ss(b);

       while( ss.good() )
       {
          string substr;
          getline( ss, substr, ',' );
          vect.push_back( substr );
          compare.push_back( substr );
       }
       if(compare.size() == 4){
        //cout <<compare[0]<<" "<<compare[1]<<endl;
         // for (int i=0; i< vect.size(); i++)
         //     cout <<compare.at(i)<<std::endl;

         if(((compare[0] == compare[3]) && (compare[1] == compare[2]) && consecutive >= 2)){
           cout<<"\nLine :"<<line_count<<"-"<<compare[0]<<"--"<<compare[1]<<"--"<<compare[2]<<"--"<<compare[3]<<"----IGNORE-----\n";
         }
         else{
           outfile<<line<<endl;
         }
         compare.erase(compare.begin(), compare.begin() + 2);

       }
     }
     else if(a != ""){ //any instruction other than mov
       //cout<<a<<endl;
       outfile<<line<<endl;

       consecutive = 0;
     }

}


  return 0;

 }
