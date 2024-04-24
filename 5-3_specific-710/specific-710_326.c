void searchBookByIssueNumber(FILE *fp)
{
    struct data data2;
    data2.issued = 0;
    int issuenumber = 0;
    printf("Enter issue no.: ");
    scanf("%d", &issuenumber);
    
    rewind(fp); // Reset the file pointer to the beginning of the file

    while (fscanf(fp, "%s %d %s %d\n", data2.author, &data2.issueNumber, data2.title, &data2.issued) == 4)
    {
        if (data2.issueNumber == issuenumber)
        {
            printf("%s %d %s\n", data2.author, data2.issueNumber, data2.title);
        }
    }
    fclose(fp);
}
