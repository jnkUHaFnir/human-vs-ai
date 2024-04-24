#include <stdio.h>
#include <string.h>

int main() {
    char var[] = "123";
    char foo[] = "abc";
    char bar[] = "xyz";

    char result[50]; // Make sure this buffer is large enough to hold the concatenated strings

    strcpy(result, "TEXT ");
    strcat(result, var);

    strcat(result, " TEXT ");
    strcat(result, foo);

    strcat(result, " TEXT ");
    strcat(result, bar);

    printf("Concatenated string: %s\n", result);

    return 0;
}
