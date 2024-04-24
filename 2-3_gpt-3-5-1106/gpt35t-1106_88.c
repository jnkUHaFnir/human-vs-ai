char source[1000000];
FILE *fp = fopen("TheFile.txt", "r");
if(fp != NULL)
{
    while(fgets(source, sizeof(source), fp) != NULL)
    {
        //Process the line stored in source
    }
    fclose(fp);
}
