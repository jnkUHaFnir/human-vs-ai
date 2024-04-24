#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *searchingFor = "stackdummy";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(char *s1, char *s2, int length) {
    if (s1 == NULL || s2 == NULL) return NULL;
    
    char *ss1 = malloc(strlen(s1) + 1);
    if (ss1 == NULL) return NULL;
    strcpy(ss1, s1);
    
    char *ss2 = malloc(length + 1);
    if (ss2 == NULL) {
        free(ss1);
        return NULL;
    }
    strncpy(ss2, s2, length);
    ss2[length] = '\0'; // Null-terminate ss2
    
    char *result = strstr(ss1, ss2);
    
    free(ss1);
    free(ss2);
    
    return result; // Return the pointer in s1, not in the heap
}

int main(void) {
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", strnstr(in, searchingFor, 5) ? "yes" : "no");
    return 0;
}
