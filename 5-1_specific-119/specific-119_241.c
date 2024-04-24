#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50
#define INCREMENT 10

void get_line(char *filename) {
    char *text = NULL;
    size_t text_size = INIT_SIZE;
    size_t pos = 0;
  
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
  
    text = malloc(sizeof(char) * text_size);
    if (!text) {
        printf("Memory allocation failed.\n");
        return;
    }

    while (fgets(text + pos, text_size - pos, file) != NULL) {
        pos += strlen(text + pos);
    
        if (text[pos - 1] == '\n' || feof(file)) {
            break;
        }

        char *new_text = realloc(text, text_size + INCREMENT);

        if (!new_text) {
            printf("Memory reallocation failed.\n");
            free(text);
            return;
        }

        text = new_text;
        text_size += INCREMENT;
    }

    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    get_line(argv[1]);
    return 0;
}
