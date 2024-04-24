#include <stdio.h>
#define ARRAY_SIZE 10

int main()
{
    int array[ARRAY_SIZE];
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    if (!array)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // use the array

    free(array);
    return 0;
}
