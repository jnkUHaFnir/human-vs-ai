#include <stdlib.h>

void addEntity(int **entities, int *size, int index)
{
    (*size)++;
    *entities = realloc(*entities, *size * sizeof(int));
    (*entities)[*size - 1] = index;
}

void removeEntity(int **entities, int *size)
{
    if (*size > 0) {
        (*size)--;
        *entities = realloc(*entities, *size * sizeof(int));
    }
}

void clearEntities(int **entities, int *size)
{
    free(*entities);
    *entities = NULL;
    *size = 0;
}

void mainProcessingFunction()
{
    int *entities = NULL;
    int size = 0;

    // Example usage
    addEntity(&entities, &size, 123);
    addEntity(&entities, &size, 456);
    removeEntity(&entities, &size);
    clearEntities(&entities, &size);
    
    // ...
}
