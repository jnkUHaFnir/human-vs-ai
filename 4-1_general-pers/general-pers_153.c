#include <stdio.h>
#include <string.h>

// Global variables to store minute and hour values
int minute = 0;
int hour = 0;

void processString(const char* input) {
    const char* keyword = "?cmd=ASET";
    if (strncmp(input, keyword, strlen(keyword)) == 0) {
        // Find the hour and minute values in the input string
        const char* token = strtok((char*)input, "&");
        for (int i = 0; token != NULL; i++) {
            if (i == 1) {
                hour = atoi(token + strlen(keyword) + 1);
            } else if (i == 2) {
                minute = atoi(token);
            }
            token = strtok(NULL, "&");
        }
    }
}

int main() {
    const char* input = "?cmd=ASET&08&30";
    processString(input);

    // Print the values to verify
    printf("Hour: %d, Minute: %d\n", hour, minute);

    return 0;
}
