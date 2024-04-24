void remove_zero(struct number *a) {
    char *b = (*a).digits; // use a pointer to char to hold the address of the first character in (*a).digits
    int shift = 0; // use shift to keep track of the number of leading zeroes

    while (*b) { // loop through the characters in (*a).digits
        if (*b != '0') {
            break; // if we find a non-zero character, exit the loop
        }
        shift++; // increment shift for each leading zero
        b++; // move to the next character
    }

    // shift the non-zero characters to the beginning of (*a).digits
    for (int i = 0; i < 11 - shift; i++) {
        (*a).digits[i] = (*a).digits[i + shift];
    }

    // append null terminator to the end of the modified (*a).digits
    (*a).digits[11 - shift] = '\0';
}
