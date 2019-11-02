#include <stdio.h>

int main(){

    int integer = 1, i = 0;

    printf("Enter a number: ");
    scanf("%d", &integer);

    while(integer > i){

        integer += i;
        i++;
    }
    printf("%d", integer);
}
