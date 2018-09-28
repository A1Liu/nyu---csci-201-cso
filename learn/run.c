#include <stdio.h>
#include <ctype.h>

void copyStr(char *s, char *t) {
	while ((*s++ = *t++)) ;
}

char *copyNstr(char *s, char *t, int n) {
	char *f;
	for (f = s; (*s++ = *t++) && n > 0; n--) ;
	return f;
}


int main() {
	// char *STG[3] = { "01234", "0123456", "012345" };
	// printf ("%s %s %s.\n", STG[0], STG[1], STG[2]);
	// // *STG[1] = *STG[2] = *STG[0]; // Bus error: *STG[2] points to a location that can't be accesses
	// STG[1] = STG[2] = STG[0]++; //
	// printf("test\n");
	// printf ("%s %s %s.\n", STG[0], STG[1], STG[2]);

	if (isdigit('\0'))
		printf("asdfasdfasdfasdf");

	return 0;
}
