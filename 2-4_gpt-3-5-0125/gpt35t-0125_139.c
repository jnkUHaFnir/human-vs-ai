for (int i = 0; i < numberOfLines; i++)
    {
        fscanf(fPtr, "%99[^:] %*c", tempArray);
        slength = strlen(tempArray);
        ptrArray[i] = (City*)malloc(sizeof(City));
        strcpy(ptrArray[i]->cityName, tempArray);
        fscanf(fPtr, "%d", &ptrArray[i]->temperature);
    }
for (int i = 0; i < numberOfLines; i++) {
    free(ptrArray[i]);
}
free(ptrArray);
