#include <stdio.h>
#include <string.h>

int main() {
    char names[50][32];
    char states[50][2];
    int b = 0; // Assuming b is defined somewhere in your code

    // Your loop to populate arrays
    // Assuming 'state[i]' contains 2-letter state codes like "tx" and 'names[i]' contains names
    int i = 0;
    while (i < b) {
        if (strcmp(states[i], "tx") == 0) {
            printf("Name: %s, State: %s\n", names[i], states[i]);
        }
        i++;
    }

    return 0;
}
