#include <stdio.h>
#include <string.h>

int main() {
    char names[50][32];
    char states[50][2];
    int i, b;

    // Assume you have populated both names and states arrays

    for (i = 0; i < b; i++) {
        if (strcmp(states[i], "tx") == 0) {
            printf("Name: %s\n", names[i]);
        }
    }

    return 0;
}
