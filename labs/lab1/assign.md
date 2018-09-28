# Lab 1: Simple C Programs
This lab consists of simple programs in C, meant to test fundamental concepts like parsing command line arguments, doing basic operations, control flow, and standard input/output.

It is graded as follows:
* Part 1 - 15 points
* Part 2 - 25 points total
  * Part 2A - 15 points
  * Part 2B - 10 Points
* Part 3 - 15 points
* Part 4 - 20 points total
	- Part 4A - 10 points
	- Part 4B - 10 points
- Part 5 - 25 points

## Part 1
Write a main program that has three command line arguments called
`start`, `end`, and `incr`. All three are type `int`.
Your program prints a series of numbers
`start`, `start+incr`, `start+(2*incr)`, `...`, `end`.
For example, if the three arguments are '2 10 3', the values
printed are '2 5 8 10'.
Note from the example that the end value is printed even if it is
not of the form start plus a multiple of incr.

You may assume for problem 1 that the arguments are legal, i.e.,
`start<end` and `incr>0`.

## Part 2

##### Part A
Write the following C function:

```C
int isPrime(int x) {
   // If x<2 or x>1000, the input is erroneous and isPrime() returns -1.
   // If 2<=x<=1000 and x is a prime number, isPrime() returns 1.
   // If 2<=x<=1000 and x is not a prime number, isPrime() returns 0.
}
```

##### Part B
Write a main program that takes two command-line arguments,
`lo` and `hi`. If `lo > hi`, `main()` prints an appropriate error message and terminates. Assuming `lo <= hi`, `main()` calls `isPrime(x)` for each `lo <= x <= hi`. For each *x*, `main()` prints one line which states either:
* *x* is invalid
* *x* is prime
* *x* is not prime

(You don't print a literal 'x' but instead the value of *x*).

## Part 3
Write a main program that reads characters from the terminal and
writes characters on the screen.  Your program must use `getchar()`
to read and `putchar()` to write.

* If the character read is not a letter, it is printed unchanged.
* If the character is an upper case letter, print the letter in
lower case.
* If the character is a lower case letter, print the letter in
upper case.

## Part 4

##### Part A
Write the following C function:

```C
void sortInt(int n, int A[n]) {
   // This routine sorts the array A.
   // Since arrays are passed to functions as a pointers, you do not
   // need the pointer trick we did in class for bad_swap in 6.2.
}
```

##### Part B
Write a main program that does all the following.  I suggest,
but do not require, that you use `getint()` from the notes and
given on page 97 of the book.

1. Reads a positive integer *N*.
2. Checks that 0<*N*<100.  If *N* is not in that range, prints
an error message and terminates.
3. Assuming *N* is legal
	1. Reads *N* more integers into an array.
	2. Prints the contents of the array, one number per line.
	3. Calls your sort routine from **Part A**.
	4.  Prints the sorted array, one number per line.

# Part 5
Write a C main program that plays the following simplification of
Conway's game of life.

The program reads 10 integers from the terminal. The first integer is called `numGen`, short for number of generations. Check that it is positive and abort the run if it is not. The remaining 9 integers must each be 0 or 1 (check that they are 0 or 1 and abort if not).

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
