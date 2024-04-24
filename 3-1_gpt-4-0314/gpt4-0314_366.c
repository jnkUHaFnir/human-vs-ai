#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STR_LEN 1000

void read_line(char *str, int n);
void pass_check(char *str);
void extract(char *s1, char *s2);

int main(void)
{
    char instr[STR_LEN + 1];
    char outstr[STR_LEN + 1];

    printf("Please enter a URL: ");
    read_line(instr, STR_LEN);
    extract(instr, outstr);

    pass_check(outstr);

    return 0;
}

void extract(char *s1, char *s2) {
    char *start = strstr(s1, "www.");

    if (!start)
    {
        strcpy(s2, ""); // Set outstr to empty if "www." not found
        return;
    }

    char *p, *q;
    q = s2;
    for (p = start; *p != 0; p++) {
        if (*p == '/')
            break;
        else {
            *q = *p;
            q++;
        }
    }
    *q = '\0';
    *p = '\0';
}

void read_line(char *str, int n) {
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            *str++ = ch;
            i++;
        }
    }
    *str = '\0';
}

void pass_check(char *str) {
    if (strlen(str) == 0)
    {
        printf("Web address starting with www. and ending with .edu not found\n");
        return;
    }

    const char *fref = "www";
    const char *lref = "edu";

    int len = strlen(str);

    char *l = &str[len - 3];
    char f[STR_LEN + 1];

    strncpy(f, str, 3);
    f[3] = '\0';

    if ((strcmp(f, fref) == 0) && strcmp(l, lref) == 0) {
        printf("Output: %s\n", str);
    } else
        printf("Web address starting with www. and ending with .edu not found\n");
}
