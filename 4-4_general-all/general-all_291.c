#include <stdio.h>
#include <pcre.h>

int main(){
    char input[128];
    pcre *re;
    const char *error;
    int erroffset;
    int ovector[30];  // provides room for subpatterns
    int rc;

    // Compile the regular expression
    re = pcre_compile("^[0-9a-zA-Z]+$", 0, &error, &erroffset, NULL);
    if (re == NULL) {
        printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);
        return 1;
    }

    // Get user input
    if (scanf("%127[^\n]", input) != 1) {
        printf("Input error\n");
        return 1;
    }

    // Match the regular expression
    rc = pcre_exec(re, NULL, input, strlen(input), 0, 0, ovector, 30);
    
    if (rc >= 0) {
        printf("Matched\n");
    } else {
        printf("Invalid\n");
    }

    pcre_free(re);
    return 0;
}
