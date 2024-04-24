#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int i = 0;
    char line_buffer[BUFSIZ];
    char *words[20];
    FILE *fp = fopen("input.txt", "r");

    // Seed the random number generator
    srand(time(NULL));

    while (fgets(line_buffer, sizeof(line_buffer), fp)) {
        // Remove newline character
        line_buffer[strcspn(line_buffer, "\n")] = 0;

        // Duplicate the string and store the pointer in the words array
        words[i] = strdup(line_buffer);
        i = i + 1;
    }

    printf("%d\n", i);
    int j = rand() % 8;
    int k = (j + 1) % 8;
    printf("%s %s", words[j], words[k]);

    // Free dynamically allocated memory
    for(int n = 0; n < i; n++) {
        free(words[n]);
    }

    fclose(fp);
    return 0;
}
