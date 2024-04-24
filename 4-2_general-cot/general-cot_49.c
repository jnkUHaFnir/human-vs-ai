#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct mystruct {
    int a;
    int b;
    char c;
};

int myarrayMaxSize = SIZE;
struct mystruct *myarray = NULL;
int currentSize = 0;

void addElement() {
    if (currentSize >= myarrayMaxSize) {
        myarrayMaxSize += SIZE;
        myarray = (struct mystruct *)realloc(myarray, myarrayMaxSize * sizeof(struct mystruct));
        if (myarray == NULL) {
            printf("Memory reallocation failed. Exiting.\n");
            exit(1);
        }
    }

    // Add new element to the array
    myarray[currentSize].a = 0; // Initial value for integer a
    myarray[currentSize].b = 0; // Initial value for integer b
    myarray[currentSize].c = 'a'; // Initial value for char c
    currentSize++;
}

int main() {
    // Add elements to the array
    for (int i = 0; i < SIZE + 5; i++) {
        addElement();
    }

    // Print the values of the elements
    for (int i = 0; i < currentSize; i++) {
        printf("Element %d: a=%d, b=%d, c=%c\n", i, myarray[i].a, myarray[i].b, myarray[i].c);
    }

    // Free the allocated memory
    free(myarray);

    return 0;
}
