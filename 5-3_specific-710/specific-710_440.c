typedef struct {
    char *a;
    char *b;
    char *c;
} mystruct;

void init_chars(char **arg) {
    *arg = malloc(sizeof(char) * 11); // Allocate memory for 10 characters + null terminator
    if (*arg != NULL) {
        strcpy(*arg, "0123456789"); // Copy the string "0123456789" to the allocated memory
        printf("%s\n", *arg);
    }
}

int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    if (msp != NULL) {
        init_chars(&msp->a);
        init_chars(&msp->b);
        init_chars(&msp->c);
        printf("%s, %s, %s\n", msp->a, msp->b, msp->c);

        // Free allocated memory
        free(msp->a);
        free(msp->b);
        free(msp->c);
        free(msp);
    }
    return 0;
}
