/** Sorting array elements using bubble sort and recursion. **/
#include<stdio.h>

void bubbleSort(int array[], int num);

int main() {
    int i, j, num, temp;
    printf("Enter number of elements : "); // Prompt users to enter their desired array size
    scanf("%d", &num);
    int array[num];
    printf("Enter numbers \n");
    for(i =  0; i < num; i++){
        scanf("%d", &array[i]);
    }
    bubbleSort(array, num);
    printf("Ascending order: \n");
    for (i = 0; i < num; i++){
        printf("%d ", array[i]);
    }
}

void bubbleSort(int array[], int num){
    int i, j ,temp;
    i = num;
    if (i > 0){
        for (j = 0; j < num - 1; j++){
            /** Using the swapping algorithm to check for order **/
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        /** Recursion statement. **/
        bubbleSort(array, num - 1);
    }
    else {
        return;
    }
    return 0;
}
