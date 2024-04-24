#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 11

int main() {
    char sentence[MAX_LEN];
    char *p = NULL;
    char *token = NULL;
    clock_t start, end;
    double cpu_time_used;

    // Method 1: Using strchr()
    printf("Using strchr():\n");
    if (fgets(sentence, MAX_LEN, stdin) != NULL) {
        start = clock();
        p = strchr(sentence, '\n');
        if (p != NULL) {
            *p = '\0';
        }
        end = clock();
        printf("Processed sentence: %s\n", sentence);
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n\n", cpu_time_used);
    }

    // Method 2: Using strtok()
    printf("Using strtok():\n");
    if (fgets(sentence, MAX_LEN, stdin) != NULL) {
        start = clock();
        token = strtok(sentence, "\n");
        end = clock();
        printf("Processed sentence: %s\n", sentence);
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n\n", cpu_time_used);
    }

    // Method 3: Using strcspn()
    printf("Using strcspn():\n");
    if (fgets(sentence, MAX_LEN, stdin) != NULL) {
        start = clock();
        sentence[strcspn(sentence, "\n")] = '\0';
        end = clock();
        printf("Processed sentence: %s\n", sentence);
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", cpu_time_used);
    }

    return 0;
}
