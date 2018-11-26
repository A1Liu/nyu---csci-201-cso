# Lab 2: 2-Dimensional Linked Lists
In this lab, you will be writing code to create and manipulate 2-dimensional structures. For example consider the following diagram (the three parallel lines of decreasing length indicate a NULL pointer).

I advise re-reading section 6.5 of the notes. [Lab link][lab-link]

### 2D Structures
You can think of a 2d-structure as a linked-list of linked-lists. The primary list is the left column; each element is a struct node2d (see the structure definitions above and to the right). The down pointers in the structure link these nodes into the primary list. In the diagram the main list has three nodes, named joe, alice, and R2D2.

Each of these nodes also has a first pointer, that starts the sub-list associated with this node. The joe sub-list has three elements, the alice sub-list is empty and the R2D2 sub-list has 2 elements.

```C
struct node2d {
struct node1d* first;
char* name;
struct node2d* down;
};

struct node1d {
struct node1d* next;
char* name;
};
```

### Creating the Example in the Diagram
The code in `mkExampleConfig.c` (in the current directory), which we The code in `mkExampleConfig.c`, which we discussed in class, constructs the 2D structure in the diagram above. You may include parts or all of that code in your lab without attribution.

Note that `mkExampleConfig.c` calls `printConfig()`, which is not supplied. It will be part of the lab assignment to write `printConfig()`.

Note that my code creates the diagram from bottom to top and from right to left (see the comments in the code). You are not required to do it that way but I think it is easier to do so since that way, whenever you create a structure S, you have already created the structures S points to.

### Part 1
Write `printConfig(struct node2d* p2d)`, which prints the nodes top to bottom, left to right. The output for the sample configuration should be.
```
  2d node name=joe
	1d node name=xy2	1d node name=sally	1d node name=e342
  2d node name=alice
  2d node name=R2D2
	1d node name=cso	1d node name=c3pO
  All finished.
```
Naturally the output from `printConfig()` depends on the structure generated. The above is the output for the configuration produced by `mkExampleConfig.c`.

### Part 2
Enhance the print2d routine as follows

1. Instead of always printing 2d node name, have the first line printed say The first 2d node has name and have the remaining lines say The next 2d node has name. Make the same improvement for 1d nodes as well.
Do this using the C conditional expression.
1. Make print2d compute the number of 2d nodes (these are the nodes in the left column, which have 2 pointers) and the number of 1d nodes (the remaining nodes, which have 1 pointer). Print these two values at the end of the run.
If you do part 2 correctly, you need not do part1.

### Part 3
Implement insertion of 1d nodes onto a given sub-list. So
```
  Ins alice wife
```
would create a 1d node with name wife and would insert it on the sub-list headed by the 2d node with name alice. Specifically:

1. Read commands from the console.
2. Each command is exactly one line.
3. The first four characters must be Ins . If they are not, print an error message and terminate the run. If any error is detected, the main() procedure must return a positive integer value less than 256 (any such value is fine) to indicate failure. If no errors are found in the run, main() must return 0, as the supplied code does. If you detect the error in one of your non-main functions and it is inconvenient to get back to main() to return non-zero, just execute exit(k); with 0<k<256, which has the same effect as main() executing return k;.
4. The next N>0 characters must be digits or letters (i.e., isalnum() is true). This string forms the name of the 2d node to which you are to add a 1d node. (Use the same treatment for an error as above.)
5. The next character must be a blank (same error treatment).
6. The next M>0 characters must be digits or letters (same error treatment). This string forms the name of the 1d node you are to add.
7. The next character must be a new line (same error treatment).
8. Keep processing such lines until an EOF is found in the first column.
9. You may set reasonable limits on M and N providing you mention the limits in your readme.
10. I promise an EOF will not occur in any column other that column one, you need not check for this. When the EOF occurs, free() any memory you have previously malloc()'ed.
### Part 4
Start with a different initial configuration, specifically the same 2d nodes as before but no 1d nodes (i.e., the first component of each 2d node is null and perform the insertions of part 3 alphabetically. That is, all 1d nodes on a given sub-list would be in alphabetical order. Each sub-list is independent. Note the requirement is to insert the 1d nodes alphabetically, not to insert them randomly and sort them at the end. Also the input is not sorted, you must insert each item where it belongs.

[lab-link]: https://cs.nyu.edu/~gottlieb/courses/cso/labs/lab2/
