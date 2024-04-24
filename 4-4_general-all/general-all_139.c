#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int temperature;
    char cityName[100];
} City;

int main() {
    int numberOfLines = 10; // Example value, assign the actual number of lines in the file
    City **ptrArray = (City **)calloc(numberOfLines, sizeof(City*));

    char tempArray[100];
    int slength;

    FILE *fPtr = fopen("data.txt", "r");
    if (fPtr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 0; i < numberOfLines; i++) {
        fscanf(fPtr, "%99[^:] %*c", tempArray);
        slength = strlen(tempArray);

        ptrArray[i] = (City*)malloc(sizeof(City));
        // Assign temperature separately or initialize it to some default value
        ptrArray[i]->temperature = 0;
        strcpy(ptrArray[i]->cityName, tempArray);
        
        // Example of reading temperature from file
        // fscanf(fPtr, "%d", &ptrArray[i]->temperature);
    }

    fclose(fPtr);

    // Now you have an array of City pointers with correctly initialized data

    // Don't forget to free the allocated memory when done
    for (int i = 0; i < numberOfLines; i++) {
        free(ptrArray[i]);
    }
    free(ptrArray);

    return 0;
}
