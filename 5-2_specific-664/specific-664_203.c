#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **words = NULL;
int number_of_words = 0;

void append(char *string, char ch) {
    size_t size = strlen(string);
    string[size] = ch;
    string[size + 1] = '\0';
}

void trim(char *word) {
    // Trim trailing special characters
    while (strlen(word) > 0 && (!isalpha(word[strlen(word) - 1]) && !isdigit(word[strlen(word) - 1]))) {
        word[strlen(word) - 1] = '\0';
    }

    // Trim leading special characters
    while (strlen(word) > 0 && (!isalpha(word[0]) && !isdigit(word[0]))) {
        memmove(word, word + 1, strlen(word));
    }
}

void read_file(char *file_name, int file_number) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[2048];
    char word[64];

    while (fgets(line, sizeof line, file) != NULL) {
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] != ' ') {
                append(word, line[i]);
            } else {
                if (strlen(word) > 1) {
                    trim(word);

                    int exists = 0;
                    for (int a = 0; a < number_of_words; a++) {
                        if (strcmp(words[a], word) == 0) {
                            exists = 1;
                            printf("%s\n", words[a]);
                            break;
                        }
                    }

                    if (!exists) {
                        printf("number of words: %i\n", number_of_words);
                        number_of_words++;
                        char **temp = realloc(words, sizeof(char *) * number_of_words);
                        if (temp == NULL) {
                            perror("realloc");
                            exit(EXIT_FAILURE);
                        }
                        words = temp;

                        words[number_of_words - 1] = malloc(strlen(word) + 1);
                        strcpy(words[number_of_words - 1], word);
                    }

                    printf("%s\n", word);
                    memset(word, 0, sizeof(word));
                }
            }
        }
    }

    fclose(file);
}

int main() {
    words = malloc(sizeof(char *));
    *words = malloc(strlen("the") + 1);
    strcpy(*words, "the");
    number_of_words = 1;

    read_file("file.txt", 1);

    // Free allocated memory
    for (int i = 0; i < number_of_words; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
