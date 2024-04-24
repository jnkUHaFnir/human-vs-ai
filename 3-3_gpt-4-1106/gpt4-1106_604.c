#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceSubstring(const char *original, const char *pattern, const char *replacement) {
    size_t patlen = strlen(pattern);
    size_t replen = strlen(replacement);

    // Counting the number of times the pattern occurs in the original string
    size_t count = 0;
    const char *oriptr;
    const char *patloc;
    for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen) {
        count++;
    }

    // Allocating memory for the new string
    size_t retlen = strlen(original) + count * (replen - patlen);
    char *retstr = (char *)malloc(retlen + 1);
    if (retstr == NULL) {
        return NULL;
    }

    // Building the new string
    oriptr = original;
    char *retptr = retstr;
    while ((patloc = strstr(oriptr, pattern))) {
        size_t skiplen = patloc - oriptr;
        // Copy the segment before the pattern
        memcpy(retptr, oriptr, skiplen);
        retptr += skiplen;

        // Copy the replacement string
        memcpy(retptr, replacement, replen);
        retptr += replen;

        // Move past the pattern in the original string
        oriptr = patloc + patlen;
    }

    // Copy the remaining part of the original string
    strcpy(retptr, oriptr);

    return retstr;
}

int main() {
    const char *str = "the quick brown fox jumps over the lazy dog";
    const char *pattern = "the";
    const char *replacement = "a";

    char *newstr = replaceSubstring(str, pattern, replacement);

    if (newstr != NULL) {
        printf("Original string: %s\n", str);
        printf("Replaced string: %s\n", newstr);
        free(newstr); // Remember to free the memory to avoid memory leaks
    }

    return 0;
}
