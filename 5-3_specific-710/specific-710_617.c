#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void readFromFile() {
    FILE *myfile; // File to access randomized floats
    int currentSz = 10; // Size iterator
    int maxSz = 1000010; // Maximum size to reference in the loop

    while (currentSz <= maxSz) {
        // Allocate memory for the array dynamically on the heap
        float *fileArr = (float*)malloc(currentSz * sizeof(float));
        if (fileArr == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }

        // Initialize file path
        char fileName[200];
        fileName[0] = '\0';
        strcat(fileName, "C:\\Users\\MatthewC\\Documents\\HonorsProject341\\RandomFloats\\");

        // Create a size string to represent the current array size and add sizeStr to the file path
        char sizeStr[50];
        sprintf(sizeStr, "%d", currentSz);
        strcat(sizeStr, "Floats.txt");
        strcat(fileName, sizeStr);

        // Open the file
        myfile = fopen(fileName, "r");

        if (myfile == NULL) {
            fprintf(stderr, "Error opening file %s\n", fileName);
            exit(1);
        }

        int iterator;

        // Feed the elements from the file into the dynamically allocated array
        for (iterator = 0; iterator < currentSz; iterator++)
            fscanf(myfile, "%f", &fileArr[iterator]);

        // Sort the randomized elements and time the sorting algorithm
        clock_t start = clock(), diff;
        heapSort(fileArr, currentSz); // Assuming heapSort function is implemented elsewhere
        diff = clock() - start;

        // Convert to milliseconds
        int millisec = diff * 1000 / CLOCKS_PER_SEC;

        printf("size: %d runtime: %d\n", currentSz, millisec);
        fclose(myfile);

        // Free the dynamically allocated memory
        free(fileArr);

        // Update the size
        currentSz += 20000;
    }
}
