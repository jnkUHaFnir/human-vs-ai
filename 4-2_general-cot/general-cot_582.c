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
        str = (char*) realloc(str, sizeof(char) * (i + 1));
        str[i] = c;
    }

    str[i] = '\0';
    return str;
}

/* check for valid string */
int checkStr(const char *check) {
    unsigned i;
    size_t len = strlen(check);

    for (i = 0; i < len; i++) {
        if(isalpha(check[i])) {
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

        while ((c = getchar()) != '\n' && c != EOF); // flush input stream

        if (ans == 'y' || ans == 'Y') {
            return 1;
        } else if (ans == 'n' || ans == 'N') {
            return 0;
        } else {
            printf("Invalid answer!!! Please enter 'y' or 'n'.\n");
        }
    } while (1);
}

/* Main */
int main(void) {
    char *l_boundRow = NULL;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow) && doAgain()) {
            free(l_boundRow);
            l_boundRow = NULL;
        } else {
            break;
        }
    } while (1);

    free(l_boundRow);
    return 0;
}
