#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getBoundary(char str[]) {
    int i;
    char c;

    str = (char*) malloc(sizeof(char));

    for (i = 0; (c = getchar()) != '\n'; i++) {
        str = (char*) realloc(str, sizeof(char) * (i + 1));
        str[i] = c;
    }

    str[i] = '\0';

    // Consume any remaining characters in the input buffer
    while ((c = getchar()) != '\n' && c != EOF);

    return str;
}

int checkStr(const char *check) {
    unsigned i;
    size_t len = strlen(check);

    for (i = 0; i < len; i++) {
        if (!isdigit(check[i])) {
            printf("Invalid integer format!!!\n");
            return 0;
        }
    }
    return 1;
}

int doAgain(void) {
    char ans, c;

    do {
        printf("Do you want to try again?: ");
        scanf(" %c", &ans);

        switch (ans) {
            case 'y':
            case 'Y':
                return 1;
            case 'n':
            case 'N':
                return 0;
            default:
                printf("Invalid answer! Please enter 'y' or 'Y' to try again, 'n' or 'N' to exit.\n");
                do {
                    c = getchar(); // Flush input buffer
                } while (c != '\n');
        }
    } while (1);
}

int main(void) {
    char *l_boundRow;
    l_boundRow = NULL;

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
