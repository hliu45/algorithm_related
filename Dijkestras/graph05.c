/**************************************************************** 
*    CMPS 101 Spring 2015 - Abstract Data Type and Algorithm    /
*        5th programming assignment- pa03                       /
*     Name:Hsin-Liang Liu   CruzID:hliu45    ID:1446091         /
*                                                               /
****************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "intList.h"
#include "loadGraph.h"
#include "biComp.h"
#include <unistd.h>
#include "dStack.h"

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
	puts("");
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

	IntList * unAdjVertices;
	unAdjVertices=initEdges(n);

	while (fgets(line, sizeof(line), fp)!=NULL) {
		UloadEdges(line, unAdjVertices, n);
	}

		
	unAdjVertices=arrange(unAdjVertices, n);	
	
	printf("undirected graph-------------------------------------\n");
	printGraph(unAdjVertices, n);
	
	//bicomponents(unAdjVertices, n);

	//dfsSweep(unAdjVertices,n);	
	
	bicomponents(unAdjVertices, n);
	
	printf("-----------------------------------------------------\n");	

	fclose(fp);
	free(unAdjVertices);
	
	return 0;
}
