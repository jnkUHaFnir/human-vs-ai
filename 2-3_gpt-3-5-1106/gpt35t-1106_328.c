#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *searchingFor = "stack";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(char *s1, char *s2, int length) {
    if(s1 == NULL || s2 == NULL) return NULL;
    char *ss1 = malloc(strlen(s1) + 1);
    strcpy(ss1, s1);
    char *ss2 = malloc(length + 1);
    strncpy(ss2, s2, length);
    ss2[length] = '\0'; // Make sure the substring is null-terminated
    char *result = strstr(ss1, ss2);
    free(ss1);
    free(ss2);
    return result;
}

int main(void) {
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 10) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 15) ? "yes" : "no");
    return 0;
}
