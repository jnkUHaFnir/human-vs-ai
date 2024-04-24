#include <stdio.h>
#include <string.h>

void removeDup(char *string) {
    int i, c = 0;
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] != string[i + 1]) {
            string[c++] = string[i];
        }
    }
    string[c] = '\0'; // Null-terminate the modified string
}

int main() {
    char string[80]; // Declare string as an array of 80 characters
    fgets(string, sizeof(string), stdin); // Use fgets to allow spaces, it reads until newline or EOF
    string[strcspn(string, "\n")] = 0; // Remove the newline character added by fgets

    removeDup(string);
    puts(string); // Print the modified string
    return 0;
}
