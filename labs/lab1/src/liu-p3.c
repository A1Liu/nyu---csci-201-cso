/*

## Part 3
Write a main program that reads characters from the terminal and
writes characters on the screen.  Your program must use `getchar()`
to read and `putchar()` to write.

* If the character read is not a letter, it is printed unchanged.
* If the character is an upper case letter, print the letter in
lower case.
* If the character is a lower case letter, print the letter in
upper case.

*/
#include <stdio.h>

char upper(char c);
char lower(char c);

int main(int argc, char *argv[argc]) {
	while( (argc = getchar()) != '\n' ) {
		if (argc >= 'A' && argc <= 'Z')
			putchar(lower(argc));
		else if (argc >= 'a' && argc <= 'z')
			putchar(upper(argc));
		else
			putchar(argc);
	}
	return 0;
}

char upper(char c) {
	return c - 'a' + 'A';
}

char lower(char c) {
	return c - 'A' + 'a';
}
