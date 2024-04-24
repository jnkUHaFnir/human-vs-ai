#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    char line_buffer[BUFSIZ];
    char* words[20];
    FILE *fp = fopen("input.txt", "r");

    while (fgets(line_buffer, sizeof(line_buffer), fp)) {
        line_buffer[strcspn(line_buffer, "\n")] = 0; // Removing newline character if present
        words[i] = strdup(line_buffer); // Allocate memory and copy the word
        i = i + 1;
    }

    printf("%d\n", i);

    int j = rand() % i;
    int k = (j + 1) % i;

    printf("%s %s\n", words[j], words[k]);

    for (int l = 0; l < i; l++) {
        free(words[l]); // Freeing allocated memory
    }

    fclose(fp);
    return 0;
}
