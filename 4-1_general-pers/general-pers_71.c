#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* safe_strcat(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char* result = (char*)malloc(len1 + len2 + 1); // +1 for null terminator
    if (result == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

int main() {
    const char* var = "variable";
    const char* foo = "foo";
    const char* bar = "bar";

    char* message = safe_strcat("TEXT ", var);
    if (message != NULL) {
        printf("message: %s\n", message);
        free(message);
    }

    char* message2_temp = safe_strcat("TEXT ", foo);
    char* message2_temp2 = safe_strcat(message2_temp, " TEXT ");
    char* message2 = safe_strcat(message2_temp2, bar);

    if (message2 != NULL) {
        printf("message2: %s\n", message2);
        free(message2_temp);
        free(message2_temp2);
        free(message2);
    }

    return 0;
}
