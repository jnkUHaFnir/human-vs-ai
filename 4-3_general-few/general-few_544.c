void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char *buffer = malloc(15 * sizeof(char));
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(fp);
        return;
    }

    fgets(buffer, 15, fp);
    sscanf(buffer, "%d", pX);

    free(buffer);
    fclose(fp);
}
