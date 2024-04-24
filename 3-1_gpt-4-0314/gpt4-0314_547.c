#include<stdio.h>

int main()
{
    int i, j = 0;
    int ret;

    do
    {
        ++j;
        ret = scanf("%d", &i);

        if (ret == 0) // If scanf encounters invalid input
        {
            scanf("%*s"); // Clear input buffer
            printf("\nInvalid input. Enter an integer.\n");
            continue;
        }

        printf("\n\n%d %d\n\n", i, j);
    } 
    while ((i != 8) && (j < 10));

    printf("\nJ = %d\n", j);
    return 0;
}
Both of these updated programs will clear the input buffer and ignore invalid inputs, ensuring that the program continues to ask for valid integer inputs.
