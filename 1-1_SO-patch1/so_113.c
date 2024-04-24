c
#include <stdio.h>
#include <string.h>
//find the first occurence of ":" record as first_position_ptr and the last occurence of ":" record as last_position_ptr. 
// Add 2 to first_position_ptr to beginning of the substring and set it to `*`
// Subtract 2 from the last_position_ptr to get the pointer of the last character in substring. 
// Iterate from 1 + first_position_ptr to last_position_ptr - 2 and set inStr to 0 to deleted the rest of substring. 
char *proc(char *inStr) {
    char *p1 = strchr(inStr, ':');
    char *p2 = strrchr(inStr, ':');
    if (p1 && p2 && p2 - p1 > 4) {
        p1[2] = '*';
        memmove(p1 + 3, p2 - 2, strlen(p2 - 2) + 1);
    }
    return inStr;
}
int main() {
    char str[] = "Found new device with wlan 33:33:33:33:33:33. Total 4 devices connected";
    printf("%s\n", proc(str));
    return 0;
}