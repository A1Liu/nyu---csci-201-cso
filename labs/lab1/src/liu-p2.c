/*
Write a main program that takes two command-line arguments,
`lo` and `hi`. If `lo > hi`, `main()` prints an appropriate error message and terminates.
 Assuming `lo <= hi`, `main()` calls `isPrime(x)` for each `lo <= x <= hi`. For each *x*,
 `main()` prints one line which states either:
* *x* is invalid
* *x* is prime
* *x* is not prime

(You don't print a literal 'x' but instead the value of *x*).

*/
#include <stdio.h>
#include <ctype.h>

#define ARGCOUNT 2

short isPrime(int x);
short parseInt(int *data, char *str);
char *getMessage(int n);

int main(int argc, char *argv[argc]) {//Part B
	if (--argc != ARGCOUNT) return 2; // Error, wrong amount of arguments
	int vars[ARGCOUNT];// Start, End, Incr
	short success;
	for (int data; argc > 0 && ( success = parseInt(&data,argv[argc]) ); argc--) {
		vars[argc-1] = data;
	}
	if (!success) return 1;
	int lo = vars[0], hi = vars[1];
	for (int x = lo; x <= hi; x++)
		printf("%d %s\n", x, getMessage( x ) );
	return 0;
}

char *getMessage(int n) {
	switch(isPrime(n)) {
		case 1:
			return "is prime";
		case 0:
			return "is not prime";
		default:
			return "is invalid";
	}
}
short isPrime(int x) {//Part A
	if (x < 2 || x > 1000) return -1;
	static short done = 0;
	static short composite[999];
	if (done) return !composite[x-2];
	for (int i = 2; i <= 1000; i++)
		if (composite[i-2] == 0)
			for (int j = i*2; j <= 1000; j+=i)
				composite[j-2] = 1;
	done = 1;
	return !composite[x-2];
}

short parseInt(int *data,char *str) {
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
