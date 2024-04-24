void remove_zero(struct number *a) {
    char *b = (*a).digits;
    int nonZeroIndex = 0;
    
    // Find the first non-zero digit
    while (*b) {
        if (*b != '0') {
            break;
        }
        b++;
    }
    
    // Copy the remaining digits back to (*a).digits
    while (*b) {
        (*a).digits[nonZeroIndex++] = *b++;
    }
    
    // Add null terminator at the end
    (*a).digits[nonZeroIndex] = '\0';
}
