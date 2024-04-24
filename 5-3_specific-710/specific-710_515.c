void openFile(FILE** file, char* filename) {
    int SIZE = 10;
    char* data = NULL;
    int n = 0;
    char c;
    printf("Enter filename: ");
    scanf("%s", filename);
    
    if (!((*file) = fopen(filename, "r"))) {
        perror("Error opening file:");
        return;
    }

    while (fscanf((*file), " %c", &c) != EOF) {
        if (n < SIZE) {
            data = (char*)realloc(data, SIZE * sizeof(char));
            if (data == NULL) {
                perror("realloc:");
                break;
            }
            data[n++] = c;
        } else {
            SIZE *= 2;
            data = (char*)realloc(data, SIZE * sizeof(char));
            if (data == NULL) {
                perror("realloc:");
                break;
            }
            data[n++] = c;  
        }
    }
    
    // Add a null terminator at the end
    data = (char*)realloc(data, (n + 1) * sizeof(char));
    data[n] = '\0';

    // Use data for further processing
    // Don't forget to free the allocated memory after use
    free(data);
}
