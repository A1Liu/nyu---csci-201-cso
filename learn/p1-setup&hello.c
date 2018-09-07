// This is a comment. When C code is compiled, this is ignored.

/* Comment block
C files end in ".c".
*/

#include <stdio.h> // This imports the

// Just like the main in java. Needs to return an int at the end.
int main() {
  printf("hello world!");// Print function in C. Print to standard output
  return 0;
}



#include <stdio.h>

#define A 12

// Declare functions These are called forwards declarations
int myfunc(int data1, char data2, double data3, short data4, long data5);
void myfunc2(char array1[], int array2[]);
void myfunc3(void);
float a,b,c;

int main() {
  extern float a,b,c;
  // C doesn't enfore the order of evaluation of + sign
  // It does enforce the order of binary operators -- It also guarrantees short-circuit evaluation of binary operators (lazy evaluation)
  // C doesn't have boolean type; non-zero means true, zero means false



}
