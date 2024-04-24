#include <stdio.h>
#include <string.h>

typedef struct {
    char word[30];
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count)
{
    int line_count = 0;
    char buffer[100];

    while (fgets(buffer, 100, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
        char* token = strtok(buffer, " ");
        while (token != NULL){
            int i = 0;
            while (i < entry_count) { // Corrected loop condition
                if (!strcmp(entries[i].word, token))
                    entries[i].counter++;
                i++;
            }
            token = strtok(NULL, " ");
        }
        line_count++;
    }
    return line_count;
}

int main() {
    WordCountEntry entries[] = {{"cat", 0}, {"nap", 0}, {"dog", 0}};
    int entry_count = sizeof(entries) / sizeof(entries[0]);

    printf("Looking for words:\n");
    int lines = process_stream(entries, entry_count);

    printf("Result:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].counter);
    }

    return 0;
}
