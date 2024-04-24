#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STR_LEN 1000

void read_line(char *str, int n);
void extract(char *s1, char *s2);

int main(void) {
    char instr[STR_LEN + 1];
    char outstr[STR_LEN + 1];

    printf("Please enter a URL: ");
    read_line(instr, STR_LEN);
    extract(instr, outstr);

    return 0;
}

void extract(char *s1, char *s2) {
    char *p, *q;
    q = s2;

    // Skip until "www."
    p = strstr(s1, "www.");
    if (p == NULL) {
        printf("Web address starting with www. not found\n");
        return;
    }

    p += 4; // Move to the start of the domain
    while (*p != '\0' && *p != '/') {
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';

    // Check if the address ends with ".edu"
    if (strlen(s2) >= 4 && strcmp(s2 + strlen(s2) - 4, ".edu") == 0) {
        printf("Output: %s\n", s2);
    } else {
        printf("Web address starting with www. and ending with .edu not found\n");
    }
}

void read_line(char *str, int n) {
    fgets(str, n, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character
}
