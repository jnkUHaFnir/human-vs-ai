#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char sentence[11];
    clock_t start, end;
    double cpu_time_used;

    // Method 1: strchr()
    start = clock();
    /* Your strchr() code here */
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("strchr() execution time: %f\n", cpu_time_used);

    // Method 2: strtok()
    start = clock();
    /* Your strtok() code here */
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("strtok() execution time: %f\n", cpu_time_used);

    // Method 3: strcspn()
    start = clock();
    /* Your strcspn() code here */
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("strcspn() execution time: %f\n", cpu_time_used);

    return 0;
}
