
// Instructions
// Homework: Write a C function escape(char s[], char t[])
// that converts the characters newline and tab into two character sequences \n and \t as it
// copies the string t to the string s. Use the C switch statement. Also write the reverse function unescape(char s[], char t[]).

#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
  char t[]  = "asdfasdf\n\tasdf";
  char s[100];
  printf("\n%s\n\n",t);

  escape(s,t);
  printf("%s\n",s);
  return 0;
}

void escape(char s[], char t[]) {
  int si = 0; char letter;
  for (int i = 0; (letter = t[i]) != EOF; i++) {
    switch(letter) {
      case '\n':
        s[si++] = '\\';
        s[si++] = 'n';
        break;
      case '\t':
        s[si++] = '\\';
        s[si++] = 't';
        break;
      default:
        s[si++] = letter;
    }
  }
  s[si] = EOF;
}

void unescape(char s[], char t[]) {
  int si = 0; char value; char nextValue;
  for (int i = 0; (value = t[i++]) != EOF; ) {
    if (value == '\\')
    	switch((nextValue = t[i++])) {
          case 'n':
            s[si++] = '\n';
            break;
          case '\\':
            s[si++] = '\\';
            break;
          case 't':
            s[si++] = '\t';
            break;
          default:
            s[si++] = '\\';
            s[si++] = nextValue;
        }
    else
    	s[si++] = value;
    }
  }
  s[si] = EOF;
}
