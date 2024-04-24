#include <stdio.h>
#include <string.h>

// Global variables for hour and minute
int hour, minute;

void extractHourAndMinute(const char *input) {
    if (strncmp(input, "?cmd=ASET", 9) == 0) {
        // Skip the first 10 characters "?cmd=ASET&" to get to the hour and minute
        const char *timeStr = input + 10;
        
        // Extract the hour and minute using sscanf
        if (sscanf(timeStr, "%2d&%2d", &hour, &minute) == 2) {
            // Values extracted successfully
            printf("Hour: %02d\n", hour);
            printf("Minute: %02d\n", minute);
        } else {
            // Values not in the expected format
            printf("Invalid time format\n");
        }
    } else {
        // String doesn't start with "?cmd=ASET"
        printf("Invalid command\n");
    }
}

int main() {
    const char *input = "?cmd=ASET&08&30";
    extractHourAndMinute(input);

    return 0;
}
