#define REPEAT_STRING(s, n) ({ \
    char* _str = (char*)malloc((n + 1) * sizeof(char)); \
    if (_str) { \
        for (int i = 0; i < n; i++) { \
            _str[i] = s; \
        } \
        _str[n] = '\0'; \
    } \
    _str; \
})
char* repeatedString = REPEAT_STRING('-', 10);
printf("%s\n", repeatedString);
free(repeatedString); // Don't forget to free the memory when done using it
