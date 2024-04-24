#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int temperature;
    char cityName[100];
} City;

int main() {
    FILE *fPtr = fopen("input.txt", "r");
    if (fPtr == NULL) {
        printf("File open error\n");
        return 1;
    }

    int numberOfLines = 5; // Example value

    City **ptrArray = (City **)calloc(numberOfLines, sizeof(City*));
    if (ptrArray == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    for (int i = 0; i < numberOfLines; i++) {
        char tempArray[100];
        if (fscanf(fPtr, "%99[^:] %*c", tempArray) != 1) {
            printf("Error reading data from file\n");
            break;
        }

        int slength = strlen(tempArray);
        ptrArray[i] = (City *)malloc(sizeof(City));
        if (ptrArray[i] == NULL) {
            printf("Memory allocation error\n");
            break;
        }

        strcpy(ptrArray[i]->cityName, tempArray);

        if (fscanf(fPtr, "%d", &ptrArray[i]->temperature) != 1) {
            printf("Error reading temperature from file\n");
            break;
        }
    }

    for (int i = 0; i < numberOfLines; i++) {
        printf("City: %s, Temperature: %d\n", ptrArray[i]->cityName, ptrArray[i]->temperature);

        free(ptrArray[i]);
    }
    free(ptrArray);

    fclose(fPtr);
    
    return 0;
}
