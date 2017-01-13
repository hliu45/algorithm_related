//Name:Hsin-Liang Liu 
//CruzID:hliu45
//ID:1446091
/*the purpose of the file is to define function being used in intList sturecture*/


#ifndef C101IntList
#define C101IntList

typedef struct IntListNode * IntList;


/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * Precondition: Inlist structure oldL is not empty.
 * Return: first element of intList.
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 * Access functions
 * Precondition: IntList structure oldL is not empty
 * Return: everything after the first elements.
 */
IntList intRest(IntList oldL);

/* Constructors
 * Precondition: None.
 * Postcondition: Let newL be the return value of cons.
 * Then: newL refers to a new object, newL is not empty.
 * first(newL) = newE, rest(newL) = oldL.
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif
