#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg) {
    *arg = malloc(sizeof(char) * 11); // allocate memory for 10 characters plus null-terminator
    strcpy(*arg, "0123456789");       // copy the string "0123456789" into the allocated memory
    printf("%s\n", *arg);
}

int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    init_chars(&(msp->a));
    init_chars(&(msp->b));
    init_chars(&(msp->c));
    printf("%s, %s, %s\n", msp->a, msp->b, msp->c);
    
    free(msp->a);  // don't forget to free the allocated memory
    free(msp->b);
    free(msp->c);
    free(msp);
    
    return 0;
}
