
#include <stdio.h>

// Homework: 5-5 (first part). Write a version of the library functions

//     char *strncpy(char *s, char *t, int n)

// This copies at most n characters from t to s. This code is not scary like other copies
// since the user of the routine can simply declare s to have space for n characters.

char *mystrncpy(char *s, char *t, int n) {
	char *temp;
	for (temp = s; n > 0 && (*s++ = *t++); n--) ;
	if (n==0) *s = '\0';
	return temp;
}

int main() {
	char s[1], *t;
	t = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
	int a[2];
	printf("%d",*(a+12));//weird behavior with pointers and arrays
	printf("\n%s\n",mystrncpy(s,t,50));
}
