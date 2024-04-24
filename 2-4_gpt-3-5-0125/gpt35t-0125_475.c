char *readline(FILE *fp) {
    char *buffer = NULL;
    char ch;
    int i = 0;
    size_t buff_len = 0;

    buffer = malloc(sizeof(char));

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        ++buff_len;
        buffer = realloc(buffer, buff_len + 1); // Allocate space for the new character and the null terminator

        buffer[i] = ch;
        ++i;
    }

    buffer[i] = '\0'; // Null-terminate the string

    return buffer;
}
