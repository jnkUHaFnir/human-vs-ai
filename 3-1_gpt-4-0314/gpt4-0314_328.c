#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *searchingFor = "stackdummy";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(char *s1, char *s2, int length) {
    if (s1 == NULL || s2 == NULL) return NULL;
    printf("searching \n\n\"%s\"\n for %.*s\n", s1, length, s2);
    
    char *p1 = s1, *p2 = s2;
    int l1, l2;

    l2 = strlen(s2);
    if (!length || l2 > length) return NULL;
    if (!l2) return s1;

    l1 = strlen(s1);
    length -= l2;

    while (*p1 && l1 > 0 && length-- >= 0) {
        char *q1 = p1, *q2 = p2;
        while (*q1 && *q2 && *q1 == *q2) {
            q1++; q2++;
        }
        if (*q2 == 0) return p1;
        p1++; l1--;
    }

    return NULL;
}

int main(void) {
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    return 0;
}
#include <string.h>

void *memmem(const void *haystack, size_t haystacklen, const void *needle, size_t needlelen);
