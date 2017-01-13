//Name: Hsin-Liang Liu
//CruzID: hliu45
//ID: 1446091

#include <stdio.h>
#include <stdlib.h>
#include "edgeList.h"


struct EdgeListNode{
	EdgeInfo fedge;
	EdgeList rest;
};

typedef struct EdgeInfoStruct EdgeInfoStruct;

const EdgeList edgeNil=NULL;

EdgeInfo edgeFirst(EdgeList oldL){
	return oldL->fedge;
}

EdgeList  edgeRest(EdgeList oldL){
	return oldL->rest;
}

EdgeList edgeCons(EdgeInfo newE, EdgeList oldL){
	EdgeList newEdge=(EdgeList)calloc(1,sizeof(EdgeInfoStruct));
	newEdge->fedge=newE;
	newEdge->rest=oldL;
	return newEdge;
}

//#endif
