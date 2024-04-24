if(fPointer == NULL) {
    perror("Error opening file");
    return -2;
}
while(fgets(singleLineContent, 150, fPointer)) {
    char *token = strtok(singleLineContent, ",\n");
    if(token == NULL) {
        printf("Error reading line\n");
        return -3;
    }

    // your data handling code
}
