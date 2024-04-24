#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 25

int main()
{
    char cAFirst[MAX_LENGTH];
    int uc = 0, lc = 0;

    fgets(cAFirst, MAX_LENGTH, stdin);

    size_t length = strlen(cAFirst);
    for (size_t i = 0; i < length; i++) {
        char currentChar = cAFirst[i];
        if (currentChar >= 'A' && currentChar <= 'Z') {
            uc++;
        } else if (currentChar >= 'a' && currentChar <= 'z') {
            lc++;
        }
    }

    printf("Uppercase Letters = %i\nLowercase Letters = %i\n", uc, lc);
    return 0;
}
