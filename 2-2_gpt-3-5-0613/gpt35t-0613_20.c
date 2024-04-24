int str_to_uint(const char* str, unsigned long int* res) {
    char* first_wrong_character;
    uintmax_t result = strtoumax(str, &first_wrong_character, 10);
    if (errno == ERANGE)
        return 0; // Overflow
    if (*first_wrong_character != '\0')
        return 0; // Not everything has been converted
    *res = result;
    return 1;
}
int str_to_uint16(const char* str, uint16_t* res) {
    unsigned long uint;
    if (!str_to_uint(str, &uint))
        return 0;
    if (uint > UINT16_MAX)
        return 0;
    *res = (uint16_t)uint;
    return 1;
}
