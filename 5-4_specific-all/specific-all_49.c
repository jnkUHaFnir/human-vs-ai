#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct mystruct {
    int a;
    int b;
    char c;
};

int main() {
    struct mystruct* myarray = (struct mystruct*)malloc(SIZE * sizeof(struct mystruct));
    if (myarray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int myarrayMaxSize = SIZE;

    int i = 1100; // For demonstration purpose, assuming we need more than initial 1000 elements
    
    if (i > myarrayMaxSize) {
        // dynamically allocate another SIZE (1000) elements
        myarray = (struct mystruct*)realloc(myarray, (myarrayMaxSize + SIZE) * sizeof(struct mystruct));
        if (myarray == NULL) {
            printf("Memory reallocation failed.\n");
            return 1;
        }
        myarrayMaxSize += SIZE;
    }

    // Continue using the extended array 'myarray' here

    // Don't forget to free the memory when it's no longer needed
    free(myarray);

    return 0;
}
