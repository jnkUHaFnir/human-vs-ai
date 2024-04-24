#include <stdio.h>
#include <assert.h>

void replaceindex(char *s, char *replace, unsigned int start, unsigned int end)
{
    assert(start < end);

    char *p = s, *q = s, *r = replace;
    register unsigned int i = 0;
    int found = 0;

    while (*q)
    {

        if (found == 0 && i == start)
        {

            found = 1;

            int replace_len = 0;
            for (; *r; ++r, ++replace_len)
            {
                *p++ = *r;
            }

            while (--replace_len < end - start)
            {
                q++;
            }
        }

        *p++ = *q++;
        i++;
    }

    *p = '\0'; // Don't forget to add null terminator at the end of the string
}

int main()
{
    char str[] = "([10 20]...[10 20]..[30 80])";
    printf("Before: %s\n", str);
    replaceindex(str, "50", 1, 7);
    printf("After: %s\n", str);

    return 0;
}
Before: ([10 20]...[10 20]..[30 80])
After: (50...[10 20]..[30 80])
