#include <stdio.h>
#include <string.h>

char *strnstr(const char *haystack, const char *needle, size_t len) {
    size_t needle_len = strlen(needle);

    if (needle_len == 0) {
        return (char *)haystack;
    }

    for (size_t i = 0; haystack[i] != '\0' && (i + needle_len) <= len; ++i) {
        if (strncmp(&haystack[i], needle, needle_len) == 0) {
            return (char *)&haystack[i];
        }
    }

    return NULL;
}

int main(void) {
    char *searchingFor = "stack";
    char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 23) ? "yes" : "no");

    return 0;
}
