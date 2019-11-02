#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *top;

void Push(int data);
int Pop();
void display();

void DecimalToBinary(int number);

int main(void) {
	int num;
	printf("Enter a number to convert to binary: ");
	scanf("%d", &num);
	printf("%d = ", num);
	DecimalToBinary(num);
	printf("\n");
  return 0;
}

void DecimalToBinary(int number) {
	while(number != 0) {
		int digit = number % 2; // get the remainder
		Push(digit);	// push the remainder into stack
		number = number / 2; //divide the number by 2
	}
	while(top != NULL) {
		printf("%d", Pop()); //print the digits while popping the stack
	}
}

void Push(int data) {
	struct node *newPtr;

	// create a stack;
	newPtr = (struct node*)malloc(sizeof(struct node*));
	newPtr->data = data;

	// if stack is full, send error msg
	if(newPtr == NULL) {
		printf("\nERROR: No memory available.");
	}
	else {
		// if stack is empty, insert at top
		if(top == NULL) {
			top = newPtr;
		}
		else {
			// if not, new stack is the new top
			newPtr->next = top;
			top = newPtr;
		}
	}
}

int Pop() {
	struct node *popPtr;

	// get the data from the stack
	int data = top->data;

	// pop the stack;
	popPtr = top;
	top = top->next;
	free(popPtr);

	// return the data
	return data;
}

void display() {
	while(top->next != NULL) {
		printf("%d", top->data);
		top = top->next;
	}
}