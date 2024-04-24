#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    // Getting the input string using fgets
    fgets(cAFirst, 25, stdin);
    
    // Initialize variable to store the length of the input string
    int length = strlen(cAFirst);
    
    // Removing newline character if it exists
    if (cAFirst[length - 1] == '\n') {
        cAFirst[length - 1] = '\0';
        length--; // Adjust the length since we no longer consider the newline
    }

    // Looping through the string until the null terminator
    for (int i = 0; i < length; i++) {
        if (cAFirst[i] >= 'A' && cAFirst[i] <= 'Z') {
            uc++;
        } else if (cAFirst[i] >= 'a' && cAFirst[i] <= 'z') {
            lc++;
        }
    }

    // Printing the result
    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
