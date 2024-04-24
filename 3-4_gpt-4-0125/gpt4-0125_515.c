#include <stdio.h>
#include <stdlib.h>

void openFile(FILE** file, char* filename)
{
    int SIZE = 10;
    char* data = NULL;
    int n = 0;
    char c;

    printf("filename: ");
    scanf("%s", filename);

    if (!((*file) = fopen(filename, "r")))
    {
        perror("Error opening file");
    }
    else
    {
        data = (char*)malloc(SIZE * sizeof(char));
        if (data == NULL)
        {
            perror("Error allocating memory");
            return;
        }

        while ((c = fgetc(*file)) != EOF)
        {
            if (n + 1 >= SIZE) // +1 for the null terminator
            {
                SIZE *= 2; // Double the size
                char* temp = (char*)realloc(data, SIZE * sizeof(char));
                if (temp == NULL)
                {
                    perror("Error reallocating memory");
                    free(data);
                    return;
                }
                data = temp;
            }
            data[n++] = c;
        }
        data[n] = '\0'; // Null-terminate the string

        printf("%s\n", data); // Example usage

        // Perform cleanup
        free(data);
    }
}

int main()
{
    FILE* file;
    char filename[256]; // Assuming filenames won't exceed 255 characters
    openFile(&file, filename);
    if(file) {
        fclose(file);
    }
    return 0;
}
