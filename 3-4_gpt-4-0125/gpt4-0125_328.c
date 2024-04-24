#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strnstr(const char *s1, const char *s2, size_t length) {
    size_t len2 = strlen(s2);
    if (!len2) {
        return (char *)s1;
    }

    for (size_t i = 0; i <= length - len2; i++) {
        if (s1[i] == *s2 && !strncmp(s1 + i, s2, len2)) {
            return (char *)(s1 + i);
        }
    }

    return NULL;
}

int main(void) {
    char *searchingFor = "stackdummy";
    char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

    printf("found: %s\n", strnstr(in, searchingFor, 15) ? "yes" : "no"); // Expected no, insufficient length
    printf("found: %s\n", strnstr(in, searchingFor, 25) ? "yes" : "no"); // Expected no, still insufficient
    printf("found: %s\n", strnstr(in, searchingFor, 35) ? "yes" : "no"); // Might expect yes if length is enough for 'stack' but it will not find 'stackdummy' within the string.
    
    // Example to find a substring that exists:
    printf("found: %s\n", strnstr(in, "now", 50) ? "yes" : "no"); // Expected yes, it searches for 'now', not 'stackdummy'

    return 0;
}
