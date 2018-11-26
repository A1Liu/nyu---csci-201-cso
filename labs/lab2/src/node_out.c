#include <stdlib.h>
#include <stdio.h>
#include "node_out.h"

//Output
void printConfig(NodeParent root) {
	NodeParent current = root;
	NodeChild child;
	int parents = 0, children = 0;
	if (current != NULL) {
		printf("The first 2d node has name=%s\n",current->name);
		parents = 1;
		children=print1d(current->child);
		for (current = current->next; current != NULL; current = current->next,parents++) {
			printf("The next 2d node has name=%s\n",current->name);
			children+=print1d(current->child);
		}
	}
	if (parents == 1)
		printf("There was 1 2D node.");
	else
		printf("There were %d 2D nodes.\n",parents);
	if (children == 1)
		printf("There was 1 1D node.");
	else
		printf("There were %d 1D nodes.\n",children);
	printf("All Finished.\n");
}

// Print output for a single chain of nodes
int print1d(NodeChild node) {
	if (node == NULL) return 0;
	int count = 1;
	printf("\tThe first 1d node has name=%s\t", node->name);
	for (node = node->next; node != NULL; node = node->next,count++) {
		printf("The next 1d node has name=%s\t", node->name);
	}
	printf("\n");
	return count;
}
