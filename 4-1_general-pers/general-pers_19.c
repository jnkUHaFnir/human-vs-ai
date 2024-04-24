#include <stdlib.h>

typedef struct {
    int size; // size of array
    int* array;
} MyStruct;

MyStruct* createMyStruct(int size) {
    MyStruct* myStruct = (MyStruct*)malloc(sizeof(MyStruct));

    if (myStruct != NULL) {
        myStruct->size = size;
        myStruct->array = (int*)malloc(size * sizeof(int));

        if (myStruct->array == NULL) {
            // Handle memory allocation failure
            free(myStruct);
            return NULL;
        }
    }

    return myStruct;
}

void destroyMyStruct(MyStruct* myStruct) {
    if (myStruct != NULL) {
        free(myStruct->array);
        free(myStruct);
    }
}

int main() {
    int size = 10;
    MyStruct* myStruct = createMyStruct(size);

    if (myStruct != NULL) {
        // Access and use myStruct->array as needed

        destroyMyStruct(myStruct); // Free memory when done
    }

    return 0;
}
