#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main(void)
{
    int i, amount;
    char** names;

    printf("Enter number of friends: ");
    scanf("%d", &amount);
    getchar();

    names = (char**)malloc(amount * sizeof(char*));

    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)malloc((MAX_CHARS + 1) * sizeof(char));
        printf("Enter name of friend %d: ", i + 1);
        fgets(names[i], MAX_CHARS, stdin);
    }

    qsort(names, amount, sizeof(char*), compareStrings);

    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)realloc(names[i], (strlen(names[i]) + 1) * sizeof(char));
        printf("%s\n", names[i]);
    }

    for (i = 0; i < amount; i++)
    {
        free(names[i]);
    }
    free(names);

    return 0;
}
``` 

This code snippet aims to be more secure and correct than the initial version you provided.
