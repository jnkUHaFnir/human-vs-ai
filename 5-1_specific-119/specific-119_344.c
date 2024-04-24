#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    char line_buffer[BUFSIZ];
    char* words[20];
    FILE *fp = fopen("input.txt", "r");

    while (fgets(line_buffer, sizeof(line_buffer), fp)) {
        // Allocate memory for the word
        words[i] = strdup(line_buffer); // or use malloc and strcpy

        i = i + 1;
    }

    if (i < 2) {
        printf("Not enough words in the file\n");
        return 1;
    }

    printf("%d\n", i);

    int j = rand() % i;
    int k;
    do {
        k = rand() % i;
    } while (k == j);

    printf("%s%s", words[j], words[k]);

    // Free allocated memory
    for (int idx = 0; idx < i; idx++) {
        free(words[idx]);
    }

    fclose(fp);
    
    return 0;
}
