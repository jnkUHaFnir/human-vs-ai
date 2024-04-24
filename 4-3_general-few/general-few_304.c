char* fixString(char str[]) {
    char* position;
    char* newString = "";
    char* finalString = malloc(strlen(str) + 1); // Allocate memory for finalString

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
            char* tempString = malloc(strlen(newString) + 2);
            strcpy(tempString, newString);
            strcat(tempString, " ");
            newString = tempString;
        }

        printf("String: |%s|\n", newString);
        if (strlen(newString) > 0) {
            strcat(finalString, newString);
        }
        printf("------------\n");
        position = strchr(position + 1, '/');
    }
    char* lastString = substr(str, oldPosition, strlen(str));
    strcat(finalString, lastString);
    printf("lastString: %s\n\n", lastString);

    return finalString;
}
