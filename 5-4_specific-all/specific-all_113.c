#include <stdio.h>
#include <string.h>

void proc(char *inStr) {
    const char tar[] = ":";
    char *first_position_ptr = strchr(inStr, tar[0]);
    char *last_position_ptr = strrchr(inStr, tar[0]);

    if (first_position_ptr != NULL && last_position_ptr != NULL) {
        int first_position = first_position_ptr - inStr;
        int last_position = last_position_ptr - inStr;

        inStr[first_position + 2] = '*';
        
        for (int i = first_position + 1; i < last_position; i++) {
            inStr[i] = '*';
        }
    }
}

int main() {
    char str[] = "Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected";
    proc(str);
    printf("%s\n", str);
    return 0;
}
