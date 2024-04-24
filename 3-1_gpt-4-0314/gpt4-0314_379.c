#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N         20
#define MAX_SIZE  200

int main() {
    char *words[N];
    int i, c = 0, w = 0, length;
    char *temp;
    int freq[26] = { 0 };

    temp = (char *)malloc(MAX_SIZE * sizeof(char));

    for (i = 0; i < N; i++) {
        printf("Give a word:");
        fgets(temp, MAX_SIZE, stdin);
        temp[strcspn(temp, "\n")] = 0;
        length = strlen(temp);
        *(words + i) = (char *)malloc((length + 1) * sizeof(char));
        strcpy(*(words + i), temp);
        printf("%s\n", *(words + i));
    }
    free(temp);

    for (w = 0; w < N; w++) {
        c = 0;
        while (words[w][c] != '\0') {
            char ch = tolower(words[w][c]);
            if (ch >= 'a' && ch <= 'z') {                    
                freq[ch - 'a']++;
            }
            c++;
        }
    }

    for (i = 0; i < 26; i++) {
        printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
    }
    
    for (i = 0; i < N; i++) {
        free(words[i]);
    }

    return 0;
}
