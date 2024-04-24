#include <stdio.h>
#include <string.h>

int main() {
    char cAFirst[25];
    int uc = 0, lc = 0;
    
    fgets(cAFirst, 25, stdin);

    for (size_t i = 0; i < 25 && cAFirst[i] != '\0'; i++) {
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
