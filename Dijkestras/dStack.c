/* ******************************************************	
 *	CS101 Abstract Data Type and Algorithm          *           
 *		5th programming assignment		*
 *  Name: Hsin-Liang Liu   CruzID: hliu45   ID:1446091	*
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "dStack.h"

IntStack * initStk() {
	IntStack * stk = (IntStack *)malloc(sizeof(IntStack));
	stk->last = NULL;
	stk->size = 0;

	return stk;
}

int isEmptyStk(IntStack * stk) {
	if (stk->size == 0)
		return 1;
	else
		return 0;
}

/*void printStk(IntStack * stk) {
	if (isEmptyStk(stk)) {
		puts("Empty stack");
		return;
	}   

	StkDfs * ft = stk->last;
	puts("");
	while(ft) {
		printf("\t %d\n", ft->intKey);
		ft = ft->prev;
	}
	puts("\t___\n\tstack\n");
}*/

void pushEdge(IntStack * stk, EdgeInfo einf) {
	StkDfs * newElt = (StkDfs *)malloc(sizeof(StkDfs));

	newElt->next = NULL;
	newElt->key = einf;
	newElt->prev = stk->last;
	if (!isEmptyStk(stk)) {
		(stk->last)->next = newElt;
	}
	stk->last = newElt;
	stk->size++;
}

void pushInt(IntStack * stk, int elt) {
        StkDfs * newElt = (StkDfs *)malloc(sizeof(StkDfs));

        newElt->next = NULL;
        newElt->intKey = elt;
        newElt->prev = stk->last;
        if (!isEmptyStk(stk)) {
                (stk->last)->next = newElt;
        }
        stk->last = newElt;
        stk->size++;
}


EdgeInfo topEdge(IntStack * stk) {
	/*if (isEmptyStk(stk)){
		return -1;
	}
	else*/
		return (stk->last)->key;
}

void popEdge(IntStack * stk) {
	if (isEmptyStk(stk))
		return;

	StkDfs * top = stk->last;
	stk->last = top->prev;
	free(top);
	stk->size--;
}
