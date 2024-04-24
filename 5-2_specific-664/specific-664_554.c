#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 11

int main() {
    char sentence[MAX_LENGTH];
    char *p = NULL;
    char *token = NULL;
    clock_t start, end;
    double cpu_time_used;

    // Method 1: strchr
    start = clock();
    // Your implementation using strchr here
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Method 1 - strchr: %f seconds\n", cpu_time_used);

    // Method 2: strtok
    start = clock();
    // Your implementation using strtok here
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Method 2 - strtok: %f seconds\n", cpu_time_used);

    // Method 3: strcspn
    start = clock();
    // Your implementation using strcspn here
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Method 3 - strcspn: %f seconds\n", cpu_time_used);

    return 0;
}
