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
    if (myarray == NULL)
    {
        // Handle allocation failure
        exit(1);
    }

    int myarrayMaxSize = SIZE;
    // Example usage
    int i = 1500; // Assuming i is greater than myarrayMaxSize

    if (i >= myarrayMaxSize)
    {
        // Calculate new size
        int newMaxSize = myarrayMaxSize + SIZE;
        struct mystruct *newArray = realloc(myarray, newMaxSize * sizeof(struct mystruct));
        
        if (newArray == NULL)
        {
            // Handle reallocation failure, original array still intact
            // You can decide here whether to free the original array or not 
            exit(1);
        }
        
        myarray = newArray;
        myarrayMaxSize = newMaxSize;
    }

    // Continue using the array

    // Don't forget to free memory when you're done with it
    free(myarray);

    return 0;
}
