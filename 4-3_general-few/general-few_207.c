#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <time.h>

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main()
{
    srand(time(NULL));
    int r = rand();
    char rand_str[7]; // Extra space for the null terminator

    snprintf(rand_str, sizeof(rand_str), "%06d", r % 1000000);

    char* result = concat("foo-", rand_str);

    printf("%s\n", result);

    free(result); // Don't forget to free the memory allocated by malloc

    return 0;
}
