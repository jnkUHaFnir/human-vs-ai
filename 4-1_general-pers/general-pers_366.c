#include <stdio.h>
#include <string.h>

#define STR_LEN 1000

void read_line(char *str, int n);
void extract(const char *s1, char *s2);
int pass_check(const char *str);

int main() {
    char instr[STR_LEN + 1];
    char outstr[STR_LEN + 1];

    printf("Please enter a URL: ");
    read_line(instr, STR_LEN);
    extract(instr, outstr);

    int result = pass_check(outstr);

    if (result == 1) {
        printf("Output: %s\n", outstr);
    } else {
        printf("Web address starting with www. and ending with .edu not found\n");
    }

    return 0;
}

void extract(const char *s1, char *s2) {
    const char *start = "www.";
    const char *end = ".edu";

    const char *ptr_start = strstr(s1, start);
    const char *ptr_end = strstr(s1, end);

    if (ptr_start != NULL && ptr_end != NULL) {
        strncpy(s2, ptr_start, ptr_end + strlen(end) - ptr_start);
        s2[ptr_end + strlen(end) - ptr_start] = '\0';
    } else {
        strcpy(s2, "");
    }
}

void read_line(char *str, int n) {
    fgets(str, n, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input
}

int pass_check(const char *str) {
    const char *fref = "www";
    const char *lref = "edu";

    if (strlen(str) < 7) {
        return 0; // Address length is not enough for a valid URL
    }

    if (strncmp(str, fref, 3) == 0 && strcmp(str + strlen(str) - 3, lref) == 0) {
        return 1; // Address starts with www. and ends with .edu
    } else {
        return 0; // Incorrect or incomplete address
    }
}
