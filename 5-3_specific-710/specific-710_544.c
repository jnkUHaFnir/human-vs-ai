void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    char *buffer = malloc(15 * sizeof(char)); // Allocate memory for 15 characters
    if (fgets(buffer, 15, fp) != NULL) {
        sscanf(buffer, "%d", pX); // Use sscanf to read integer value from buffer
    }
    free(buffer);
    fclose(fp);
}
