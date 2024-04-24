#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(void)
{
    char* username[SIZE];
    int i;

    /* Read words into array */
    for (i = 0; i < SIZE; i++)
    {
        username[i] = malloc(SIZE * sizeof(char));
        if (username[i] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        printf("Enter a word: ");
        fgets(username[i], SIZE, stdin);
        // Remove newline character if present
        username[i][strcspn(username[i], "\n")] = 0;
    }

    /* Print out array */
    for (int p = 0; p < SIZE; p++) {
        printf("%s ", username[p]);
    }

    /* Free allocated memory */
    for (int p = 0; p < SIZE; p++) {
        free(username[p]);
    }

    return 0;
}
