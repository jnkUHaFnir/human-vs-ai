#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables for hour and minute
int hour = 0;
int minute = 0;

void update_time_values(const char* input) {
    // Check if the string starts with "?cmd=ASET"
    if (strncmp(input, "?cmd=ASET", 10) == 0) {
        // Using strtok to extract hour and minute values
        char* token = strtok((char*)input + 10, "&");
        if (token != NULL) {
            hour = atoi(token);
            token = strtok(NULL, "&");
            if (token != NULL) {
                minute = atoi(token);
            }
        }
    }
}

int main() {
    const char* input = "?cmd=ASET&08&30";
    update_time_values(input);

    printf("Hour: %d, Minute: %d\n", hour, minute);

    return 0;
}
