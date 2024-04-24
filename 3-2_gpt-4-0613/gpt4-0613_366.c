#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STR_LEN 1000

void read_line(char *str, int n);
void check_and_extract(char *s1, char *s2);

int main(void)
{
    char instr[STR_LEN + 1];
    char outstr[STR_LEN + 1];

    printf("Please enter a URL: ");
    read_line(instr, STR_LEN);

    check_and_extract(instr, outstr);

    if (*outstr) {
        printf("Output: %s\n", outstr);
    } else {
        printf("Web address starting with www. and ending with .edu not found\n");
    }

    return 0;
}

void check_and_extract(char *s1, char *s2)
{
    const char *prefix1 = "http://www.";
    const char *prefix2 = "https://www.";
    int prefix_length = 0;

    if (strstr(s1, prefix1) == s1) {
        prefix_length = strlen(prefix1);
    } else if (strstr(s1, prefix2) == s1) {
        prefix_length = strlen(prefix2);
    } else {
        s2[0] = '\0';  //indicate no valid url found
        return;
    }

    const char *suffix = ".edu";
    size_t length = strlen(s1) - strlen(suffix);
  
    if (strstr(s1 + length, suffix) == s1 + length) {
        
        strncpy(s2, s1 + prefix_length, length - prefix_length);
        s2[length - prefix_length] = '\0';  // add null termination
    } else {
        s2[0] = '\0';  //indicate no valid url found
    }
}


void read_line(char *str, int n)
{
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
