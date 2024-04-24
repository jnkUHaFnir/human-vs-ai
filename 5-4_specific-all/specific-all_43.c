#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct {
    char word[30];
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
    int line_count = 0;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        
        char* token = strtok(buffer, " ");
        while (token != NULL){
            for (int i = 0; i < entry_count; i++) {
                if (strcmp(entries[i].word, token) == 0) { // Check if token matches a word
                    entries[i].counter++;
                }
            }
            token = strtok(NULL, " ");
        }
        line_count++;
    }
    
    return line_count;
}
