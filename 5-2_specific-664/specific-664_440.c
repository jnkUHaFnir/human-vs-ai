#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg) {
    *arg = malloc(sizeof(char) * 11); // Allocate memory for the string (including the null terminator)
    if (*arg == NULL) {
        // Handle memory allocation failure
        return;
    }
    strcpy(*arg, "0123456789"); // Copy the string to the allocated memory
    printf("%s\n", *arg);
}

int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp == NULL) {
        // Handle memory allocation failure
        return 1;
    }

    init_chars(&msp->a); // Pass a pointer to pointer
    init_chars(&msp->b);
    init_chars(&msp->c);

    printf("%s, %s, %s\n", msp->a, msp->b, msp->c);

    // Don't forget to free the allocated memory
    free(msp->a);
    free(msp->b);
    free(msp->c);
    free(msp);

    return 0;
}
