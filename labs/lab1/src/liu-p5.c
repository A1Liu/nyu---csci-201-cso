/*

# Part 5
Write a C main program that plays the following simplification of
Conway's game of life.

The program reads 10 integers from the terminal. The first integer is called `numGen`,
short for number of generations. Check that it is positive and abort the run if it is not.
The remaining 9 integers must each be 0 or 1 (check that they are 0 or 1 and abort if not).

View these 9 binary values as a 3x3 matrix. So if the numbers
were` 1 1 1 0 1 0 1 0 1` you view them as

`1 1 1`
`0 1 0`
`1 0 1`

This matrix is called generation 0.

Each element of the matrix is called a cell. A cell has
neighbors on top, bottom, left, right, and diagonals. The four
corner cells (matrix elements 0,0 0,2 2,0 2,2) each have only
three neighbors; whereas, the middle cell (element 1,1) has eight
neighbors.

Generation 1 is calculated from generation 0 as follows.
1. for each cell in generation 0, count how many of its neighbors
are 1.
2. If that count gives 2 or 3, the cell is 1 in generation 1.
3. If the count is neither 2 nor 3, the cell is 0 in generation 1.

Repeat this process to produce all 9 values in generation 1.

Then, using the generation 1 matrix, calculate the generation 2
matrix using the same procedure.

Stop when you reach generation `numGen` and print the resulting
3 by 3 matrix on the screen.

*/

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
void nextGen(int n, A[n][n]);
int countNeighbors(int n, int A[n][n], int r, int c);
void printMatrix(int n, int A[n][n]);

int main(int argc, char *argv[argc]) {
	int data[3][3];
	return 0;
}

void nextGen() {

}

int countNeighbors(int n, int A[n][n], int r, int c) {// Count neighbors of cell at A[r][c] given r and c

}

void printMatrix(int n, int A[n][n]) {

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
