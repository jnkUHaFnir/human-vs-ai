#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars (char **arg)
{
    *arg = malloc (sizeof (char)*11); // Add extra space for null-terminator.
    strcpy(*arg, "0123456789"); // Use strcpy to copy the string.
    printf ("%s\n", *arg);
}

int main ()
{
    mystruct *msp = malloc (sizeof (mystruct));
    init_chars (&(msp->a));
    init_chars (&(msp->b));
    init_chars (&(msp->c));
    printf ("%s, %s, %s\n", msp->a, msp->b, msp->c);

    // Free the allocated memory
    free(msp->a);
    free(msp->b);
    free(msp->c);
    free(msp);

    return 0;
}
0123456789
0123456789
0123456789
0123456789, 0123456789, 0123456789
