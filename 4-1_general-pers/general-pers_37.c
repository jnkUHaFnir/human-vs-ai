#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[26]; // Increase size by 1 to include space for null terminator
    int k = 0, uc = 0, lc = 0;

    // Read input and ensure null-termination
    if (fgets(cAFirst, sizeof(cAFirst), stdin) != NULL) {
        cAFirst[strcspn(cAFirst, "\n")] = '\0'; // Replace '\n' with '\0'
    } else {
        printf("Error reading input\n");
        return 1;
    }

    for (size_t i = 0; i < strlen(cAFirst); i++) {
        k = (int)cAFirst[i];
        if ((k <= 90) && (k >= 65)) {
            uc++;
        }
        if ((k >= 97) && (k <= 122)) {
            lc++;
        }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
