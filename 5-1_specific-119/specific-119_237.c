void insert(char *str, char input, int n) {
    int i;
    size_t space = n + 2; // Increment space by n + 2 to accommodate the new character and null terminator

    // Move existing characters to the right to make space for the new character
    for (i = n; i >= 0; i--) {
        str[i+1] = str[i];
    }

    str[0] = input; // Insert the new character at the beginning

    str = realloc(str, space); // Reallocate memory for the updated string

    // Print the resulting string
    for (i = 0; i < space - 1; i++) { // Print until just before the null terminator
        printf("%c", str[i]);
    }
    printf("\n");

    // Don't forget to add the null terminator at the end of the string
    str[space - 1] = '\0';
}
