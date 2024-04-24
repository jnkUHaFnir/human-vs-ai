#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <time.h>

char* concat(const char *s1, char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the zero-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main()
{
    srand(time(NULL));
    int r = rand() % 1000000; // Ensure r is a 6-digit random number

    char r_str[7]; // To store the 6-digit random number as a string
    sprintf(r_str, "%06d", r); // Convert int to 6-digit string with leading zeros

    char* result = concat("foo-", r_str);
    
    printf("%s\n", result);

    free(result); // Free the dynamically allocated memory

    return 0;
}
