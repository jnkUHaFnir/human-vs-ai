#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null terminator
    if (result == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main()
{
    srand(time(NULL));
    int r = rand() % 1000000; // Limit to 6 digits

    char r_string[7]; // 6 digits + null terminator
    sprintf(r_string, "%06d", r); // Convert integer to string with leading zeros if needed

    char* result = concat("foo-", r_string);
    printf("%s\n", result);
    
    free(result); // Free the allocated memory
    return 0;
}
