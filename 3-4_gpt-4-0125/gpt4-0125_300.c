#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} IntArray;

void initArray(IntArray *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(IntArray *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(IntArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

int main() {
    IntArray a;
    initArray(&a, 10); // Start with capacity of 10

    // Example use: Insert some elements
    for (int i = 0; i < 50; ++i) { // Simulate inserting 50 elements
        insertArray(&a, i);
    }

    printf("Array size: %zu\n", a.used);
    for (size_t i = 0; i < a.used; ++i) {
        printf("%d ", a.array[i]);
    }

    freeArray(&a); // Remember to free the memory
    return 0;
}
