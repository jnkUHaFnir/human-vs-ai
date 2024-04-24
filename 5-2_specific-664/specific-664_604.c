#include <stdio.h>
#include <string.h>

void findAndReplace(char *str, const char *find, const char *replace) {
    int find_len = strlen(find);
    int replace_len = strlen(replace);
    int str_len = strlen(str);

    char result[1000]; // Assuming maximum string length of 1000, you may need to adjust this if needed
    char *ins = str;
    char *tmp = result;
    while (1) {
        const char *p = strstr(ins, find);

        if (p == NULL) {
            strcpy(tmp, ins);
            break;
        }

        memcpy(tmp, ins, p - ins);
        tmp += p - ins;
        memcpy(tmp, replace, replace_len);
        tmp += replace_len;
        ins = p + find_len;
    }

    *tmp = '\0';

    strcpy(str, result);
}

int main() {
    char str[] = "This is a sample text with sample word to be replaced.";
    const char find[] = "sample";
    const char replace[] = "replaced";

    findAndReplace(str, find, replace);

    printf("Result: %s\n", str);

    return 0;
}
