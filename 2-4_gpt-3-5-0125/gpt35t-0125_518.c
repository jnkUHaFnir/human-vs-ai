char source[1000000];
int index = 0;
int c;

FILE *fp = fopen("TheFile.txt", "r");
if(fp != NULL)
{
    while((c = getc(fp)) != EOF && index < sizeof(source)-1)
    {
        source[index] = c;
        index++;
    }
    source[index] = '\0'; // Null-terminate the string
    fclose(fp);

    for(int x = 0; source[x] != '\0'; x++)
    {
        //Process chars
    }
}
