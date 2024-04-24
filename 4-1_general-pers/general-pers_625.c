#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* text()
{
    return "tata";
}

int main()
{
    char saida[50];
    const char* str = text();
    strcpy(saida, str);
    printf("%s", saida);
    return 0;
}
