#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N         20
#define MAX_SIZE  200

int main() {
    char *words[N];
    int i, c = 0, length;
    char *temp;
    int freq[26] = { 0 };

    temp = (char *) malloc(MAX_SIZE * sizeof(char));

    for (i = 0; i < N; i++) {
        printf("Give a word:");
        fgets(temp, MAX_SIZE, stdin);
        length = strlen(temp);
        *(words + i) = (char *) malloc((length + 1) * sizeof(char));
        strcpy(*(words + i), temp);
        printf("%s\n", *(words + i));
    }
    free(temp);

    while (*words[c] != '\0' && c < 20) {
        if ((*words[c] >= 'a' && *words[c] <= 'z') || (*words[c] >= 'A' && *words[c] <= 'Z')) {
            freq[*words[c] - 'a']++;
        }
        c++;
    }

    for (i = 0; i < 26; i++) {
        printf("%c occurs %d times in the entered string.\n", i + 'a', freq[i]);
    }
    return 0;
}
