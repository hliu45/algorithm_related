#include <stdio.h>
#include <stdlib.h>
#include "edgeStack.h"
#include <string.h>

//typedef struct IntStack IntStack;
//typedef struct EdgeListNode * EdgeList;

struct EdgeListNode{
	EdgeInfo fedge;
	EdgeList rest;
}; 

/*struct EdgeList{
	struct EdgeListNode * prev;
	struct EdgeListNode * next;
};*/




//typedef struct EdgeInfoStruct EdgeInfoStruct;

const EdgeList edgeNil = NULL;

/*struct{
	struct EdgeList prev;
	struct EdgeList next;
}EdgeList;*/

EdgeInfo edgeFirst(EdgeList oldL){
	return oldL->fedge;
}

EdgeList edgeRest(EdgeList oldL){
	return oldL->rest;
}

void edgePush(EdgeInfo newE, EdgeList * oldL){
	EdgeList * newEdge=(EdgeList *)calloc(1,sizeof(EdgeInfoStruct));
	newEdge->next = NULL;
}

EdgeList edgePop(EdgeList oldL){
	EdgeList newP;
	newP = oldL->rest;
	return newP; 
}
