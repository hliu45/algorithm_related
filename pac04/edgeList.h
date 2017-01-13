//Name: Hsin-Liang Liu
//CruzID:hliu45
//ID:1446091


/* edgeList.h
 * This file define the EdgeList structure; 
 * Including edge information: to and weight;
 * edgeFirst(EdgeList oldL) would call the first edge information;
 * edgeRest(EdgeList oldL) is contain the rest of the information except the first edge information;
 * edgeCons(EdgeInfo newE,EdgeList oldL) would add the edge information newE to the oldL; 
 */

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode * EdgeList;

typedef struct EdgeInfoStruct
    {
    int to;
    double wgt;
    }
    EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions
 * Precondition: EdgeList is not empty. * 
 * Return: the first edge information  */

/** first
 * */
EdgeInfo edgeFirst(EdgeList oldL);

/*Access functions
 * Precondition: EdgeList is not empty. *
 * Return: the rest information of EdgeList structure */

/** rest
 * */
EdgeList edgeRest(EdgeList oldL);

/* Constructors
 * Precondition: NONE.
 * Postcondition: it return newL as new EdgeList structure
 * It input edge information to the oldL to form a new EdgeList  
 *  */

/** cons
 * */
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif
