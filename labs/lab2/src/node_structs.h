#ifndef DENOWFIEND
	#define DENOWFIEND

	typedef struct nodeChild {

		struct nodeChild *next;
		char *name;

	} nodeChild, *NodeChild;

	typedef struct nodeParent {

		struct nodeParent *next;
		nodeChild *child;
		char *name;

	} nodeParent, *NodeParent;

	NodeChild newNodeChild(char *name, NodeChild next);
	NodeParent newNodeParent(char *name, NodeParent next, NodeChild child);
	void freeChild(NodeParent node);
	void freeNamedChild(NodeParent node, char *name);
	void freeChildren(NodeParent node);
	void freeSiblings(NodeChild node);
	NodeParent freeNextParent(NodeParent node);
	NodeChild freeNextChild(NodeChild node);

#endif
