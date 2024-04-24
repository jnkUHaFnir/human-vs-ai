#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRIMSPACES(p) while(*p != '\0' && isspace((unsigned char)*p) != 0) ++p
#define NSTRIP(p, n) p += n
#define STRIP(p) ++p

char *getcode(const char *input)
{
    char *p = (char *)input, *buf, *pbuf;

    if ((buf = malloc(256)) == NULL)
        return NULL;

    pbuf = buf;
    while (*p != '\0')
    {
        if (strncmp(p, "CODE", 4) == 0)
        {
            NSTRIP(p, 4); // remove 'code'
            TRIMSPACES(p); // trim white-space after 'code'

            if (*p != '=')
                return NULL;

            STRIP(p); // remove '='
            TRIMSPACES(p); // trim white-spaces after '='

            while (*p != '\0' && *p != '-')
                *pbuf++ = *p++;

            break;
        }
        p++;
    }

    *pbuf++ = '\0';

    return buf;
}

int main()
{
    char buf[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char *code = getcode(buf);
    printf("Found code: %s\n", code);
    free(code);
    return 0;
}
