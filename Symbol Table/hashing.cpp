#include<bits/stdc++.h>
#define NULL_VALUE -999999
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




//******************HashTable class starts here**************************
class hashitem{
public:
    string key;
    int value;
    int index;
    hashitem *next;
};


class HashTable
{
    int length , collision;
    hashitem **array;
public:
	HashTable(int length = 0);
	~HashTable();
	int hash1(string key);
	int hash2(string key);
	int hash3(string key);
	int LinerProbeInsert(string key , int value , int func);
    bool LinerProbeSearch(string key , int func);
    void LinerProbeDelete(string key , int func);

    int SeparateChainInsert(string key , int value , int func);
    bool SeparateChainSearch(string key , int func);
    void SeparateChainDelete(string key , int func);

    int getCollision(){return collision;}
    void printHash();
};

HashTable::HashTable(int len)
{
    length = len;
    collision = 0;
    array = new hashitem*[len];
    for(int i=0 ; i< len ; i++){
        array[i] = new hashitem;
        array[i]->key = "empty";
        array[i]->value = -1;
        array[i]->index = 0;
        array[i]->next = NULL;
    }
}
void HashTable::printHash(){
    for(int i=0 ; i< length ; i++){
        if(array[i]->value != -1 && array[i]->value != -2){
            cout<<"("<<array[i]->key<<" , "<<array[i]->value<<")\n";
        }
    }
}
int HashTable::hash1(string key){
    int h=7 ;
    for(int i=0 ; i< key.length() ; i++){
        h = (h*31 + (int)key[i]) % INFINITY;
    }
    return h%length;

}

int HashTable::hash2(string key){
    int h= 0;
    for(int i=0 ; i< key.length() ; i++){
        h = (h*521*i + (int)key[i])%INFINITY;
    }
    return h%length;

}

int HashTable::hash3(string key){
    int h=0 ;
    int prime[] = { 191 , 19 , 6793 , 157 , 3491 , 9157 };
    for(int i=0 ; i< key.length() ; i++){
        h = (h*prime[rand()%5] + (int)key[i])%INFINITY;
    }
    return h%length;

}

int HashTable::LinerProbeInsert(string key , int value , int func)
{
    int index;
    if(func == 1)
         index = hash1(key);
    else if(func == 2)
         index = hash2(key);
    else
         index = hash3(key);


    int idx = index;
    int empty = -1;

    if(array[index]->value != -1 && array[index]->key ==  key) //Same alue exists
        return NULL_VALUE;
    else if(array[index]->value != -1 && array[index]->key !=  key)
        collision++;
    while(array[index]->value != -1){
        index = (index+1)%length;
        if(array[index]->value == -2){
            empty = index;
        }
    }
    if(empty == -1){
        array[index]->key = key;
        array[index]->value = value;
        array[index]->index = idx;
    }
    else{
        array[empty]->key = key;
        array[empty]->value = value;
        array[empty]->index = idx;

    }

    return collision;
}

bool HashTable::LinerProbeSearch(string key , int func)
{
    int index;
    if(func == 1)
         index = hash1(key);
    else if(func == 2)
         index = hash2(key);
    else
         index = hash3(key);


    int idx = index;
    if(array[index]->key == key){
        return true;
    }
    else{
        while(array[index]->key != key && array[index]->value != -1){
            index = (index+1)%length;
           // collision--;
//            cout<<index<<" HIiiiiiiiiiii";
            if(index == idx)
                return false;
        }
        if(array[index]->key== key ){
//            cout<<index<<" "<<collision<<endl;
            return true;
        }
        else
            return false;
    }

}
void HashTable::LinerProbeDelete(string key , int func)
{
    int index;
    if(func == 1)
         index = hash1(key);
    else if(func == 2)
         index = hash2(key);
    else
         index = hash3(key);


    int idx = index;

    if(array[index]->value != -1 && array[index]->key ==  key){
        array[index]->key = "empty";
        array[index]->value = -2;
        array[index]->index = -1;
        return;

    }
    while(array[index]->value != -1 ){
            index = (index+1)%length;
            if(array[index]->key ==  key)
            {
               array[index]->key = "empty";
                array[index]->value = -2;
                array[index]->index = -1;
                return;
            }
    }


}

