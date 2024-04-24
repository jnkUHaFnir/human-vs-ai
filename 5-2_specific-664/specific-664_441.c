#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg) {
    *arg = (char *)malloc(sizeof(char) * 11); // Increase size by 1 for the null terminator
    if (*arg != NULL) {
        snprintf(*arg, 11, "0123456789");
        printf("%s\n", *arg);
    }
}

int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    init_chars(&msp->a);
    init_chars(&msp->b);
    init_chars(&msp->c);
    printf("%s, %s, %s\n", msp->a, msp->b, msp->c);

    free(msp->a);
    free(msp->b);
    free(msp->c);
    free(msp);

    return 0;
}
