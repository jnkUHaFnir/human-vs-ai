#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    if (fgets(cAFirst, sizeof(cAFirst), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    size_t input_length = strlen(cAFirst);
    // Remove newline character from input if it exists
    if (input_length > 0 && cAFirst[input_length - 1] == '\n') {
        cAFirst[input_length - 1] = '\0';
    }

    for (size_t i = 0; i < input_length; i++) {
        if (cAFirst[i] >= 'A' && cAFirst[i] <= 'Z') {
            uc++;
        } else if (cAFirst[i] >= 'a' && cAFirst[i] <= 'z') {
            lc++;
        }
    }

    printf("Uppercase Letters = %i\nLowercase Letters = %i\n", uc, lc);

    return 0;
}
