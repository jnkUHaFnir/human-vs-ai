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
        str = (char *) realloc(str, sizeof(char) * (i + 1));
        str[i] = c;
    }

    str[i] = '\0';
    return str;
}

/* check for valid string */
int checkStr(const char *check) {
    size_t len = strlen(check);

    for (size_t i = 0; i < len; i++) {
        if(isalpha(check[i])) {
            printf("Invalid integer format!\n");
            return 0;
        }
    }
    return 1;
}

/* Ask if do again */
int doAgain(void) {
    char ans, c;

    do {
        printf("Do you want to try again? (y/n): ");
        scanf(" %c", &ans);

        switch (ans) {
            case 'y':
            case 'Y':
                return 1;
            case 'n':
            case 'N':
                return 0;
            default:
                printf("Invalid answer! Enter 'y' or 'n' only\n");
                do {
                    c = getchar(); // flush input stream
                } while (c != '\n');
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
            continue;
        }
        else {
            break;
        }
    } while (1);

    free(l_boundRow);
    return 0;
}
