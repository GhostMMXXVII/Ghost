#include <stdio.h>

int summation(int sumN);
int factorial(int factN);
int fibonacci(int fibN);


int main() {

	int integer, ordinalOne;

	printf("Enter a number: ");
	scanf("%d", &integer);

	ordinalOne = integer % 10;

	if (integer >= 0) {
		printf("The summation from 1 to %d is %d \n", integer, summation(integer));
		printf("The value of %d! is %d \n", integer, factorial(integer));
		if (ordinalOne == 1) {
			printf("The %dst Fibonacci value is %d \n", integer, fibonacci(integer));
		}
		else if (ordinalOne == 2) {
			printf("The %dnd Fibonacci value is %d \n", integer, fibonacci(integer));
		}
		else if (ordinalOne == 3) {
			printf("The %drd Fibonacci value is %d \n", integer, fibonacci(integer));
		}
		else {
			printf("The %dth Fibonacci value is %d \n", integer, fibonacci(integer));
		}
	}
	else {
		printf("input value should be a positive integer\n");
	}

	return 0;
}

int summation(int sumN) {
	int sum = 0, i;
	for (i = 1; i <= sumN; ++i) {
		sum += i;
	}
	return sum;
}

int factorial(int factN) {
	int fact = 1;
	while (factN > 0) {
		fact *= factN;
		factN--;
	}
	return fact;
}

int fibonacci(int fibN) {
	int a = 0, b = 1, fib, i = 1;

	do {
		fib = a + b;
		a = b;
		b = fib;
		i++;
	} while (i < fibN);
	return fib;
}