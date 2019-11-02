#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkKeyword(char input[]);
int checkWhiteSpace(char input[]);
int checkNum(char input[]);
int checkSpeclChar(char input[]);

int main() {
    
    char input[16];

  	printf("\nVariable Name Validator\n"
  			"This program will determine whether your input is a valid indentifier or not\n"
  			"Enter a variable name(max 16 chars): ");

	fgets(input, 16, stdin);
	printf("Input: %s \n", input);

	if((checkKeyword(input) == 1) || (checkNum(input) == 1) || (checkWhiteSpace(input) == 1) || (checkSpeclChar(input) == 1)) {
		printf("Output: Invalid \n\n");
	}
	else {
		printf("Output: Valid \n\n");
	}
}

int checkKeyword(char input[]) {

	int i;
	char keywords[32][9] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", 
    "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", 
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

	for(i = 0; i < 32; i++) {
		if (strcmp(keywords[i], input) == 0) {
			return 1;
		}
	}
	return 0;
}

int checkWhiteSpace(char input[]) {

	int i;
	for(i = 1; i < strlen(input) - 1; i++) {
		if(input[i] == ' ') {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int checkNum(char input[]) {

	if(input[0] >= '0' && input[0] <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}

int checkSpeclChar(char input[]) {

	int i = -1;
	while(input[++i]) {
		if((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') 
			|| input[i] == ' ' || input[i] == '@') {
			return 0;
	}
		else {
			return 1;
		}
	}
}