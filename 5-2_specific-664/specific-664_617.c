void readFromFile() {
    FILE *myfile;
    int currentSz = 10;
    int maxSz = 1000010;

    while (currentSz <= maxSz) {
        // Allocate memory for the array dynamically
        float *fileArr = (float *)malloc(currentSz * sizeof(float)); 
        if (fileArr == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        // Rest of your code remains the same
        // ...

        // After using the array, free the allocated memory
        free(fileArr);

        currentSz += 20000;
    }
}
