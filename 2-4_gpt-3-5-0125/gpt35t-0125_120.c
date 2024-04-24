#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    // Find the length of the input string
    size_t length = strlen(cAFirst);

    for (size_t i = 0; i < length; i++) {
        char ch = cAFirst[i];

        if (ch >= 'A' && ch <= 'Z') {
            uc++;
        }
        if (ch >= 'a' && ch <= 'z') {
            lc++;
        }
    }

    printf("Uppercase Letters=%d\nLowercase Letters=%d\n", uc, lc);

    return 0;
}
