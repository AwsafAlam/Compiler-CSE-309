int f(int a){
    return 2*a;
}

int g(int a, int b){
    int x;
    x=f(a)+a+b;
    return x;
}

int main(){
    int a,b;
    int c[3];
    a=1;
    c[2]=2;
    a=g(c[2],1);
    println(a);
    return 0;
}
