#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

// Note that a double pointer is used for the argument
void init_chars(char **arg)
{
    *arg = malloc(sizeof(char) * 11); // +1 for the null terminator
    if (*arg) {
        strcpy(*arg, "0123456789"); // Copy the string into the allotted space
        printf("%s\n", *arg);
    }
}

int main()
{
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp) {
        init_chars(&msp->a);
        init_chars(&msp->b);
        init_chars(&msp->c);
        printf("%s, %s, %s\n", msp->a, msp->b, msp->c);
        
        // Don't forget to free the allocated memory
        free(msp->a);
        free(msp->b);
        free(msp->c);
        free(msp);
    }
    return 0;
}
