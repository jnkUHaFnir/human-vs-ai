char* fixString(char str[]) {
    char* position;
    char* newString = ""; // Incorrect initialization
    char* finalString = malloc(strlen(str) + 1); // Allocate memory for final string
    finalString[0] = '\0'; // Initialize finalString as an empty string

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
            newString = strncat(newString, temp, 1); // Concatenate ' ' to newString
        }

        printf("String: |%s|\n", newString);

        if (strlen(newString) > 0) {
            strncat(finalString, newString, strlen(newString)); // Concatenate newString to finalString
        }

        printf("------------\n");
        position = strchr(position + 1, '/');
    }

    char* lastString = substr(str, oldPosition, strlen(str));
    strncat(finalString, lastString, strlen(lastString)); // Concatenate lastString to finalString

    printf("lastString: %s\n\n", lastString);

    free(lastString); // Free allocated memory for lastString

    return finalString;
}
