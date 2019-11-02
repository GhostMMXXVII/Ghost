/**
** Al Vincent Musa : BSCS-2B : Data Structures and Algorithms
**
** *Create a C program that will generate a list of all integers from 0 to n in random order.
** *Your program must make sure that no two elements can have the same value.
** *Your program can use the rand() function to generate random numbers from 0 to n.
** *Your program must have a screen report for showing the contents of range of elements.
** *Initially all array elements must have a value of -1.
**/

#include<stdio.h>
#include<stdlib.h>

void clear(int array[], int n);				// clear() declaration
void print(int array[], int n);				// print() declaration
void options();								// options() declaration
void set(int array[], int n);				// set() declaration
int view(int array[], int n, int a, int b);	// view() declaration

int main() {

    int n;									// holds the user defined array size
    int uChoice;							// holds the user option choices
    int start, end;							// holds the start and end range of elements to be printed
        
    while(1) {
        printf("Enter desired array size; (1-10,000) : "); // ask user for desired array size
        scanf("%d", &n);
        
        if(n < 1 || n > 10000) {							// checked if input is within 1-10,000
            printf("Array size should be not less 1 or greater than 10, 000.\n");
        }
        else {
            break;
        }
    }

    int myArray[n];

    clear(myArray, n);						// clear array 
    print(myArray, n);						// print all elements of array

    while(1) {								// options
        options();
        printf(">> ");	
		scanf("%d", &uChoice);

        switch(uChoice) {
            case 1: {
                    printf("Array initialized...\n");	// initialize array with random integers
                    set(myArray, n);
                    print(myArray, n);
                }
                break;
            case 2: {
                    printf("Cleared...\n");				// clear all array elements to -1
                    clear(myArray, n);
                    print(myArray, n);
                }
                break;
            case 3: {
                    printf("Printed...\n");				// print all array elements
                    print(myArray, n);
                }
                break;
            case 4: {
            		printf("Specify range of elements to be viewed: (start, end) ");	// print specific range of elements from the array
					scanf("%d %d", &start, &end);
					printf("\n");
					view(myArray, n, start, end);
            	}
            	break;
            case 5: {
		            printf("Program closed...\n");		// terminate program
        	        exit(1);
		        }
		        break;
            default: {
                    printf("Invalid input, try again...\n"); // print if input does exceed 1 - 5 
                }
                break;
        }
    }

    return 0;
}

void clear(int array[], int n) { 			// initialize all elements to -1

    int i;
    
    for(i = 0; i < n; i++) {
        array[i] = -1;
    }
    
    return;
}

void print(int array[], int n) {			// print all elements of the array
    
    int i;

	printf("\n");

	for(i = 0; i < n; i++) {

		if(i != 0 && i % 10 == 0) {
			printf("\n");
		}
		printf("%4d ", array[i]);
		
	}

	printf("\n");
	
	return;
}

void options() {							// print all elements of myArray
	
	printf(	"-----------------------------------\n"
			"Enter the numbers codes from the options.\n"
			"1. Set\n"
			"2. Clear\n"
			"3. Print\n"
			"4. View\n"
			"5. Exit\n"
			"-----------------------------------\n");
	return;
}

void set(int array[], int n) {				// initialize all elements with random integers using rand() function
    int i, j, randNum;    
    for(i = 0; i < n; i++) {   
        
        for(j = 0; j < n; j++) {
            if(array[j] == randNum) {
                do {
                   randNum = (rand() % ((n - 1) - 0 + 1)) + 0;
                }while(array[j] == randNum);
            }
            else {
                array[i] = randNum;
            }
        }
    }

    return;
}

int view(int array[], int n, int a, int b) {	// print portion of elements of myArray
	if(a < 1 || a > n || b  < 1 || b > n) {
		printf("Input out of range. Input should be 1 to %d.\n", n);
	}
	else {
		for(int i = a - 1; i <= b - 1; i++) {
			if(i != 0 && i % 10 == 0) {
				printf("\n");
			}
			printf("%4d ", array[i]);
		}
	}
	printf("\n");

	return 1;
}
