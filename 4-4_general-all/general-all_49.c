#include <stdlib.h>

#define SIZE 1000

struct mystruct {
    int a;
    int b;
    char c;
};

struct mystruct* myarray = NULL;
int myarrayMaxSize = 0;

void resizeArray(int newSize) {
    struct mystruct* newArray = realloc(myarray, newSize * sizeof(struct mystruct));
    if (newArray == NULL) {
        // Handle allocation failure
        // For example, print an error message and exit
        printf("Memory allocation failed\n");
        exit(1);
    }
    myarray = newArray;
    myarrayMaxSize = newSize;
}

int main() {
    // Initially allocate memory for SIZE elements
    resizeArray(SIZE);

    // Access elements beyond the originally allocated size
    int i = 1005;
    if (i >= myarrayMaxSize) {
        // Resize the array by another SIZE elements
        resizeArray(myarrayMaxSize + SIZE);
    }

    // Now myarray can hold up to myarrayMaxSize elements

    // Don't forget to free the allocated memory when you're done
    free(myarray);

    return 0;
}
