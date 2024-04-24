#include <stdio.h>
#include <string.h>

char names[50][32];
char states[50][2];
int b; // Assuming b is defined somewhere in your code

int main() {
    int i = 0;
    while (i < b) {
        if (strcmp(states[i], "tx") == 0) { // Compare strings using strcmp
            printf("Name: %s\n", names[i]);
        }
        i = i + 1;
    }

    return 0;
}
