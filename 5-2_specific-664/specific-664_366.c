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
    char *p = strstr(s1, "www."); // find "www." in the input string
    if (p == NULL) {
        strcpy(s2, "Web address starting with 'www.' not found");
        return;
    }
    
    p += 4; // move to the start of domain
    char *q = strstr(p, ".edu"); // find ".edu" in the domain
    if (q == NULL) {
        strcpy(s2, "Web address ending with '.edu' not found");
        return;
    }
    
    *q = '\0'; // terminate the string at the end of the domain
    strcpy(s2, p); // copy the domain to the output string
}

void read_line(char *str, int n) {
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n) {
            *str++ = (char)ch;
            i++;
        }
    }
    *str = '\0';
}

void pass_check(char *str) {
    printf("Output: %s\n", str);
}
