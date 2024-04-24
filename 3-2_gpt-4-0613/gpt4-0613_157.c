#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst,25,stdin);

    for (size_t i = 0; cAFirst[i] != '\0'; i++) {  // iterate through the characters until null character
      if (cAFirst[i] >= 'A' && cAFirst[i] <= 'Z') {        // check if character is uppercase
          uc++;
      }
      if (cAFirst[i] >= 'a' && cAFirst[i] <= 'z') {        // check if character is lowercase
          lc++;
      }
    }

    printf("Uppercase Letters = %i \nLowercase Letters = %i \n",uc,lc );
    return 0;
}
