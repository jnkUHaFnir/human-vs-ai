#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int temperature;
    char cityName[100];
} City;

int main() {
    FILE* fPtr = fopen("input.txt", "r"); // Open file for reading
    if (fPtr == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }

    int numberOfLines = 10; // Assuming a fixed number of lines for testing

    City **ptrArray = (City **)calloc(numberOfLines, sizeof(City*));
    if (ptrArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    char tempArray[100];
    int slength;

    for (int i = 0; i < numberOfLines; i++) {
        if (fscanf(fPtr, "%99[^:]:%d", tempArray, &ptrArray[i]->temperature) == 2) {
            slength = strlen(tempArray);
            ptrArray[i] = (City*)malloc(sizeof(City));
            if (ptrArray[i] == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            strcpy(ptrArray[i]->cityName, tempArray);          
        } else {
            printf("Error reading data from file\n");
            return 1;
        }
    }

    // Code to use ptrArray

    // Free memory
    for (int i = 0; i < numberOfLines; i++) {
        free(ptrArray[i]);
    }
    free(ptrArray);

    fclose(fPtr); // Close the file
    return 0;
}
