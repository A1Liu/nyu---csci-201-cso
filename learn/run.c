#include <stdio.h>

int main() {
  int x = 3, y;
  y = + + + + + x;
  y = - + - + - + x;
  printf("hello");
  y = - ++x;
  // y = ++ -x;//ERROR address "-x" is not assignable
  // y = ++ x ++;//ERROR address "x ++" is not assignable
  // y = ++ ++ x;//ERROR address "++x" is not assignable
  return 0;
}
