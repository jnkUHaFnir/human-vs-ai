#include <stdio.h>
#include <string.h>

typedef struct {
    char word[30];
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
    int line_count = 0;
    char buffer[30];

    while (fgets(buffer, 30, stdin)) {
        char* token = strtok(buffer, " \n");
        while (token != NULL) {
            int i = 0;
            while (i < entry_count) {
                if (!strcmp(entries[i].word, token)) {
                    entries[i].counter++;
                }
                i++;
            }
            line_count++;
            token = strtok(NULL, " \n");
        }
    }
    return line_count;
}

int main() {
    // Prepare WordCountEntry entries
    WordCountEntry entries[] = {
        {"cat", 0},
        {"nap", 0},
        {"dog", 0}
    };
    int entry_count = sizeof(entries) / sizeof(entries[0]);

    printf("Looking for %d words\n", entry_count);

    printf("Looking for words:\n");
    int processed_lines = process_stream(entries, entry_count);

    // Output the result
    printf("\nResult:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].counter);
    }

    return 0;
}
