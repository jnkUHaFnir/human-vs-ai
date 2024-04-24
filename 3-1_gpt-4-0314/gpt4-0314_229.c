#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    char *s = "This is a test";
    int num_replacements = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            num_replacements++;
        }
    }

    int newstring_len = strlen(s) + num_replacements * (strlen("gho") - strlen("te"));
    char *newstring = malloc(newstring_len + 1); // +1 for the null terminator

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // skip the next character in the original string
        } else {
            newstring[j++] = s[i];
        }
    }
    newstring[j] = '\0'; // don't forget to add the null terminator

    printf("%s\n", newstring);

    free(newstring); // don't forget to free the allocated memory

    return 0;
}
