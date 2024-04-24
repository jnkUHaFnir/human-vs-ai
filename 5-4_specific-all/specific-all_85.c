#include <stdio.h>
#include <string.h>

int main() {

    char sentences[] = {"This is the first sentence, And this is the second"};
    char *sentence = strtok(sentences, ",");
    
    while (sentence != NULL) {
        int length = strlen(sentence);

        // Traverse sentence from end
        for (int i = length - 1; i >= 0; i--) {
            if (sentence[i] == ' ') {
                // putting the NULL character at the position of space characters for next iteration.
                sentence[i] = '\0';

                // Start from next character
                printf("%s ", &(sentence[i]) + 1);
            }
        }
        
        // printing the first word
        printf("%s", sentence);

        sentence = strtok(NULL, ",");
        if (sentence != NULL) {
            printf(" ");
        }
    }

    return 0;
}
