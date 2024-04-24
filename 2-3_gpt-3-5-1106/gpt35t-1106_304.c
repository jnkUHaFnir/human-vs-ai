char* fixString(char str[]) {
    char* position;
    char* newString;
    char* finalString;

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
            printf("Previous char: %c\n", str[charPosition - 1);
            char temp[2] = " ";
            newString = strcat(temp, newString);
        }

        printf("String: |%s|\n", newString);
        if (finalString == NULL) {
            finalString = strdup(newString);
        } else {
            char* temp = strdup(finalString);
            free(finalString);
            finalString = strcat(temp, newString);
        }
        free(newString);
        printf("------------\n");
        position = strchr(position + 1, '/');
    }
    char* lastString = substr(str, oldPosition, strlen(str));
    if (finalString == NULL) {
        finalString = strdup(lastString);
    } else {
        char* temp = strdup(finalString);
        free(finalString);
        finalString = strcat(temp, lastString);
    }
    free(lastString);
    printf("lastString: %s\n\n", lastString);
    return finalString;
}
