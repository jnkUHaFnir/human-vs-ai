#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

struct mystruct {
    int a;
    int b;
    char c;
};

int main() {
    struct mystruct *myarray = malloc(SIZE * sizeof(struct mystruct));
    if (myarray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    int myarrayMaxSize = SIZE;
    int currentSize = SIZE;

    // Your code here to interact with the initial myarray

    int i = 2000; // Just an example of needing more space
    if (i > myarrayMaxSize) {
        // Allocate a new larger array
        int newMaxSize = myarrayMaxSize + SIZE;
        struct mystruct *newArray = realloc(myarray, newMaxSize * sizeof(struct mystruct));
        if (newArray == NULL) {
            printf("Memory reallocation failed\n");
            free(myarray);
            return 1;
        }
        myarray = newArray;
        myarrayMaxSize = newMaxSize;
    }

    // Continue using the extended array as needed

    free(myarray); // Free the memory when done

    return 0;
}
