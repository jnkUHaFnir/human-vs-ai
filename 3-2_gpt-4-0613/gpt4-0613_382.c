while (1)
{
    fgets(bnumber, 10, stdin);
    len = strlen(bnumber);
    if (bnumber[len - 1] == '\n')
    {
        bnumber[len - 1] = 0;
    }
    if (strcmp(bnumber, STOP) == 0) break;
    binaryreturn = convertbinary(bnumber);
    printf("%d\n", binaryreturn); 
    printf("Enter binary byte or type q to quit:?\n");
}
