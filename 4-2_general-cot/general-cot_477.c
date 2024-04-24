#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 100

int main() {
    char sentence[MAX_LEN];
    char *p = NULL;
    char *token = NULL;
    clock_t start, end;
    double cpu_time_used;

    // Method 1: strchr
    start = clock();
    if (fgets(sentence, MAX_LEN, stdin) != NULL) {
        p = strchr(sentence, '\n');
        if (p != NULL) *p = '\0';
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Method 1 (strchr) took %f seconds.\n", cpu_time_used);

    // Method 2: strtok
    start = clock();
    if (fgets(sentence, MAX_LEN, stdin) != NULL) {
        token = strtok(sentence, "\n");
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Method 2 (strtok) took %f seconds.\n", cpu_time_used);

    // Method 3: strcspn
    start = clock();
    if (fgets(sentence, MAX_LEN, stdin) != NULL) {
        sentence[strcspn(sentence, "\n")] = '\0';
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Method 3 (strcspn) took %f seconds.\n", cpu_time_used);

    return 0;
}
