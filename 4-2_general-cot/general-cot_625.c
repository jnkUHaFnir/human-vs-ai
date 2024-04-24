#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* text()
{
    static char palavra1[]= "tata";  // static keyword to ensure the variable survives after the function call
    return palavra1;
}

int main()
{
    char saida[50];
    strcpy(saida, text());   // copy the string from text to the var saida
    printf("%s", saida);
    return 0;
}
