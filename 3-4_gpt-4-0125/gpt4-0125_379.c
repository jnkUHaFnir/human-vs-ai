#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N         20
#define MAX_SIZE  200

int main() {
    char *words[N];
    int i, j, c = 0, length;
    char *temp;
    int freq[26] = { 0 };

    temp = (char *)malloc(MAX_SIZE * sizeof(char));

    for (i = 0; i < N; i++) {
        printf("Give a word:");
        gets(temp); // Note: gets() is unsafe, consider using fgets() instead!
        length = strlen(temp);
        *(words + i) = (char *)malloc((length + 1) * sizeof(char));
        strcpy(*(words + i), temp);
    }
    free(temp);

    // Correcting the frequency calculation part
    for (i = 0; i < N; i++) { // Go through each string
        for (j = 0; words[i][j] != '\0'; j++) { // Go through each character of the string
            char ch = tolower(words[i][j]); // Convert each letter to lowercase for uniform counting
            if (ch >= 'a' && ch <= 'z') {                    
                freq[ch - 'a']++;
            }
        }
    }

    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) { // Only print letters that appear
            printf("%c occurs %d times in the entered words.\n", i + 'a', freq[i]);
        }
    }

    // Free memory
    for (i = 0; i < N; i++) {
        free(words[i]);
    }

    return 0;
}
