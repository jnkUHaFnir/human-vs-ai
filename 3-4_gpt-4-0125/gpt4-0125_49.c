#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct mystruct {
    int a;
    int b;
    char c;
};

int main() {
    // Initial dynamic allocation
    struct mystruct* myarray = malloc(SIZE * sizeof(struct mystruct));
    if (myarray == NULL) {
        // Handle allocation failure
        printf("Memory allocation failed\n");
        exit(1);
    }
    int myarrayMaxSize = SIZE;
    // Example usage
    myarray[0].a = 1; // Just an example of how to access the array
}
// Assuming `i` is the current index you're working with and might be out of bounds
if (i >= myarrayMaxSize) {
    int newSize = myarrayMaxSize + SIZE; // Calculate the new size
    struct mystruct* temp = realloc(myarray, newSize * sizeof(struct mystruct));
    if (temp == NULL) {
        // Handle reallocation failure
        printf("Memory reallocation failed\n");
        // Depending on your use case, you might want to free the original array and exit or handle it differently
        free(myarray);
        exit(1);
    }
    myarray = temp; // Use the newly allocated block
    myarrayMaxSize = newSize; // Update your tracking size
}
int main() {
    struct mystruct* myarray = malloc(SIZE * sizeof(struct mystruct));
    if (myarray == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    int myarrayMaxSize = SIZE;

    // Simulating the process of using and potentially resizing the array
    for (int i = 0; i < 2000; i++) { // Let's say you have a loop that might exceed the initial size
        if (i >= myarrayMaxSize) {
            int newSize = myarrayMaxSize + SIZE;
            struct mystruct* temp = realloc(myarray, newSize * sizeof(struct mystruct));
            if (temp == NULL) {
                printf("Memory reallocation failed\n");
                free(myarray);
                exit(1);
            }
            myarray = temp;
            myarrayMaxSize = newSize;
        }

        // Just as an example, using 'i' to fill some data
        myarray[i].a = i;
        myarray[i].b = i * 2;
        myarray[i].c = 'A' + (i % 26);
    }

    // Remember to free the allocated memory when you're done
    free(myarray);
}
