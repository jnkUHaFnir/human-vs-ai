void searchBookByIssueNumber(FILE *fp) {
    struct data data2;
    int issuenumber = 0;
    int found = 0;  // To track if we found a matching book
    
    printf("Enter issue no.: ");
    scanf("%d", &issuenumber);

    // Assuming data in file does not have authors or titles with spaces
    while (fscanf(fp, "%s %d %s %d\n", data2.author, &data2.issueNumber, data2.title, &data2.issued) != EOF) {
        if (data2.issueNumber == issuenumber) {
            printf("Author: %s, Issue Number: %d, Title: %s, Issued: %d\n",
            data2.author, data2.issueNumber, data2.title, data2.issued);
            found = 1;
            break; // Remove break if you want to find all matches
        }
    }

    if (!found) {
        printf("No book found with issue number %d.\n", issuenumber);
    } 

    fclose(fp);
}
int main() {
    FILE *fp;
    fp = fopen("c1.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    start(fp);

    return 0;
}
