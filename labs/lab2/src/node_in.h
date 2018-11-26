#ifndef QOBEOIFUBVD
	#define QOBEOIFUBVD

	#include "node_structs.h"

	NodeParent parse_in(NodeParent root, void (*addChildNode)(NodeParent, char*) );
	// Returns 2D array with a list of references to nodes that are the ancestor of nodes to be deleted
	NodeParent getNodeParent(NodeParent node, char *str);

#endif
