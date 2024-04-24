#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg) {
    *arg = malloc(sizeof(char) * 11); // Allocate memory for 10 characters and 1 for null terminator
    if (*arg == NULL) {
        // Error handling if allocation fails
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(*arg, "0123456789");
    printf("%s\n", *arg);
}

int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp == NULL) {
        // Error handling if allocation fails
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    init_chars(&msp->a);
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
