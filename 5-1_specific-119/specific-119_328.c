#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *searchingFor = "stackdummy";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(const char *s1, const char *s2, int length) {
    if(s1 == NULL || s2 == NULL) return NULL;
    int len1 = strlen(s1);
    int len2 = strnlen(s2, length);
    
    for (int i = 0; i <= len1 - len2; i++) {
        if (strncmp(&s1[i], s2, len2) == 0) {
            return (char *)&s1[i];
        }
    }
    return NULL;
}

int main(void) {
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 20) ? "yes" : "no");
    return 0;
}
