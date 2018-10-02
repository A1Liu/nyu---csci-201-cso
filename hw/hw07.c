// Homework: At the very end of chapter 3 you wrote escape() that converted a
//tab character into the two characters \t (it also converted newlines but ignore that).
// Call this function detab() and call the reverse function entab(). Combine the entab()
// and detab functions by writing a function tab that has one command line argument.
//
//   tab -en   # performs like entab()
//   tab -de   # performs like detab()
#include <string.h>
#define ENTAB_ARG "-en"
#define DETAB_ARG "-de"

int tab(char s[], char t[], char * arg) {
	if (strcmp(arg,ENTAB_ARG) == 0) {
		entab(s,t);
		return 1;
	} else if (strcmp(arg, DETAB_ARG) == 0) {
		detab(s,t);
		return 1;
	}
	return -1;

}

void detab(char s[], char t[]) {
  int si = 0; char letter;
  for (int i = 0; (letter = t[i]); i++) {
    switch(letter) {
      case '\t':
        s[si++] = '\\';
        s[si++] = 't';
        break;
      default:
        s[si++] = letter;
    }
  }
  s[si] = '\0';
}

void entab(char s[], char t[]) {
  int si = 0; char value; char nextValue;
  for (int i = 0; (value = t[i++]); ) {
    if (value == '\\')
    	switch((nextValue = t[i++])) {
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
  s[si] = '\0';
}
