#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int*)malloc(10 * sizeof(int));
    int i, count = 1;

    if(p == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Input :\n");
    for(i = 0; ; i++)
    {
        scanf("%d", p + i);
        if(*(p + i) == 22)
        {
            break;
        }
        if(i == (10 * count) - 1)
        {
            p = realloc(p, (10 + 10 * count) * sizeof(int));
            if(p == NULL)
            {
                printf("Memory reallocation failed.\n");
                free(p);
                return 1;
            }
            count++;
        }
    }

    printf("\nOutput :\n");
    for(i = 0; *(p + i) != 22; i++)
    {
        printf("%d\n", *(p + i));
    }

    free(p);
    return 0;
}
