void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    char buffer[15];
    fgets(buffer, 15, fp);
    sscanf(buffer, "%d", pX);
    fclose(fp);
}
