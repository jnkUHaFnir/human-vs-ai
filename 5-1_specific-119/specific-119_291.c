#include <stdio.h>
#include <string.h>
#include <pcre.h>

int main() {
    char name[128];
    const char* pattern = "^[0-9a-zA-Z]*$";
    pcre* re;
    const char* error;
    int erroffset;

    re = pcre_compile(pattern, 0, &error, &erroffset, NULL);
    if (re == NULL) {
        printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);
        return 1;
    }

    printf("Enter the name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    int rc = pcre_exec(re, NULL, name, strlen(name), 0, 0, NULL, 0);

    if (rc < 0) {
        if (rc == PCRE_ERROR_NOMATCH) {
            printf("Invalid input\n");
        } else {
            printf("PCRE matching error %d\n", rc);
        }
    } else {
        printf("Matched\n");
    }

    pcre_free(re);
    return 0;
}
