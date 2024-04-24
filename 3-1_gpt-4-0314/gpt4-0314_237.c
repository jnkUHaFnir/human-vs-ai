void insert(char *str, char input, int n) {
    int i;
    
    // Reallocate space for the new character + null terminator
    str = realloc(str, n + 2);

    // Shift all characters to the right by one position
    for (i = n; i >= 1; i--) {
        str[i] = str[i - 1];
    }

    // Insert the input character at the beginning
    str[0] = input;

    // Add null terminator at the end of the string
    str[n + 1] = '\0';

    // Print the resulting string
    printf("Resulting string: %s\n", str);
}
