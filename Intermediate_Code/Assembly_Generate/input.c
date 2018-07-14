int f(int a){
    return 2*a;
}

int g(int a, int b){
    int x;
    x=f(a)+a;
    return x;
}

int main(){
    int a,b;
    int c[3];
    a=1;
    c[2]=2;
    a=f(c[2]);
    g(a,3);
    println(a);
    return 0;
}
