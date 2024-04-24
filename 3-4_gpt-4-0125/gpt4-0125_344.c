#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i = 0;
    char line_buffer[BUFSIZ];
    char* words[20]; // Assuming there are no more than 20 lines for simplicity
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    while (fgets(line_buffer, sizeof(line_buffer), fp) && i < 20) {
        // Remove newline character if present
        line_buffer[strcspn(line_buffer, "\n")] = 0;
        words[i] = strdup(line_buffer); // Allocate and copy
        if (words[i] == NULL) {
            perror("Failed to allocate memory");
            fclose(fp);
            return EXIT_FAILURE;
        }
        i++;
    } 
    fclose(fp); // Close the file as soon as you are done with it
    
    if (i == 0) { // Check if the file was empty or no lines were read
        printf("No words read from the file.\n");
        return EXIT_FAILURE;
    }
    
    printf("Number of lines read: %d\n", i);
    
    // Seed the random number generator
    srand(time(NULL)); // Note: only call srand once
    
    int arraySize = i; // The actual number of lines read
    int j = rand() % arraySize;
    int k = (j + 1) % arraySize; // Guarantees k is a different line unless there's only one line
    
    printf("%s %s\n", words[j], words[k]);
    
    // Free the dynamically allocated memory
    for (int n = 0; n < i; n++) {
        free(words[n]);
    }
    
    return 0;
}
