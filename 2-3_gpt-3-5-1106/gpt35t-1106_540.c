#define REPEAT_STRING(str, n) ({ \
    char* repeatedString = malloc(strlen(str) * n + 1); \
    for (int i = 0; i < n; i++) { \
        strcat(repeatedString, str); \
    } \
    repeatedString; \
})
char* repeated = REPEAT_STRING("-", 10);
printf("%s\n", repeated); // Output: ----------
free(repeated);
