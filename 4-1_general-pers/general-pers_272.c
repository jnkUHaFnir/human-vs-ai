#include <stdio.h>
#include <string.h>

int main() {
    char names[50][32];
    char states[50][2];
    int b, i;

    // Assuming b contains the number of elements
    // Input names and states
    for (i = 0; i < b; i++) {
        printf("Enter name: ");
        scanf("%s", names[i]);
        printf("Enter state (e.g., tx): ");
        scanf("%s", states[i]);
    }

    // Print names of people living in 'tx'
    for (i = 0; i < b; i++) {
        if (strcmp(states[i], "tx") == 0) {
            printf("Name: %s\n", names[i]);
        }
    }

    return 0;
}
