char* fixString(char str[]) {
    char* position;
    char* finalString = malloc(strlen(str) + 1); // Allocate memory for finalString
    finalString[0] = '\0'; // Ensure finalString is empty at the beginning

    int oldPosition = 0;
    printf("Original str: %s\n", str);
    printf("Original length: %d\n\n", strlen(str));

    position = strchr(str, '/');
    while (position != NULL) {
        int charPosition = position - str;

        char* newString = substr(str, oldPosition, charPosition - oldPosition);
        oldPosition = charPosition;

        if (charPosition > 0 && str[charPosition - 1] != ' ') {
            newString = strcat(newString, " ");
        }

        strcat(finalString, newString); // Concatenate newString to finalString
        free(newString); // Free dynamically allocated memory for newString
        position = strchr(position + 1, '/');
    }
    
    char* lastString = substr(str, oldPosition, strlen(str));
    strcat(finalString, lastString);
    free(lastString);

    return finalString;
}
