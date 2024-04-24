#include <stdio.h>
#include <string.h>

const char *proc(char *inStr) {
    const char *tar = ":";
    char *first_position_ptr = strstr(inStr, tar);
    char *last_position_ptr = strrchr(inStr, tar[0]);

    if (first_position_ptr != NULL && last_position_ptr != NULL) {
        int first_position = first_position_ptr - inStr + 1;
        int last_position = last_position_ptr - inStr + 1;

        if (last_position > first_position) {
            inStr[first_position] = '*';
            for (int i = first_position + 1; i < last_position; i++) {
                inStr[i] = 0;
            }
        }
    }

    return inStr;
}

int main() {
    char str[] = "Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected";
    proc(str);
    printf("%s\n", str);
    return 0;
}
