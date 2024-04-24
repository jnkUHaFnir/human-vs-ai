int main() {
    FILE* fin = NULL;
    FILE* fout = NULL;
    char fInName[50];
    char fOutName[50];
    
    printf("Please type input file, and output file please type legibly:\n");

    // scanf returns the number of items successfully read
    int itemsRead = scanf("%49s %49s", fInName, fOutName); // limit to buffer size
    if (itemsRead < 1) {
        printf("Error: No input file name provided.\n");
    } 
    else if (itemsRead < 2) {
        printf("Error: No output file name provided.\n");
    } 
    else {
        // Attempt to open files only if both names have been provided
        fin = fopen(fInName, "r");
        fout = fopen(fOutName, "w"); // Usually, the output file is meant for writing

        if (!fin) {
            printf("Error: Cannot open input file %s.\n", fInName);
        } 
        else if (!fout) {
            printf("Error: Cannot open output file %s.\n", fOutName);
            // Remember to close fin if fout fails to open
            fclose(fin);
        } 
        else {
            printf("Both files opened successfully.\n");
            // Remember to close files when you're done
            fclose(fin);
            fclose(fout);
        }
    }

    return 0;
}