int HashTable::SeparateChainInsert(string key , int value , int func)
{
    int index;
   if(func == 1)
         index = hash1(key);
    else if(func == 2)
         index = hash2(key);
    else
         index = hash3(key);

   hashitem *item;
   item = new hashitem;
   item->key = key;
   item->value = value;
   item->index = index;
   item->next = NULL;

   hashitem *head;
   head = array[index];

   if(head->next == NULL)
   {
       head->next = item;
   }
   else{

   //Discarding repeating values
    if( head->next->key ==  key)
        return NULL_VALUE;
    else{
        collision++;
        while(head->next != NULL){
            head = head->next;
        }
        head->next = item;
    }

   }
//    cout<<index<<" "<<collision<<endl;
    return collision;
}
bool HashTable::SeparateChainSearch(string key , int func)
{
    int index;
    if(func == 1)
         index = hash1(key);
    else if(func == 2)
         index = hash2(key);
    else
         index = hash3(key);

    int idx = index;
    hashitem *head;
    head = array[index];

    while(head->next !=NULL){
        head = head->next;
        if(head->key == key)
            return true;

    }
    return false;

}
void HashTable::SeparateChainDelete(string key , int func)
{
    int index;
    if(func == 1)
         index = hash1(key);
    else if(func == 2)
         index = hash2(key);
    else
         index = hash3(key);


    hashitem *head;
    head = array[index];

    if(head->next == NULL)
        return;
    while(head->next != NULL){
        if(head->next->key == key){
           hashitem *temp;
           temp = head->next;
            head->next = temp->next;
            free(temp);
            return;
        }

        head = head->next;
    }


}

HashTable::~HashTable()
{
    if(array) delete [] array;
    array = 0;

}

double diffclock( clock_t clock1, clock_t clock2 ) {

        double diffticks = clock2 - clock1;
        double diffms    = diffticks / ( CLOCKS_PER_SEC  );

        return diffms;
    }

int main()
{
    int n , len ;

    scanf("%d%d",&n,&len);
    HashTable LinearProbe1(n), LinearProbe2(n) , LinearProbe3(n)
              , SeparateChain1(n) , SeparateChain2(n) , SeparateChain3(n);


    string a , test[n];


    for(int j =0 ; j< n; j++){
        for(int i = 0 ; i< len; i++){

            int randomChar = rand()%(26+26);

            if (randomChar < 26)
                a.push_back('a' + randomChar)  ;
             else
                a.push_back('A' + randomChar - 26) ;

        }
        cout<<a<<endl;
//        LinearProbe1.LinerProbeInsert(a , j , 1);
//        LinearProbe2.LinerProbeInsert(a , j , 2);
//        LinearProbe3.LinerProbeInsert(a , j , 3);

        SeparateChain1.SeparateChainInsert(a , j , 1);
        SeparateChain2.SeparateChainInsert(a , j , 2);
        SeparateChain3.SeparateChainInsert(a , j , 3);

//        LinearProbe1.LinerProbeDelete(a , 1);
//        LinearProbe2.LinerProbeDelete(a , 2);
//        LinearProbe3.LinerProbeDelete(a , 3);

//        SeparateChain1.SeparateChainDelete(a  , 1);
//        SeparateChain2.SeparateChainDelete(a  , 2);
//        SeparateChain3.SeparateChainDelete(a  , 3);

        a.clear();

    }

    LinearProbe1.printHash();
    for(int j =0 ; j< n; j++){

        for(int i = 0 ; i< len; i++){

            int randomChar = rand()%(26+26);

            if (randomChar < 26)
                test[j].push_back('a' + randomChar)  ;
             else
                test[j].push_back('A' + randomChar - 26) ;


        }

    }

    cout<<"\n\nReport Generation:"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"\t\tHash1\tHash2\tHash3"<<endl;
    cout<<"Linear Probing  ";
    cout<<LinearProbe1.getCollision()<<"\t";
    cout<<LinearProbe2.getCollision()<<"\t";
    cout<<LinearProbe3.getCollision() <<"\t\n";
    cout<<" Chaining   \t";

    cout<<SeparateChain1.getCollision()<<"\t";
    cout<<SeparateChain2.getCollision()<<"\t";
    cout<<SeparateChain3.getCollision()<<"\t\n";
    cout<<"\nSearch Time :-"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"\t\tHash1\tHash2\tHash3"<<endl;

    clock_t start = clock();

    for(int j=0 ; j<n ; j++){
        LinearProbe1.LinerProbeSearch(test[j]  , 1);
    }
    clock_t end = clock();
    cout <<"Linear Probing  "<<diffclock(start,end)<<"\t";
     start = clock();

    for(int j=0 ; j<n ; j++){
        LinearProbe2.LinerProbeSearch(test[j]  , 2);
    }
     end = clock();
    cout <<diffclock(start,end)<<"\t";
     start = clock();

    for(int j=0 ; j<n ; j++){
        LinearProbe3.LinerProbeSearch(test[j]  , 3);
    }
     end = clock();
    cout<<diffclock(start,end)<<"\t\n";
     start = clock();

    for(int j=0 ; j<n ; j++){
        SeparateChain1.SeparateChainSearch(test[j]  , 1);
    }
     end = clock();
    cout <<" Chaining   \t"<<diffclock(start,end)<<"\t";
     start = clock();

    for(int j=0 ; j<n ; j++){
        SeparateChain2.SeparateChainSearch(test[j]  , 2);
    }
     end = clock();
    cout<<diffclock(start,end)<<"\t";
     start = clock();

    for(int j=0 ; j<n ; j++){
        SeparateChain3.SeparateChainSearch(test[j]  , 3);
    }
     end = clock();
    cout<<diffclock(start,end)<<"\n";

    return 0;
}
