City** ptrArray = (City**)calloc(numberOfLines, sizeof(City*));

char tempArray[100];
char* temp = tempArray;
int slength;

for (int i = 0; i < numberOfLines; i++) {
    fscanf(fPtr, "%99[^:] %*c", tempArray);
    slength = strlen(temp);
  
    ptrArray[i] = (City*)malloc(sizeof(City));
    
    ptrArray[i]->cityName = (char*)malloc(slength + 1); // Allocate memory for cityName including null terminator
    strcpy(ptrArray[i]->cityName, temp);
   
    //fscanf(fPtr, "%d", &ptrArray[i]->temperature); // Need to use & to read into temperature
    
    // Bonus issue: The above line should have & before ptrArray[i]->temperature to pass it by reference
}

// Don't forget to free the memory allocated for cityName in each struct and the array itself when done using it
for (int i = 0; i < numberOfLines; i++) {
    free(ptrArray[i]->cityName);
    free(ptrArray[i]);
}
free(ptrArray);
