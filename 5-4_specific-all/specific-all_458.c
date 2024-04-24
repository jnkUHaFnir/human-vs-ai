#include <stdio.h>
#include <assert.h>

void replaceindex(char *s, char *replace, unsigned int start, unsigned int end) {
    assert(start < end);

    char *p = s, *q = s, *r = replace;
    unsigned int i = 0;
    int found = 0;
    int difference = strlen(replace) - (end - start) + 1; // Calculate the size difference

    while (*q) {
        if (!found && i == start) {
            found = 1;

            // Replace the substring
            while (*r) {
                *p++ = *r++;
            }

            // Adjust pointer based on size difference
            q += (end - start) < strlen(replace) ? difference : 0;
        }

        *p++ = *q++;
        i++;
    }

    *p = '\0'; // Add null terminator at the end
}

int main() {
    char str[] = "([10 20]...[10 20]..[30 80])";
    printf("Before: %s\n", str);
    replaceindex(str, "50", 1, 7);
    printf("After: %s\n", str);

    return 0;
}
Before: ([10 20]...[10 20]..[30 80])
After: (50...[10 20]..[30 80])
