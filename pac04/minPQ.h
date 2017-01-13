//Name: Hsin-Liang Liu
//CruzID: hliu45
//ID:1446091

/* minPQ.h 
 * This files can do multiple functions that are used for performing Prim/Dijkstra Algorithm
 */
#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

//typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('c')

typedef struct 
{
  int numVertices;
  int minVertex;
  int numPQ;
  double oo;
  int* status;
  int* parent;
  double* wight;
  double* fringeWgt;
}MinPQ;



/* Access functions (what are the preconditions?)
 * */

void findMin(MinPQ *pq);

/** isEmpty
 * */
int isEmptyPQ(MinPQ *pq);

/** getMin
 * */
int getMin(MinPQ *pq);

/** getStatus
 * */
int getStatus(MinPQ *pq, int id);

/** getParent
 * */
int getParent(MinPQ *pq, int id);

/** getPriority
 * */
double getPriority(MinPQ *pq, int id);

/* Manipulation procedures 
 * Precondition: pq is not empty
 * Postcondition: None
 * These functions can manipulate and retrieve the information we wnat
 * */

/** delMin
 * */
void delMin(MinPQ *pq);

/** insertPQ
 * */
void insertPQ(MinPQ *pq, int id,double priority, int par);

/** decreaseKey
 * */
void decreaseKey(MinPQ *pq, int id, double priority, int par);

/* Constructors
 * Precondition: pq is empty
 * Postcondition: create an element that has parent/weight/status information
 * */

/**
 * */
MinPQ *createPQ(int n, int status[],double priority[], int parent[]);



#endif
