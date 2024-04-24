#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* text()
{
    static char palavra1[] = "tata";
    return palavra1;
}

int main()
{
    char saida[50];
    strcpy(saida, text());
    printf("%s", saida);
    return 0;
}
