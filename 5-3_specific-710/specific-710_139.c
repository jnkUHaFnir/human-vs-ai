ptrArray[i] = (City*)malloc(sizeof(City));
if(ptrArray[i] == NULL) {
    // Handle memory allocation error
}
ptrArray[i]->cityName = (char*)malloc(sizeof(char) * (slength + 1));
if(ptrArray[i]->cityName == NULL) {
    // Handle memory allocation error
}
for (int i = 0; i < numberOfLines; i++)
{
    if (fscanf(fPtr, "%99[^:] %*c", tempArray) != 1) {
        // Handle fscanf error
    }
    
    slength = strlen(tempArray);
    
    ptrArray[i] = (City*)malloc(sizeof(City));
    if (ptrArray[i] == NULL) {
        // Handle memory allocation error
    }
    
    ptrArray[i]->cityName = (char*)malloc(sizeof(char) * (slength + 1));
    if (ptrArray[i]->cityName == NULL) {
        // Handle memory allocation error
    }
    
    strcpy(ptrArray[i]->cityName, tempArray);
    
    int tempTemperature;
    if (fscanf(fPtr, "%d", &tempTemperature) != 1) {
        // Handle fscanf error
    }
    ptrArray[i]->temperature = tempTemperature;
}
