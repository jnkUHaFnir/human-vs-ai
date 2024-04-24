#include<stdio.h>
#include<string.h>

void proc(char *inStr) {
    char *first_position_ptr = strchr(inStr, ':');
    char *last_position_ptr = strrchr(inStr, ':');

    int first_position = (first_position_ptr == NULL ? -1 : first_position_ptr - inStr);
    int last_position = (last_position_ptr == NULL ? -1 : last_position_ptr - inStr);

    if (first_position != -1 && last_position != -1) {
        inStr[first_position + 2] = '*';
    }

    for (int i = first_position + 1; i < last_position && i < strlen(inStr); i++) {
        inStr[i] = ' ';
    }
}

int main() {
    char str[] = "Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected";
    proc(str);
    printf("%s\n", str);
    return 0;
}
