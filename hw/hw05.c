#include <stdio.h>
#include <conio.h>
#include <ctype.h>
//
// Instructions
// Homework: 5-1. As written, getint() treats a + or - not followed by a digit as
 // a valid representation of zero. Fix it to push such a character back on the input.

int getint(int *pn) {// pn holds the data
	int c, sign;
	while (isspace(c=getch())) ; // Move to first non-space character
	if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {// If we're getting something that's a letter or something weird, put it back and return 0
		ungetch(c);
		return 0;
	}

	sign = (c=='-') ? -1 : 1; // Whether to be negative or positive
	if (c=='+' || c=='-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			ungetch(sign == -1 ? '-' : '+');
			return 0;
		}
	}// if it's a sign

	 for (*pn = 0; isdigit(c); c=getch())
	 	*pn = 10 * *pn + (c-'0');
	 *pn *= sign;
	 if (c != EOF)
	 	ungetch(c);
	 return c;
}
// Homework: Rewrite changeltox() to use array style and a for loop.


void changeltox (char s[]) {
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == 'l') s[i] = 'x';
	}
}

int main() {
	return 0;
}
