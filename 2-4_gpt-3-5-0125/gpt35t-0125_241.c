#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 50
#define INCREMENT_SIZE 10

void get_line (char* filename) {
    char* text;
    int size = INIT_SIZE;
    int index = 0;
    FILE* file = fopen(filename,"r");

    text = malloc(sizeof(char) * INIT_SIZE);

    while (fgets(text + index, size - index, file) != NULL) {
        index += strlen(text + index);

        if (text[index - 1] == '\n' || text[index - 1] == EOF) {
            break;
        }
        
        if (index >= size - 1) {
            size += INCREMENT_SIZE;
            text = realloc(text, size);
        }
    }

    printf("The text was %s\n", text);

    free(text);
}

int main(int argc, char *argv[]) {
    get_line(argv[1]);
    return 0;
}
