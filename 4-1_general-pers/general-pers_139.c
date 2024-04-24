#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int temperature;
    char cityName[1]; // Using flexible array member for cityName
} City;

int main() {
    FILE* fPtr = fopen("input.txt", "r"); // Assuming input file name is "input.txt"
    if(fPtr == NULL) {
        perror("Error opening file");
        return 1;
    }

    int numberOfLines = 5; // Example value, should be based on the number of lines in the file
    City** ptrArray = (City **)calloc(numberOfLines, sizeof(City*));
    if(ptrArray == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    char tempArray[100];
    int slength;

    for (int i = 0; i < numberOfLines; i++) {
        if(fscanf(fPtr, "%99[^:]:%d", tempArray, &slength) != 2) {
            fprintf(stderr, "Error reading from file");
            return 1;
        }

        ptrArray[i] = (City*)malloc(sizeof(City) + sizeof(char) * slength);
        if(ptrArray[i] == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        ptrArray[i]->temperature = slength;
        strcpy(ptrArray[i]->cityName, tempArray);
    }

    // Ensure to close the file after reading
    fclose(fPtr);

    // Free allocated memory
    for (int i = 0; i < numberOfLines; i++) {
        free(ptrArray[i]);
    }
    free(ptrArray);

    return 0;
}
