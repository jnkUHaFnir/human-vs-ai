#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isupper and islower functions

int main()
{
    char cAFirst[25];
    int uc =0 ,lc =0;

    fgets(cAFirst, sizeof(cAFirst), stdin);

    // Calculate the actual length of the input without the newline character added by fgets
    size_t length = strlen(cAFirst);
    if (cAFirst[length - 1] == '\n') {
        cAFirst[length - 1] = '\0';
        length--;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (isupper(cAFirst[i])) {
            uc++;
        }
        if (islower(cAFirst[i])) {
            lc++;
        }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
