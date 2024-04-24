void openFile(FILE** file, char* filename) {
    int SIZE = 10;
    char* data, *data2;
    int n = 0;
    char c;
    
    // Read the filename safely
    printf("filename:");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character if present

    if (!((*file) = fopen(filename, "r"))) {
        perror("Error:");
    } else {
        if ((data = (char*)malloc(SIZE * sizeof(char))) == NULL) {
            perror("malloc:");
        }   

        while (fscanf((*file), "%c", &c) != EOF) {
            if (n < SIZE) {
                data[n++] = c;
            } else {
                SIZE *= 2; // Double the size
                if ((data2 = (char*)realloc(data, SIZE * sizeof(char))) != NULL) {
                    data = data2;
                    data[n++] = c;  
                } else {
                    free(data);
                    break;
                }
            }
        }
    }
}
