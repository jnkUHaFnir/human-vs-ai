#include <stdio.h>
#include <string.h>

#define SIZE 100 // Increasing buffer size for larger words

void pluralize(char* word) {
    int len = strlen(word);
    // Rule a
    if (word[len - 1] == 'y') {
        word[len - 1] = '\0'; // Remove the 'y'
        printf("%sies\n", word); // Add 'ies'
    }
    // Rule b
    else if (word[len - 1] == 's' || 
            (len >= 2 && (strcmp(word + len - 2, "ch") == 0 || strcmp(word + len - 2, "sh") == 0))) {
        printf("%ses\n", word); // Add 'es'
    }
    // Rule c
    else {
        printf("%ss\n", word); // Just add 's'
    }
}

int main(void) {
    char words[][SIZE] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    int n = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < n; ++i) {
        printf("Singular: %s, Plural: ", words[i]);
        pluralize(words[i]);
    }

    return 0;
}
