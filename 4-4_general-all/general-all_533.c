#include <stdio.h>
#include <string.h>

typedef struct {
    char word[30];
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count)
{
    int line_count = 0;
    char buffer[30];

    while (fgets(buffer, 30, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character if present
        char* token = strtok(buffer, " ");
        while (token != NULL) {
            int i = 0;
            while (i < entry_count) {
                if (strcmp(entries[i].word, token) == 0) {
                    entries[i].counter++;
                    break; // Exit loop if word is found
                }
                i++;
            }
            token = strtok(NULL, " ");
        }
        line_count++;
    }
    return line_count;
}
