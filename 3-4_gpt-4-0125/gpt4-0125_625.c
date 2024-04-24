#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* text() { // Return type changed to const char* to match the string literal
    return "tata"; // Return a string literal directly
}

int main() { // Correct return type for main is int
    char saida[50];
    strcpy(saida, text()); // Copy the string literal "tata" into saida
    printf("%s", saida);
    return 0;
}
