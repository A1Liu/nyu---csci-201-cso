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
void sortInt(int n, int A[n]);
void printA(int n, int A[n]);

int main(int argc, char *argv[argc]) {//Part B
	int n;
	int success = getint(&n);
	if (success && n < 100 && n > 0) ;
	else {
		printf("Invalid entry for 'n'");
		return 1;
	}
	int i = 0;
	int A[n];
	for (int data; i < n && ( success = getint(&data) ); A[i++] = data) ;
	printA(n,A);
	printf("Sorting...\n");
	sortInt(n,A);
	printA(n,A);
	return 0;
}

void printA(int n, int A[n]) {
	for (int i = 0; i < n; i++)
		printf("%d\n",A[i]);
}
//n is size of array, A[] is array
void sortInt(int n, int A[n]) {//Part A
	for (int i = 1; i < n; i++) {
		int current = A[i];
		int j;
		for (j = i; j > 0 && current < A[j-1]; j--) {
			A[j] = A[j-1];
		}
		A[j] = current;
	}
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

int getint(int *pn) {//Returns 0 if there was a failure, or the character that ended the integer if not a failure.
	int c, sign;
	while (isspace(c=getch())) ;

	if (!isdigit(c) && c!='\n' && c!='+' && c!='-') {//Change back to EOF
		ungetch(c);
		return 0;
	}

	sign = (c=='-') ? -1 : 1;
	if (c=='+' || c=='-')
		c = getch();
	for (*pn = 0; isdigit(c); c=getch())
		*pn = 10 * *pn + (c-'0');
	*pn *= sign;
	if (c != '\n')//Change back to EOF
		ungetch(c);
	return c == 0 ? -1 : c;
}
