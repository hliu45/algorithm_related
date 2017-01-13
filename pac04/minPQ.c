//Name:Hsin-Liang Liu
//CruzID:hliu45
//ID:1446091


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minPQ.h"


int isEmptyPQ(MinPQ *pq){
	if (pq->numPQ==0)
		return 1;
	else
		return 0;
}

void findMin(MinPQ *pq){
	int v;
	double minWgt;
	
	minWgt=pq->oo;
	for(v=1;v<=pq->numVertices;v++){
		if(pq->status[v]==FRINGE)
		 if(pq->fringeWgt[v]<minWgt){
			pq->minVertex=v;
			minWgt=pq->fringeWgt[v];
		}
	}
}



int getMin(MinPQ *pq){
	if(pq->minVertex==-1)
		findMin(pq);
	return pq->minVertex;
}

int getStatus(MinPQ *pq, int id){
	return pq->status[id];
}

int getParent(MinPQ *pq, int id){
	return pq->parent[id];
}

double getPriority(MinPQ *pq, int id){
	return pq->fringeWgt[id];
}

void delMin(MinPQ *pq){
	int oldMin=getMin(pq);
	pq->status[oldMin]=INTREE;
	pq->minVertex=-1;
	pq->numPQ--;
}

void insertPQ(MinPQ *pq,int id,double priority, int par){
	pq->parent[id]=par;
	pq->fringeWgt[id]=priority;
	pq->status[id]=FRINGE;
	pq->minVertex=-1;
	pq->numPQ++;
}

void decreaseKey(MinPQ *pq,int id,double priority,int par){
	pq->parent[id]=par;
	pq->fringeWgt[id]=priority;
	pq->minVertex=-1;
}

MinPQ *createPQ(int n,int* status,double *priority,int *parent){
	MinPQ *pq=(MinPQ *)calloc(n+1,sizeof(MinPQ));
	status=(int *)calloc(n+1,sizeof(int));
	pq->parent=parent;
	pq->fringeWgt=priority;
	pq->status=status;
	//pq->wight=wight;

	int i;
	for(i=1;i<=n;i++)	
		pq->status[i]=UNSEEN;

	pq->numVertices=n;
	pq->numPQ=0;
	pq->minVertex=-1;
	pq->oo=1000.0;

	return pq;
}
