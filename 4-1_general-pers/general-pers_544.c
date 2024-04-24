void foo() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
}

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    
    char buffer[15];
    if (fgets(buffer, 15, fp) != NULL) {
        if (sscanf(buffer, "%d", pX) != 1) {
            fprintf(stderr, "Error parsing integer\n");
        }
    } else {
        fprintf(stderr, "Error reading file\n");
    }
    
    fclose(fp);
}
