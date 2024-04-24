ptrArray[i] = (City*)malloc(sizeof(int)+(sizeof(char)*slength));
ptrArray[i] = (City*)malloc(sizeof(City));
fscanf(fPtr, "%99[^:]:", tempArray); // Notice the ':' in the format specifier.
fscanf(fPtr, "%d", &ptrArray[i]->temperature);
strcpy(ptrArray[i]->cityName, tempArray);
