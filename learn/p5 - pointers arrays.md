

& - Gets reference to data instead of data itself
* - Gets data that a reference points to

for example:
```C
int a[5], *pa; // int *pa means that when you dereference pa, you get an int. i.e. pa is a pointer to an int
pa = &a[0]; // Gets a reference to the first element of a
int x = *pa; // gets the value held at address pa
x = *(pa+1); // gets the value held at the address pa+1, i.e. a[1]. C knows how many bits to move because it knows the type of data that pa points to
x = a[0]; // get value of
x = *a; // if a is an array, then when a is written by itself it's interpreted as the address of the first element of a

int i = 2;
x = a[i]; // Get value in a at index i
x = *(a+i); // get value at address a+1, i.e. same thing as a[i]

int b[5], a[5];
pa = &a[0] // See above
pa = a; // Legal: pa is a container for an address in memory, so it can hold the pointer value of a
a = pa; // illegal: a is not a container of an address, it is an address for a container. It doesn't hold other addresses besides the one for element 0 of the array
a = b; //error: array type 'int [5]' is not assignable
&a[0] = pa; // illegal: You can't change the address of an element in the array

//Check this out:

void copyStr(char *s, char *t) {
	while ((*s++ = *t++)) ;
}

char *copyNstr(char *s, char *t, int n) {
	char *f;
	for (f = s; (*s++ = *t++) && n > 0; n--) ;
	return f;
}

int main() {
	return 0;
}

```
