#include <stdio.h>
#include <string.h>
#include <assert.h>

void replaceindex(char *s, char *replace, unsigned int start, unsigned int end) {
    size_t len = strlen(s);
    size_t replace_len = strlen(replace);
    char temp[256] = {0}; // Assuming the string won't exceed 256 bytes.
    assert(start < end);
    assert(end <= len);

    // Copy the initial part before 'start'.
    strncpy(temp, s, start);

    // Append the replacement string.
    strcat(temp, replace);

    // Append the rest of the original string after 'end'.
    strcat(temp, s + end + 1);

    // Now, copy the modified string back into the original.
    strcpy(s, temp);
}

int main() {
    char str[] = "([10 20]...[10 20]..[30 80])";
    printf("Before: %s\n", str);
    replaceindex(str, "50", 1, 7); // Indices are based on your definition (0-based).
    printf("After: %s\n", str);
    
    return 0;
}
