#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char sentence[11];
    char *p = NULL;
    char *token = NULL;

    // Using strchr
    if (fgets(sentence, 11, stdin) != NULL) {
        p = strchr(sentence, '\n');
        if (p != NULL) {
            *p = '\0';
        }
    }

    printf("Using strchr: %s\n", sentence);

    // Using strtok
    if (fgets(sentence, 11, stdin) != NULL) {
        token = strtok(sentence, "\n");
    }

    printf("Using strtok: %s\n", sentence);

    // Using strcspn
    if (fgets(sentence, 11, stdin) != NULL) {
        sentence[strcspn(sentence, "\n")] = '\0';
    }

    printf("Using strcspn: %s\n", sentence);

    return 0;
}
