# Lab 2: 2-Dimensional Linked Lists
This lab consists of C files that define and traverse a 2-dimensional linked list structure. The input lengths for N and M must not exceed 100 characters.

## Compiling and Grading files
To grade parts 1 and 2, please refer to the `node_structs.c`, `node_structs.h`, and `node_out.c` files.  
To test part 3, the main function in `main.c` should be altered to read

```C
int main(int argc, char *argv[argc]) {
	return part3();
}
```

and then all `.c` files should be compiled with `gcc *.c`.  
To test part 4, the main function should be altered to read
```C
int main(int argc, char *argv[argc]) {
	return part4();
}
```
and then all `.c` files should be compiled with `gcc *.c`.

## Description of files
```shell
.
├── main.c              - Main program
├── node_in.c           - Input functions
├── node_in.h
├── node_out.c          - Output functions
├── node_out.h
├── node_structs.c      - Node creation, destruction, and traversal functions
├── node_structs.h
├── utils.c             - Utility functions
└── utils.h
```
