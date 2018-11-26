#include <stdio.h>

void p() {
	printf("Test");
}

void p(char *s) {
  printf("%s\n",s);
}

void quit(int code, char *message) {
	if (message == NULL)  printf("ERROR WITH CODE %d\n",code);
	else {
		for (; isspace(*message); message++) ;
		printf("ERROR WITH CODE %d%s%s\n",code,*message == '\0' ? "" : ": ",message);
	}
	exit(code);
}
