#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg) {
    *arg = malloc(sizeof(char) * 11); // Allocate memory for 10 characters plus null terminator
    if (*arg == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strncpy(*arg, "0123456789", 10); // Copy the string into the allocated memory
    (*arg)[10] = '\0'; // Null-terminate the string
    printf("%s\n", *arg);
}

int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    init_chars(&msp->a);
    init_chars(&msp->b);
    init_chars(&msp->c);
    printf("%s, %s, %s\n", msp->a, msp->b, msp->c);

    // Remember to free memory allocated
    free(msp->a);
    free(msp->b);
    free(msp->c);
    free(msp);
    
    return 0;
}
