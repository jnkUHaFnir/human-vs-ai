#include <stdio.h>
#include <string.h>

void obfuscateSubstring(char *inStr) {
    const char *tar = ":";
    char *start = strstr(inStr, tar) + 2;
    char *end = strstr(inStr, tar) + 17; // substring length is 17 characters

    while (start < end) {
        if (*start != ' ')
            *start = '*';
        start++;
    }
}

int main() {
    char str[] = "Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected";
    
    obfuscateSubstring(str);
    
    printf("%s\n", str);
    return 0;
}
