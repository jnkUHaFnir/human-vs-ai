#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N        20
#define MAX_SIZE 200

int main() {
    char *words[N];
    int i, c = 0, length;
    char *temp;
    int freq[26] = {0};

    temp = (char *)malloc(MAX_SIZE * sizeof(char));

    for (i = 0; i < N; i++) {
        printf("Give a word:");
        gets(temp);
        length = strlen(temp);
        words[i] = (char *)malloc((length + 1) * sizeof(char));
        strcpy(words[i], temp);
    }

    free(temp);

    for (i = 0; i < N; i++) {
        c = 0;
        while (words[i][c] != '\0') {
            if ((words[i][c] >= 'a' && words[i][c] <= 'z') || 
                (words[i][c] >= 'A' && words[i][c] <= 'Z')) {
                freq[tolower(words[i][c]) - 'a']++;
            }
            c++;
        }
    }

    for (i = 0; i < 26; i++) {
        printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
    }

    // Free memory for words array
    for (i = 0; i < N; i++) {
        free(words[i]);
    }

    return 0;
}
