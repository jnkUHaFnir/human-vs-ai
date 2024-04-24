#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N         20
#define MAX_SIZE  200

int main() {
    char *words[N];
    int i, j, length;
    char *temp;
    int freq[26] = { 0 };

    temp = (char *)malloc(MAX_SIZE * sizeof(char));

    for (i = 0; i < N; i++) {
        printf("Give a word: ");
        fgets(temp, MAX_SIZE, stdin);        // Use fgets instead of gets
        temp[strcspn(temp, "\n")] = 0;       // Remove the newline character
        length = strlen(temp);
        words[i] = (char *)malloc((length + 1) * sizeof(char)); // Directly use index
        strcpy(words[i], temp);
        printf("%s\n", words[i]);
    }
    free(temp);

    // Iterate over each word
    for (i = 0; i < N; i++) {
        j = 0; // Start at the beginning of each word
        // Iterate over each character in the word
        while (words[i][j] != '\0') {
            char current_char = words[i][j];
            if (current_char >= 'a' && current_char <= 'z') {
                freq[current_char - 'a']++;
            } else if (current_char >= 'A' && current_char <= 'Z') { 
                freq[current_char - 'A']++;
            }
            j++;
        }
    }

    // Print histogram
    for (i = 0; i < 26; i++) {
        printf("%c occurs %d times in the entered words.\n", i + 'a', freq[i]);
    }

    // Free the allocated memory for each word
    for (i = 0; i < N; i++) {
        free(words[i]);
    }

    return 0;
}
