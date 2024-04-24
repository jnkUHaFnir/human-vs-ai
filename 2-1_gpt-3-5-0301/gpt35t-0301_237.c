void insert(char *str, char input, int n) {
    size_t space = strlen(str) + 2; // add space for input character and null terminator
    str = realloc(str, space);
    for (int i = n; i >= 0; i--) {
        str[i + 1] = str[i]; // shift characters to the right
    }
    str[0] = input; // insert input character at the beginning
    printf("Resulting string: %s\n", str);
}