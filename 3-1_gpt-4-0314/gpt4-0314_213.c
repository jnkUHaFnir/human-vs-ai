#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("files.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int first_num;

    // Reading the number of integers on the first line
    if (fscanf(file, "%d", &first_num) != 1)
    {
        printf("Error: Could not read the first number.\n");
        fclose(file);
        return 1;
    }

    int* p = (int*)malloc(first_num * sizeof(int));
    if (p == NULL)
    {
        printf("Error: Could not allocate memory for the array.\n");
        fclose(file);
        return 1;
    }

    // Reading the integers on the second line
    for (int j = 0; j < first_num; j++)
    {
        if (fscanf(file, "%d", &p[j]) != 1)
        {
            printf("Error: Could not read the integer at index %d.\n", j);
            free(p);
            fclose(file);
            return 1;
        }
    }

    // Printing the read integers
    for (int j = 0; j < first_num; j++)
    {
        printf("\t%d\t", p[j]);
    }
    printf("\n%d", first_num);

    free(p);
    fclose(file);

    return 0;
}
