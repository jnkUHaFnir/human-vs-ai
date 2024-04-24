// This program extracts the text from a website URL
#include <stdio.h>
#include <string.h>
#define STR_LEN 1000

void read_line(char *str, int n);
void find_www_edu_url(char *str);

int main(void)
{
    char instr[STR_LEN + 1];

    printf("Please enter a URL: ");
    read_line(instr, STR_LEN);
    find_www_edu_url(instr);

    return 0;
}

void read_line(char *str, int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && i < n) {
        str[i++] = ch;
    }
    str[i] = '\0';
}

void find_www_edu_url(char *str) {
    const char *prefix = "www.";
    const char *suffix = ".edu";

    // Check if the URL starts with "www."
    char *start = strstr(str, prefix);
    if (start == NULL) {
        printf("Web address starting with www. and ending with .edu not found\n");
        return;
    }

    // Find the end of the domain, which should end with ".edu"
    char *end = strstr(start, suffix);
    if (end == NULL || *(end + strlen(suffix)) != '\0' && *(end + strlen(suffix)) != '/') {
        printf("Web address starting with www. and ending with .edu not found\n");
        return;
    } else {
        end += strlen(suffix); // Move to the end of ".edu"
        // Terminate the string at the end of ".edu"
        *end = '\0';
        printf("%s\n", start);
    }
}
