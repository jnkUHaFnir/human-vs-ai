#include <stdio.h>

int main() {
    char names[50][32];
    char states[50][3];
    int b; // assuming b is declared and initialized in your code
    
    int i = 0;
    while (i < b) {
        if (strcmp(states[i], "tx") == 0) {
            printf("Name: %s\n", names[i]);
        }
        i = i + 1;
    }
    
    return 0;
}
