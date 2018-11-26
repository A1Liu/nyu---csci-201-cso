#include <string.h>
#include "node_in.h"
#include "utils.h"
#define SPACE ' '
#define NEWLINE '\n'

// Parses input from console
NodeParent parse_in(NodeParent root, void (*addChildNode)(NodeParent, char*) ) {
	int toksize, sep;
	NodeParent records = newNodeParent(root->name, NULL, NULL);
	NodeParent rcurrent, current;
	for (current = root,rcurrent = records;
		(current = current->next) != NULL;
		rcurrent = (rcurrent->next = newNodeParent(current->name,NULL,NULL) ) ) ;

	for (char *str = nexttok(&sep, &toksize); sep != END ; str = nexttok(&sep, &toksize) ) {
		if (strcmp(str,"Ins") || sep != SPACE || toksize == 0) {
			quit(ERROR_CODE,"Error at line 18 in node_in.c");
		}
		str = nexttok(&sep, &toksize);
		rcurrent = getNodeParent(records, str);
		current = getNodeParent(root, str);

		if (sep != SPACE || toksize == 0 || current == NULL) {
			quit(ERROR_CODE,"Error at line 25 in node_in.c");
		}

		str = nexttok(&sep, &toksize);
		if (sep != NEWLINE || toksize == 0) {
			quit(ERROR_CODE,"Error at line 25 in node_in.c");
		}

		(*addChildNode)(rcurrent, str);
		(*addChildNode)(current, str);
	}
	return records;
}

// Gets the parent node with the correct name, or NULL if it doesn't exist downstream of node
NodeParent getNodeParent(NodeParent node, char *str) {
	for( ; node != NULL && strcmp(node->name,str); node = node->next) ;
	return node;
}

// Gets the next token
