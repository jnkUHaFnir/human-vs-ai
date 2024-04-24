void openFile(FILE** file, char* filename)
{
    int SIZE = 10;
    char* data, * data2;
    int n = 0;
    char c;

    printf("filename:");
    scanf("%s", filename);

    if (!((*file) = fopen(filename, "r")))
    {
        perror("Error:");
    }
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
                SIZE *= 2; // Double the size when reallocating
                if ((data2 = (char*)realloc(data, SIZE * sizeof(char))) != NULL)
                {
                    data = data2;
                    data[n++] = c;
                }
                else
                {
                    free(data);
                    perror("realloc:");
                    break;
                }
            }
        }

        // Add null terminator at the end of the data
        data[n] = '\0';

        // Do something with data

        free(data);
        fclose(*file);
    }
}
