#include <stdio.h>
#include <ctype.h>
#define ARGCOUNT 2
#define ERROR_CODE 2
#define BUFSIZE 100
char buf[BUFSIZE];
int  bufp = 0;

int  getch(void);
void ungetch(int);
int getint(int *pn);
short parseInts(int argc, char *argv[argc], int vars[argc-1]);
short parseInt(int *data, char *str);

int main() {
	char *a = "1234223";
	int d = 1;
	int suc = parseInt(&d,a);
	printf("%d %c\n%s\n",d,*a,suc ? "Success" : "Fail");
	return 0;
}

short parseInts(int argc,char *argv[argc-1], int vars[argc]) {//argc and argv are same values as from command line
	//vals stores the values
	//returns 1 if successful and 0 if failed
	short success = 0;
	for (int data = --argc; argc > 0 && ( success = parseInt( &data, argv[argc]) ); (vars[--argc] = data) );
	return success;
}

int getch(void) {
	return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many chars\n");
	else
		buf[bufp++] = c;
}

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
	 return c == 0 ? -1 : c;
}

short parseInt(int *data,char *str) {//For strings
	short sign=1;
	*data = 0;
	short success;
	char current = *str;

	// Handle the first slot
	if ( ( success = isdigit(current) ) ) *data = current - '0';
	else if (current == '-') sign =  -1;
	else if (current != '+') return 0;

	// Loop through the rest
	for ( ; (current = *(++str)) && ( success = isdigit(current) ); ) {
		*data = *data * 10 + (current - '0');
	}
	*data *= sign;
	return success;//returns 1 for successful and 0 for failed
}
