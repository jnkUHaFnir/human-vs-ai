char* fixString(char str[]) {
    char* position;
    char* newString = malloc(strlen(str) + 1);
    char* finalString = malloc(strlen(str) + 1);
    finalString[0] = '\0';

    int oldPosition = 0;
    printf("Original str: %s\n", str);
    printf("Original length: %d\n\n", strlen(str));

    position = strchr(str, '/');
    while (position != NULL) {
        int charPosition = position - str;

        printf("String position: %d->%d\n", oldPosition, charPosition);
        newString = substr(str, oldPosition, charPosition - oldPosition);
        oldPosition = charPosition;
        if (charPosition > 0 && str[charPosition - 1] != ' ') {
            printf("Previous char: %c\n", str[charPosition - 1]);
            strcat(newString, " ");
        }

        printf("String: |%s|\n", newString);
        if (strlen(newString) > 0) {
            strcat(finalString, newString);
        }
        printf("------------\n");
        position = strchr(position + 1, '/');
    }
    char* lastString = substr(str, oldPosition, strlen(str) - oldPosition);
    strcat(finalString, lastString);
    printf("lastString: %s\n\n", lastString);
    free(newString);
    return finalString;
}
