#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    size_t length = strlen(cAFirst);
    for (size_t i = 0; i < length; i++) {
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
