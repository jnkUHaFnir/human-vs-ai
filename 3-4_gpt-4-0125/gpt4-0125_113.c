#include <stdio.h>
#include <string.h>

// Modify to remove the MAC address and replace it with "*"
char* proc(char *inStr) {
    char *first_position_ptr = strchr(inStr, ':');
    char *last_position_ptr = strrchr(inStr, ':');

    if (first_position_ptr && last_position_ptr) {
        // Ensure there's a space before the MAC address
        if ((first_position_ptr != inStr) && (*(first_position_ptr - 1) == ' ')) {
            *(first_position_ptr - 1) = '*';
            // Delete everything from '*' to just before the last ':'
            for (char *p = first_position_ptr; p < last_position_ptr; p++) {
                *p = 0;
            }
        }
    }

    return inStr;
}

int main() {
    char str[] = "Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected";
    printf("%s\n", proc(str));
    return 0;
}
