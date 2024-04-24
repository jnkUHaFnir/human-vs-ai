#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    char sentence[MAX_SIZE];
    char *p = NULL, *token = NULL;
    clock_t start, end;
    double cpu_time_used;

    // Benchmarking strchr
    start = clock();
    if (fgets(sentence, MAX_SIZE, stdin) != NULL) {
        p = strchr(sentence, '\n');
        if (p != NULL) {
            *p = '\0';
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("strchr time: %f seconds\n", cpu_time_used);

    // Benchmarking strtok
    start = clock();
    if (fgets(sentence, MAX_SIZE, stdin) != NULL) {
        token = strtok(sentence, "\n");
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("strtok time: %f seconds\n", cpu_time_used);

    // Benchmarking strcspn
    start = clock();
    if (fgets(sentence, MAX_SIZE, stdin) != NULL) {
        sentence[strcspn(sentence, "\n")] = '\0';
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("strcspn time: %f seconds\n", cpu_time_used);

    return 0;
}
