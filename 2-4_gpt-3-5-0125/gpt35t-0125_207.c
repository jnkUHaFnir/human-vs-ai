#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <time.h>

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1); // +1 for the zero-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main ()
{
    srand(time(NULL));
    int r = rand();

    char str[10]; // Assuming the maximum length of a 6-digit number is 6 digits
    sprintf(str, "%d", r); // Convert integer to string
    
    printf("%s\n", concat("foo-", str));

    return 0;
}
