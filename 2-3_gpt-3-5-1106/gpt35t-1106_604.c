#include <stdio.h>
#include <string.h>

void findAndReplace(char *s, const char *find, const char *replace) {
    int find_len = strlen(find);
    int replace_len = strlen(replace);
    char *found = strstr(s, find);

    while (found) {
        memmove(found + replace_len, found + find_len, strlen(found + find_len) + 1);
        memcpy(found, replace, replace_len);
        found = strstr(found + replace_len, find);
    }
}

int main() {
    char s[] = "This is a test string with test";
    const char *find = "test";
    const char *replace = "replacement";
    
    findAndReplace(s, find, replace);

    printf("%s\n", s); // Output: "This is a replacement string with replacement"
    
    return 0;
}
