ptrArray[i] = (City*)malloc(sizeof(City));
fscanf(fPtr, "%d", &(ptrArray[i]->temperature));
strcpy(ptrArray[i]->cityName, tempArray);
for (int i = 0; i < numberOfLines; i++)
{
    fscanf(fPtr, "%99[^:] %*c", tempArray);
    ptrArray[i] = (City*)malloc(sizeof(City));
    strcpy(ptrArray[i]->cityName, tempArray);
    fscanf(fPtr, "%d", &(ptrArray[i]->temperature));
}
