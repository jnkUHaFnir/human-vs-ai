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
        line_buffer[strcspn(line_buffer, "\n")] = 0; // Remove newline character
        words[i] = strdup(line_buffer);
        i = i + 1;
    }

    printf("%d\n", i);

    if (i < 2) {
        printf("Not enough words in the file\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator
    
    int j = rand() % i;
    int k = (j + 1) % i;

    printf("%s %s\n", words[j], words[k]);

    // Release memory allocated by strdup
    for (int m = 0; m < i; m++) {
        free(words[m]);
    }

    fclose(fp);

    return 0;
}
