#include <stdio.h>
#include <string.h>

#define MAX_WORDS 30
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
    int line_count = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] == '.') { // Check if input is period to end
            break;
        }

        char* token = strtok(buffer, " \n");
        while (token != NULL) {
            int i = 0;
            while (i < entry_count) {
                if (strcmp(entries[i].word, token) == 0) {
                    entries[i].counter++;
                }
                i++;
            }
            token = strtok(NULL, " \n");
            line_count++;
        }
    }

    return line_count;
}

int main(int argc, char *argv[]) {
    // Sample usage
    WordCountEntry entries[MAX_WORDS] = {0};
    int entry_count = argc - 1; // Number of words to search for
    int i;

    for (i = 1; i < argc; i++) {
        strcpy(entries[i-1].word, argv[i]);
    }

    printf("Looking for %d words:\n", entry_count);

    for (i = 0; i < entry_count; i++) {
        printf("%s\n", entries[i].word);
    }

    printf("Input words (end with '.'):\n");

    int line_count = process_stream(entries, entry_count);

    printf("Result:\n");

    for (i = 0; i < entry_count; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].counter);
    }

    return 0;
}
