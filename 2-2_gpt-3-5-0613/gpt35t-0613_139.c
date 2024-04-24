City **ptrArray = (City **)calloc(numberOfLines, sizeof(City*));

char tempArray[100];
int slength;

for (int i = 0; i < numberOfLines; i++)
{
    fscanf(fPtr, "%99[^:] %*c", tempArray);
    char *temp = tempArray;
    slength = strlen(temp);
    ptrArray[i] = (City*)malloc(sizeof(City) + sizeof(char) * (slength + 1));
    strcpy(ptrArray[i]->cityName, temp);
    //fscanf(fPtr, "%d", &(ptrArray[i]->temperature));
}
