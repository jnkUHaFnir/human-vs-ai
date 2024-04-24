City **ptrArray = (City **)calloc(numberOfLines, sizeof(City*));
ptrArray[i] = (City*)malloc(sizeof(int)+(sizeof(char)*slength));
ptrArray[i] = (City*)malloc(sizeof(City));
strcpy(ptrArray[i]->cityName, temp);
//fscanf(fPtr, "%d", ptrArray[i]->temperature);
fscanf(fPtr, "%d", &(ptrArray[i]->temperature));
for (int i = 0; i < numberOfLines; i++) {
    // Read the city name up to the colon, but not including it
    fscanf(fPtr, "%99[^:]", tempArray); // Make sure to check the return value for errors
    ptrArray[i] = (City *)malloc(sizeof(City)); // Allocate memory for the whole struct
    
    if (!ptrArray[i]) {
        // Handle allocation error (e.g., free already allocated memory and exit)
    }
    
    strcpy(ptrArray[i]->cityName, tempArray); // Copy city name
    
    // Skip the colon and any spaces after it, then read the temperature
    fscanf(fPtr, ": %d", &(ptrArray[i]->temperature)); // Read the temperature
    
    // Optionally, you could skip to the end of the line here if needed
    // fscanf(fPtr, "%*[^\n]\n"); // This reads and discards characters until a newline
}
