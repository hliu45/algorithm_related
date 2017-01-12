//Name:Hsin-Liang Liu
//CruzID:hliu45
//ID:1446091

#ifndef DFS_1
#define DFS_1

#define W 1 
#define G 2
#define B 3

#include "intList.h"
#include "dStack.h"


//DFS

void printArrays(int, int[], int[], int[]);
IntStack * dfsSweep(IntList[], int);
int dfs(IntList[], int,int ,int[], int[], int[],int[], IntStack *, int);
int min(int,int);
int * initColor(int);
int * initDiscoverTime(int);
int * initFinishTime(int);
int * initParent(int);
int bicompDFS(IntList[], int, int, int[], int[], IntStack *, int);
void bicomponents(IntList[], int);
#endif
