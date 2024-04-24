#include <stdio.h>
#include <string.h>

typedef struct {
    const char* word;
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
    int line_count = 0;
    char buffer[30];

    while (fgets(buffer, 30, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character

        char* token = strtok(buffer, " ");
        while (token != NULL) {
            int i = 0;
            while (i < entry_count) {
                if (strcmp(entries[i].word, token) == 0) {
                    entries[i].counter++;
                    break; // Exit loop early if word found
                }
                i++;
            }
            token = strtok(NULL, " "); // Get next token
        }
        line_count++;
    }

    return line_count;
}

int main() {
    WordCountEntry entries[] = {{"cat", 0}, {"nap", 0}, {"dog", 0}};
    int entry_count = sizeof(entries) / sizeof(entries[0]);

    printf("Looking for %d words:\n", entry_count);
    int lines_checked = process_stream(entries, entry_count);

    printf("Result:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].counter);
    }

    return 0;
}
