#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *searchingFor = "stackdummy";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(char *s1, char *s2, int length) {
    if (s1 == NULL || s2 == NULL) return NULL;
    printf("Searching for \"%.*s\" in \"%s\"\n", length, s2, s1);

    size_t s1_len = strlen(s1);
    size_t s2_len = strnlen(s2, length);
    
    if (s2_len > length) return NULL; // Ensure s2 length does not exceed length

    for (size_t i = 0; i <= s1_len - s2_len; i++) {
        if (strncmp(s1 + i, s2, s2_len) == 0) {
            return s1 + i;
        }
    }

    return NULL; // substring not found
}

int main(void) {
    printf("found: %s\n", strnstr(in, searchingFor, strlen(searchingFor)) ? "yes" : "no");
    return 0;
}
