/**************************************************************** 
 *    CMPS 101 Spring 2015 - Abstract Data Type and Algorithm   /
 *        4th programming assignment- pa04                      /
 *     Name:Hsin-Liang Liu   CruzID:hliu45    ID:1446091        /
 *                                                              /
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intList.h"
#include "edgeList.h"
#include "minPQ.h"
#include <assert.h>


void updateFringe(MinPQ *pq,EdgeList adjInfoV,int v);
void printArray(EdgeList *adjInfo,int n,int *parent,double *fringeWgt,int *status);
void shortestPath(MinPQ *pq, EdgeList adjInfo,int v);

/**initial Edge information to NULL*/
EdgeList * initEdgesP(int n){
	EdgeList *adjInfo=calloc(n+1,sizeof(EdgeList));
	int i;
	for(i=1;i<=n;i++)
		adjInfo[i]=NULL;
	return adjInfo;
}

/**initial parent to -1*/
int *initParent(int n){
	int *parent=calloc(n+1,sizeof(int));
	int i;
	for(i=1;i<=n;i++)
		parent[i]=-1;
	return parent;
}

/**initial fringeWgt*/
double *initFringeWgt(int n){
	double *fringeWgt=calloc(n+1,sizeof(int));
	int i;
	for(i=1;i<=n;i++)
		fringeWgt[i]=99999.0;
	return fringeWgt;
}

/**Reade the line and allocate the number as from to weight */
EdgeInfo parseEdgeU(char line[]){
	EdgeInfo newE;
	int numWords;
	numWords=sscanf(line,"%d %d %lf",&newE.from, &newE.to, &newE.wgt);
	if(numWords<2 || numWords>3){
		printf("Bad edge: %s",line);
	exit(1);
	}
 	if(numWords==2)
   	newE.wgt=0.0;
  
	return newE;
}

/**Read the first line and denote it as the total number of vertice*/
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

/**load the graph as directed graph*/
void loadEdgesDir(char *line, EdgeList *adjVertices)
{
   	EdgeInfo e;
   	e = parseEdgeU(line);
   	adjVertices[e.from]=edgeCons(e,adjVertices[e.from]);
}

/**load the graph as undirected graph*/
void loadEdgesUni(char *line, EdgeList *adjVertices)
{
	EdgeInfo e;
	e=parseEdgeU(line);
	adjVertices[e.from]=edgeCons(e,adjVertices[e.from]);
	int instant=e.from;
	e.from=e.to;
	e.to=instant;
	adjVertices[e.from]=edgeCons(e,adjVertices[e.from]);
}


/** execute either Prim's MST or Dijksur's SSP based on the command line -P or -D */
void greedyTree(EdgeList *adjInfo,int n,int s,int *parent,double *fringeWgt,int task){
        int *status=calloc(n+1,sizeof(int));
        MinPQ *pq=createPQ(n+1,status,fringeWgt,parent);

        insertPQ(pq,s,0.0,-1);
        while(isEmptyPQ(pq)==0){
                int v=getMin(pq);
                delMin(pq);
		if(task==1)
			updateFringe(pq,adjInfo[v],v);
		else
			shortestPath(pq,adjInfo[v],v);
        }
	printf("\n");
   	if(task==1)
		printf("Prim's Algorithm MST - starting from vertex %d\n",s);
   	else
		printf("Dijkstra SSSP        - starting from vertex %d\n",s);
	printf("------------------------------------------------\n");
	printArray(adjInfo,n,parent,fringeWgt,status);
}

/**this will search the shortes weight from fringe to tree (It's used in Prim's algorithm) */
void updateFringe(MinPQ *pq,EdgeList adjInfoV,int v){
        EdgeList remAdj;
        remAdj=adjInfoV;
        while(remAdj){
                EdgeInfo wInfo=edgeFirst(remAdj);
                int w=wInfo.to;
                double newWgt=wInfo.wgt;
                if(pq->status[w]==UNSEEN)
                        insertPQ(pq,w,newWgt,v);
                if(pq->status[w]==FRINGE) 
                        if(newWgt<getPriority(pq,w))
                                decreaseKey(pq,w,newWgt,v);
        remAdj=edgeRest(remAdj);
        }
}

