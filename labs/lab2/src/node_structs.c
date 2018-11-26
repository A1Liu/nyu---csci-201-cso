#include <stdlib.h>
#include <string.h>
#include "node_structs.h"

// 'constructor' for a 1d node
NodeChild newNodeChild(char* name, NodeChild next) {
	NodeChild node = malloc(sizeof(nodeChild));
	node->name = name;
	node->next = next;
	return node;
}

// 'constructor' for a 2d node
NodeParent newNodeParent(char* name, NodeParent next, NodeChild child) {
	NodeParent node = malloc(sizeof(nodeParent));
	node->name = name;
	node->next = next;
	node->child = child;
	return node;
}

// frees all the children of a parent node
void freeChildren(NodeParent node) {
	if (node != NULL && node->child != NULL) {// If we need to free the child node and its siblings
		freeSiblings(node->child);
		free(node->child);
		node->child = NULL;
	}
}

void freeChild(NodeParent node) {
	if (node != NULL && node->child != NULL) {// If we need to free the child
		NodeChild next = node->child->next;
		free(node->child);
		node->child = next;
	}
}

void freeNamedChild(NodeParent node, char *name) {
	if (node == NULL || node->child == NULL) return; // cmon son
	NodeChild current;
	for (current = node->child;
		current != NULL && strcmp(current->name,name) == 0;
		freeChild(node),current = node->child) ;
	if (current == NULL) return;
	for (NodeChild next;
		(next = current->next) != NULL; )
		if (strcmp(next->name,name) == 0)
			freeNextChild(current);
		else
			current = next;
}

// frees all the downstream siblings of a child node
void freeSiblings(NodeChild node) {
	if (node == NULL) return;//There's no children!

	NodeChild current,next = node->next;//Instantiate my boyz

	for (node->next = NULL;//Set the original node's next memeber to NULL; because everything after it's gonna be gone
			(current = next) != NULL;//Set current = next; if current = NULL, then we don't need to free anything else
			next=current->next,free(current) ) ; // Move next up, and free what we just moved to
}

// Free a node and remove it from the linked list
NodeParent freeNextParent(NodeParent node) {
	if (node != NULL) {
		NodeParent next = node->next;
		node->next = next->next;
		freeChildren(next);
		free(next);
		return node->next;
	} return NULL;
}

// Free a node and remove it from the linked list
NodeChild freeNextChild(NodeChild node) {
	if (node != NULL) {
		NodeChild next = node->next;
		node->next = next->next;
		free(next);
		return node->next;
	} return NULL;
}
