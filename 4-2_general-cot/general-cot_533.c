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
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            for (int i = 0; i < entry_count; i++) {
                if (strcmp(entries[i].word, token) == 0)
                    entries[i].counter++;
            }
            line_count++;
            token = strtok(NULL, " \n");
        }
    }

    return line_count;
}

int main() {
    WordCountEntry entries[3] = {{"cat", 0}, {"nap", 0}, {"dog", 0}};
    int count = process_stream(entries, 3);

    printf("Result:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %d\n", entries[i].word, entries[i].counter);
    }

    return 0;
}
