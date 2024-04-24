#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define NEW_SIZE 1000

struct mystruct {
    int a;
    int b;
    char c;
};

int main() {
    struct mystruct *myarray = malloc(SIZE * sizeof(struct mystruct));
    if (myarray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int myarrayMaxSize = SIZE;
    int i = myarrayMaxSize; // Example value for i exceeding current size

    if (i >= myarrayMaxSize) {
        struct mystruct *temp = realloc(myarray, (myarrayMaxSize + NEW_SIZE) * sizeof(struct mystruct));
        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            free(myarray); // Free the original array
            return 1;
        }
        myarray = temp;
        myarrayMaxSize += NEW_SIZE;
    }

    // Now you can access myarray[i] safely up to myarrayMaxSize

    free(myarray); // Don't forget to free dynamically allocated memory when done

    return 0;
}
