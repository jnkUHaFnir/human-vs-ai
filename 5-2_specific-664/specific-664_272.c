#include <stdio.h>
#include <string.h>

int main() {
    char names[50][32];
    char states[50][2];

    // Assume names and states arrays are properly filled

    int i = 0;
    while (i < 50) {
        if (strcmp(states[i], "tx") == 0) {
            printf("A string %s\n",  names[i]);
        }
        i = i + 1;
    }

    return 0;
}
