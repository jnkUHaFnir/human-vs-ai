#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[30]; // Assuming you have a struct like this
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
    short line_count = 0;
    char buffer[30];

    while (fgets(buffer, 30, stdin)) {
        if (buffer[0] == '.') // Check for termination character at the start of the input
            break;

        buffer[strcspn(buffer, "\n")] = '\0'; // A more reliable way to remove newline characters
        char* token = strtok(buffer, " \n"); // Get the first token
        
        while (token != NULL) {
            for (int i = 0; i < entry_count; i++) { // Check all entries for each token
                if (strcmp(entries[i].word, token) == 0) { // strcmp returns 0 if strings are equal
                    entries[i].counter++;
                    break; // Found and incremented the counter, no need to continue the loop
                }
            }
            token = strtok(NULL, " \n"); // Move to the next token
        }
        line_count++;
    }
    return line_count;
}
