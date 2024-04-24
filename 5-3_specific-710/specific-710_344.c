#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 100

int main() {
    srand(time(NULL));

    int i = 0;
    char line_buffer[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    FILE *fp = fopen("input.txt", "r");
    
    while (fgets(line_buffer, sizeof(line_buffer), fp) && i < MAX_WORDS) {
        line_buffer[strcspn(line_buffer, "\n")] = 0; // Remove newline character
        strcpy(words[i], line_buffer);
        i++;
    }

    printf("%d\n", i);

    int j = rand() % i;
    int k = (j + 1) % i;

    printf("%s %s\n", words[j], words[k]);

    fclose(fp);

    return 0;
}
