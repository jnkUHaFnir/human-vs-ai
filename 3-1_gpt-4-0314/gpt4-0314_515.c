#include <stdio.h>
#include <stdlib.h>

void openFile(FILE** file, char* filename)
{
    int SIZE = 10;
    char* data = NULL;
    int n = 0;
    char c;
    printf("filename: ");
    scanf("%s", filename); // Removed '&' before '*filename'
    if (!((*file) = fopen(filename, "r")))
        perror("Error:");
    else
    {
        if ((data = (char*)malloc(SIZE * sizeof(char))) == NULL)
        {
            perror("malloc:");
        }
        else
        {
            while ((c = fgetc((*file))) != EOF) // Changed 'fscanf' to 'fgetc', removed "%s" and modified 'c'
            {
                if (n + 1 >= SIZE) // Moved realloc before adding new character and added +1 for the null terminator
                {
                    SIZE *= 2;
                    char* data2 = (char*)realloc(data, SIZE * sizeof(char));
                    if (data2 != NULL) data = data2;
                    else
                    {
                        free(data);
                        break;
                    }
                }
                data[n++] = c;
            }
            data[n] = '\0'; // Added null terminator
            printf("Data read: %s\n", data);
            free(data); // Free memory
        }
    }
}

int main()
{
    FILE *file = NULL;
    char filename[256];
    openFile(&file, filename);
    if (file != NULL) fclose(file);
    return 0;
}
