#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg) {
    *arg = malloc(sizeof(char) * 11); // Allocate memory for 10 characters plus 1 for the null terminator '\0'
    if (*arg != NULL) {
        strcpy(*arg, "0123456789"); // Copy the string "0123456789" into the allocated memory
        printf("%s\n", *arg);
    } else {
        // Handle allocation failure
        printf("Memory allocation failed\n");
    }
}

int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp == NULL) {
        // Handle allocation failure
        return 1;
    }

    init_chars(&msp->a);
    init_chars(&msp->b);
    init_chars(&msp->c);

    printf("%s, %s, %s\n", msp->a, msp->b, msp->c);

    free(msp->a); // Free dynamically allocated memory
    free(msp->b);
    free(msp->c);
    free(msp);

    return 0;
}
