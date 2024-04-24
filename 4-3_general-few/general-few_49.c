#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct mystruct
{
  int a;
  int b;
  char c;
};

int main()
{
    struct mystruct *myarray = malloc(SIZE * sizeof(struct mystruct));
    if (myarray == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        return 1;
    }

    int myarrayMaxSize = SIZE;
    int i = 0;

    // Access myarray like a dynamic array
    myarray[i].a = 1;
    myarray[i].b = 2;
    myarray[i].c = 'A';

    i++;

    // Check if we need to allocate more memory
    if (i >= myarrayMaxSize) {
        myarrayMaxSize += SIZE;
        struct mystruct *temp = realloc(myarray, myarrayMaxSize * sizeof(struct mystruct));
        if (temp == NULL) {
            // Handle memory reallocation failure
            printf("Memory reallocation failed\n");
            free(myarray);
            return 1;
        }
        myarray = temp;
    }

    // Continue using the updated myarray

    free(myarray); // Don't forget to free the memory when you're done

    return 0;
}
