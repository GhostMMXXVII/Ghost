/**
** Al Vincent Musa : BSCS-2B : Data Structures and Algorithms
**
** *Create a C program that will generate a list of all integers from 0 to 99 in random order.
** *Your program must make sure that no two elements can have the same value.
** *Your program can use the rand() function to generate random numbers from 0 to 99.
** *Your program must have a screen report for showing the contents of range of elements.
** *Initially all array elements must have a value of -1.
**/

#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

void clear(int array[]);				// clear() declaration
void options();							// option() declaration
void print(int array[]);				// print() declaration
void set(int array[]);					// set() declaration
int view(int array[], int a, int b);	// view() declaration

int main() {

	int myArray[100];			// array of ints with 100 elements
	char uI;					// to hold the number codes of the options.
	int start = 0, end = 0;		// for view()

	clear(myArray);				// initialize all elements of myArray to -1
	print(myArray);				// print all elements of myArray

	while(1) {					// user interface

		options();
		printf(">> ");	
		scanf("%s", &uI);

		switch(uI) {															// display options avilable to the user
			case '1': {															// initialize all elements of myArray with random ints
					printf("Array initialized...\n");
					set(myArray);
					print(myArray);
				}
				break;
			case '2': {															// display consecutive elements specified by the user
					printf("Specify range of elements to be viewed: ");
					scanf("%d %d", &start, &end);
					printf("\n");
					view(myArray, start, end);

				}
				break;
			case '3': {															// clear and initialize all elements of myArray to -1
					printf("Cleared...\n");
					clear(myArray);
					print(myArray);
				}
				break;
			case '4': {															// print all elements of myArray
					printf("Printed...\n\n");
					print(myArray);
				}
				break;
			case '5': {															// exit the program
					printf("Program closed...\n\n");
					exit(1);
				}
				break;
			default: 
					printf("Invalid input... Try Again...\n\n");				// print if input does not match any number codes
					options();
				break;


		}
	}

	return 0;
}

void clear(int array[]) {				// clear all elements of myArray.

	for(int i = 0; i < 100; i++) {
		array[i] = -1;
	}

	return;
}

void print(int array[]) {				// Print all elements of myArray

	printf("\n");
	for(int i = 0; i < 100; i++) {

		if(i != 0 && i % 10 == 0) {
			printf("\n");
		}
		printf("%2d ", array[i]);
		
	}

	printf("\n\n");
	
	return;
}

void options() {						// print all elements of myArray
	
	printf(	"-----------------------------------\n"
			"Enter number codes only.\n"
			"1. Set\n"
			"2. View\n"
			"3. Clear\n"
			"4. Print\n"
			"5. Exit\n"
			"-----------------------------------\n");
	return;
}

void set(int array[]) {					// initialize all elements of myArray

	for(int i = 0; i < 100; i++) {   
        int randNum = (rand() % 100);
        for(int j = 0; j < 100; j++) {
            if(array[j] == randNum) {
                do {
                    randNum = (rand() % 100);
                }while(array[j] == randNum);
            }
            else {
                array[i] = randNum;
            }
        }
    }

	return;
}

int view(int array[], int a, int b) {	// print portion of elements of myArray

	for(int i = a - 1; i <= b - 1; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 1;
}