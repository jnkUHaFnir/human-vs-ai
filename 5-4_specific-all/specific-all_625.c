#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void text(char *output)
{
    char palavra1[] = "tata";
    strcpy(output, palavra1);
}

int main()
{
    char saida[50];
    text(saida); // pass the saida array to the text function
    printf("%s", saida);
    return 0;
}
