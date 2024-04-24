#include <stdio.h>
#include <assert.h>

void replaceindex(char *s, const char *replace, unsigned int start, unsigned int end) {
    assert(start < end);

    char *p = s, *q = s, *r = replace;
    unsigned int i = 0;
    int found = 0;
    int replaceLen = 0;

    while (*replace != '\0') {
        replaceLen++;
        replace++;
    }

    replace -= replaceLen;

    while (*q) {
        if (found == 0 && i == start) {
            found = 1;

            while (*r) {
                *p++ = *r++;
            }

            if (replaceLen < (end - start)) {
                q += (end - start);
            } else {
                q += replaceLen;
            }
        }

        *p++ = *q++;
        i++;
    }

    *p = '\0';
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
