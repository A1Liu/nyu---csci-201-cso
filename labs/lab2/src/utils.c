#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"
#define BUFSIZE 100
char buf[BUFSIZE]; //
int bufi; // Buffer index

const int ERROR_CODE = 42;
const char END = EOF;

void quit(int code, char *message) {
	if (message == NULL)  printf("ERROR WITH CODE %d\n",code);
	else {
		for (; isspace(*message); message++) ;
		printf("ERROR WITH CODE %d%s%s\n",code,*message == '\0' ? "" : ": ",message);
	}
	exit(code);
}

char *nexttok(int *c, int *size) {
	for (bufi = 0; (*c = getchar()) != END && isalnum(*c) ; buf[bufi++] = *c) ;
	buf[bufi] = '\0';
	char *str = malloc(sizeof(char)* (bufi+1) );
	strcpy(str,buf);
	*size = bufi;
	return str;
}
