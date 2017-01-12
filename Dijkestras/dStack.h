//Name:   Hsin-Liang Liu 
//CruzID: hliu45
//ID:	  1446091

#ifndef STACK
#define STACK

typedef struct EdgeInfoStruct{
        int f;
        int t;
}EdgeInfo;


struct stkTime
{
	int intKey;
	EdgeInfo key;
	struct stkTime * prev;
	struct stkTime * next;
};

/*typedef struct EdgeInfoStruct{
	int f;
	int t;
}EdgeInfo;*/

typedef struct stkTime StkDfs;

typedef struct
{
	int size;
	StkDfs * last;
} IntStack;

IntStack * initStk();
int isEmptyStk(IntStack *);

//Access function
//Precondition: Stack is not empty.
//Postcondition: None.
void printStk(IntStack *);

//Access function
//Precondition: None.
//Postcondition: Stack is not empty.
void pushEdge(IntStack *, EdgeInfo);

void pushInt(IntStack *,int);

//Access function
//Precondition: stack is not empty.
//return: the first element's time, return -1 if stack is nil.
EdgeInfo topEdge(IntStack *);

//Access function
//Precondition: Stack is not nil.
//Postcondition: None.
void popEdge(IntStack *);

#endif
