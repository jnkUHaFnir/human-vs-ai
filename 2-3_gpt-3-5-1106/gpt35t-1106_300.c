#include <stdio.h>
#include <stdlib.h>

int main() {
    int maxEntities = 3000; // Maximum game entities
    int* indexArray = (int*)malloc(maxEntities * sizeof(int)); // Allocate memory for the array
    int numEntities = 0; // Keep track of how many entities have been added

    // Add entities to the array
    indexArray[numEntities++] = 1;
    indexArray[numEntities++] = 2;
    // ...

    // Pass the array to a function

    // Free the memory when done
    free(indexArray);

    return 0;
}
