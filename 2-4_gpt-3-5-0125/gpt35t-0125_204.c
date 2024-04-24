FILE *myFile;
myFile = fopen("numbers.txt", "r");
if (myFile == NULL)
{
    printf("Error Reading File\n");
}
else
{
    int i = 0;
    while (fscanf(myFile, "%d", &redica[i]) != EOF)
    {
        i++;
    }
    fclose(myFile);
}
