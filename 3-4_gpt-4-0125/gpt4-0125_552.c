#include <stdio.h>
#include <stdlib.h>

struct data {
    char author[25];
    int issueNumber;
    char title[25];
    int issued;
};

void searchBookByIssueNumber(FILE *fp) {
    struct data d;
    int issuenumber = 0;
    printf("Enter issue no.: ");
    scanf("%d", &issuenumber);

    while (fscanf(fp, "%24s %d %24s %d\n", d.author, &d.issueNumber, d.title, &d.issued) == 4) {
        if (d.issueNumber == issuenumber) {
            printf("%s %d %s\n", d.author, d.issueNumber, d.title);
            return; // Assuming only one match is needed, else remove this line.
        }
    }
    printf("Book with issue number %d not found.\n", issuenumber);
}

void start(FILE *fp) {
    printf("---------------------------------------------------\n");
    printf("|             WELCOME TO LIBRARY MANAGEMENT       |\n");
    printf("---------------------------------------------------\n");
    
    searchBookByIssueNumber(fp);
}

int main() {
    FILE *fp;
    fp = fopen("c1.txt", "r"); // Changed to "r" to read existing data
    if (!fp) {
        printf("Failed to open file\n");
        return 1;
    }
    start(fp);
    fclose(fp); // Moved fclose here.

    return 0;
}
