    typedef struct{
        int temperature;
        char *cityName;// pointer to char
    }City;
    City **ptrArray = calloc(numberOfLines, sizeof(City*));
    char tempArray[100];
    int slength;
    for (int i = 0; i < numberOfLines; i++)
    {
        fscanf(fPtr, "%99[^:] %*c", tempArray);
        slength = strlen(tempArray);
        ptrArray[i] = malloc( sizeof(City));// memory for structure
        ptrArray[i]->cityName = malloc( 1 + slength));// memory for cityName + 1 for '\0'
        strcpy(ptrArray[i]->cityName, tempArray);
        fscanf(fPtr, "%d", &ptrArray[i]->temperature);
    }