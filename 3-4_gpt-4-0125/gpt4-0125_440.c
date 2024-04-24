#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcpy

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars (char **arg) // Use a pointer to a pointer to modify the original pointer
{
    *arg = malloc (sizeof (char) * 10); // Allocate memory for 10 chars
    strcpy(*arg, "0123456789"); // Copy the string into the allocated memory
    printf ("%s\n", *arg);
}

int main ()
{
    mystruct *msp = malloc (sizeof (mystruct));
    init_chars (&msp->a); // Pass the address of the pointer
    init_chars (&msp->b);
    init_chars (&msp->c);
    printf ("%s, %s, %s\n", msp->a, msp->b, msp->c);

    // Don't forget to free the allocated memory when you're done
    free(msp->a);
    free(msp->b);
    free(msp->c);
    free(msp);

    return 0;
}
