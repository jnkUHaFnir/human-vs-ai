ptrArray[i] = (City*)malloc(sizeof(City));
fscanf(fPtr, "%99[^:] %*c", tempArray);
temp = tempArray;
slength = strlen(temp);
fscanf(fPtr, "%d", &(ptrArray[i]->temperature));
for (int i = 0; i < numberOfLines; i++)
{ 
    //Allocates enough memory for City struct
    fscanf(fPtr, "%99[^:] %*c", tempArray);
    temp = tempArray;
    slength = strlen(temp);
    ptrArray[i] = (City*)malloc(sizeof(City));
    strcpy(ptrArray[i]->cityName, temp);
    fscanf(fPtr, "%d", &(ptrArray[i]->temperature));
}
