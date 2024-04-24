#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <time.h>

char* concat(const char *s1, const int r)
{
    char str[20]; // Assuming the maximum length of integer would be 10 digits
    sprintf(str, "%d", r);
    
    char *result = malloc(strlen(s1) + strlen(str) + 1); // +1 for the zero-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, str);
    return result;
}

int main()
{
    srand(time(NULL));
    int r = rand() % 1000000; // Generating a random 6-digit number

    char* result = concat("foo-", r);
    printf("%s\n", result);

    free(result); // Don't forget to free the memory allocated by malloc

    return 0;
}
