/*  CS101 Abstract Data Type and Algorithm            *
 *       3th Programming Assignment                   *
 *  Name: Hsin-Liang Liu  CruzID:hliu45  ID:1446091   *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfs.h"

//int dfs(IntList * adjVs, int v,int p, int * color, int * dTime,int * fTime, int * parent, Stack * fStk, int time);

int * initColor(int n){
	int i;
	int *color=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;++i)
		color[i]=W;
	return color;
}

int * initDiscoverTime(int n){
	int i;
	int *dTime=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;++i)
		dTime[i]=0;
	return dTime;
}

int * initFinishTime(int n){
	int i;
	int *fTime=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;++i)
		fTime[i]=0;
	return fTime;
}

int * initParent(int n){
	int i;
	int *parent=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;++i)
		parent[i]=-1;
	return parent;
}

void printArrays(int n,int *dTime,int *fTime,int *parent){
	int i;
        printf("\n");
	printf("dfs tree-----------------------------------------\n");
	printf("vertex\t dTime\t fTime\t parent\n");
	for(i=1;i<=n;++i){
		printf("%d\t %d\t",i,dTime[i]);
		printf("%d\t %d\n",fTime[i],parent[i]);
    }
}

int min(int num1, int num2){
	if(num1>=num2)
		return num2;
	else 
		return num1;
}

void bicomponents(IntList * adjVs, int n) {
        int * color, * dTime1, * fTime1, * parent1;
	int time=0;        

        color = initColor(n);
        dTime1 = initDiscoverTime(n);
        fTime1 = initFinishTime(n);
        parent1 = initParent(n);
        Stack * stk1 = initStk();
        
        //color W indicate white, G indicate gray, B indicate black
        int i;
        for (i = 1; i <= n; ++i)
                if (color[i] == W)
                        time = bicompDFS(adjVs, i,-1, color, dTime1,fTime1, parent1, stk1, time);

        printArrays(n, dTime1, fTime1, parent1);//print out the 4 coulmn table

        free(color);
        free(dTime1);
        free(fTime1);
        free(parent1);
}
        
int bicompDFS(IntList * adjVs, int v,int p, int * color, int * dTime,int * fTime, int * parent, Stack * fStk, int time) {
        int w;
        IntList remAdj;
	int back; 
        color[v] = G;
        time++;
        dTime[v] = time;
	back=dTime[v];
        remAdj = adjVs[v];
        while(remAdj != intNil) {
                w = intFirst(remAdj);
                if (color[w] == W) {
			EdgeInfo einfo;
			einfo.f=v;
			einfo.t=w;
			pushStk(fStk,einfo);
			int wBack=bicompDFS(adjVs,w,v,color,dTime,fTime,parent,fStk,time);
                        parent[w] = v;
                        time = bicompDFS(adjVs, w, p, color, dTime,\
                                        fTime, parent, fStk, time);
			if(wBack>=dTime[v]){
				while((topStk(fStk).f!=einfo.f || topStk(fStk).t!=einfo.t)/* && isEmptyStk(fStk)!=1*/){
				printf("(%d,%d) ",topStk(fStk).f,topStk(fStk).t);
				popStk(fStk);
				
				}
			if(topStk(fStk).f==einfo.f && topStk(fStk).t==einfo.t){
				printf("(%d,%d) ",topStk(fStk).f,topStk(fStk).t);
				popStk(fStk);	
				}
			puts("");
			}
			back=min(back,wBack);
                }
                
		if(color[w] == G && w!=p){
			EdgeInfo einfo;
			einfo.f=v;
			einfo.t=w;
			pushStk(fStk,einfo);
			back=min(dTime[w],back);
		}				
                remAdj = intRest(remAdj);
        }

        ++time;
        fTime[v] = time;
        color[v] = B;
       
        return back;
}
