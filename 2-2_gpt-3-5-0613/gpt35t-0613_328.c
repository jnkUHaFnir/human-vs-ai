#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *searchingFor = "stackdummy";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(char *s1, char *s2, int length) {
    if (s1 == NULL || s2 == NULL) return NULL;

    printf("searching \n\n\"%s\"\n for %.*s\n", s1, length, s2);

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if (length > len1 || length > len2) return NULL;

    char *ss1 = malloc(len1 + 1);
    strcpy(ss1, s1);

    char *ss2 = malloc(length + 1);
    strncpy(ss2, s2, length);
    ss2[length] = '\0';

    char *result = strstr(ss1, ss2);

    free(ss1);
    free(ss2);

    return result;
}

int main(void) {
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 10) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 20) ? "yes" : "no");

    return 0;
}
