#include <stdio.h>

int main() {
    char input[100]; // Assuming input will not exceed 100 characters
    int num;
    int sum = 0;
    int count = 0;
    
    // Read the input line
    printf("Enter numbers separated by spaces: ");
    fgets(input, sizeof(input), stdin);
    
    // Parse the numbers one by one
    char *ptr = input;
    while (sscanf(ptr, "%d", &num) == 1) {
        sum += num;
        count++;
        while (*ptr && *ptr != ' ') ptr++; // Move to next number
        while (*ptr && *ptr == ' ') ptr++; // Skip spaces
    }
    
    // Calculate and display the average
    if (count > 0) {
        double average = (double)sum / count;
        printf("Average: %.2f\n", average);
    } else {
        printf("No numbers provided.\n");
    }

    return 0;
}
