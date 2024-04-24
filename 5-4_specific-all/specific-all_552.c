void searchBookByIssueNumber(FILE *fp)
{
    struct data data2;
    data2.issued = 0;
    int issuenumber = 0;
    printf("Enter issue number: ");
    scanf("%d", &issuenumber);

    rewind(fp); // move file pointer to the beginning of the file

    while (fread(&data2, sizeof(struct data), 1, fp) == 1)
    {
        if (data2.issueNumber == issuenumber)
        {
            printf("%s %d %s\n", data2.author, data2.issueNumber, data2.title);
        }
    }

    fclose(fp);
}
