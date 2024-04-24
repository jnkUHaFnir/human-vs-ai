#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Assume these are your global variables.
int hour = 0;
int minute = 0;

bool parse_time_command(const char* input) {
    // Check if the input string starts with the expected command.
    if (strncmp(input, "?cmd=ASET&", 10) == 0) {
        // Temp copy of the input because strtok modifies it.
        char temp[256];
        strncpy(temp, input + 10, 255); // Skip the "?cmd=ASET&" part
        temp[255] = '\0'; // ensure null-termination in case of extremely long input

        // Extract the hour.
        char *token = strtok(temp, "&");
        if (token != NULL) {
            hour = atoi(token); // Convert hour to integer.
            
            // Extract the minute.
            token = strtok(NULL, "&");
            if (token != NULL) {
                minute = atoi(token); // Convert minute to integer.
                // Success: found both hour and minute.
                return true;
            }
        }
    }
    // Command not found, or parsing failed.
    return false;
}

int main() {
    // Example usage:
    const char* testString = "?cmd=ASET&08&30";
    if (parse_time_command(testString)) {
        printf("Hour: %d, Minute: %d\n", hour, minute);
    } else {
        printf("Command parsing failed.\n");
    }

    return 0;
}
