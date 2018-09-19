//Homework: Write a C funcion int odd (int x) that
//returns 1 if x is odd and returns 0 if x is even. Can you do it without an if statement?

#include <stdio.h>

int odd(int x);
void rotate3(int *A, int *B, int *C);
void plusminus(int *x, int *y);

int main() {
	int a = 1,b = 2,c = 3;
	printf("Before Rotation:\n  A: %d\n  B: %d\n  C: %d\n",a,b,c);
	rotate3(&a,&b,&c);
	printf("After Rotation:\n  A: %d\n  B: %d\n  C: %d\n\n",a,b,c);
	int x=10,y=5;
	printf("Before PlusMinus:\n  x: %d\n  y: %d\n",x,y);
	plusminus(&x,&y);
	printf("After PlusMinus:\n  x: %d\n  y: %d\n\n",x,y);
	return 0;
}

int odd(int x) {
	return x % 2;
}

//Homework: Write rotate3(A,B,C) that sets A to the old value of B, sets B to old C, and C to old A.
void rotate3(int *A,int *B,int *C) {
	int d = *A;
	*A = *B;
	*B = *C;
	*C = d;
}


//Homework: Write plusminus(x,y) that sets x to old x + old y and sets y to old x - old y.

void plusminus(int *x,int *y) {
	int temp = *x;
	*x = *x + *y;
	*y = temp - *y;
}
