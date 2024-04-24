#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int counter; 
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
    int line_count = 0;
    char buffer[30];

    while (fgets(buffer, 30, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character

        char* token = strtok(buffer, " ");
        while (token != NULL) {
            int i = 0;
            while (i < entry_count) {
                if (strcmp(entries[i].word, token) == 0) {
                    entries[i].counter++;
                }
                i++;
            }
            token = strtok(NULL, " ");
        }
        line_count++;
    }

    return line_count;
}

int main() {
    WordCountEntry entries[MAX_ENTRIES] = {{"cat", 0}, {"nap", 0}, {"dog", 0}};

    printf("Looking for %d words\n", MAX_ENTRIES);
    printf("Looking for words:\n");

    int lines = process_stream(entries, MAX_ENTRIES);

    printf("Result:\n");
    for (int i = 0; i < MAX_ENTRIES; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].counter);
    }

    return 0;
}
