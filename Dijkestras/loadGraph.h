//Name:Hsin-Liang Liu
//CruzID:hliu45
//ID:1446091

#ifndef LOADGRAPH
#define LOADGRAPH

#include "intList.h"

//load and build graph
typedef struct {
  int from;                                                         
  int to;
  double weight;
} Edge;


	FILE * open_file(char *);
	IntList * initEdges(int); 
	int parseN(char *);
	Edge parseEdges(char *, int);
	void loadEdges(char *, IntList[], int);
	void UloadEdges(char *, IntList[], int);
	void printGraph(IntList[], int);
	IntList * transposeGraph(IntList[], int);
	int hasCycle(IntList[], int);
	int hasCycleLen(IntList[], int, int, IntList);
	IntList * arrange(IntList *adjVs,int num);

#endif
