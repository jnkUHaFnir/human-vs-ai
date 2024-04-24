#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5
#define GROWTH_FACTOR 2

int main() {
    char line[100];
    int* numbers = NULL;
    size_t size = 0;
    size_t capacity = 0;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t current_size = 0;
        char* token = strtok(line, ":,");
        
        while (token != NULL) {
            int number = atoi(token);

            // Resize the array if needed
            if (size >= capacity) {
                capacity = (capacity == 0) ? INITIAL_CAPACITY : capacity * GROWTH_FACTOR;
                numbers = (int*)realloc(numbers, capacity * sizeof(int));
                if (numbers == NULL) {
                    fprintf(stderr, "Memory allocation error\n");
                    exit(EXIT_FAILURE);
                }
            }

            numbers[size++] = number;
            current_size++;
            token = strtok(NULL, ":,");
        }
        
        // Use the values from the most recently scanned line for other tasks
        for (size_t i = size - current_size; i < size; i++) {
            printf("%d ", numbers[i]); // Replace this with your processing logic
        }
        printf("\n");
    }

    free(numbers);
    return 0;
}
