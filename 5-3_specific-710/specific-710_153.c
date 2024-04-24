#include <stdio.h>
#include <string.h>

int hour, minute;

void updateGlobalVariables(const char *inputString) {
    // Check if the input string starts with "?cmd=ASET"
    if (strncmp(inputString, "?cmd=ASET", 9) == 0) {
        // Parse the hour and minute values from the inputString
        if (sscanf(inputString, "?cmd=ASET&%d&%d", &hour, &minute) == 2) {
            printf("Hour: %d\n", hour);
            printf("Minute: %d\n", minute);
        } else {
            printf("Invalid format for hour and minute values\n");
        }
    } else {
        printf("String does not start with \"?cmd=ASET\"\n");
    }
}

int main() {
    // Example input string
    const char *input = "?cmd=ASET&08&30";
    
    // Update global variables hour and minute based on the input string
    updateGlobalVariables(input);

    return 0;
}
