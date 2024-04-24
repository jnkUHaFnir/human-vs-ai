#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **words;
int number_of_words = 1;

void trim(char *word) {
    int length = strlen(word);
    while (length > 0 &&
           (word[length - 1] < '0' || word[length - 1] > '9') &&
           (word[length - 1] < 'A' || word[length - 1] > 'Z') &&
           (word[length - 1] < 'a' || word[length - 1] > 'z')) {
        word[length - 1] = '\0';
        length = strlen(word);
    }

    while (length > 0 &&
           (word[0] < '0' || word[0] > '9') &&
           (word[0] < 'A' || word[0] > 'Z') &&
           (word[0] < 'a' || word[0] > 'z')) {
        memmove(word, word + 1, strlen(word));
        length = strlen(word);
    }
}

void append(char *string, char ch) {
    int size = strlen(string);
    string[size] = ch;
    string[size + 1] = '\0';
}

void read_file(char *file_name, int file_number) {
    FILE *file = fopen(file_name, "r");
    char line[2048];
    char word[64];

    while (fgets(line, sizeof(line), file) != NULL) {
        int i = 0;
        while (line[i] != '\0') {
            if (line[i] != ' ' && line[i] != '\n') {
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
                        if (words[number_of_words] == NULL) {
                            perror("malloc");
                            exit(EXIT_FAILURE);
                        }

                        strcpy(words[number_of_words], word);
                        number_of_words++;
                    }

                    printf("%s\n", word);
                    memset(word, 0, strlen(word));
                }
            }
            i++;
        }
    }

    fclose(file);
}

int main() {
    words = malloc(10 * sizeof(char *));
    if (words == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    
    words[0] = malloc(strlen("the") + 1);
    if (words[0] == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    strcpy(words[0], "the");

    read_file("input.txt", 1);

    // Free dynamically allocated memory
    for (int i = 0; i < number_of_words; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
