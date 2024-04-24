void deldigit(char* str) {
    char* result = str;

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            str++;
        }
        else {
            *result = *str;
            result++;
            str++;
        }
    }

    *result = '\0';
    printf("%s", str);
}
