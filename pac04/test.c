#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edgeList.h"
#include "edgeList.c"
#include "minPQ.h"
#include "minPQ.c"

EdgeList * initE(int n)
{
   EdgeList *edj=calloc(n+1,sizeof(EdgeList));
   int i;
   for(i=1;i<=n;i++)
	edj[i]=NULL;
   return edj;
}

void loadEdge(EdgeInfo fromA,EdgeList *edge)
{
	int a=1;
	edge[a]=edgeCons(fromA,edge[a]);
}

int main(){
  char Line[]={3,4};
  EdgeList *e=initE(3);
  EdgeInfo parseEdge(char line[]){
  EdgeInfo nE;
  sscanf(line,"%d %d",&nE.from,&nE.to);
  return nE;
}
  EdgeInfo etest;
  etest=parseEdge(Line);  
  loadEdge(etest,e);

return 0;
}
