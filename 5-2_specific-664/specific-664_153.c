#include <stdio.h>
#include <string.h>

// Global variables for hour and minute
int hour = 0;
int minute = 0;

void processString(const char *input) {
    const char *prefix = "?cmd=ASET";
    
    // Check if the input string starts with the prefix
    if (strncmp(input, prefix, strlen(prefix)) == 0) {
        // Find the positions of hour and minute values
        const char *hourPtr = input + strlen(prefix);
        const char *minutePtr = strchr(hourPtr, '&');
        
        if (minutePtr != NULL) {
            // Extract hour value
            char hourStr[3];
            strncpy(hourStr, hourPtr, 2);
            hourStr[2] = '\0';
            hour = atoi(hourStr);
            
            // Extract minute value
            char minuteStr[3];
            strncpy(minuteStr, minutePtr + 1, 2);
            minuteStr[2] = '\0';
            minute = atoi(minuteStr);
        }
    }
}

int main() {
    const char *input = "?cmd=ASET&08&30";
    
    processString(input);
    
    printf("Hour: %d, Minute: %d\n", hour, minute);
    
    return 0;
}
