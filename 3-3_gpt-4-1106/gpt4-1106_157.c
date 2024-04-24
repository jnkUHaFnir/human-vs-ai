#include <stdio.h>
#include <ctype.h> // Include this for isupper and islower

int main() {
    char cAFirst[25];
    int uc = 0, lc = 0;

    // Ensure that the string is read properly.
    if (fgets(cAFirst, sizeof(cAFirst), stdin) != NULL) {
        // Iterate over each character until the end of the string.
        for (size_t i = 0; i < strlen(cAFirst); ++i) {
            // Use isupper/islower to check for uppercase/lowercase.
            if (isupper(cAFirst[i])) {
                uc++;
            } else if (islower(cAFirst[i])) {
                lc++;
            }
        }

        printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    }

    return 0;
}
cAFirst[strcspn(cAFirst, "\n")] = '\0';
