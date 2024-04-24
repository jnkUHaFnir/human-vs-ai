#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void heapSort(float arr[], int size); // Ensure you have the prototype for heapSort or include its definition

void readFromFile() {
    FILE *myfile; //File to access randomized floats
    int currentSz = 10; //Size iterator
    int maxSz = 1000010; // Maximum size to reference in the loop

    while (currentSz <= maxSz) {
        // Dynamically allocates a new array with the current size on the heap.
        float *fileArr = malloc(currentSz * sizeof(float)); // Changed to heap allocation
        if (fileArr == NULL) {
            printf("Memory allocation failed\n");
            exit(1); // Exit if allocation fails
        }

        // (No changes to initialization of fileName)
        char fileName[200];
        fileName[0] = '\0';
        strcat(fileName, "C:\\Users\\MatthewC\\Documents\\HonorsProject341\\RandomFloats\\");

        // (No changes to handling of size string)
        char sizeStr[50];
        sprintf(sizeStr, "%d", currentSz);
        strcat(sizeStr, "Floats.txt");
        strcat(fileName, sizeStr);                 

        // Opens the file 
        myfile = fopen(fileName, "r");

        // (No changes to reading from the file)
        int iterator;
        for (iterator = 0; iterator < currentSz; iterator++) {
            fscanf(myfile, "%f", &fileArr[iterator]);
        }

        // (No changes to timing and sorting)
        clock_t start = clock(), diff;
        heapSort(fileArr, currentSz);
        diff = clock() - start;

        // Converts to milliseconds.
        int millisec = diff * 1000000 / CLOCKS_PER_SEC;

        printf("size: %d runtime: %d\n", currentSz, millisec);
        fclose(myfile);

        // Frees the dynamically allocated array
        free(fileArr);

        // Updates the size.
        currentSz += 20000;
    }
}

int main() {
    readFromFile();
    return 0;
}
