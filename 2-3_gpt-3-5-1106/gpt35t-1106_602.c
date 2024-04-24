#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    #define SIZE 100
    char username[100][SIZE]; 
    int i;
    int p;

    /* Read words into array */
    for(i = 0; i < 100; i++)
    {
        scanf("%s",username[i]);
    }

    /* Print out array */
    for (p = 0; p < 100; p++) {
        printf("%s ", username[p]);
    }

    return 0;
}
