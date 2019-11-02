/** Musa, Al Vincent V. CS-1B Computer Programming 2 ME07.c (modified) **/

// This program contains a list and operations in the list
// are taken from the input file "list.txt" that contains
// the operations to be done and the input values.

/* Operating and maintaining a list */
#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
struct listNode {
	char data; /* each listNode contains a character */
	struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */

typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void insert( ListNodePtr *sPtr, int value );
int delete( ListNodePtr *sPtr, int value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
int count(ListNodePtr currentPtr);
int max(ListNodePtr currentPtr);
int min(ListNodePtr currentPtr);

int main( void ) {

	ListNodePtr startPtr = NULL; /* initially there are no nodes */
	int choice; /* user's choice */
	int item; /* char entered by user */
	int elements;
	
	FILE *inFilePtr = fopen("list.txt", "r");

	/* loop while user does not choose 3 */
	while (fscanf(inFilePtr, "%d %d", &choice, &item) != EOF) {
		switch ( choice ) {
			case 1: 
				insert( &startPtr, item ); /* insert item in list */
				printList( startPtr );
				break; 
			case 2: /* delete an element */
				/* if list is not empty */
				if ( !isEmpty( startPtr ) ) {
					printf( "DELETE: %d\n", item );
					if ( delete( &startPtr, item ) ) { /* remove item */
						
						printList( startPtr );
					} /* end if */
					else {
						printf( "%d not found.\n\n", item );
					} /* end else */
				} /* end if */

				else {
					printf( "List is empty.\n\n" );
				} /* end else */
				break;
			default:
				break;

		} /* end switch */
	} /* end while */
	
	printf("Count: %d\n", count(startPtr));		// Print the number of elements in the list.
	printf("Maximum key: %d\n", max(startPtr));	// Print the maximum value in the list.
	printf("Minimum key: %d\n", min(startPtr));	// Print the minimum value in the list.

	fclose(inFilePtr); // close input file pointer

	return 0; /* indicates successful termination */

} /* end main */

/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, int value ) {
	ListNodePtr newPtr;		/* pointer to new node */
	ListNodePtr previousPtr; 	/* pointer to previous node in list */
	ListNodePtr currentPtr; 	/* pointer to current node in list */

	newPtr = malloc( sizeof( ListNode ) ); /* create node */

	if ( newPtr != NULL ) { /* is space available */
	
	newPtr->data = value; 	/* place value in node */
	newPtr->nextPtr = NULL; /* node does not link to another node */

	previousPtr = NULL;
	currentPtr = *sPtr;

		/* loop to find the correct location in the list */
		while ( currentPtr != NULL && value > currentPtr->data ) {
			previousPtr = currentPtr; 		/* walk to ...*/
			currentPtr = currentPtr->nextPtr;	/* ... next node */
		} /* end while */


		/* insert new node at beginning of list */
		if ( previousPtr == NULL ) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		} /* end if */
		else { /* insert new node between previousPtr and currentPtr */
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		} /* end else */
		printf("INSERT: %d\n", value); // Print the inserted value.
	} /* end if */
	else {
	printf( "%d not inserted. No memory available.\n", value );
	} /* end else */
} /* end function insert */

/* Delete a list element */
int delete( ListNodePtr *sPtr, int value ) {
	ListNodePtr previousPtr; 	/* pointer to previous node in list */
	ListNodePtr currentPtr; 	/* pointer to current node in list */
	ListNodePtr tempPtr;		/* temporary node pointer */
	
	/* delete first node */
	if ( value == ( *sPtr )->data ) {
		tempPtr = *sPtr; 		/* hold onto node being removed */
		*sPtr = ( *sPtr )->nextPtr; 	/* de-thread the node */
		free( tempPtr );		/* free the de-threaded node */
		return value;
	} /* end if */
	else {
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->nextPtr;

		/* loop to find the correct location in the list */
		while ( currentPtr != NULL && currentPtr->data != value ) {
			previousPtr = currentPtr;		/* walk to ... */
			currentPtr = currentPtr->nextPtr; 	/* ... next node */
		} /* end while */
		if ( currentPtr != NULL ) {
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free( tempPtr );
			return value;
		} /* end if */

		/* delete node at currentPtr */
	} /* end else */

} /* end function delete */

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr ) {
	return sPtr == NULL;
} /* end function isEmpty */

/* Print the list */
void printList( ListNodePtr currentPtr ) {
	/* if list is empty */
	if ( currentPtr == NULL ) {
		printf( "List is empty.\n\n" );
	} /* end if */
	else {
		printf( "The list is: " );
	/* while not the end of the list */

		while ( currentPtr != NULL ) {
			printf( "%d --> ", currentPtr->data );
			currentPtr = currentPtr->nextPtr;
		} /* end while */
		printf( "NULL\n\n" );
	} /* end else */
} /* end function printList */

/* Count the elements in the list */
int count(ListNodePtr currentPtr) {
	int countElem = 0;

	/* if list is empty */
	if ( currentPtr == NULL ) {
		printf( "List is empty.\n\n" );
	} /* end if */
	else {
		while ( currentPtr != NULL ) {
			countElem++;
			currentPtr = currentPtr->nextPtr;
		} /* end while */
	} /* end else */

	return countElem;
} /* end function count() */

/* Find the highest value in the list */
int max(ListNodePtr currentPtr) {
	
	int maxKey = currentPtr->data;		// Takes the first element as the initial maximum key.
	
	currentPtr = currentPtr->nextPtr; 	// Go to the next node.

	if ( currentPtr == NULL ) {
		printf( "List is empty.\n\n" );
	} /* end if */
	else {
		while ( currentPtr != NULL ) {

			if(currentPtr->data > maxKey) {
				maxKey = currentPtr->data;
			}
			currentPtr = currentPtr->nextPtr;
		} /* end while */
	} /* end else */

	return maxKey;	// return max key.
}

/* Find the lowest value in the list */
int min(ListNodePtr currentPtr) {
	
	int minKey = currentPtr->data;		// Takes the first element as the initial maximum key.
	
	currentPtr = currentPtr->nextPtr;	// Go to the next node.

	if ( currentPtr == NULL ) {
		printf( "List is empty.\n\n" );
	} /* end if */
	else {
		while ( currentPtr != NULL ) {

			if(currentPtr->data < minKey) {
				minKey = currentPtr->data;
			}
			currentPtr = currentPtr->nextPtr;
		} /* end while */
	} /* end else */

	return minKey;	// return min key.
}
