#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
    int line_count = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fgets(buffer, MAX_WORD_LENGTH, stdin)) {
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            for (int i = 0; i < entry_count; i++) {
                if (strcmp(entries[i].word, token) == 0) {
                    entries[i].counter++;
                }
            }
            line_count++;
            token = strtok(NULL, " \n");
        }
    }

    return line_count;
}

int main(int argc, char *argv[]) {
    WordCountEntry entries[MAX_WORDS];
    int entry_count = 0;

    // Process initial arguments
    for (int i = 1; i < argc; i++) {
        strncpy(entries[entry_count].word, argv[i], MAX_WORD_LENGTH-1);
        entries[entry_count].word[MAX_WORD_LENGTH-1] = '\0';
        entries[entry_count].counter = 0;
        entry_count++;
    }

    printf("Looking for %d words\n", entry_count);
    printf("Looking for words:\n");

    // Process input stream
    int line_count = process_stream(entries, entry_count);

    printf("Result:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].counter);
    }

    return 0;
}
