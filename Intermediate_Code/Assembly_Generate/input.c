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
    a=1;
    b=2;
    a=f(b);
    println(a);
    return 0;
}
