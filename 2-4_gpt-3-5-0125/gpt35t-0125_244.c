void get_line(char* filename) {
    char* text;
    FILE* file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    text = malloc(sizeof(char) * INIT_SIZE);
    if (!text) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    size_t size = INIT_SIZE;
    size_t len = 0;
    size_t read;

    while (fgets(text + len, size - len, file) != NULL) {
        read = strlen(text + len);
        len += read;

        if (text[len - 1] == '\n' || text[len - 1] == EOF) {
            break;
        }

        size *= 2;
        text = realloc(text, size);
        if (!text) {
            fprintf(stderr, "Memory reallocation failed\n");
            return;
        }
    }

    printf("The text was %s\n", text);

    free(text);
    fclose(file);
}
