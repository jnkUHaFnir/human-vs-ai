#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *searchingFor = "stackdummy";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(char *s1, char *s2, int length) {
    if(s1 == NULL || s2 == NULL) return NULL;
    
    char *ss1 = malloc(strlen(s1) + 1);
    strcpy(ss1, s1);
    char *ss2 = malloc(length + 1);
    strncpy(ss2, s2, length);
    char *result = strstr(ss1, ss2);
    
    free(ss1);
    free(ss2);
    
    return result;
}

int main(void) {
    char *result = strnstr(in, searchingFor, 5);
    printf("found: %s\n", result ? "yes" : "no");
    printf("found: %s\n", result ? "yes" : "no");
    printf("found: %s\n", result ? "yes" : "no");

    return 0;
}
