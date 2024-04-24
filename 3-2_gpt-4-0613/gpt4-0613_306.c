void remove_zero(struct number *a) {
    char *b = a->digits;
    while (*b == '0' && *b != '\0') // Skip all leading zeroes and ensure we don't go past the '\0' null terminator
        b++;
    
    // Now b points to the first non-zero digit or the null terminator
    // Move the remainder of b, including null terminator back to start of a->digits
    memmove(a->digits, b, strlen(b) + 1);  // +1 for the null terminator
}
void remove_zero(struct number *a) {
    char *b = a->digits;
    while (*b == '0' && *b != '\0') // Skip all leading zeros and ensure we don't go past the '\0' null terminator
        b++;
    
    // Now b points to the first non-zero digit or the null terminator
    // Move the remainder of b, including null terminator back to start of a->digits
    memmove(a->digits, b, strlen(b) + 1);  // +1 for the null terminator
    
    if(strlen(a->digits) < 10)
        a->digits[strlen(a->digits)] = '\0';
}
