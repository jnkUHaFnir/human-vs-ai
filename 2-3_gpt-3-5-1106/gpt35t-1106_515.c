void openFile(FILE** file, char* filename)
{
    int SIZE = 10;
    char* data, * data2;
    int n = 0;
    char c[2]; // Changed to char array

    if (!((*file) = fopen(filename, "r")))
        perror("Error:");
    else
    {
        if ((data = (char*)malloc(SIZE * sizeof(char))) == NULL)
        {
            perror("malloc:");
        }
        while (fscanf((*file),"%c", c) != EOF) // Changed to read a single character
        {
            if (n < SIZE)
            {
                data[n++] = c[0]; // Store the character in the array
            }
            else
            {
                if ((data2 = (char*)realloc(data, SIZE * 2 * sizeof(char))) != NULL) // Increase the size for reallocation
                {
                    data = data2;
                    data[n++] = c[0];  
                }
                else
                {
                    free(data);
                }
            }
        }
        fclose(*file); // Close the file
    }
}
