/*   CS101 Abstract Data Type and Algorithm
 *   	5th Programming Assignment
 *   Name:Hsin-Liang Liu 
 *   CruzID:hliu45 
 *   ID:1446091
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadGraph.h"

IntList * initEdges(int n) {
	IntList * adjVs = (IntList *)calloc(n + 1, sizeof(IntList));
	int i;
	for (i = 1; i <= n; ++i) 
		adjVs[i] = NULL;
	return adjVs;
}


int parseN(char * line) {
	int num;
	char * lineTmp = strdup(line);
	char * w0 =  strtok(lineTmp, " \t\n");
	char * w1 =  strtok(NULL, " \t\n");

	if (w0 == NULL || w1 != NULL) {
		fprintf(stderr, "bad line 1: %s", line);
		exit(1);
	}

	num = atoi(w0);
	free(lineTmp);
	return num;
}

Edge parseEdges(char * line, int num) {
	Edge newE;
	char * lineTmp = strdup(line);
	char * w0 =  strtok(lineTmp, " \t\n");
	char * w1 =  strtok(NULL, " \t\n");
	char * w2 =  strtok(NULL, " \t\n");
	char * w3 =  strtok(NULL, " \t\n");

	if (w0 == NULL || w1 == NULL || w3 != NULL) {
		fprintf(stderr, "bad edge: %s", line);
		exit(1);
	}

	newE.from = atoi(w0);
	newE.to   = atoi(w1);

	if (newE.from <= 0 || newE.from > num \
	    || newE.to <= 0 || newE.to > num) {
		fprintf(stderr, "Edge (%d, %d) is out of range\n",\
			newE.from,   newE.to);
		newE.from = 0;
		newE.to = 0;
	}  

	if (w2 != NULL)
		newE.weight = atof(w2);
	else
		newE.weight = 0.0;
	free(lineTmp);


	return newE;
}

IntList * arrange(IntList *adjVs,int num){
	int i,k,l,m,temp;
	IntList * unAdj=initEdges(num);
	for(i=1;i<=num;i++){
		IntList node=adjVs[i];
		int j=1;
		int a[num+1];
		while(node){
			a[j]=intFirst(node);
			node=intRest(node);
			j++;
		}
//------------------------------------------------
	for(l=1;l<j;l++){
		temp=a[l];
		m=l-1;
		while((temp<a[m])&&(m>=1)){
			a[m+1]=a[m];
			m=m-1;
			}
		a[m+1]=temp;
		}
//----------------------------------------------
	for(k=j-1;k>=1;k--){
		unAdj[i]=intCons(a[k],unAdj[i]);
		}
	}
	
	return unAdj;
}

void UloadEdges(char * line, IntList * adjVs, int num){
	Edge e = parseEdges(line, num);

	if (e.from != 0 && e.to != 0){
		adjVs[e.from] = intCons(e.to, adjVs[e.from]);
		adjVs[e.to]=intCons(e.from,adjVs[e.to]);
		}
}

void printGraph(IntList * adjVs, int num) {                                     
	int i;
	for (i = 1; i <= num; ++i) {
		IntList pnode = adjVs[i];
		int init = 1;
		printf("%d\t", i);
		while (pnode) {
			if(init)
				printf("[");
			else
				printf(",");
			printf("%d", intFirst(pnode));
			pnode = intRest(pnode);
			init = 0;
		}
		if (init)           // if the IntList is NULL 
			printf("NULL");
		else
			printf("]");
		printf("\n");
	}
}

IntList *transposeGraph(IntList * oriGraph, int n)
{
   int i;
   IntList *adjVertice=initEdges(n);
   for(i=1;i<=n;i++){
     IntList pnode=oriGraph[i];
      while(pnode){
       adjVertice[intFirst(pnode)]=intCons(i,adjVertice[intFirst(pnode)]);
       pnode=intRest(pnode);
     } free(pnode);
   }
  return adjVertice;
}

