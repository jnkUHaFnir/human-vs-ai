void foo() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
}

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char buffer[15];
    fgets(buffer, 15, fp);
    sscanf(buffer, "%d", pX);
    
    fclose(fp);
}
