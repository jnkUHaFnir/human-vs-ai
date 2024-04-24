#include <stdio.h>
#include <string.h>

int main() {
    char cAFirst[25];
    int uc = 0, lc = 0;

    if (fgets(cAFirst, 25, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; // Exit if reading input fails
    }

    // Now, iterate until the null terminator is encountered
    for (size_t i = 0; cAFirst[i] != '\0' && i < 25; i++) {
        if (cAFirst[i] >= 'A' && cAFirst[i] <= 'Z') {
            uc++;
        }
        if (cAFirst[i] >= 'a' && cAFirst[i] <= 'z') {
            lc++;
        }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
