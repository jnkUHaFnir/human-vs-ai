#include <stdio.h>
#include <string.h>

char* proc(char *inStr) {
    const char tar[] = ":";
    char *first_position_ptr = strchr(inStr, tar[0]);
    char *last_position_ptr = strrchr(inStr, tar[0]);

    int first_position = (first_position_ptr == NULL ? -1 : first_position_ptr - inStr);
    int last_position = (last_position_ptr == NULL ? -1 : last_position_ptr - inStr);

    if (first_position != -1 && last_position != -1) {
        inStr[first_position + 2] = '*';
    }

    for (int i = first_position; i < (last_position + 1); i++) {
        inStr[i] = 0;
    }
    return inStr;
}

int main() {
    char str[] = "Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected";
    printf("%s\n", str);
    proc(str);
    printf("%s\n", str);
    return 0;
}
Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected
Found new device with wlan *. Total 4 devices connected
