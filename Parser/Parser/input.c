int x,y,z;
float a;

void hello(){
	int b;
	return 3; 			//Error at line : 7. Return type doesn't match
}

void hello(); 			//Error at line : 9. hello Declared multiple times

int foo1(int a);

float foo1(int a){
	y=b; 				// Error at line: 14. Undeclared variable b ** Error at line: 14. Type mismatched
	return 3.4; 		//Error at line : 16. Return type doesn't match
}

float foo2(int a,int b){
	return 0; 			// Error at line : 20. Return type doesn't match
}

int nondec(int a);

int main(){

	int a[2],b,c; float d;
	a 5;
	b= 2.5;			//Error at line: 27. Trying to access array like normal variable!
	b= hello();
	a[hello()] = 3.5;
}
