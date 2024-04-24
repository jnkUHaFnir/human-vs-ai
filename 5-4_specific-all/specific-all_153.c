#include <stdio.h>
#include <string.h>

// Global variables for hour and minute
int hour, minute;

void updateGlobalVariables(const char *input) {
    // Check if the input string starts with "?cmd=ASET"
    if (strncmp(input, "?cmd=ASET", strlen("?cmd=ASET")) == 0) {
        // Extract hour and minute values from the string
        if (sscanf(input, "?cmd=ASET&%2d&%2d", &hour, &minute) == 2) {
            printf("Hour: %02d\n", hour);
            printf("Minute: %02d\n", minute);
        } else {
            printf("Invalid format for hour and minute values.\n");
        }
    } else {
        printf("String does not start with \"?cmd=ASET\".\n");
    }
}

int main() {
    char input[] = "?cmd=ASET&08&30";
    updateGlobalVariables(input);

    return 0;
}
