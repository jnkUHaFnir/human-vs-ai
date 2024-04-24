#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    char line_buffer[BUFSIZ];
    char* words[20];
    FILE *fp = fopen("input.txt", "r");

    while (fgets(line_buffer, sizeof(line_buffer), fp)) {
        words[i] = malloc(strlen(line_buffer) + 1);
        strcpy(words[i], line_buffer);
        i = i + 1;
    }

    printf("%d\n", i);

    int j = rand() % i;
    int k = (j + 1) % i;
    printf("%s%s", words[j], words[k]);

    for (int m = 0; m < i; ++m) {
        free(words[m]); // Freeing dynamically allocated memory
    }

    fclose(fp);
    return 0;
}
