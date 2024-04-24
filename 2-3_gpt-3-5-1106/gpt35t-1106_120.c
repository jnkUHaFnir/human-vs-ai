#include <stdio.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    for (int i = 0; cAFirst[i] != '\0'; i++) {
        if (cAFirst[i] >= 65 && cAFirst[i] <= 90) {
            uc++;
        }
        if (cAFirst[i] >= 97 && cAFirst[i] <= 122) {
            lc++;
        }
    }

    printf("Uppercase Letters = %i\nLowercase Letters = %i\n", uc, lc);
    return 0;
}
