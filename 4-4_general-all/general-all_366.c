#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STR_LEN 1000

void read_line(char *str, int n);
void extract(char *instr, char *outstr);

int main(void)
{
    char instr[STR_LEN + 1];
    char outstr[STR_LEN + 1];

    printf("Please enter a URL: ");
    read_line(instr, STR_LEN);
    extract(instr, outstr);

    if (strlen(outstr) > 0) {
        printf("Output: %s\n", outstr);
    } else {
        printf("Web address starting with www. and ending with .edu not found\n");
    }

    return 0;
}

void extract(char *instr, char *outstr) {
    char *start = strstr(instr, "www.");
    if (start != NULL) {
        char *end = strstr(start, ".edu");
        if (end != NULL) {
            // Found "www." and ".edu"
            strncpy(outstr, start, end + 4 - start); // Include the ".edu"
            outstr[end + 4 - start] = '\0';
        }
    }
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
