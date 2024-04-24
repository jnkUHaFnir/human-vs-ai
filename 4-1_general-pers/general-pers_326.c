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
    struct data data2;
    int issuenumber = 0;
    
    printf("Enter issue number: ");
    scanf("%d", &issuenumber);
    
    while (fscanf(fp, "%s %d %s %d", data2.author, &data2.issueNumber, data2.title, &data2.issued) == 4)
    {
        if (data2.issueNumber == issuenumber)
        {
            printf("%s %d %s\n", data2.author, data2.issueNumber, data2.title);
            break; // Exit loop after finding the book
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
    fp = fopen("c1.txt", "r"); // Use "r" mode to read from file

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    start(fp);

    fclose(fp); // Close the file before exiting

    return 0;
}
