#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* safe_strcat(const char* str1, const char* str2) {
    char* result = (char*)malloc(strlen(str1) + strlen(str2) + 1); // +1 for the null terminator
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
        printf("Message 1: %s\n", message);
        free(message);
    } else {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char* message2 = safe_strcat(safe_strcat("TEXT ", foo), safe_strcat(" TEXT ", bar));
    if (message2 != NULL) {
        printf("Message 2: %s\n", message2);
        free(message2);
    } else {
        printf("Memory allocation failed.\n");
        return 1;
    }

    return 0;
}
