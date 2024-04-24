FILE *fp = fopen("TheFile.txt", "r");
if(fp != NULL)
{
    fseek(fp, 0, SEEK_END); // move to the end of the file
    long size = ftell(fp);  // get the position which is the size
    rewind(fp); // move back to the start of the file
    char *source = (char*)malloc(size + 1); // +1 for the null-terminator
    if(source != NULL)
    {
        fread(source, 1, size, fp);
        source[size] = '\0'; // don't forget the null-terminator
    }
    fclose(fp);
}
