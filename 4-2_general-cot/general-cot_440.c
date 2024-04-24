#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg) {
    *arg = malloc(sizeof(char) * 11); // Allocate memory for the string including the null terminator
    if (*arg == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(*arg, "0123456789"); // Copy the string "0123456789" including null terminator
    printf("%s\n", *arg);
}

int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    init_chars(&msp->a);
    init_chars(&msp->b);
    init_chars(&msp->c);

    printf("%s, %s, %s\n", msp->a, msp->b, msp->c);

    // Free allocated memory
    free(msp->a);
    free(msp->b);
    free(msp->c);
    free(msp);

    return 0;
}
