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

    fseek(fp, 0, SEEK_SET); // Reset file pointer to the beginning of the file

    char line[100]; // Assuming each line in the file is less than 100 characters
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s %d %s %d", data2.author, &data2.issueNumber, data2.title, &data2.issued);

        if (data2.issueNumber == issuenumber)
        {
            printf("%s %d %s\n", data2.author, data2.issueNumber, data2.title);
            break; // Break out of the loop once the book is found
        }
    }
    fclose(fp);
}

void start(FILE *fp)
{
    // Implementation of start function remains the same
}

int main()
{
    FILE *fp;
    fp = fopen("c1.txt", "r+"); // Open the file in read/write mode
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    start(fp);

    return 0;
}
