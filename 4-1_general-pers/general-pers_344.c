#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    char line_buffer[BUFSIZ];
    char* words[20];
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line_buffer, sizeof(line_buffer), fp)) {
        words[i] = strdup(line_buffer);
        i++;
    }

    int num_words = i;
    printf("%d\n", num_words);

    if (num_words < 2) {
        printf("Insufficient words to choose from.\n");
        return 1;
    }

    int j = rand() % num_words;
    int k = (j + 1) % num_words;

    printf("%s%s", words[j], words[k]);

    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }

    fclose(fp);
    return 0;
}
