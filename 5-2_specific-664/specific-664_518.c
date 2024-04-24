char source[1000000];
int index = 0;
int symbol;

FILE *fp = fopen("TheFile.txt", "r");
if(fp != NULL)
{
    while ((symbol = getc(fp)) != EOF && index < sizeof(source) - 1)
    {
        source[index++] = (char)symbol;
    }
    source[index] = '\0'; // Add null terminator at the end
    fclose(fp);
}

// Check if index is less than sizeof(source) - 1 to ensure null termination
