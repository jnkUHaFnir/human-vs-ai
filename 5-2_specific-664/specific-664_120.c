#include <stdio.h>

int main() {
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    for (size_t i = 0; i < 25 && cAFirst[i] != '\0'; i++) {
        char currentChar = cAFirst[i];
        if (currentChar >= 'A' && currentChar <= 'Z') {
            uc++;
        } else if (currentChar >= 'a' && currentChar <= 'z') {
            lc++;
        }
    }

    printf("Uppercase Letters=%i\nLowercase Letters=%i\n", uc, lc);

    return 0;
}
