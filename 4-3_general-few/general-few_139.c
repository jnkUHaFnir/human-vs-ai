City **ptrArray = (City **)calloc(numberOfLines, sizeof(City*));

char tempArray[100];
char* temp = tempArray;
int slength;

for (int i = 0; i < numberOfLines; i++)
{
    fscanf(fPtr, "%99[^:] %*c", tempArray);
    slength = strlen(tempArray);
    ptrArray[i] = (City*)malloc(sizeof(City));
    ptrArray[i]->cityName = malloc(slength + 1); // +1 for null terminator
    strcpy(ptrArray[i]->cityName, tempArray);
    fscanf(fPtr, "%d", &(ptrArray[i]->temperature)); // Read the temperature directly into the temperature member

    // Bonus Issue: Make sure to use & when reading integer values
}

// Free memory
for (int i = 0; i < numberOfLines; i++)
{
    free(ptrArray[i]->cityName);
    free(ptrArray[i]);
}
free(ptrArray);
