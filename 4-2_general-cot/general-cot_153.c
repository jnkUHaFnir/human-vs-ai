#include <stdio.h>
#include <string.h>

int hour;
int minute;

void parseString(const char *input) {
    // Check if the string starts with "?cmd=ASET"
    if (strncmp(input, "?cmd=ASET", 10) == 0) {
        char *token = strtok((char*)input + 10, "&"); // Skip the initial part of the string

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
    const char *input = "?cmd=ASET&08&30";
    parseString(input);

    printf("Hour: %d, Minute: %d\n", hour, minute);

    return 0;
}
