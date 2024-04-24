#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N         20
#define MAX_SIZE  200

int main() {
    char *words[N];
    int i, j, length;
    char temp[MAX_SIZE];
    int freq[26] = { 0 };

    for (i = 0; i < N; i++) {
        printf("Give a word:");
        fgets(temp, MAX_SIZE, stdin); // Using fgets instead of gets
        length = strlen(temp);
        if (temp[length - 1] == '\n') {
            temp[length - 1] = '\0'; // Removing the newline character from input
        }
        words[i] = (char *)malloc((length + 1) * sizeof(char));
        strcpy(words[i], temp);
        printf("%s\n", words[i]);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < strlen(words[i]); j++) {
            if ((words[i][j] >= 'a' && words[i][j] <= 'z') || (words[i][j] >= 'A' && words[i][j] <= 'Z')) {
                freq[tolower(words[i][j]) - 'a']++;
            }
        }
    }

    for (i = 0; i < 26; i++) {
        printf("%c occurs %d times in the entered strings.\n", i + 'a', freq[i]);
    }

    for (i = 0; i < N; i++) {
        free(words[i]); // Free dynamically allocated memory
    }

    return 0;
}
