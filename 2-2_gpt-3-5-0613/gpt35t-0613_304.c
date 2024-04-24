char* fixString(char str[]) {
    char* position;
    char* newString = "";
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
            printf("Previous char: %c\n", str[charPosition - 1]);
            newString = strcat(newString, " ");
        }

        printf("String: |%s|\n", newString);
        if (strlen(newString) > 0) {
            if (finalString == NULL) {
                finalString = malloc(strlen(newString) + 1);
                strcpy(finalString, newString);
            } else {
                finalString = realloc(finalString, strlen(finalString) + strlen(newString) + 1);
                strcat(finalString, newString);
            }
        }
        printf("------------\n");
        position = strchr(position + 1, '/');
    }
    char* lastString = substr(str, oldPosition, strlen(str));
    if (finalString == NULL) {
        finalString = malloc(strlen(lastString) + 1);
        strcpy(finalString, lastString);
    } else {
        finalString = realloc(finalString, strlen(finalString) + strlen(lastString) + 1);
        strcat(finalString, lastString);
    }
    printf("lastString: %s\n\n", lastString);
    return finalString;
}
int main() {
    char testString[] = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    printf("%s", fixString(testString));

    return 0;
}
