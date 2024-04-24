void openFile(FILE** file,char* filename)
{
    int SIZE=10;
    char* data;
    int n = 0;
    char c;
    printf("filename:");
    scanf("%s",filename);
    if (!((*file) = fopen(filename, "r")))
        perror("Error:");
    else
    {   
        if ((data = (char*)malloc(SIZE * sizeof(char))) == NULL)
        {
            perror("malloc:");
            return;
        }   
        while (fscanf((*file),"%c",&c) != EOF)
        {
            if (n >= SIZE)
            {
                SIZE *= 2;
                char* temp = (char*)realloc(data, SIZE * sizeof(char));
                if (temp == NULL)
                {
                    perror("realloc:");
                    free(data);
                    return;
                }
                data = temp;
            }
            data[n++] = c;  
        }
        data[n] = '\0'; // Null-terminate the string
    }
    fclose(*file);
}
