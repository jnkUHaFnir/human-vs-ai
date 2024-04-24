#include <stdio.h>
#include <stdlib.h>

int main(void) {
    #define SIZE 100
    char* usernames = malloc(100 * SIZE);

    if (usernames == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    /* Read words into array */
    for (int i = 0; i < 100; i++) {
        usernames[i*SIZE] = '\0';  // Ensure the string is terminated
        scanf("%99s", &usernames[i*SIZE]);  // Read up to 99 characters to leave space for null terminator
    }

    /* Print out array */
    for (int p = 0; p < 100; p++) {
        printf("%s\n", &usernames[p*SIZE]);
    }

    free(usernames);  // Don't forget to free allocated memory
    return 0;
}
