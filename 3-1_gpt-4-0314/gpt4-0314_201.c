#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p = (int *) malloc(10 * 4);
    int i, a, count = 1;
    printf("Input :\n");
    for (i = 0; ; i++)
    {
        scanf("%d", p + i);
        if (*(p + i) == 22)
        {
            break;
        }
        if (i == 9 + (count - 1) * 10)
        {
            count++;
            p = (int *) realloc(p, (10 + 10 * count) * sizeof(int));
        }
    }
    
    printf("\nOutput :\n");
    for(int j = 0; *(p + j) != 22; j++)
    {
        printf("%d\n", *(p + j));
    }
    
    free(p);
    return 0;
}
