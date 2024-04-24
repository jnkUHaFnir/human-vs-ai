#include <stdio.h>
#include <string.h>

struct data
{
    char author[25];
    int issueNumber;
    char title[25];
    int issued;
};

void searchBookByIssueNumber(FILE *fp)
{
    struct data data2;
    data2.issued = 0;
    int issuenumber = 0;
    printf("Enter issue number: ");
    scanf("%d", &issuenumber);

    // Reset file pointer to the beginning
    fseek(fp, 0, SEEK_SET);

    while (fscanf(fp, "%s %d %s %d\n", data2.author, &data2.issueNumber, data2.title, &data2.issued) == 4)
    {
        if (data2.issueNumber == issuenumber)
        {
            printf("Author: %s\nIssue Number: %d\nTitle: %s\n", data2.author, data2.issueNumber, data2.title);
            break; // Stop searching after finding the book
        }
    }
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
    fp = fopen("c1.txt", "r+");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    start(fp);

    fclose(fp);
    return 0;
}
