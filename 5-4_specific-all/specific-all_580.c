#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* InputWords = NULL;
    InputWords = fopen("ListOfWords.txt","r"); /* replace "ListOfWords.txt" with the actual file name */

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    char *word = NULL;
    size_t wordSize = 0;

    while (1) {
        char temp[100]; // Assuming a maximum word length of 99 characters
        if (fscanf(InputWords, "%99s", temp) == 1) {
            if (isdigit(temp[0])) {
                // Skip numbers
                continue;
            }

            size_t len = strlen(temp);
            word = (char *)realloc(word, (wordSize + len + 1) * sizeof(char));
            strcpy(word + wordSize, temp);
            wordSize += len;
            word[wordSize++] = ' '; // Add space between words
        } else {
            break; // End of file reached
        }
    }

    if (wordSize > 0) {
        // Remove the extra space at the end
        word[--wordSize] = '\0';
        printf("%s\n", word);
    }

    free(word);
    fclose(InputWords);

    return 0;
}
