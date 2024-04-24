#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

int main() {
    int x = 10; // Number of strings you want to allocate
    char **array;
    
    // Allocate memory for the array of strings
    array = (char **)malloc(x * sizeof(char *));
    
    if(array == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    
    for(int i = 0; i < x; i++) {
        // Allocate memory for each string
        array[i] = (char *)malloc((MAX_LENGTH) * sizeof(char));
        
        if(array[i] == NULL) {
            printf("Memory allocation failed for string %d. Exiting...\n", i);
            return 1;
        }
    }
    
    // Use the array here
    
    // Don't forget to free the memory when you're done
    for(int i = 0; i < x; i++) {
        free(array[i]);
    }
    free(array);
    
    return 0;
}
