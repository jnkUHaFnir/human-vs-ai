#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    size_t length = strlen(cAFirst);
    for (size_t i = 0; i < length; i++) {
        char c = cAFirst[i];
        if (c >= 'A' && c <= 'Z') {
            uc++;
        }
        if (c >= 'a' && c <= 'z') {
            lc++;
        }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
