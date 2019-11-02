#include <stdio.h>

int main() {

	char fileName[99] = "hello-World.txt";
	char helloWorld[99];
	FILE *hello;
	hello = fopen(fileName, "r");
	fscanf(hello, "%s", &helloWorld);
	printf("%s \n", helloWorld);

	return 0;
}