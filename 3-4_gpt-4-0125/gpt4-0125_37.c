#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;
    
    // Read input
    fgets(cAFirst, 25, stdin);
    
    // Remove newline character if present
    cAFirst[strcspn(cAFirst, "\n")] = '\0'; 

    // Calculate length of the actual string excluding '\0'
    size_t length = strlen(cAFirst);
    
    for (size_t i = 0; i < length; i++) {
      if (cAFirst[i] >= 'A' && cAFirst[i] <= 'Z') { // Check for uppercase
        uc++;
      } else if (cAFirst[i] >= 'a' && cAFirst[i] <= 'z') { // Check for lowercase
        lc++;
      }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
