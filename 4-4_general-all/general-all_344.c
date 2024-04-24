#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    int i = 0;
    char line_buffer[BUFSIZ];
    char* words[20];
    FILE *fp = fopen("input.txt", "r");

    while (fgets(line_buffer, sizeof(line_buffer), fp)) {
        // Allocate memory for the word
        words[i] = malloc(strlen(line_buffer) + 1);
        if (words[i] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        
        // Copy the word into the allocated memory
        strcpy(words[i], line_buffer);
        i = i + 1;
    }

    printf("%d\n", i);

    // Generate random indices
    srand(time(NULL));
    int j = rand() % i;
    int k = (j + 1) % i;

    // Print two random words
    printf("%s%s", words[j], words[k]);
    
    // Free allocated memory
    for (int idx = 0; idx < i; idx++) {
        free(words[idx]);
    }

    fclose(fp);
    return 0;
}
