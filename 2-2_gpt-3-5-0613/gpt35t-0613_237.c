void insert(char *str, char input, int n) {
    int i;
    size_t space = n + 1; // initialize space with n + 1, since you have already allocated that space in the main function

    for (i = 0; i < n; i++) {
        str[i+1] = str[i];  // shift each character one position to the right
    }
    str[0] = input; // set the first character to the input

    str = realloc(str, ++space); // increase the size of the string after inserting the character

    for (i = 0; i < space; i++) {
        printf("%c", str[i]);
    }
}
