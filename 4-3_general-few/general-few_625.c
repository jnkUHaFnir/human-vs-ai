#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void text(char *palavra1) {  // Modified to accept a char array as a parameter
    strcpy(palavra1, "tata");
}

int main() {
    char saida[50];
    text(saida);   // passing the char array to be filled by the text function
    printf("%s", saida);
    return 0;
}
