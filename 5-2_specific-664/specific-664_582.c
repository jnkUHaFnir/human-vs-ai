#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* get boundary */
char* getBoundary(char str[]){
    int i;
    char c;

    str = (char*) malloc(sizeof(char));

    for (i = 0; (c = getchar()) != '\n'; i++) {
        str = (char *) realloc(str, sizeof(char) * (i+1));
        str[i] = c;
    }

    str[i] = '\0';
    return str;
}

/* check for valid string */
int checkStr(const char *check) {
    unsigned i;
    size_t len = strlen(check);

    for (i = 0; i < len; i++)
        if(isalpha(check[i])) {
            printf("Invalid integer formatt!!!");
            return 0;
        }
    return 1;
}

/* Ask if do again */
int doAgain(void) {
    char ans, c;

    do {
        printf("Do you want to try again?: ");
        scanf(" %c", &ans);

        switch (ans) {   
            case 'y':
            case 'Y':
                return 1; // Return 1 for yes
            case 'n':
            case 'N':
                return 0; // Return 0 for no
            default:
                printf("Invalid answer!!! Please enter 'y' or 'Y' for yes, 'n' or 'N' for no\n");
                do { /* flush input stream */
                    c = getchar();
                } while (c != '\n'); 
        }   
    } while (1);
}

/* Main */
int main(void) {
    char *l_boundRow;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow)) {
            if (doAgain()) {
                free(l_boundRow);
                continue; // Ask the user to try again
            } else {
                break; // Exit the loop if the user does not want to try again
            }
        } else {
            break; // Exit the loop if the input is valid
        }
    } while (1);

    free(l_boundRow);
    return 0;
}
