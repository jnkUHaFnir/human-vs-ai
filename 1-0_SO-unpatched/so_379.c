    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define N         20
    #define MAX_SIZE  200
    int main(void) {
        char *words[N];
        int n, i, j, c, length;
        char temp[MAX_SIZE];
        int freq[26] = { 0 };
        for (i = 0; i < N; i++) {
            printf("Give a word:");
            if (!fgets(temp, sizeof temp, stdin))
                break;
            temp[strcspn(temp, "\n")] = '\0';  /* strip the \n if present */
            length = strlen(temp);
            words[i] = malloc(length + 1);
            strcpy(words[i], temp);
            printf("%s\n", words[i]);
        }
        n = i; /* save number of words */
        for (i = 0; i < n; i++) {
            for (j = 0; (c = words[i][j]) != '\0'; j++) {
                if (c >= 'a' && c <= 'z')
                    freq[c - 'a']++;
                else
                if (c >= 'A' && c <= 'Z')
                    freq[c - 'A']++;
            }
        }
        for (i = 0; i < 26; i++) {
            if (freq[i] > 0)
                printf("%c occurs %d times in the entered strings.\n", i + 'a', freq[c]);
        }
        return 0;
    }