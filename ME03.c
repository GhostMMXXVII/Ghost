/** Musa, Al Vincent V.  BSCS-1B  ME03.c  CS103-Computer Programming 2 **/

/** This program reads two input files and save the data into into their corresponding arrays.
        If the column of matrixA is equal to the row of matrixB, then it is compatible for multiplication.
        Row elements of matrixA and Column elements of matrixB are multiplied and summed up as another
        element for matrixAB**/

#include<stdio.h>
#include<stdlib.h>

int main() {

        int aRow, aColumn, bRow, bColumn, i, j, n, sum = 0, product = 0;

        FILE *filePtr1;  // file pointer for "matrix_A.in".
        FILE *filePtr2;  // file pointer for "matrix_B.in".
        FILE *filePtr3;  // file pointer for "matrix_AB.out".

        filePtr1 = fopen("matrix_A.in", "rt");
        filePtr2 = fopen("matrix_B.in", "rt");
        filePtr3 = fopen("matrix_AB.out", "wt");

        fscanf(filePtr1, "%d %d", &aRow, &aColumn);  // read the first two data from file for the array size.
        fscanf(filePtr2, "%d %d", &bRow, &bColumn);  // read the first two data from file for the array size.


        int matrixA[aRow][aColumn], matrixB[bRow][bColumn];
        int matrixAB[aRow][bColumn];

        /** Read the remaining data from "matrix_A.in" for Matrix A. **/
        for(i = 0; i < aRow; i++) {
                for(j = 0; j < aColumn; j++) {
                        fscanf(filePtr1, "%d", &matrixA[i][j]);
                }
        }

        /** Read the remaining data from "matrix_B.in" for Matrix B. **/
        for(i = 0; i < bRow; i++) {
                for(j = 0; j < bColumn; j++) {
                        fscanf(filePtr2, "%d", &matrixB[i][j]);
                }
        }

        /** Print the elements of Matrix A. **/
       printf("Matrix A \n");
        for(i= 0; i < aRow; i++) {
                for(j = 0; j < aColumn; j++) {
                        printf("%2d ", matrixA[i][j]);
                }
                printf("\n");
        }

        printf("\n");

        /** Print the elements of Matrix B. **/
        printf("Matrix B \n");
        for(i = 0; i < bRow; i++) {
                for(j = 0; j < bColumn; j++) {
                        printf("%2d ", matrixB[i][j]);
                }
                printf("\n");
        }

        /** Check whether aColumn is equal to bRow. If yes, the matrix multiplication
                is executed. **/
        if(aColumn == bRow) {
                for(i = 0; i < aRow; i++){
                        for(j = 0; j < bColumn; j++) {
                                matrixAB[i][j] = 0;
                                for(n = 0; n < aColumn; n++){
                                        matrixAB[i][j] += matrixA[i][n] * matrixB[n][j];

                                }
                        }
                }
        }
        else if(aColumn != bRow) {
                printf("\nMatrices are not compatible for multiplication.\n"
                        "Terminating program now..\n\n");
                exit(1);
        }

        /** Print the new elements of matrixAB to "matrixAB.out". **/
        fprintf(filePtr3, "%d %d\n", aRow, bColumn);
        for(i = 0; i < aRow; i++){
                fprintf(filePtr3,"\n");
                for(j = 0; j < bColumn; j++) {
                        fprintf(filePtr3, " %d", matrixAB[i][j]);
                }
        }

        /** Print the new elements of matrixAB. **/
        printf("\nMatrix AB \n");
        for(i = 0; i < aRow; i++) {
                printf("\n");
                for(j = 0; j < bColumn; j++) {
                        printf("%2d ", matrixAB[i][j]);
                }
        }
        printf("\n");

        fclose(filePtr1);
        fclose(filePtr2);
        fclose(filePtr3);

        return 0;
}