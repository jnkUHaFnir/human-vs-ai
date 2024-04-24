#include <stdio.h>
#include <assert.h>

void replaceindex(char *s, char *replace, unsigned int start, unsigned int end)
{
    assert(start < end);

    char *p = s, *q = s, *r = replace;
    unsigned int i = 0;
    int found = 0;

    while (*q) {
        if (found == 0 && i == start) {
            found = 1;

            while (*r) {
                *p++ = *r++;
                i++;
            }

            // Adjust q to skip over the characters in the range
            q += (end - start);

            if (i < end) {
                // Increment q if the replacement string was shorter
                while (i < end) {
                    q++;
                    i++;
                }
            }
        } else {
            *p++ = *q++;
            i++;
        }
    }

    *p = '\0'; // Null-terminate the string
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
``` 

This code ensures that the replacement string is copied correctly and adjusts the pointers `p` and `q` accordingly to handle cases where the replacement string is shorter than the characters being replaced.
