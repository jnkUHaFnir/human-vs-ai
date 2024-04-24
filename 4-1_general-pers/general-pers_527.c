#include <stdio.h>
#include <stdlib.h>

void fun1(int *a, int size)
{
    if (size > 4) {
        a[4] = 1;
    }
}

int main()
{
    int *a = (int *)malloc(2 * sizeof(int));
    if (a == NULL) {
        return 1; // Error handling for failed memory allocation
    }

    a[0] = 1;
    a[1] = 2;

    fun1(a, 2);

    printf("%d", a[1]);   // Output 2

    free(a);
    return 0;
}
