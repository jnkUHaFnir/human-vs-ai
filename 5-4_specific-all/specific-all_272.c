#include <stdio.h>
#include <string.h>

// Assuming 'b' is the number of elements in the arrays
#define MAX_SIZE 50
#define MAX_LENGTH 32

int main() {
    char names[MAX_SIZE][MAX_LENGTH];
    char states[MAX_SIZE][2];
    int i;

    // Assuming you have populated your arrays 'names' and 'states' with user input

    for (i = 0; i < b; i++) {
        // Using strcmp to compare strings, '=' is for assignment
        if (strcmp(states[i], "tx") == 0) {
            printf("Name: %s, State: %s\n", names[i], states[i]);
        }
    }

    return 0;
}
