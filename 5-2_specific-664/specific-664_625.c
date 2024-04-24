#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void text(char *saida)
{
    char palavra1[] = "tata";
    strcpy(saida, palavra1);
}

int main()
{
    char saida[50];
    text(saida); // passing the saida buffer to store the result
    printf("%s", saida);
    return 0;
}
