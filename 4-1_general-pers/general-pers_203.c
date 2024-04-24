#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trim.h"

extern char **words;
extern int number_of_words;

void append(char *string, char ch) {
    size_t size = strlen(string);
    string[size] = ch;
    string[size + 1] = '\0';
}

void read_file(char *file_name, int file_number) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[2048];
    char word[64];

    while (fgets(line, sizeof line, file) != NULL) {
        size_t i = 0;
        while (i < strlen(line) && line[i] != '\n') {
            if (line[i] != ' ') {
                append(word, line[i]);
            } else {
                if (strlen(word) > 1) {
                    trim(word);

                    int exists = 0;
                    for (int a = 0; a < number_of_words; a++) {
                        if (strcmp(words[a], word) == 0) {
                            exists = 1;
                            break;
                        }
                    }

                    if (!exists) {
                        char **temp = realloc(words, sizeof(char *) * (number_of_words + 1));
                        if (temp == NULL) {
                            perror("realloc");
                            exit(EXIT_FAILURE);
                        }
                        words = temp;

                        words[number_of_words] = malloc(strlen(word) + 1);
                        strcpy(words[number_of_words], word);
                        number_of_words++;
                    }

                    printf("%s\n", word);
                    memset(word, 0, sizeof(word));
                }
            }
            i++;
        }
    }
    fclose(file);
}
