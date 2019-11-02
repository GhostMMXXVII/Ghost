/** Musa, Al Vincent V.  BSCS-1B  ME04.c  CS103-Computer Programming 2 **/
/** This program prints out the addresses of variables, arrays, and pointer
	variables and swaps array elements between two arrays using pointers
	and offset notation.
**/

#include <stdio.h>


int swap(int *array01, int *array02); // Prototype declaration for swap().

int main() {

	/** Variable declaration for each data type. **/
	double decimal = 62.63;
	int integer = 666;
	char character = 'A';
	int arrayOne[] = {85, 74, 78, 7, 32};
	int arrayTwo[] = {52, 88, 9, 3, 47};

	/** Pointer for each variables declared above. **/
	double *decPtr = &decimal;
	int * intPtr = &integer;
	char * charPtr = &character;
	int * a1Ptr = arrayOne;
	int * a2Ptr = arrayTwo;

	/** Prints out the memory addresses of variables and pointers. Uses tabs and spaces for readability. **/
	printf("\n%s\t   %s\t      %s\t     %s\n", "Variable_type", "name", "address", "value");
	printf("------------------------------------------------------------------\n");
	printf("%s\t\t   %s    %p     %.2f\n", "Double", "decimal", &decimal, decimal);
	printf("%s\t\t   %s    %p     %d\n", "int", "integer", &integer, integer);
	printf("%s\t\t   %s  %p     %c\n", "char", "character", (void *) &character, character);
	printf("%s\t   %s   %p     {%d, %d, %d, %d, %d}\n", "int array", "arrayOne", &arrayOne[0], arrayOne[0], arrayOne[1], arrayOne[2], arrayOne[3], arrayOne[4]);
	printf("%s\t   %s   %p     {%d, %d, %d, %d, %d}\n", "int array", "arrayTwo", &arrayTwo[0], arrayTwo[0], arrayTwo[1], arrayTwo[2], arrayTwo[3], arrayTwo[4]);
	printf("%s\t\t   %s     %p     %p\n", "double*", "decPtr", &decPtr, decPtr);
	printf("%s\t\t   %s     %p     %p\n", "int*", "intPtr", &intPtr, intPtr);
	printf("%s\t\t   %s      %p     %p\n", "char*", "chPtr", &charPtr, charPtr);
	printf("%s %s      %p     %p\n", "int* (for array 1)", "a1Ptr", &a1Ptr, a1Ptr);
	printf("%s %s      %p     %p\n", "int* (for array 2)", "a2Ptr", &a2Ptr, a2Ptr);

	printf("------------------------------------------------------------------\n");
	printf("Before swapping:\n"
			"ArrayOne: {%d, %d, %d, %d, %d}\n"
			"ArrayTwo: {%d, %d, %d, %d, %d}\n", arrayOne[0], arrayOne[1], arrayOne[2], arrayOne[3], arrayOne[4],
												arrayTwo[0], arrayTwo[1], arrayTwo[2], arrayTwo[3], arrayTwo[4]);

	/** Sends the two arrays to swap(). **/
	swap(a1Ptr, a2Ptr);

	printf("------------------------------------------------------------------\n");
	printf("After swapping:\n"
			"ArrayOne: {%d, %d, %d, %d, %d}\n"
			"ArrayTwo: {%d, %d, %d, %d, %d}\n", arrayOne[0], arrayOne[1], arrayOne[2], arrayOne[3], arrayOne[4],
												arrayTwo[0], arrayTwo[1], arrayTwo[2], arrayTwo[3], arrayTwo[4]);
	printf("------------------------------------------------------------------\n");

	return 0;
}

/** swap() swaps each elements of two arrays. **/
int swap(int *array01, int *array02) {

	int i, temp = 0;

	for(i = 0; i < 5; i++){
		temp = *(array01 + i);
		*(array01 + i) = *(array02 + i);
		*(array02 + i) = temp;
	}
   	return *array01, *array02;

}
