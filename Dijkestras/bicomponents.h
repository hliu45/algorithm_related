//Name:Hsin-Liang Liu
//CruzID:hliu45
//ID:1446091

#ifndef BICOMPONENTS
#define BICOMPONENTS

#define W 1 
#define G 2
#define B 3

#include "intList.h"
#include "dStack.h"


//DFS

int min(int,int);
int * initColor(int);
int * initDiscoverTime(int);

int bicompDFS(IntList[], int, int, int[], int[], IntStack *, int);
void bicomponents(IntList[], int);
#endif
