#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* text()
{
    char *palavra1 = "tata";
    return strdup(palavra1);
}

int main()
{
    char *saida = text();
    printf("%s", saida);
    free(saida); // Remember to free the memory allocated by strdup
    return 0;
}
