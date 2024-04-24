char source[1000000];

FILE *fp = fopen("TheFile.txt", "rb");
if(fp != NULL)
{
    size_t bytesRead = fread(source, 1, sizeof(source)-1, fp);
    source[bytesRead] = '\0';
    fclose(fp);
}
