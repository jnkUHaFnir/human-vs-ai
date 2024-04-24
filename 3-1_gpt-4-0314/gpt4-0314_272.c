#include <stdio.h>
#include <string.h>

int main()
{
    char names[50][32];
    char states[50][3]; // Changed to 3 to accommodate the null-terminating character
    int b = ...; // Set the value for b, number of times the program will loop

    // Fill names and states arrays here

    for (int i = 0; i < b; i++) {
        if (strcmp(states[i], "tx") == 0) {
            printf("a string %s\n", names[i]);
        }
    }

    return 0;
}
