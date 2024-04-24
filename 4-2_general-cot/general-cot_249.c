#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* get boundary */
char* getBoundary(char str[]){
    int i = 0;
    char c;
    str = (char*) malloc(1); // Allocate initial memory

    while ((c = getchar()) != '\n') {
        str = (char*) realloc(str, i + 2); // Increase memory size by 1 each time
        str[i++] = c;
    }

    str[i] = '\0';

    return str;
}

/* check for valid string */
int checkStr(const char *check) {
    size_t len = strlen(check);

    for (size_t i = 0; i < len; i++) {
        if (isalpha(check[i])) {
            printf("Invalid integer format!!!\n");
            return 0;
        }
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
            case 'n':
            case 'N':
                return (ans == 'y' || ans == 'Y') ? 1 : 0;
            default:
                printf("Invalid answer!!! Answer 'y' and 'Y' or 'n' and 'N' only\n");
                while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
        }
    } while (1);
}

/* Main */
int main(void) {
    char *l_boundRow = NULL;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow) && doAgain())
            continue;
        else
            break;
    } while (1);

    free(l_boundRow);
    return 0;
}
