#include <stdio.h>

struct data
{
    char author[25];
    int issueNumber;
    char title[25];
    int issued;
};

void searchBookByIssueNumber(FILE *fp)
{
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return;
    }

    struct data data2;
    data2.issued = 0;
    int issuenumber = 0;
    printf("Enter issue number: ");
    scanf("%d", &issuenumber);

    rewind(fp); // Reset file pointer to the beginning of the file

    while (fscanf(fp, "%s %d %s %d\n", data2.author, &data2.issueNumber, data2.title, &data2.issued) == 4)
    {
        if (data2.issueNumber == issuenumber)
        {
            printf("%s %d %s\n", data2.author, data2.issueNumber, data2.title);
            break; // Exit loop after finding the desired entry
        }
    }

    if (data2.issueNumber != issuenumber)
    {
        printf("Book with issue number %d not found.\n", issuenumber);
    }

    fclose(fp);
}

void start(FILE *fp)
{
    printf("---------------------------------------------------\n");
    printf("|                                                 |\n");
    printf("|      WELCOME TO LIBRARY MANAGEMENT              |\n");
    printf("|                                                 |\n");
    printf("---------------------------------------------------\n");

    searchBookByIssueNumber(fp);
}

int main()
{
    FILE *fp;
    fp = fopen("c1.txt", "r"); // Open file in read mode
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    start(fp);

    return 0;
}
