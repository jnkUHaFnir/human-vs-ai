#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *searchingFor = "stackdummy";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(char *s1, char *s2, size_t length) {
    if (s1 == NULL || s2 == NULL) return NULL;

    char *end = s1 + length; // Define an endpoint for the search
    size_t pattern_length = strlen(s2);
    
    for (; *s1 && s1 <= end - pattern_length; ++s1) {
        if (strncmp(s1, s2, pattern_length) == 0) {
            // Found s2 in s1
            return s1;
        }
    }

    // s2 was not found
    return NULL;
}

int main(void) {
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, "stack", strlen(in)) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, "dummy", strlen(in)) ? "yes" : "no");
    return 0;
}