/**this will search shortest path (It's used in DijkSra's Algorithm) */
void shortestPath(MinPQ *pq, EdgeList adjInfo,int v){
        double myDist=pq->fringeWgt[v];
        EdgeList remAdj;
        remAdj=adjInfo;
        while(remAdj){
        EdgeInfo wInfo=edgeFirst(remAdj);
        int w=wInfo.to;
        double newDist=myDist+wInfo.wgt;
        if(pq->status[w]==UNSEEN)
                insertPQ(pq,w,newDist,v);
        if(pq->status[w]==FRINGE)
                if(newDist<getPriority(pq,w))
                       decreaseKey(pq,w,newDist,v);
        remAdj=edgeRest(remAdj);
        }
}

/**print array as four column talbe*/
void printArray(EdgeList *adjInfo,int n,int *parent,double *fringeWgt,int *status){
	int i;
	printf("vertex\t parent\t fringeWgt\t status\n");
	for(i=1;i<=n;i++){
	printf("%d\t %d\t %lf\t ",i,parent[i],fringeWgt[i]);
	if(status[i]=='u')
		printf("unseen\n");
	else if(status[i]=='f')
		printf("fringe\n");
	else
		printf("tree\n");
	}
}

//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
 	int n,s; //n:the total number of vertex, s:the starting vertex
 	FILE *fp;
 	char *infile=argv[3];
 	char *fgetsRetn,line[1024];
 	int task; //(task denote whether it's Prim's or Dijkstra's algirthm, 1:Prim ,2:Dijkstra)
 
	//if the command line does not follow the command line, the program will stop
  	if(argc!=4){ 
    		printf("Usage: graph input.data\n"); 
    	exit(0);
   	}
  
	if(!((strcmp(argv[1],"-P"))*(strcmp(argv[1],"-p"))*(strcmp(argv[1],"P"))*(strcmp(argv[1],"p"))))
		task=1;  //not case sensitive
	else if(!((strcmp(argv[1],"-D"))*(strcmp(argv[1],"-d"))*(strcmp(argv[1],"D"))*(strcmp(argv[1],"d"))))
		task=2;  //not case sensitive
	else{
		printf("choose between Prim MST(-P) and Dijkstra SSSP(-D)\n");
		exit(-1);
	}

	s=atoi(argv[2]);

       	if(strcmp(argv[3],"-")){
        	fp=fopen(infile,"r");
        if(fp==NULL){
                fprintf(stderr, "no such file!\n");
                exit(-1);
        	}
	printf("\n");
        printf("Opened %s for input\n",infile);
        }
        else
                fp=stdin;
        fgetsRetn = fgets(line, sizeof(line), fp);
        if (!fgetsRetn) //if the file doesn't match any file in the directory
                fprintf(stderr, "empty file\n");    
     	/*(Above part deal with the command line)*/

//-----------------------------------------------------------------

       n=parseN(line);//number of nodes
	if(s>n){
		printf("The start vertex has to be smaller than the total number of nodes\n");
		exit(-1);
	}
	/*(this make sure the start vertex wouldn't exceed total number of vertex)*/
//--------------------------------------------------------------------

	EdgeList *oriGraph=calloc(n+1,sizeof(EdgeList));   
        oriGraph=initEdgesP(n);
              
      	while (fgets(line, sizeof(line), fp)){
              	if(task==1)
			loadEdgesUni(line,oriGraph); //load unidrected graph for Prim's algorithm
		else
			loadEdgesDir(line,oriGraph); //load directed graph Dijkra's algorithm
        }     

	int *parent=initParent(n); //initial parent
 	double *fringeWgt=initFringeWgt(n); //initial fringeWgt
        
	greedyTree(oriGraph,n,s,parent,fringeWgt,task);//execute prim's or Dijkstra's algorithm
	
	printf("-----------------------------------------------------END\n");
      	return (0);   
}
