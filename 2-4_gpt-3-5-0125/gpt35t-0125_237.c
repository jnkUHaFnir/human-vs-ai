void insert(char *str, char input, int n) {
    int i;
    size_t space = n + 1; // Initialize space correctly
    str = realloc(str, space); // Reallocate memory for the new character

    // Shift all characters to the right to make space for the input character
    for (i = n-1; i >= 0; i--) {
        str[i+1] = str[i];
    }

    // Assign the input character to the first position in the array
    str[0] = input;

    // Print the resulting string
    for (i = 0; i < n + 1; i++) {
        printf("%c", str[i]);
    }
}
