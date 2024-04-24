#include <stdlib.h>
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

    printf("Output: ");
    pass_check(outstr);

    return 0;
}

void extract(char *s1, char *s2) {
    char *p, *q;
    p = strstr(s1, "www.");
    if (p == NULL) {
        strcpy(s2, "");
        return;
    }
    p += 4; // Move pointer 4 characters ahead to skip "www."

    q = strstr(p, ".edu");
    if (q == NULL) {
        strcpy(s2, "");
        return;
    }

    strncpy(s2, p, q - p + 4); // Copy the web address including "www." and ".edu"
    s2[q - p + 4] = '\0'; // Null-terminate the extracted string
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
    if (strlen(str) == 0) {
        printf("Web address starting with www. and ending with .edu not found\n");
        return;
    }

    if (strncmp(str, "www.", 4) == 0 && strncmp(str + strlen(str) - 4, ".edu", 4) == 0) {
        puts(str);
    } else {
        printf("Web address starting with www. and ending with .edu not found\n");
    }
}
