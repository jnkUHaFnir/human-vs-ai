void insert(char **str, char input, int n) {
    size_t len = strlen(*str);
    *str = realloc(*str, len + 2);  // Increase the size of the string by 1 for the new character and 1 for the null terminator

    // Shift all characters to the right by one position
    for (int i = len; i >= 0; i--) {
        (*str)[i + 1] = (*str)[i];
    }

    // Insert the new character at the beginning
    (*str)[0] = input;

    printf("Resulting string: %s\n", *str);
}
case '1':
    printf("What is the character you want to insert: ");
    scanf(" %c", &input);
    insert(&str, input, n);
    break;
