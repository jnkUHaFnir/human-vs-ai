void searchBookByIssueNumber(FILE *fp, int issuenumber) {
    struct data data2;
    data2.issued = 0;

    fseek(fp, 0, SEEK_SET); // Reset file pointer to beginning

    while (fscanf(fp, "%s %d %s %d", data2.author, &data2.issueNumber, data2.title, &data2.issued) == 4) {
        if (data2.issueNumber == issuenumber) {
            printf("%s %d %s\n", data2.author, data2.issueNumber, data2.title);
        }
    }
}

void start(FILE *fp) {
    printf("---------------------------------------------------\n");
    printf("|                                                 |\n");
    printf("|      WELCOME TO LIBRARY MANAGEMENT              |\n");
    printf("|                                                 |\n");
    printf("---------------------------------------------------\n");

    /* Other functions can be called here */
    
    int issuenumber = 0;
    printf("Enter issue number: ");
    scanf("%d", &issuenumber);

    searchBookByIssueNumber(fp, issuenumber);

    fclose(fp); // Close the file after all operations are done
}

int main() {
    FILE *fp;
    fp = fopen("c1.txt", "r+"); // Use "r+" mode for reading and writing

    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    start(fp);

    return 0;
}
