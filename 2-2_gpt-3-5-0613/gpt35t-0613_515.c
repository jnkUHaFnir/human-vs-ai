void openFile(FILE** file, char* filename) {
    int SIZE = 10;
    char* data;
    int n = 0;
    char c;
    
    printf("filename:");
    scanf("%s", filename);
    
    if (!((*file) = fopen(filename, "r")))
        perror("Error:");
    else {
        if ((data = malloc(SIZE * sizeof(char))) == NULL) {
            perror("malloc:");
        }   
        
        while (fscanf((*file), "%c", &c) != EOF) {
            if (n == SIZE) {
                SIZE *= 2;
                char* data2 = realloc(data, SIZE * sizeof(char));
                
                if (data2 != NULL) {
                    data = data2;
                } else {
                    free(data);
                    break;
                }
            }
            
            data[n++] = c;
        }
        
        fclose(*file);
    }
}
