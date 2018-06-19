//#include<stdio.h>
int x,y,z; float a;
int i,c,j;
void foo();

int var(int a, int b){
	int l,c;
	return a+b;
}

void foo(){
	x=2;
	y=x-5;
}

int main(int k){
	var(9,7);
	int a[2],c,i,j ; float d;
	a[0]=1;
	a[1]=5;
	i= a[0]+a[1];
	j= 2*3+(5%3 < 4 && 8) || 2 ;
	d=var(1,2*3)+3.5*2;
	foo();
	return 0;
}
