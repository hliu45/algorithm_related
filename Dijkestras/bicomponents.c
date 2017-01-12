/*  CS101 Abstract Data Type and Algorithm            *
 *       3th Programming Assignment                   *
 *  Name: Hsin-Liang Liu  CruzID:hliu45  ID:1446091   *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfs.h"
#include "bicomponents.h"

/*int * initColor(int n){
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
}*/

int min(int num1, int num2){
	if(num1>=num2)
		return num2;
	else 
		return num1;
}


void bicomponents(IntList * adjVs, int n) {
        int * color, * dTime1;
	int time=0;        

        color = initColor(n);
        dTime1 = initDiscoverTime(n);
        IntStack * stk1 = initStk();
        
        //color W indicate white, G indicate gray, B indicate black
        int i;
        for (i = 1; i <= n; ++i)
                if (color[i] == W)
                        time = bicompDFS(adjVs, i,-1, color, dTime1, stk1, time);

        free(color);
        free(dTime1);
}
        
int bicompDFS(IntList * adjVs, int v,int p, int * color, int * dTime, IntStack * fStk, int time) {
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
			int wBack=bicompDFS(adjVs,w,v,color,dTime,fStk,time);
                        time = bicompDFS(adjVs, w, p, color, dTime,\
                                     fStk, time);
			if(wBack>=dTime[v]){
				printf("articulation point:%d ",v);
				puts("");
				printf("bicomponent: ");
				while((topStk(fStk).f!=einfo.f || topStk(fStk).t!=einfo.t)){
				printf("(%d,%d) ",topStk(fStk).f,topStk(fStk).t);
				popStk(fStk);
				
				}
			if(topStk(fStk).f==einfo.f && topStk(fStk).t==einfo.t){
				printf("(%d,%d) ",topStk(fStk).f,topStk(fStk).t);
				puts("");
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
        color[v] = B;
       
        return back;
}
