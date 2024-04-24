#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("files.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int first_num, j;
    fscanf(file, "%d", &first_num); // Reading the first integer from the file

    int *p = (int *)malloc(first_num * sizeof(int));

    for (j = 0; j < first_num; j++)
    {
        fscanf(file, "%d", &p[j]); // Reading the integers at the second line
    }

    for (j = 0; j < first_num; j++)
    {
        printf("\t%d\t", p[j]); // Printing the integers stored in the array
    }
    printf("\n%d", first_num);

    free(p);
    fclose(file);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("files.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int specific_line = 3;
    int current_line = 1;
    char line_buffer[1024];

    while (current_line < specific_line && fgets(line_buffer, sizeof(line_buffer), file) != NULL)
    {
        current_line++; // Read lines until we reach the specific line
    }

    if (current_line == specific_line)
    {
        int num_array[20];
        int i = 0;
        char *token = strtok(line_buffer, " ");
        while (token != NULL && i < 20)
        {
            num_array[i] = atoi(token); // Convert string token to integer and store it in num_array
            token = strtok(NULL, " ");
            i++;
        }

        // Now num_array contains the integers read from the given line
        for (int j = 0; j < i; j++)
        {
            printf("\t%d\t", num_array[j]);
        }
    }

    fclose(file);
    return 0;
}
