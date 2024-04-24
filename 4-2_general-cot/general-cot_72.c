#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* safeConcat(const char *s1, const char *s2, const char *s3) {
    size_t len = strlen(s1) + strlen(s2) + strlen(s3) + 1; // +1 for null terminator
    char* result = (char*)malloc(len);
    
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    
    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);
    
    return result;
}

int main() {
    const char *var = "VAR";
    const char *foo = "FOO";
    const char *bar = "BAR";

    char *message = safeConcat("TEXT ", var, "");
    char *message2 = safeConcat(safeConcat("TEXT ", foo, ""), " TEXT ", bar);

    printf("Message: %s\n", message);
    printf("Message2: %s\n", message2);

    free(message);
    free(message2);

    return 0;
}
