#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void text(char palavra[])
{
    char palavra1[] = "tata";
    strcpy(palavra, palavra1);
}

int main()
{
    char saida[50];
    text(saida); // Copy the string from text to the variable saida
    printf("%s", saida);
    return 0;
}
