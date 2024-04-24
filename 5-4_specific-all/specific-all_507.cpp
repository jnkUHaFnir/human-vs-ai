#include <stdlib.h>

int main(int argc, char * argv[]) {
    const int size = 1000000000;

    int *a = (int *)malloc(sizeof(int));
    int capacity = 1;

    for (int i = 0; i < size; i++) {
        if (i == capacity) {
            capacity *= 2;
            a = (int *)realloc(a, capacity * sizeof(int));
        }
        a[i] = i;
    }

    free(a);
    return 0;
}
