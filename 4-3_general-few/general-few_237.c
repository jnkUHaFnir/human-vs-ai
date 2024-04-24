void insert(char *str, char input, int n) {
    size_t len = strlen(str);
    str = realloc(str, len + 2); // Allocate space for the new character and the null terminator
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Shift all characters to the right
    for (int i = len; i >= 0; i--) {
        str[i+1] = str[i];
    }

    // Insert the new character at the beginning
    str[0] = input;
    str[len + 1] = '\0'; // Add null terminator

    printf("Resulting string: %s\n", str);
}
