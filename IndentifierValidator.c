#include <stdio.h>
#include <string>

int main() {
    
    const char keywords[32][8] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", 
    "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", 
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    char input[];

  	printf("Variable Name Validator\n"
  			"This program will determine whether your input is a valid indentifier or not\n"
  			"Enter a variable name(max 16 chars): ");
  	gets(input);


	return 0;
}