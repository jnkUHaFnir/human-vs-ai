str = (char *) realloc(str, sizeof(char) + i);
str = (char *) realloc(str, (i + 1) * sizeof(char));
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Improved getBoundary to use fgets */
char* getBoundary(){
    char* str = malloc(1024); // Allocate a large buffer temporarily
    if(fgets(str, 1024, stdin) != NULL) {
        str = realloc(str, strlen(str)+1); // Adjust size to actual input
        return str;
    }
    
    free(str); // If fgets fails, cleanup and return NULL
    return NULL;
}

/* check for valid string */
int checkStr(const char *check)
{
    for (size_t i = 0; i < strlen(check); i++)
        if(isalpha(check[i]))
        {
            printf("Invalid integer formatt!!!\n");
            return 0;
        }
    return 1;
}

/* Improved doAgain */
int doAgain(void)
{
    char ans[3]; // Buffer to read the whole input line including newline

    do {
        printf("Do you want to try again? (y/n): ");
        fflush(stdout); // Ensure printf output is shown before fgets reads input
        if (fgets(ans, sizeof(ans), stdin) == NULL) return 0; // Handle error or EOF
        
        // Clear the input buffer if the answer was too long
        if (strchr(ans, '\n') == NULL) {
            while (getchar() != '\n'); // Read until the end of line
        }
        
        if (ans[0] == 'y' || ans[0] == 'Y') return 1;
        if (ans[0] == 'n' || ans[0] == 'N') return 0;
        
        printf("Invalid answer!!! answer 'y' and 'Y' or 'n' and 'N' only\n");
    } while (1);
}

int main(void)
{
    char *l_boundRow = NULL;

    do {
        printf("Enter lower bound row: ");
        free(l_boundRow); // Free the previously allocated memory if any
        l_boundRow  = getBoundary();

        // Allows to exit the loop if input is correct without asking to retry
        if (checkStr(l_boundRow)) break;

        // Asking only if input is incorrect.
    } while (!checkStr(l_boundRow) && doAgain());

    free(l_boundRow);
    return 0;
}
