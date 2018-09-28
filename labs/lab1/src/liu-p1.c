#include <stdio.h>
#include <ctype.h>
#define ARGCOUNT 3

int parseInt(int *data, char * str);
void output(int data[], int start, int end, int incr);

int main(int argc, char *argv[]) {
	if (--argc != ARGCOUNT) return 2; // Error, wrong amount of arguments
	int vars[ARGCOUNT];// Start, End, Incr
	short success;
	for (int data; argc > 0 && ( success = parseInt(&data,argv[argc]) ); argc--) {
		vars[argc-1] = data;
	}
	if (!success) return 1; // one of the arguments wasn't correct
	int start = vars[0], end = vars[1], incr = vars[2];

	int len = (end - start) / incr;
	len += (end - start) % incr ? 2 : 1;
	int out[len];
	output(out,start,end,incr);
	for (int i = 0; i < len; i++) {
		printf("%d ",out[i]);
	}
	printf("\n");
	return 0;
}

void output(int data[],int start, int end, int incr) {
	int i = 0;
	for ( ; start < end; start += incr)
		data[i++] = start;
	data[i] = end;
}

int parseInt(int *data,char *str) {// need to handle negatives
	int sign=1;
	*data = 0;
	int success = 1;
	char current = *str;

	// Handle the first slot
	if (isdigit(current))
		*data = current - '0';
	else if (current == '-')
		sign =  -1;
	else if (current == '+') ;
	else return 0;
	// Loop through the rest
	for (int i = 1; (current = *(str+i)) && (success = isdigit(current)); i++) {
		*data = *data * 10 + (current - '0');
	}
	*data *= sign;
	return success;
}
