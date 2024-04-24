int* entityIndexes = (int*)malloc(numEntities * sizeof(int));
entityIndexes = (int*)realloc(entityIndexes, newNumEntities * sizeof(int));
free(entityIndexes);
