   fgets(filename, sizeof(filename), stdin);
   filename[strcspn(filename, "\n")] = '\0'; //to remove newline character
- The way you are using the file pointer makes me suspect that you wouldn't need to pass it as an argument and much less as a double pointer, this would be useful if you need to keep the pointer to the file stream outside the function, if that's the case, you can leave it as is, otherwise you can use a local variable and close the stream when you are finished.
   
   
Here is he code with some corrections as mentioned and other minor ones:
void openFile(char *filename)
{
    int SIZE = 10;
    char *data, *data2;
    int n = 0;
    char c;
    FILE *file; //local variable
    printf("filename:");
    scanf("%99s", filename);// &* is pointless, using %99s, assuming filename[100]
    if (!(file = fopen(filename, "r")))
        perror("Error:");
    else
    {
        if ((data = malloc(SIZE)) == NULL) //char size is always 1 byte, no cast needed, include stdlib.h
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
                if ((data2 = realloc(data, SIZE)) != NULL) // again no cast, no sizeof(char)
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
    fclose(file); //close file stream
}
Note that the only catastrophic problems are the ones with `fscanf`, you can fix those only and the code will likely work, I'd still advise the other fixes.