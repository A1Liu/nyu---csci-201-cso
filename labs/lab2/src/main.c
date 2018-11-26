#include "node_out.h"
#include "node_in.h"
#include <string.h>
#include "utils.h"
#define TRUE 1

// Use hash table to get references to all values

NodeParent mkExConfig(int addchild);
void addToFront(NodeParent node, char *name);
void addAlphabetical(NodeParent root, char * name);
// Frees nodes in tree_root whose names match trees in record_root
void freeChildNodes(NodeParent tree_root, NodeParent record_root);
int part3(void);
int part4(void);

int main(int argc, char *argv[argc]) {
	NodeParent root = mkExConfig(TRUE);
	NodeParent records = parse_in( root, addToFront );
	printConfig(root);
	freeChildNodes(root, records);
	printConfig(root);
	return 0;
}

int part3() {
	NodeParent root = mkExConfig(TRUE);
	NodeParent records = parse_in( root, addToFront );
	printConfig(root);
	freeChildNodes(root, records);

	return 0;
}

int part4() {
	NodeParent root = mkExConfig(!TRUE);
	NodeParent records = parse_in( root, addAlphabetical );
	printConfig(root);
	freeChildNodes(root, records);
	return 0;
}

void addToFront(NodeParent node, char *name) {
	node->child = newNodeChild(name, node->child);
}

void addAlphabetical(NodeParent root, char *name) {
	if (root == NULL) return; // cmon son
	NodeChild current = root->child;
	if (current == NULL || // node should go at the beginning of the list
		strcmp(current->name,name) >= 0) {

		root->child = newNodeChild(name,current);
		return;
	}

	for (NodeChild next; (next = current->next) != NULL && // iterate through nodes such that
		strcmp(next->name,name) < 0;
		current = next ) ;
	current->next = newNodeChild(name,current->next);
}

void freeChildNodes(NodeParent tree_root, NodeParent record_root) {
	NodeParent rcurrent, current;
	for(rcurrent = record_root;
		rcurrent != NULL;
		rcurrent = rcurrent->next) {

			for (current = tree_root;
				current != NULL && strcmp(current->name, rcurrent->name) != 0;
				current = current->next) ;
			for (NodeChild child = rcurrent->child;
				child != NULL; child =
				child->next) freeNamedChild(current, child->name);
	}
}

NodeParent mkExConfig(int addchild) {
    NodeChild ctemp;
    NodeParent ptemp;

    // create rows from bottom to top
	ctemp = NULL;
	if (addchild != 0) {
		ctemp = newNodeChild("c3p0", ctemp);
		ctemp = newNodeChild("cso", ctemp);
	}
	ptemp = newNodeParent("R2D2", NULL, ctemp);

	ptemp = newNodeParent("alice",ptemp, NULL);
	ctemp = NULL;
	if (addchild != 0) {
		ctemp = newNodeChild("e342", ctemp);
		ctemp = newNodeChild("sally", ctemp);
		ctemp = newNodeChild("xy2", ctemp);
	}
	ptemp = newNodeParent("joe", ptemp, ctemp);

    return ptemp;
}
