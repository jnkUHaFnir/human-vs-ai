#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STR_LEN 1000

void read_line(char *str, int n);
void pass_check(const char *str);
void extract(const char *s1, char *s2);

int main(void) {
    char instr[STR_LEN + 1];
    char outstr[STR_LEN + 1] = ""; // Initialize to empty string

    printf("Please enter a URL: ");
    read_line(instr, STR_LEN);
    extract(instr, outstr);

    if(strlen(outstr) > 0) { // Check if outstr has been updated with an address
        pass_check(outstr);
    } else {
        printf("Web address starting with www. and ending with .edu not found\n");
    }

    return 0;
}

void extract(const char *s1, char *s2) {
    const char *p = strstr(s1, "www."); // Use strstr to find the first occurrence of "www."

    if (p) { // Ensure "www." is found in the string
        while (*p != '\0' && *p != '/') {
            *s2++ = *p++;
        }
        *s2 = '\0'; // Null-terminate the copied string
    }
}

void read_line(char *str, int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = (char)ch;
        }
    }
    str[i] = '\0'; // Ensure input is null-terminated
}

void pass_check(const char *str) {
    // Check directly if str starts with "www." and ends with ".edu"
    if (strncmp(str, "www.", 4) == 0 && strcmp(str + strlen(str) - 4, ".edu") == 0) {
        printf("Output: %s\n", str);
    } else {
        printf("Web address starting with www. and ending with .edu not found\n");
    }
}
