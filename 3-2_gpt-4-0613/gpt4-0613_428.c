#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int k = 0,uc =0 ,lc =0 ;

    fgets(cAFirst,25,stdin); // get input

    size_t length = strlen(cAFirst);

    for (size_t i = 0; i < length; i++) { // run loop for the string length
        k = (int)cAFirst[i];
        if ((k <= 90) && (k >= 65)) {
            uc++;
        }
        if ((k >= 97) && (k <= 122)) {
            lc++;
        }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n",uc,lc );
    return 0;
}
