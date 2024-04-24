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
        fgets(temp, MAX_SIZE, stdin);
        length = strlen(temp);
        temp[length - 1] = '\0'; // removing the newline character
        words[i] = (char *)malloc((length) * sizeof(char));
        strcpy(words[i], temp);
        printf("%s\n", words[i]);
    }
    free(temp);

    for (i = 0; i < N; i++) {
        for (j = 0; j < strlen(words[i]); j++) {
            if ((words[i][j] >= 'a' && words[i][j] <= 'z') || (words[i][j] >= 'A' && words[i][j] <= 'Z')) {                    
                freq[tolower(words[i][j]) - 'a']++;
            }
        }
    }

    for (i = 0; i < 26; i++) {
        printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
    }
    return 0;
}
