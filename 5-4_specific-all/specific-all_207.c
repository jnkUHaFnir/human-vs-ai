#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    if (result == NULL) {
        // Handle malloc failure
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main()
{
    srand((unsigned int)time(NULL));
    int r = rand() % 1000000; // Generate a random 6-digit number

    char numStr[7]; // 6 digits + null-terminator
    snprintf(numStr, sizeof(numStr), "%06d", r); // Convert int to 6-digit string

    char* result = concat("foo-", numStr);
    printf("%s\n", result);

    free(result); // Free memory allocated by concat
    return 0;
}
