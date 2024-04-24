char *convert_to_16(char *characters, int n) {
    char sub_buffer[3];
    char code[3];
    char *buffer = (char*)malloc((n * 2) + 1); // Allocate memory based on input string length
    buffer[0] = '\0'; // Initialize buffer to an empty string
    for(int i = 0; i < n; i++) {
        strncpy(code, characters + i, 1);
        sprintf(sub_buffer, "%x", *code);
        strncat(buffer, sub_buffer, 2);
    }
    return buffer;
}
