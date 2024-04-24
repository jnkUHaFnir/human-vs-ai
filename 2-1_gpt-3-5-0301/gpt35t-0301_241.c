#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 50
#define READ_SIZE 10

void get_line(char* filename) {
    char* text;
    int size = INIT_SIZE;
    int len = 0;

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    text = malloc(size * sizeof(char));
    if (!text) {
        printf("Error: could not allocate memory\n");
        fclose(file);
        return;
    }

    while (fgets(text + len, READ_SIZE, file)) {
        len += READ_SIZE - 1;

        if (text[len-1] == '\n') {
            // End of line found
            break;
        }

        // Reallocate more memory if necessary
        if (len + READ_SIZE > size) {
            size += INIT_SIZE;
            char* temp = realloc(text, size * sizeof(char));
            if (!temp) {
                printf("Error: could not reallocate memory\n");
                free(text);
                fclose(file);
                return;
            } else {
                text = temp;
            }
        }
    }

    // Trim the string to the actual length
    text[len-1] = '\0';

    printf("The text was \"%s\"\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
    } else {
        get_line(argv[1]);
    }
    return 0;
}
