#include <stdio.h>
#include <string.h>

int main() {
    char input[] = "?cmd=ASET&08&30";
    char cmd[] = "?cmd=ASET";
    int hour, minute;

    if (strstr(input, cmd) == input) {
        if (sscanf(input, "?cmd=ASET&%d&%d", &hour, &minute) == 2) {
            printf("Hour: %d, Minute: %d\n", hour, minute);
            // Assign hour and minute to global variables here
        } else {
            printf("Invalid format\n");
        }
    } else {
        printf("String does not start with '?cmd=ASET'\n");
    }

    return 0;
}
