#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head, *ptr;

void printList();
void initializeList();
void insert();
void delete();
int listLength();
int interface();

int main(int argc, char const *argv[])
{
	int choice = 0;

	initializeList();

	while(choice != 9) {
		choice = interface();

		switch(choice) {

			case 1: {
				insert();
				printList();
			}
			break;

			case 2: {
				printList();
			}
			break;

			case 3: {
				printf("The list has %d elements\n", listLength() );
			}
			break;

			case 4: {
				delete();
			}
			break;

			case 9: {
				exit(0);
			}
			break;

			default: {
				printf("Invalid input\n");
			}
			break;
		}
	}

	return 0;
}

// interface function;
int interface() {
	int choice = 0;

	printf("\nEnter the number from the list of options from below\n"
		"1. Insert new data\n"
		"2. Print the list\n"
		"3. Print the length of the list\n"
		"4. Delete last node\n"
		"9. Exit program\n\n");

	printf("Option: ");
	scanf("%d", &choice);

	return choice;
}

// intialize list
void initializeList() {
	ptr = NULL;
	head = ptr;
}

// print list function
void printList() {
	if(head == NULL) {
		printf("List is empty\n");
	} 
	else {
		printf("List: HEAD ");

		ptr = head;

		while(ptr != NULL) {
			printf("--> %d ", ptr->data);

			ptr = ptr->next;
		}

		printf("--> END\n");
	}
}

// insert sort function
// void insert() {
// 	struct node *previousPtr, *newPtr;
// 	int input;

// 	newPtr = (struct node *) malloc(sizeof(struct node *));

// 	printf("\nEnter data: ");
// 	scanf("%d", &input);

// 	if (newPtr != NULL) {
// 		newPtr->data = input;
// 		newPtr->next = NULL;

// 		previousPtr = NULL;
// 		ptr = head;

// 		while(ptr != NULL && input > ptr->data) {
// 			previousPtr = ptr;
// 			ptr = ptr->next;
// 		}

// 		if(previousPtr == NULL) {
// 			newPtr->next = head;
// 			head = newPtr;
// 		}
// 		else {
// 			previousPtr->next = newPtr;
// 			newPtr->next = ptr;
// 		}
// 	}
// 	else {
// 		printf("No memory available.\n");
// 	}
// }

// Insert at head function
// void insert() {
// 	struct node *newPtr;
// 	int input;

// 	newPtr = (struct node *) malloc(sizeof(struct node *));

// 	printf("\nEnter data: ");
// 	scanf("%d", &input);

// 	if(newPtr != NULL) {
// 		newPtr->data = input;
// 		newPtr->next = NULL;

// 		newPtr->next = head;
// 		head = newPtr;
// 	}
// 	else {
// 		printf("No memory available.\n");
// 	}
// }

// Insert at tail function
void insert() {
	struct node *newPtr, *tailPtr;
	int input;

	newPtr = (struct node *) malloc(sizeof(struct node *));

	printf("\nEnter data: ");
	scanf("%d", &input);

	if(newPtr != NULL) {
		newPtr->data = input;
		newPtr->next = NULL;

		tailPtr = head;

		if(head == NULL) {
			head = newPtr;
		}
		else {
			while(tailPtr->next != NULL) {
				tailPtr = tailPtr->next;
			}
			tailPtr->next = newPtr;
		}
	}
	else {
		printf("No memory available.\n");
	}
}

// Delete head function
// void delete() {
// 	struct node *deletePtr, *previousPtr;

// 	if(head == NULL) {
// 		printf("The list is empty. Nothing to delete.\n");
// 	}
// 	else {
// 		printf("Deleting last node...\n");
		
// 		deletePtr = head;
// 		head = head->next;

// 		free(deletePtr);

// 		printf("Last node deleted...\n");
// 		printList();
// 	}
// }

// Delete tail function
// void delete() {
// 	struct node *deletePtr, *previousPtr;

// 	if(head == NULL) {
// 		printf("The list is empty. Nothing to delete.\n");
// 	}
// 	else {
// 		printf("Deleting last node...\n");
		
// 		previousPtr = head;
// 		deletePtr = head;

// 		while(deletePtr->next != NULL) {
// 			previousPtr = deletePtr;
// 			deletePtr = deletePtr->next;
// 		}

// 		if(deletePtr == head) {
// 			head = NULL;
// 		}
// 		else {
// 			previousPtr->next = NULL;
// 		}
// 		free(deletePtr);

// 		printf("Last node deleted...\n");
// 		printList();
// 	}
// }

//Delete function that deletes  speciific value
void delete() {
	struct node *deletePtr, *previousPtr;
	int value;

	printf("Enter value you want to delete: ");
	scanf("%d", &value);

	if(head == NULL) {
		printf("The list is empty. Nothing to delete.\n");
	}
	else {
		if(value == head->data) {
			printf("Deleting node...\n");

			deletePtr = head;
			head = head->next;
			free(deletePtr);

			printf("Node deleted...\n");
 			printList();
		}
		else {
			printf("Deleting node...\n");

			previousPtr = head;
			ptr = head->next;

			while(ptr != NULL && ptr->data != value) {
				previousPtr = ptr;
				ptr = ptr->next;
			}

			if(ptr != NULL) {
				deletePtr = ptr;
				previousPtr->next = ptr->next;

				free(deletePtr);

				printf("Node deleted...\n");
	 			printList();
			}
			else {
				printf("%d does not exist or cannot be found\n", value );
			}
		}	
	}
}

int listLength() {
	int count = 0;

	ptr = head;

	if(ptr == NULL) {
		printf("List is empty\n");
	}
	else {
		while(ptr != NULL) {
			count++;
			ptr = ptr->next;
		}
	}

	return count;
}
	