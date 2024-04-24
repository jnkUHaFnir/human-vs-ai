#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char sentence[11];
    char *p = NULL;
    char *token = NULL;
    clock_t start, end;
    double cpu_time_used;

    // Method 1: strchr
    if (fgets(sentence, 11, stdin) != NULL) {
        start = clock();
        p = strchr(sentence, '\n');
        *p = '\0';
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Method 1: CPU time used = %f seconds\n", cpu_time_used);
    }

    // Method 2: strtok
    if (fgets(sentence, 11, stdin) != NULL) {
        start = clock();
        token = strtok(sentence, "\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Method 2: CPU time used = %f seconds\n", cpu_time_used);
    }

    // Method 3: strcspn
    if (fgets(sentence, 11, stdin) != NULL) {
        start = clock();
        sentence[strcspn(sentence, "\n")] = '\0';
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Method 3: CPU time used = %f seconds\n", cpu_time_used);
    }

    return 0;
}
