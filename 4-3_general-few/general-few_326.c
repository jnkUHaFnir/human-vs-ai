#include <stdio.h>

struct data
{
    char author[25];
    int issueNumber;
    char title[25];
    int issued;
};

void searchBookByIssueNumber(FILE *fp, int issuenumber)
{
    struct data data2;

    while (fscanf(fp, "%s %d %s %d\n", data2.author, &data2.issueNumber, data2.title, &data2.issued) != EOF)
    {
        if (data2.issueNumber == issuenumber)
        {
            printf("%s %d %s\n", data2.author, data2.issueNumber, data2.title);
            break; // Add break to stop searching after finding the issue
        }
    }
    fclose(fp);
}

void start(FILE *fp)
{
    printf("---------------------------------------------------\n");
    printf("|      WELCOME TO LIBRARY MANAGEMENT              |\n");
    printf("---------------------------------------------------\n");

    int issuenumber;
    printf("Enter the issue number to search: ");
    scanf("%d", &issuenumber);

    searchBookByIssueNumber(fp, issuenumber);
}

int main()
{
    FILE *fp;
    fp = fopen("c1.txt", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    start(fp);
    return 0;
}
