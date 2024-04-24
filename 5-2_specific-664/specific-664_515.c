#include <stdio.h>
#include <stdlib.h>

void openFile(FILE** file, char* filename)
{
    int SIZE = 10;
    char *data, *data2;
    int n = 0;
    char c;
    
    printf("filename:");
    scanf("%s", filename);
    
    if (!((*file) = fopen(filename, "r")))
        perror("Error:");
    else
    {   
        if ((data = (char*)malloc(SIZE * sizeof(char))) == NULL)
        {
            perror("malloc:");
        }
        
        while (fscanf((*file), "%c", &c) != EOF)
        {
            if (n < SIZE)
            {
                data[n++] = c;
            }
            else
            {
                SIZE *= 2; // Increase size before reallocating
                if ((data2 = (char*)realloc(data, SIZE * sizeof(char))) != NULL)
                {
                    data = data2;
                    data[n++] = c;
                }
                else
                {
                    free(data);
                }
            }
        }
        
        data[n] = '\0'; // Null-terminate the string
        
        fclose(*file); // Close the file
    }
}

int main()
{
    FILE* file;
    char filename[100];
    
    openFile(&file, filename);
    printf("Data read: %s\n", filename);
    
    return 0;
}
