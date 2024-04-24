City **ptrArray = (City **)calloc(numberOfLines, sizeof(City*));
if (ptrArray == NULL) {
    // Handle allocation failure
}

char tempArray[100];
int slength;

for (int i = 0; i < numberOfLines; i++)
{
    fscanf(fPtr, "%99[^:] %*c", tempArray);
    slength = strlen(tempArray);

    // Allocate memory for the entire City structure
    ptrArray[i] = (City*)malloc(sizeof(City));
    if (ptrArray[i] == NULL) {
        // Handle allocation failure
    }

    // Allocate memory for cityName in the City structure
    ptrArray[i]->cityName = (char*)malloc(slength + 1); // +1 for null terminator
    if (ptrArray[i]->cityName == NULL) {
        // Handle allocation failure
    }

    strcpy(ptrArray[i]->cityName, tempArray);

    // Allocate memory for temperature in the City structure
    ptrArray[i]->temperature = (int*)malloc(sizeof(int));
    if (ptrArray[i]->temperature == NULL) {
        // Handle allocation failure
    }

    fscanf(fPtr, "%d", ptrArray[i]->temperature);
}
