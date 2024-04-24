#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to concatenate two strings
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main()
{
    srand(time(NULL));

    // Generate a 6 digit random number
    int r = rand() % 1000000;
    char random_str[7]; // 6 digits + 1 null terminator
    sprintf(random_str, "%06d", r); // Convert integer to 6-digit string

    // Concatenate "foo-" with the random number
    char *result = concat("foo-", random_str);

    printf("%s\n", result);

    free(result); // Free allocated memory

    return 0;
}
