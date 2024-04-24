void get_line(char* filename) {
    char* text = NULL;
    size_t size = 0;
    FILE* file = fopen(filename, "r");

    int c;
    size_t index = 0;

    while ((c = fgetc(file)) != EOF && c != '\n') {
        if (index == size) {
            size += INIT_SIZE;
            text = realloc(text, size * sizeof(char));
        }
        text[index++] = c;
    }

    text = realloc(text, (index + 1) * sizeof(char));
    text[index] = '\0';  // Null-terminate the string

    printf("The text was %s\n", text);

    free(text);
}
