#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    if (fgets(cAFirst, 25, stdin) != NULL) {
        size_t input_length = strnlen(cAFirst, 25);

        for (size_t i = 0; i < input_length; i++) {
            int k = (int)cAFirst[i];
            if ((k >= 'A') && (k <= 'Z')) {
                uc++;
            }
            if ((k >= 'a') && (k <= 'z')) {
                lc++;
            }
        }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    
    return 0;
}
