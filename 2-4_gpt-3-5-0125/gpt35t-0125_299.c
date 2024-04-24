#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTITIES 3000

void processEntities(int* entityIndexList, int numEntities) {
    // Process the entities here
    for (int i = 0; i < numEntities; i++) {
        printf("Entity index: %d\n", entityIndexList[i]);
    }
}

int main() {
    int* entityIndexList = NULL;
    int numEntities = 0;
    int maxEntities = 0;

    // Read the raw list of in-game entities
    // Assuming you have some way of getting the entity indexes, let's add some dummy data
    int entityIndex;
    while (scanf("%d", &entityIndex) == 1) {
        if (numEntities >= maxEntities) {
            maxEntities += MAX_ENTITIES;
            entityIndexList = realloc(entityIndexList, maxEntities * sizeof(int));
        }
        entityIndexList[numEntities++] = entityIndex;
    }

    // Process the entity index list
    processEntities(entityIndexList, numEntities);

    // Free the allocated memory
    free(entityIndexList);

    return 0;
}
