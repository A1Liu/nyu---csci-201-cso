/*
Write a main program that takes two command-line arguments,
`lo` and `hi`. If `lo > hi`, `main()` prints an appropriate error message and terminates. Assuming `lo <= hi`, `main()` calls `isPrime(x)` for each `lo <= x <= hi`. For each *x*, `main()` prints one line which states either:
* *x* is invalid
* *x* is prime
* *x* is not prime

(You don't print a literal 'x' but instead the value of *x*).

*/

int isPrime(int x);

int main(int argc, char *argv[argc]) {//Part B
	return 0;
}

int isPrime(int x) {//Part A
	// If x<2 or x>1000, the input is erroneous and isPrime() returns -1.
	// If 2<=x<=1000 and x is a prime number, isPrime() returns 1.
	// If 2<=x<=1000 and x is not a prime number, isPrime() returns 0.
	return 0;
}
