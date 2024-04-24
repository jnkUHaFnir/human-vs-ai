#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct mystruct
{
    int a;
    int b;
    char c;
};

struct mystruct *myarray = NULL;
int myarrayMaxSize = SIZE;
int currentSize = 0;

void resizeArray(int newSize)
{
    struct mystruct *temp = realloc(myarray, newSize * sizeof(struct mystruct));
    if (temp == NULL)
    {
        // Handle memory allocation failure
        printf("Memory reallocation failed.\n");
        // You may choose to exit here or handle the error in a different way
    }
    else
    {
        myarray = temp;
        myarrayMaxSize = newSize;
    }
}

int main()
{
    myarray = malloc(SIZE * sizeof(struct mystruct));
    if (myarray == NULL)
    {
        // Handle memory allocation failure
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Use the array as needed
    // For example, add elements to the array
    for (int i = 0; i < SIZE + 5; i++)
    {
        if (i >= myarrayMaxSize)
        {
            resizeArray(myarrayMaxSize + SIZE);
        }

        myarray[i].a = i;
        myarray[i].b = i * 2;
        myarray[i].c = 'A' + (i % 26);
        currentSize++;
    }

    // Print the elements in the array
    for (int i = 0; i < currentSize; i++)
    {
        printf("Element %d: a=%d, b=%d, c=%c\n", i, myarray[i].a, myarray[i].b, myarray[i].c);
    }

    // Free the allocated memory when it's no longer needed
    free(myarray);

    return 0;
}
