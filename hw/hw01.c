//Write a (C-language) program to print the value of EOF.

#include <stdio.h>

int prgrm1(){

  printf("\nThe EOF character code is: %d\n",EOF);
  printf("The EOF character in ASCII is: %c\n", EOF);
  return 0;
}


//Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

//#include <stdio.h>

#define STOP_CHAR '\n'
#define SPACE_CHAR ' '

int prgrm2() {
  int c,space = 0;
  while((c = getchar()) != STOP_CHAR) {
    if(c == SPACE_CHAR) {
      if(!space) {
        printf("%c",c);
      }
      space = 1;
    } else {
      printf("%c",c);
      space = 0;
    }
  }
  printf("\n");
  return 0;
}

//Write a program that prints its input one word per line.

//#include <stdio.h>

#define STOP_CHARACTER '\n'

int prgrm3() {
  int c,blank=0;
  while((c=getchar()) != STOP_CHARACTER) {
    if(c == ' ') {
      if(!blank) {
        printf("\n");
      }
      blank = 1;
    } else {
      printf("%c",c);
      blank = 0;
    }
  }
  printf("\n");
  return 0;
}


int main() {
  return prgrm3();
}
