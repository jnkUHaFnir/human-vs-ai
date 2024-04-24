#include <stdio.h>
#include <string.h>

// Remove the obfuscating substring from the input string inStr.
// Returns the modified string.
char *proc(char *inStr) {
    char *first_position_ptr = strchr(inStr, ':');
    if (first_position_ptr != NULL) {
        first_position_ptr--; // Move back to the first digit
        char *last_position_ptr = strrchr(inStr, ':');
        if (last_position_ptr != NULL) {
            last_position_ptr += 3; // Move forward to the last digit

            // Overwrite the substring with '*' and shift the rest of the string
            *first_position_ptr = '*';
            memmove(first_position_ptr + 1, last_position_ptr + 1, strlen(last_position_ptr + 1) + 1);
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
