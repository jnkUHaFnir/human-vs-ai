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
    data2.issued = 0;
    int issuenumber = 0;
    printf("Enter the issue number: ");
    scanf("%d", &issuenumber);

    rewind(fp); // Start from the beginning of the file

    while (fread(&data2, sizeof(struct data), 1, fp) == 1)
    {
        if (data2.issueNumber == issuenumber)
        {
            printf("%s %d %s\n", data2.author, data2.issueNumber, data2.title);
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
    fp = fopen("c1.txt", "rb+"); // Open the file in binary mode for reading/writing
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    start(fp);

    fclose(fp); // Close the file after we are done using it

    return 0;
}
