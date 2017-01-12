#ifndef EdgeSTACK
#define EdgeSTACK



typedef struct EdgeListNode * EdgeList;

/*struct EdgeList{
	struct EdgeListNode * prev;
	struct EdgeListNode * next;
};*/

typedef struct{
	EdgeList * next;
}EdgeListNode;

//typedef struct EdgeListNode * EdgeList;

/*typedef struct EdgeInfoStruct{
	int thru;
	int to;
}EdgeInfo;*/

/*struct EdgeListNode{
	//struct EdgeListNode newP;
	//struct EdgeListNode * prev;
	//struct EdgeListNode * next;
	EdgeInfo fedge;
	EdgeList rest;
};*/

/*struct EdgeList{
	struct EdgeList * prev;
	struct EdgeList * next;
};*/

/*struct EdgeInfo{
	struct EdgeInfo * last;
};*/

extern const EdgeList edgeNil;

EdgeInfo edgeFirst(EdgeList oldL);

EdgeList edgeRest(EdgeList oldL);

void edgePush(EdgeInfo newE, EdgeList * oldL);

EdgeList edgePop(EdgeList oldL);

#endif
