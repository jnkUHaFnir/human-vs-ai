#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("files.txt", "r");
    
    if (file == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    int line_number = 2; // Line number to read integers from
    int current_line = 1;
    int num_elements;
    
    // Find the line of interest
    while (current_line < line_number) {
        if (fscanf(file, "%d", &num_elements) != 1) {
            printf("Error reading number of elements from line %d.\n", line_number);
            fclose(file);
            return 1;
        }
        
        for (int i = 0; i < num_elements; i++) {
            int element;
            if (fscanf(file, "%d", &element) != 1) {
                printf("Error reading element %d from line %d.\n", i+1, line_number);
                fclose(file);
                return 1;
            }
        }
        
        current_line++;
    }
    
    // Read integers from the line of interest
    if (fscanf(file, "%d", &num_elements) != 1) {
        printf("Error reading number of elements from line %d.\n", line_number);
        fclose(file);
        return 1;
    }
    
    int* numbers = (int*)malloc(num_elements * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }
    
    for (int i = 0; i < num_elements; i++) {
        if (fscanf(file, "%d", &numbers[i]) != 1) {
            printf("Error reading element %d from line %d.\n", i+1, line_number);
            fclose(file);
            free(numbers);
            return 1;
        }
    }
    
    // Print the read numbers
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    free(numbers);
    fclose(file);

    return 0;
}
