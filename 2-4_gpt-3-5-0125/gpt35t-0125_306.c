void remove_zero(struct number *a) {
    char *b = (*a).digits; // Use char pointer to iterate over characters
    int index = 0; // Index to keep track of the first non-zero digit

    // Find index of the first non-zero digit
    while (*b) {
        if (*b != '0') {
            break;
        }
        index++;
        b++;
    }

    // Copy the rest of the characters back to (*a).digits
    for (int i = index; i < 11; i++) {
        (*a).digits[i - index] = (*a).digits[i];
    }

    // Null terminate the string after the copied characters
    (*a).digits[11 - index] = '\0';
}
