#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg)
{
    *arg = malloc(sizeof(char) * 11);  // +1 for the null terminator
    if (*arg != NULL) {
        strcpy(*arg, "0123456789");
    }
}

int main()
{
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp != NULL) {
        init_chars(&(msp->a));
        init_chars(&(msp->b));
        init_chars(&(msp->c));
        printf("%s, %s, %s\n", msp->a, msp->b, msp->c);

        // Remember to free dynamically allocated memory
        free(msp->a);
        free(msp->b);
        free(msp->c);
        free(msp);
    }
    return 0;
}
