#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* self-referential structure */
struct listNode {
	char name[100];
	char sciName[100];
	char info[1000];

	struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */

typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

void mainMenu ();
void exitProg ();
void new(ListNodePtr *sPtr);

int main() {

	ListNodePtr startPtr = NULL; /* initially there are no nodes */

	int menuChoice;
	
	printf("\nThis is an animal data collection program.\n");
	mainMenu();

	do {
		printf(">> ");	
		scanf("%d", &menuChoice);
		
		switch(menuChoice) {
			case 1: {
					new(&startPtr);
				}
				break;
			case 2: {

				}
				break;
			case 3: {

				}
				break;
			case 4: {
					exitProg();
				}
				break;
			default: 
					printf("Invalid input... Try Again...\n");
					mainMenu();
				break;


		}
	} while(1);

}

void mainMenu() {
	printf(	"\n"
			"1. New\n"
			"2. Edit\n"
			"3. Delete\n"
			"4. Exit\n");
	return;
}

void exitProg() {
	
	char choice;

	printf("The program is about to close, are you sure?(Y / N)\n");
	scanf("%c", &choice);
	
	if(choice == 'Y' || choice == 'y') {
		printf("Program closed.\n");
		exit(1);
	}
	else if(choice == 'N' || choice == 'n') {
		mainMenu();
		return;
	}
}

void new(ListNodePtr *sPtr) {

	char animalName[100];
	char scientificName[100];
	char information[1000];

	printf("\nName: ");
	scanf("%s", animalName);

	printf("Scientific Name: ");
	scanf("%s", scientificName);

	printf("Information: ");
	scanf("%s", information);

	ListNodePtr newPtr;			/* pointer to new node */
	ListNodePtr previousPtr; 	/* pointer to previous node in list */
	ListNodePtr currentPtr; 	/* pointer to current node in list */

	newPtr = malloc( sizeof( ListNode ) ); /* create node */

	if ( newPtr != NULL ) { /* is space available */
	
	strcmp(newPtr->name, animalName);		/* place value in node */
	strcmp(newPtr->sciName, scientificName); 	/* place value in node */
	strcmp(newPtr->info, information); 		/* place value in node */
	newPtr->nextPtr = NULL;		/* node does not link to another node */

	previousPtr = NULL;
	currentPtr = *sPtr;

		/* loop to find the correct location in the list */
		while ( currentPtr != NULL && strcmp(animalName,currentPtr->name) > 0) {
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
		printf( "\n\nName: %s \n"
				"Scientific Name: %s \n"
				"Information: %s \n", animalName, scientificName, information); // Print the inserted value.
	} /* end if */
	else {
	printf( "Not inserted. No memory available.\n");
	} /* end else */
}