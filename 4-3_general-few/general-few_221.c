#include <stdio.h>
#include <stdlib.h>

char * getString(void);

int main(void){
    char * str = NULL;

    printf("Write something:\n");
    str = getString();
    printf("You wrote:\n");
    printf("%s\n", str);
    free(str);

    return 0;
}

char * getString(void) {
    char * string = NULL;
    char ch;
    int length = 0;

    do {
        scanf("%c", &ch);
        if (length == 0) {
            string = (char *) malloc(sizeof(char));
        } else {
            string = (char *) realloc(string, (length + 1) * sizeof(char));
        }
        if (string == NULL) {
            printf("ERROR: memory could not be allocated!!\n");
            return NULL;
        }

        string[length] = ch;
        length++;
    } while (ch != '\n');

    string[length - 1] = '\0';
    return string;
}
