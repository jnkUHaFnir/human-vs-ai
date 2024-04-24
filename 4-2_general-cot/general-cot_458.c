#include <stdio.h>
#include <assert.h>

void replaceindex(char *s, const char *replace, unsigned int start, unsigned int end) {
    assert(start < end);

    char *p = s, *q = s;
    unsigned int i = 0;
    int found = 0;

    while (*q) {

        if (found == 0 && i == start) {
            found = 1;

            while (*replace) {
                *p++ = *replace++;
            }

            // Increment q by the difference if the new string is shorter
            while (++start < end) {
                q++;
            }
        }

        *p++ = *q++;
        i++;
    }

    *p = '\0'; // Add null terminator at the end of the modified string
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
