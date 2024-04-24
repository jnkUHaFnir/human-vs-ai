#include <stdio.h>

int main()
{
    int size;

    do {
        printf("Size of tower (0 <= x <= 23): ");
        scanf("%i", &size);

        if (size < 0 || size > 23) {
            printf("Invalid size\n");
        }

    } while (size < 0 || size > 23);

    // rest of your code...

    return 0;
}
