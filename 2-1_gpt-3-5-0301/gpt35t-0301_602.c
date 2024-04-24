#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_NUM_WORDS 100

int main() {
    char input[MAX_INPUT_SIZE];
    char *words[MAX_NUM_WORDS];
    int num_words = 0;

    // Read input lines
    while (fgets(input, MAX_INPUT_SIZE, stdin) != NULL) {
        // Split input into words
        char *token = strtok(input, " \n");
        while (token != NULL && num_words < MAX_NUM_WORDS) {
            // Dynamically allocate memory for each word and store pointer in words array
            words[num_words] = malloc((strlen(token) + 1) * sizeof(char));
            if (words[num_words] == NULL) {
                printf("Error: unable to allocate memory\n");
                exit(1);
            }
            strcpy(words[num_words], token);
            num_words++;

            token = strtok(NULL, " \n");
        }
    }

    // Print words
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
        free(words[i]); // Free dynamically allocated memory
    }

    return 0;
}
