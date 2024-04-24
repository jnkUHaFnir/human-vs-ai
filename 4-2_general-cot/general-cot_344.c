#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int i = 0;
    char line_buffer[BUFSIZ];
    char* words[20];
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line_buffer, sizeof(line_buffer), fp) && i < 20) {
        words[i] = strdup(line_buffer); // Allocate memory and copy word
        i++;
    }

    printf("%d\n", i);

    srand(time(NULL));
    int j = rand() % i;
    int k = (j + 1) % i;

    printf("%s %s", words[j], words[k]);

    // Free allocated memory for words
    for (int idx = 0; idx < i; idx++) {
        free(words[idx]);
    }

    fclose(fp);
    return 0;
}
