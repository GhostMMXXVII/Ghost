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

void clear(int array[], int n);				// clear() declaration
void options();							// option() declaration
void print(int array[], int n);				// print() declaration
void set(int array[], int n);					// set() declaration
int view(int array[], int n, int a, int b);	// view() declaration

int main() {

	int n = 1;
	int myArray[n];			// array of ints with 100 elements
	char uI;					// to hold the number codes of the options.
	int start = 0, end = 0;		// for view()

	while(1) {
        printf("Enter desired array size; (1-10,000) : ");
        scanf("%d", &n);
        
        if(n < 1 || n > 10000) {
            printf("Array size should be not less 1 or greater than 10, 000.\n");
        }
        else {
            break;
        }
    }

	clear(myArray, n);				// initialize all elements of myArray to -1
	print(myArray, n);				// print all elements of myArray

	while(1) {					// user interface

		options();
		printf(">> ");	
		scanf("%s", &uI);

		switch(uI) {															// display options avilable to the user
			case '1': {															// initialize all elements of myArray with random ints
					printf("Array initialized...\n");
					set(myArray, n);
					print(myArray, n);
				}
				break;
			case '2': {															// display consecutive elements specified by the user
					printf("Specify range of elements to be viewed: ");
					scanf("%d %d", &start, &end);
					printf("\n");
					view(myArray, n, start, end);

				}
				break;
			case '3': {															// clear and initialize all elements of myArray to -1
					printf("Cleared...\n");
					clear(myArray, n);
					print(myArray, n);
				}
				break;
			case '4': {															// print all elements of myArray
					printf("Printed...\n\n");
					print(myArray, n);
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

void clear(int array[], int n) {				// clear all elements of myArray.

	for(int i = 0; i < n; i++) {
		array[i] = -1;
	}

	return;
}

void print(int array[], int n) {				// Print all elements of myArray

	printf("\n");
	for(int i = 0; i < n; i++) {

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

void set(int array[], int n) {					// initialize all elements of myArray

	for(int i = 0; i < n; i++) {
		array[i] = i;
	}

	for(int i = 0; i < n; i++) {
		int random = (rand() % (99 - 0 + 1)) + 0;
		 int temp = array[i];
		 array[i] = array[random];
		 array[random] = temp; 
	}

	return;
}

int view(int array[], int n, int a, int b) {	// print portion of elements of myArray

	for(int i = a - 1; i <= b - 1; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 1;
}