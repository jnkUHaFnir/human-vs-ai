#include <stdio.h>
#include <string.h>

void proc(char *inStr) {
    char *first_position_ptr = strchr(inStr, ':');
    char *last_position_ptr = strrchr(inStr, ':');

    if (first_position_ptr != NULL && last_position_ptr != NULL &&
        first_position_ptr < last_position_ptr) {
        // Replace MAC address with asterisk followed by spaces.
        *first_position_ptr++ = ' ';
        *first_position_ptr++ = '*';
        for (char *ptr = first_position_ptr; ptr <= last_position_ptr + 2; ptr++) {
            *ptr = ' ';
        }
    }
}

int main() {
    char str[] = "Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected";
    proc(str);
    printf("%s\n", str);
    return 0;
}
