#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

double measureTime(void (*func)(char *), char *sentence) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    func(sentence);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    return cpu_time_used;
}

void method1(char *sentence) {
    char *p = strchr(sentence, '\n');
    if (p != NULL) {
        *p = '\0';
    }
}

void method2(char *sentence) {
    char *token = strtok(sentence, "\n");
}

void method3(char *sentence) {
    sentence[strcspn(sentence, "\n")] = '\0';
}

int main() {
    char sentence[MAX_LENGTH];

    // Input
    printf("Enter a string: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Measure time for method 1
    double time_method1 = measureTime(method1, sentence);

    // Measure time for method 2
    double time_method2 = measureTime(method2, sentence);

    // Measure time for method 3
    double time_method3 = measureTime(method3, sentence);

    printf("Time taken by method 1: %f seconds\n", time_method1);
    printf("Time taken by method 2: %f seconds\n", time_method2);
    printf("Time taken by method 3: %f seconds\n", time_method3);

    return 0;
}
