int main() {
    char fInName[50];
    char fOutName[50];

    printf("Please enter input and output file names:\n");
    int items_read = scanf("%s %s", fInName, fOutName);

    if (items_read == 0) {
        printf("Error: No file names entered.\n");
    } else if (items_read == 1) {
        printf("Error: Only one file name entered.\n");
    } else {
        printf("File names entered: %s %s\n", fInName, fOutName);
    }

    return 0;
}
