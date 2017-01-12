/**************************************************************** 
*    CMPS 101 Spring 2015 - Abstract Data Type and Algorithm    /
*        3th programming assignment- pa03                       /
*     Name:Hsin-Liang Liu   CruzID:hliu45    ID:1446091         /
*                                                               /
****************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "intList.h"
#include "loadGraph.h"
#include "dStack.h"
#include "dfsTrace.h"
#include "dfsPhase.h"
#include <unistd.h>


int main(int argc, char* argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Usage: graph01 input.data \n");
   		exit(0);
	}
	
        char * infile=argv[1];
	FILE * fp;
	if(strcmp(argv[1],"-")){
	fp=fopen(infile,"r");
	if(fp==NULL){
		fprintf(stderr, "no such file!\n");
		exit(-1);
	}
	printf("Opened %s for input\n",infile);
	}		 	
	else
		fp=stdin;

	char line[1024];
	int n;
	char * fgetsRetn;
	fgetsRetn = fgets(line, sizeof(line), fp);
	if (!fgetsRetn)
		fprintf(stderr, "empty file\n");
	n = parseN(line);

	IntList * adjVertices;
	adjVertices = initEdges(n);

	while (fgets(line, sizeof(line), fp)) {
		loadEdges(line, adjVertices, n);
	}

	printf("This is original graph\n");//output original graph
	printf("------------------------------------------\n");
	printGraph(adjVertices, n);

	Stack * finishStk1 = dfsSweep1(adjVertices, n);//do the first phase DFS

	printf("------------------------------------------\n");
	printStk(finishStk1);

	IntList * tranGraph = transposeGraph(adjVertices, n);
	printf("Transpose graph\n");//output transpose graph
	printf("------------------------------------------\n");
	printGraph(tranGraph, n);

	dfsSweep2(tranGraph, n, finishStk1);

	fclose(fp);
	free(adjVertices);
	free(tranGraph);
	free(finishStk1);

	return 0;
}
