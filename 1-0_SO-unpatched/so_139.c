    typedef struct{
        int temperature;
        char *cityName;// pointer to char
    }City;
    City **ptrArray = calloc(numberOfLines, sizeof(City*));
    if ( ptrArray == NULL) {
        printf ( "calloc failed\n");
        exit(1);
    }
    char tempArray[100];
    int slength;
    for (int i = 0; i < numberOfLines; i++)
    {
        fscanf(fPtr, "%99[^:] %*c", tempArray);
        slength = strlen(tempArray);
        ptrArray[i] = malloc( sizeof(City));// memory for structure
        if ( ptrArray[i] == NULL) {
            printf ( "malloc failed\n");
            exit ( 1);
        }
        ptrArray[i]->cityName = malloc( 1 + slength));// memory for cityName + 1 for '\0'
        if ( ptrArray[i]->cityName == NULL) {
            printf ( "malloc failed\n");
            exit (1);
        }
        strcpy(ptrArray[i]->cityName, tempArray);
        fscanf(fPtr, "%d", &ptrArray[i]->temperature);
    }