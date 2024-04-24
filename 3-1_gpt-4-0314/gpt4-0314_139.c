#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int temperature;
    char *cityName;
} City;

int main() {
    int numberOfLines = 3;  // Assume you have 3 lines
    City **ptrArray = (City **)calloc(numberOfLines, sizeof(City *));

    char tempArray[100];
    int slength;

    FILE *fPtr = fopen("sample.txt", "r");  // Replace this with your file
    if (!fPtr) {
        printf("Error opening file\n");
        return -1;
    }

    for (int i = 0; i < numberOfLines; i++) {
        memset(tempArray, '\0', sizeof(tempArray));

        fscanf(fPtr, "%99[^:] %*c", tempArray);
        slength = strlen(tempArray);

        ptrArray[i] = (City *)malloc(sizeof(City));
        ptrArray[i]->cityName = (char *)malloc(sizeof(char) * (slength + 1));
        strcpy(ptrArray[i]->cityName, tempArray);

        fscanf(fPtr, "%d", &(ptrArray[i]->temperature));
    }

    fclose(fPtr);

    // Print the data
    for (int i = 0; i < numberOfLines; i++) {
        printf("City: %s, Temperature: %d\n", ptrArray[i]->cityName,
               ptrArray[i]->temperature);
    }

    // Free allocated memory
    for (int i = 0; i < numberOfLines; i++) {
        free(ptrArray[i]->cityName);
        free(ptrArray[i]);
    }
    free(ptrArray);
    return 0;
}
