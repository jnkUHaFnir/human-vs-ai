#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_ENTRIES 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
    int line_count = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character if present

        char* token = strtok(buffer, " \n");
        while (token != NULL) {
            int i = 0;
            // Check all entries against the token
            while (i < entry_count) {
                if (strcmp(entries[i].word, token) == 0)
                    entries[i].counter++;
                i++;
            }
            token = strtok(NULL, " \n");
            line_count++;
        }
    }
    return line_count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <word1> <word2> ... <wordN>\n", argv[0]);
        return 1;
    }

    WordCountEntry entries[MAX_ENTRIES] = {0};
    int num_entries = argc - 1;

    for (int i = 0; i < num_entries; i++) {
        strncpy(entries[i].word, argv[i + 1], MAX_WORD_LENGTH - 1);
        entries[i].counter = 0;
    }

    printf("Looking for %d words:\n", num_entries);
    
    int line_count = process_stream(entries, num_entries);

    printf("\nResult:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].counter);
    }

    return 0;
}
