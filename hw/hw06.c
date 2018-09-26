// Homework: 5-5 (first part). Write a version of the library functions

//     char *strncpy(char *s, char *t, int n)

// This copies at most n characters from t to s. This code is not scary like other copies
// since the user of the routine can simply declare s to have space for n characters.

char *strncpy(char *s, char *t, int n) {
	char *temp;
	for (temp = s; n > 0; n--) {
		*s++ = *t++;
	}
}
