#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

#define MAX 1000

struct Node {
	int data;
	char word[MAX];
	char wordDef[MAX];
	struct Node *next;
};

struct Node *head, *ptr;

char wordTemp[MAX];
char defTemp[MAX];

void insert(char *string1, char *string2);
void search(char *string1);
void delete(char *word);
void printList();
void getWord();
void getWordDef();
void userInterface();
void modtest_getWord();

void modtest_insert();
void modtest_delete();
void modtest_search();

int main() {
	int choice = 0;

	while(choice != 9) {

		userInterface();
		printf("Option: ");
		scanf("%d", &choice);
		printf("\n");

		switch(choice) {
			case 1: {
				// printf("Enter new word: ");
				// getWord();
				// printf("Enter word definition: ");
				// getWordDef();
				// insert(wordTemp, defTemp);
				modtest_insert();
				printList();
			}
			break;

			case 2: {
				printf("Enter word to search: ");
				getWord();
				search(wordTemp);
			}
			break;

			case 9: {
				printf("Program ended...\a\n");
			}
			break;

			default: {
				printf("Invalid input...\n");
			}
		}
	}

	return 0;
}

void userInterface() {
	printf("\nEnter the number from the list of options from below\n"
		"1. New word\n"
		"2. Search a word\n"
		"9. Exit program\n\n");
}

void getWord() {
	scanf(" %[^\n]%*c", wordTemp);
}

void getWordDef() {
	scanf(" %[^\n]%*c", defTemp);
}

void insert(char *string1, char *string2) {
	struct Node *newPtr, *tailPtr;

	newPtr = (struct Node *)malloc(sizeof(struct Node *));

	if(newPtr != NULL) {
		strcpy(newPtr->word, string1);
		strcpy(newPtr->wordDef, string2);
		newPtr->next = NULL;

		tailPtr = head;

		if(head == NULL) {
			head = newPtr;
			printf("New word added successfully!\n");
		}
		else {
			while(tailPtr->next != NULL) {
				tailPtr = tailPtr->next;
			}
			tailPtr->next = newPtr;
			printf("New word added successfully!\n");
		}
	}
	else {
		printf("No memory available.\n");
	}
}

void search(char *string1) {
	int isFound = 0;

	if(head == NULL) {
		printf("List is empty, nothing to find\n");
	}
	else {
		ptr = head;

		while(ptr != NULL && isFound == 0) {
			if(strcmp(ptr->word, string1) == 0) {
				printf("\nWord: %s\n", ptr->word);
				printf("Definition: %s\n", ptr->wordDef);
				isFound = 1;
			}
			else {
				ptr = ptr->next;
			}
		}
		if(isFound == 0) {
			printf("\n%s is not found or does not exist\n", string1 );
		}
	}
}

void printList() {

	if(head == NULL) {
		printf("List is empty\n");
	} 
	else {
		ptr = head;

		while(ptr != NULL) {
			printf("\n");
			printf("Word: %s\n", ptr->word);
			printf("Definition: %s\n", ptr->wordDef);

			ptr = ptr->next;
		}
	}
}

void delete(char *word) {
	struct Node *deletePtr, *previousPtr, *ptr;


	if(head == NULL) {
		printf("\nThe list is empty. Nothing to delete.\n");
	}
	else {
		if(strcmp(head->word, word) == 0) {
			printf("\nDeleting node...\n");

			deletePtr = head;
			head = head->next;
			free(deletePtr);

			printf("%s deleted...\n", word);
 			printList();
		}
		else {
			printf("\nDeleting node...\n");

			previousPtr = head;
			ptr = head->next;

			while(ptr != NULL && strcmp(ptr->word, word) != 0) {
				previousPtr = ptr;
				ptr = ptr->next;
			}

			if(ptr != NULL) {
				deletePtr = ptr;
				previousPtr->next = ptr->next;

				free(deletePtr);

				printf("%s deleted...\n", word);
	 			printList();
			}
			else {
				printf("%s does not exist or cannot be found\n", word );
			}
		}	
	}
}

void modtest_getWord() {
	getWord();
	getWordDef();
	printf("\n%s", wordTemp);
	printf("\n%s", defTemp);
}

void modtest_insert() {
	insert("cat", "meow meow");
	insert("dog", "woof woof");
	insert("bird", "tweet tweet");
	insert("fish", "blob blob");
	insert("cow", "moo moo");
}

void modtest_search() {
	search("dragon");
	search("fish");
	search("bug");
}

void modtest_delete() {
	delete("dog");
	delete("monkey");
	delete("shark");
	delete("bird");
	delete("eagle");
}