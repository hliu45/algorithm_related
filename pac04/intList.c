/*Hsin-Liang Liu*/
/*ID:1446091*/

#include<stdlib.h>
#include "intList.h"

struct IntListNode
{
  int node;
  IntList next;
};

typedef struct IntListNode IntListNode;

const IntList nil=NULL;


int intFirst(IntList oldList)
 { 
  return oldList->node;
 }

IntList intRest(IntList oldList)
 {
 return oldList->next;
 }

IntList intCons(int newElement, IntList oldList)
 {
   IntList newList=(IntList)calloc(1,sizeof(IntListNode));
   newList->node=newElement;
   newList->next=oldList;
   return newList;
 }

