void openFile(FILE** file, char* filename)
{
    int SIZE = 10;
    char* data, *data2;
    int n = 0;
    char c;
    printf("filename:");
    printf("%s\n", filename);
    if (!((*file) = fopen(filename, "r")))
        perror("Error:");
    else
    {
        if ((data = (char*)malloc(SIZE * sizeof(char))) == NULL)
        {
            perror("malloc:");
        }
        while (fscanf((*file), " %c", &c) == 1)
        {
            if (n < SIZE)
            {
                data[n++] = c;
            }
            else
            {
                SIZE *= 2; // Double the size
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
        data[n] = '\0'; // Null-terminate the string
        printf("Data read: %s\n", data); // Example: printing the read data
    }

    fclose(*file);
    free(data);
}
