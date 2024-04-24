#include <stdio.h>
#include <assert.h>

void replaceindex(char *s, char *replace, unsigned int start, unsigned int end)
{
    assert(start < end);

    char *p = s, *q = s, *r = replace; // pointers to input, output, and replacement strings
    int found = 0; // flag to track if start index is found

    for (unsigned int i = 0; *q; ++i, ++q) {
        if (!found && i == start) {
            found = 1;

            for (; *r; ++r, ++p) {
                *p = *r;
            }

            // Reset r to the beginning of the replace string
            r = replace;

            while (++i < end) {
                ++q; // increment q to skip characters
            }
        }

        *p = *q;
        p++;
    }

    *p = '\0'; // null-terminate the output string
}

int main()
{
    char str[] = "([10 20]...[10 20]..[30 80])";
    printf("Before: %s\n", str);
    replaceindex(str, "50", 1, 7);
    printf("After: %s\n", str);

    return 0;
}
