#include <stdio.h>
#include <string.h>

#define STR_LEN 1000

void read_line(char *str, int n);
void extract(char *s1, char *s2);
void pass_check(char *str);

int main(void) {
    char instr[STR_LEN + 1];
    char outstr[STR_LEN + 1];

    printf("Please enter a URL: ");
    read_line(instr, STR_LEN);
    extract(instr, outstr);

    pass_check(outstr);

    return 0;
}

void extract(char *s1, char *s2) {
    char *p, *q;
    q = s2;
    for (p = s1; *p != 0 && (*p != 'w' || *(p + 1) != 'w' || *(p + 2) != 'w' || *(p + 3) != '.'); p++)
        ;

    if (*p == 0) {
        strcpy(s2, "Web address starting with www. not found");
        return;
    }

    for (; *p != 0 && (*p != 'e' || *(p + 1) != 'd' || *(p + 2) != 'u'); p++)
        ;

    if (*p == 0) {
        strcpy(s2, "Web address ending with .edu not found");
        return;
    }

    while (*p != 0 && *p != '/') {
        *q++ = *p++;
    }
    *q = '\0';
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
    printf("Output: ");
    if (strstr(str, "www.") != NULL && strstr(str, ".edu") != NULL) {
        puts(str);
    } else {
        printf("Web address starting with www. and ending with .edu not found\n");
    }
}
