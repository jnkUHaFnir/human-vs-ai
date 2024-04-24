#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* text()
{
    char *palavra1 = malloc(5 * sizeof(char)); // allocate memory for the string
    strcpy(palavra1, "tata");
    return palavra1;
}

int main()
{
    char* palavra = text();
    char saida[50];
    
    strcpy(saida, palavra);  // copy the string from text to the variable saida
    printf("%s", saida);

    free(palavra); // free the dynamically allocated memory
    return 0;
}
