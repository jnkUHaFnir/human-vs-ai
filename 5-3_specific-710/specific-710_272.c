#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

int main() {
    char names[MAX_SIZE][32];
    char states[MAX_SIZE][3]; // Increase size to allow for "tx" and null terminator

    int b;
    printf("Enter the number of entries: ");
    scanf("%d", &b);

    // Reading input data
    for (int i = 0; i < b; i++) {
        printf("Enter name %d: ", i+1);
        scanf("%s", names[i]);
        printf("Enter state (2 characters) for %s: ", names[i]);
        scanf("%s", states[i]);
    }

    // Print names of people living in "tx"
    for (int i = 0; i < b; i++) {
        if (strcmp(states[i], "tx") == 0) { // Use strcmp for comparing strings
            printf("%s lives in Texas.\n", names[i]);
        }
    }

    return 0;
}
