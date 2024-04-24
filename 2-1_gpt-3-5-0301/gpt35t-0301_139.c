ptrArray[i] = (City*)malloc(sizeof(City));
ptrArray[i]->temperature = 0; // initialize temperature to 0
strcpy(ptrArray[i]->cityName, temp);
City **ptrArray = (City **)calloc(numberOfLines, sizeof(City*));

char tempArray[100];
char *temp;
int slength;

for (int i = 0; i < numberOfLines; i++)
{
    // read line from file
    temp = fgets(tempArray, sizeof(tempArray), fPtr);
    if (temp == NULL) {
        break;
    }

    // allocate memory for City struct and copy city name
    slength = strlen(temp);
    ptrArray[i] = (City*)malloc(sizeof(City));
    ptrArray[i]->temperature = 0; // initialize temperature to 0
    strcpy(ptrArray[i]->cityName, temp);

    // read temperature from file
    fscanf(fPtr, "%d", &ptrArray[i]->temperature);
}

// free memory
for (int i = 0; i < numberOfLines; i++) {
    free(ptrArray[i]);
}
free(ptrArray);
