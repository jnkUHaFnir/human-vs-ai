#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *searchingFor = "stackdummy";
char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

char *strnstr(char *s1, char *s2, int length) {
    printf("searching \n\n\"%s\"\n for %.*s\n", s1, length, s2);
    char *ss2 = malloc(length + 1);
    strncpy(ss2, s2, length);
    ss2[length] = '\0';  // Ensure null termination for ss2
    char *result = strstr(s1, ss2);
    free(ss2);
    if(result != NULL){
      char *copy_result = strdup(result);
      // strdup will allocate memory and copies the result string.
      // you have to free(copy_result) where you use this function
      return copy_result; 
    }
    else{
      return NULL;
    }
}

int main(void) {
    char* found = strnstr(in, searchingFor, 5);
    printf("found: %s\n", found ? "yes" : "no");
    free(found);

    found = strnstr(in, searchingFor, 5);
    printf("found: %s\n", found ? "yes" : "no");
    free(found);

    found = strnstr(in, searchingFor, 5);
    printf("found: %s\n", found ? "yes" : "no");
    free(found);

    return 0;
}
