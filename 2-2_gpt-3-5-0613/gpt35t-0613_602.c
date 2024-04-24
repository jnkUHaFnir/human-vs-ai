char* username[SIZE];
int numWords = 100;
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main (void)
{
    char* username[SIZE];
    int i;
    int p;

    /* Read words into array */
    for(i = 0; i < SIZE; i++)
    {
        username[i] = calloc(SIZE, sizeof(char)); 
        scanf("%99s", username[i]);
    }

    /* Print out array */
    for (p = 0; p < SIZE; p++) {
        printf("%s\n", username[p]);
    }

    /* Free allocated memory */
    for (p = 0; p < SIZE; p++) {
        free(username[p]);
    }

    return 0;
}
