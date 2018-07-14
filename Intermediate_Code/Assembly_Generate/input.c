int f(int a){
    return 2*a;
}

int g(int a, int b){
    int x;
    x=f(a)+a+b;
    return x*f(b);
}

int main(){
    int a,b;
    int c[3];
    a=1;
    c[2]=2;
    a=g(c[2],1);
    b=0;
    println(a);
    for(i=0;i<4;i++){
        while(a--){
            b++;
        }
    }
    println(b);
    println(a);
    return 0;
}
