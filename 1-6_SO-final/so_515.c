void openFile(FILE *file, char *filename) //double pointer is pointless, pass FILE pointer with no *
{
    int SIZE = 10;
    char *data, *data2;
    int n = 0;
    char c;
    printf("filename:");
    scanf("%s", filename);            //*& pointless
    if (!((file) = fopen(filename, "r")))
        perror("Error:");
    else
    {
        if ((data = malloc(SIZE)  == NULL) //char size is always 1 byte, no cast needed, include stdlib.h
        {
            perror("malloc:");
        }
        while (fscanf(file, "%c", &c) != EOF) //specifier for char is %c, furthermore you need & operator
        {                                     //probably the source of your problems
            if (n < SIZE)
            {
                data[n++] = c;
            }
            else
            {
                if ((data2 = realloc(data, SIZE) != NULL) // again no cast, no sizeof(char)
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
    }
}