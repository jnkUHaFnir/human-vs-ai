#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* safe_strcat(const char* str1, const char* str2) {
    char* result = malloc(strlen(str1) + strlen(str2) + 1);
    if (result == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    const char* var = "World";
    const char* foo = "Hello";
    const char* bar = "Concatenation";

    char* message = safe_strcat("TEXT ", var);
    printf("Message: %s\n", message);
    free(message);

    char* message2 = safe_strcat(safe_strcat("TEXT ", foo), safe_strcat(" TEXT ", bar));
    printf("Message2: %s\n", message2);
    free(message2);

    return 0;
}
