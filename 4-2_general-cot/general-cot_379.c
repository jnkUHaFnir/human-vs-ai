#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalpha() function

#define N         20
#define MAX_SIZE  200

int main() {
    char *words[N];
    char temp[MAX_SIZE];
    int i, c = 0, length;
    int freq[26] = { 0 };

    for (i = 0; i < N; i++) {
        printf("Give a word:");
        fgets(temp, sizeof(temp), stdin);
        length = strlen(temp);
        
        // Remove newline character if present
        if (temp[length - 1] == '\n') {
            temp[length - 1] = '\0';
        }
        
        words[i] = (char *)malloc((length + 1) * sizeof(char));
        strcpy(words[i], temp);
    }

    for (i = 0; i < N; i++) {
        char *ptr = words[i];
        while (*ptr != '\0') {
            if (isalpha(*ptr)) {
                freq[tolower(*ptr) - 'a']++; // Convert to lowercase and count
            }
            ptr++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
        }
    }

    // Free memory for words
    for (i = 0; i < N; i++) {
        free(words[i]);
    }

    return 0;
}
