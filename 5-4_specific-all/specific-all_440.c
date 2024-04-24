#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars (char **arg)
{
    // Allocate memory for the string
    *arg = malloc (sizeof(char) * 11); // Need 11 bytes for the string + null terminator
    if (*arg == NULL) {
        // Handle malloc failure
        exit(1);
    }
    
    // Copy the string "0123456789" to the allocated memory
    strcpy(*arg, "0123456789");
    
    printf("%s\n", *arg);
}

int main ()
{
    // Allocate memory for mystruct
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp == NULL) {
        // Handle malloc failure
        return 1;
    }
    
    // Initialize each member of mystruct
    init_chars(&msp->a);
    init_chars(&msp->b);
    init_chars(&msp->c);
    
    // Output the strings in mystruct
    printf("%s, %s, %s\n", msp->a, msp->b, msp->c);
    
    // Free memory allocated for mystruct
    free(msp->a);
    free(msp->b);
    free(msp->c);
    free(msp);

    return 0;
}
