#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N         20
#define MAX_SIZE  200

int main() {
    char *words[N];
    int i, c = 0, length;
    char *temp;
    int freq[26] = { 0 };

    temp = (char *)malloc(MAX_SIZE * sizeof(char));

    for (i = 0; i < N; i++) {
        printf("Give a word:");
        gets(temp);
        length = strlen(temp);
        words[i] = (char *)malloc((length + 1) * sizeof(char));
        strcpy(words[i], temp);
        printf("%s\n", words[i]);
    }
    free(temp);

    for (i = 0; i < N; i++) {
        char *ptr = words[i];
        while (*ptr != '\0') {
            if (isalpha(*ptr)) {                    
                if (isupper(*ptr)) {
                    freq[*ptr - 'A']++;
                } else {
                    freq[*ptr - 'a']++;
                }
            }
            ptr++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
        }
    }

    // Free memory for words array
    for (i = 0; i < N; i++) {
        free(words[i]);
    }

    return 0;
}
