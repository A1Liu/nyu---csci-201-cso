#include <stdio.h>
#include <ctype.h>
#define ARGCOUNT 2
#define ERROR_CODE 2

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
