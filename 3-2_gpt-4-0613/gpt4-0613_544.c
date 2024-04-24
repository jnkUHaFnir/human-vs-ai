void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    char *buffer = malloc(15 * sizeof(char)); // change sizeof(int) to sizeof(char)
    if (fp != NULL) { // check if the file has been opened successfully
        if (fgets(buffer, 15, fp) != NULL){ // check if fgets success
            sscanf(buffer, "%d", pX);
        }
        fclose(fp);
    } else {
        printf("Failed to open file.\n");
    }
    free(buffer);
}
void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    char buffer[15];
    if (fp != NULL) {
        if (fgets(buffer, 15, fp) != NULL){
            sscanf(buffer, "%d", pX);
        }
        fclose(fp);
    } else {
        printf("Failed to open file.\n");
    }
}
