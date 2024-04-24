#define MAX_BUF_SIZE 1000000

char source[MAX_BUF_SIZE];

FILE *fp = fopen("TheFile.txt", "r");
if(fp != NULL)
{
    fgets(source, MAX_BUF_SIZE, fp);
    fclose(fp);
}

// Process the contents of the buffer
for(int x = 0; source[x] != '\0'; x++)
{
    // Process chars
}
