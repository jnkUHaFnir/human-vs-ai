#include <stdio.h>
#include <string.h> // For strcmp
char names[50][32]; // Array of strings to store up to 50 names, each up to 31 characters long (+ null terminator)
char states[50][3]; // Array of strings to store up to 50 state codes, each 2 characters long (+ null terminator)
int i = 0;
while (i < b) {
    if (strcmp(states[i], "tx") == 0) {
        printf("a string %s\n", names[i]);
    }
    i = i + 1;
}
