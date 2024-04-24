#include <stdio.h>
#include <assert.h>

void replaceindex(char *s, const char *replace, unsigned int start, unsigned int end) {
    assert(s != NULL && replace != NULL && start < end);

    char *p = s, *q = s, *r = replace;
    unsigned int i = 0;
    int found = 0;

    while (*q) {
        if (found == 0 && i == start) {
            found = 1;

            // Calculate the difference between the length of the replacement string and the substring
            int diff = end - start;
            int replace_len = 0;
            for (const char *temp = replace; *temp; temp++, replace_len++);

            // Replace the substring
            for (; *r && replace_len > 0; r++, replace_len--, start++, q++) {
                *p++ = *r;
            }

            // Adjust the pointer position if the replacement string is shorter
            while (diff > 0) {
                q++;
                diff--;
            }
        }

        *p++ = *q++;
        i++;
    }

    *p = '\0'; // Add null terminator to the end of the modified string
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
