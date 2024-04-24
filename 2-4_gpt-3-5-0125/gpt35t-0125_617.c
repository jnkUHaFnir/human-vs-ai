void readFromFile() {
    FILE *myfile;
    int currentSz = 10;
    int maxSz = 1000010;

    while (currentSz <= maxSz) {
        float *fileArr = malloc(currentSz * sizeof(float));
        if (fileArr == NULL) {
            printf("Memory allocation failed");
            return;
        }

        // Rest of your code remains the same

        // Remember to free the dynamically allocated memory after using it
        free(fileArr);

        currentSz += 20000;
    }
}
