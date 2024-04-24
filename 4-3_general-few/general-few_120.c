#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, sizeof(cAFirst), stdin);

    for (size_t i = 0; cAFirst[i] != '\0'; i++) {
        int k = (int)cAFirst[i];
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
