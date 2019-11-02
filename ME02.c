/** Program computes the mean and standard deviation of the array of data **/
#include<stdio.h>
#include<math.h>

int main () {
    int a, i = 0;
    float array[a], mean;

    FILE *filePtr;
    filePtr = fopen("input2.txt", "rt");

    while (!EOF){
        if ( i == 0){
            fscanf(filePtr, "%d", &a);
        }
        else {
            fscanf(filePtr, "%.2f", &array[i]);
        }
        i++;
    }
    for (i = 0; i < a; i++){
        mean += array[i];
    }
    printf("The mean is %.2f. \n", mean);




}
