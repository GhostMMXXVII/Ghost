/** Musa, Al Vincent V. BSCS-1B CS103 Computer Programming 2 ME05.c
*		This programs read ten string from a input file "strings.txt" 
*		and put the strings in an array. Then the length of the strings
*		are determined before being sorted. Strings with same length are
*		arranged alphabetically. After the sort, the new order of strings
*		are printed and written on an output file "sorted.txt" along with their lengths.
**/

#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX 64

int main() {

	int i, j = 0, x;
	long int len1, len2;
	char strings[10][MAX], temp[MAX];
	char *charPtr = &strings[10][MAX];

	/** File pointer for the input and output file. **/
	FILE *strPtr;
	FILE *strOutPtr;
	
	strPtr = fopen("strings.txt", "rt");
	strOutPtr = fopen("sorted.txt", "wt");

	/** Read the strings and save it on the array. **/
	for (i = 0; i < 10; i++) {
   		fscanf(strPtr, "%s ", strings[i]);
	}
  	
	/** Convert UPPERCASE characters into lowercase. **/
  	for(i = 0; i < 10; i++){
  		for(j = 0; j < MAX ; j++){
  			strings[i][j] = tolower(strings[i][j]);
  		}
  	}

	/** Sort the strings using bubble sort in ascending order. String that are with the same length are alphabetically arranged. **/ 
  	for(i = 0; i < 10; i++){
        for(j = 0; j < 10 - 1; j++){
			len1 = strlen(strings[j]);
			len2 = strlen(strings[j + 1]);
			if(len1 > len2){
        		strcpy(temp, strings[j]);
            	strcpy(strings[j], strings[j + 1]);
            	strcpy(strings[j + 1], temp);
            }
			/** Check if length is equal, then swap. **/
			if(len1 == len2) {
				if(strcmp(strings[j], strings[j + 1]) > 0){
					strcpy(temp, strings[j]);
            		strcpy(strings[j], strings[j + 1]);
            		strcpy(strings[j + 1], temp);
				}
			}
        }
    }

	/** Print **/
	fprintf(strOutPtr,"%-10s%s\n", "STRINGS", "LENGTH");
	printf("\n%-10s%s\n", "STRINGS", "LENGTH");
	for(i = 0; i < 10; i++){
		printf("%-10s%lu \n", strings[i], strlen(strings[i]));
		fprintf(strOutPtr, "%-10s%lu \n", strings[i], strlen(strings[i]));	
	}
	printf("\n");

	fclose(strPtr);
	fclose(strOutPtr);
	return 0;
}

