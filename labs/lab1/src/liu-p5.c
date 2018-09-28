#include <stdio.h>
#include <ctype.h>
#define ARGCOUNT 2
#define ERROR_CODE 2
#define BUFSIZE 100
#define MATRIX_SIZE 3
#define MATRIX_LENGTH MATRIX_SIZE*MATRIX_SIZE
#define END_CHAR EOF
char buf[BUFSIZE];
int  bufp = 0;

int  getch(void);
void ungetch(int);
int getint(int *pn);
void nextGen(int n, int A[n][n],int B[n][n]);
int countNeighbors(int n, int A[n][n], int r, int c);
void printMatrix(int n, int A[n][n]);

int main(int argc, char *argv[argc]) {

	int array[MATRIX_LENGTH];
	int (*A)[MATRIX_SIZE] = (int (*)[MATRIX_SIZE])array;
	int B[MATRIX_SIZE][MATRIX_SIZE];
	int numGen, success = 0,valid = 0;

	//Get number of generations
	success = getint(&numGen) && numGen > 0;
	if (!success) return 1;

	//Get the data matrix
	for (int n = 0; n < MATRIX_LENGTH &&
		(success = getint(&array[n]) ) &&
		(valid = !array[n] || array[n] == 1 ); n++) ;
		//Could multiply success by this value and store in success instead
		//of using second variable
	if (!success || !valid) return 1;


	for (int gen = 0 ; gen < numGen ; gen++) {
		printf("Generation %d\n",gen);
		printMatrix(MATRIX_SIZE,A);//print the generation
		nextGen(MATRIX_SIZE,A,B);//Get the next generation

	}
	//Print the final matrix
	printf("Generation %d (Final State)\n",numGen);
	printMatrix(MATRIX_SIZE,A);
	return 0;
}

//Changes values of A to next generation, uses B as temporary storage
void nextGen(int n, int A[n][n], int B[n][n]) {
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			B[r][c] = countNeighbors(n,A,r,c);
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			A[r][c] = B[r][c] == 2 || B[r][c] == 3 ? 1 : 0;
}

int countNeighbors(int n, int A[n][n], int r, int c) {// Count neighbors of cell at A[r][c] given r and c
	int count = 0;
	for (int i = r > 0 ? r - 1 : 0; i <= r+1 && i < n; i++) {
		for (int j = c > 0 ? c - 1 : 0; j <= c+1 && j < n; j++) {
			count+=A[i][j];
		}
	}
	return count-A[r][c];
}

void printMatrix(int n, int A[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ",A[i][j]);
		printf("\n");
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

int getint(int *pn) {// pn holds the data
	int c,FAIL = 0,SUCCESS = 1;
	while (isspace(c=getch())) ; // Move to first non-space character
	if (c == END_CHAR) {
		return FAIL;
	}
	if (!isdigit(c) && c!='+' && c!='-') {// If we're getting something that's a letter or something weird, put it back and return 0
		ungetch(c);
		return FAIL;
	}

	int sign = (c=='-') ? -1 : 1; // Whether to be negative or positive
	if (c=='+' || c=='-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			ungetch(sign == -1 ? '-' : '+');
			return FAIL;
		}
	}// if it's a sign

	 for (*pn = 0; isdigit(c); c=getch())
	 	*pn = 10 * *pn + (c-'0');
	 *pn *= sign;
	 if (c != END_CHAR) ungetch(c);
	 return SUCCESS;
}
