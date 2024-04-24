void init_chars(char **arg) {
    *arg = malloc(sizeof(char) * 11); // Allocate memory for 10 characters + null terminator
    if (*arg != NULL) {
        strncpy(*arg, "0123456789", 10); // Copy the characters to the allocated memory
        (*arg)[10] = '\0'; // Null terminate the string
        printf("%s\n", *arg);
    } else {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
    }
}
int main() {
    mystruct *msp = malloc(sizeof(mystruct));
    init_chars(&msp->a);
    init_chars(&msp->b);
    init_chars(&msp->c);
    printf("%s, %s, %s\n", msp->a, msp->b, msp->c);

    // Don't forget to free the allocated memory when you're done with it
    free(msp->a);
    free(msp->b);
    free(msp->c);
    free(msp);
    
    return 0;
}
