#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <time.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* intToString(int num)
{
    // Max length for a 6 digit number (including negative sign)
    char *str = malloc(7 * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    snprintf(str, 7, "%d", num);
    return str;
}

int main()
{
    srand(time(NULL));
    int r = rand() % 1000000; // Ensure r is a 6-digit number

    char numStr[7]; // Buffer for formatted number
    sprintf(numStr, "%06d", r); // Format r as a 6-digit number

    char *result = concat("foo-", numStr);
    printf("%s\n", result);

    free(result); // Free dynamically allocated memory
    return 0;
}
