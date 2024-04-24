#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* safe_strcat(const char* s1, const char* s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    
    char* result = (char*)malloc(len1 + len2 + 1); // +1 for the null terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }
    
    strcpy(result, s1);
    strcat(result, s2);
    
    return result;
}

int main() {
    const char* var = "variable";
    const char* foo = "foo";
    const char* bar = "bar";

    char* message = safe_strcat("TEXT ", var);
    printf("message: %s\n", message);
    free(message);

    char* message2 = safe_strcat(safe_strcat("TEXT ", foo), safe_strcat(" TEXT ", bar));
    printf("message2: %s\n", message2);
    free(message2);

    return 0;
}
