#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size; //size of array
    int *array;
} MyStruct;

int main()
{
    MyStruct *myStruct = malloc(sizeof(MyStruct)); //Allocate memory for struct

    if(myStruct == NULL)
    {
        printf(" Memory for struct not allocated.\n");
        return 0;
    }

    myStruct->size = 10; //Configure size

    myStruct->array = malloc(myStruct->size * sizeof(int)); //Allocate memory for array inside struct

    if(myStruct->array == NULL)
    {
        printf(" Memory for array not allocated.\n");
        return 0;
    }

    //Your code here...

    free(myStruct->array); //Don't forget to free the memory of the array when you done
    free(myStruct); //And then free the memory of struct
    return 0;
}
