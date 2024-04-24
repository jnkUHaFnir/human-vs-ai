#include <stdio.h>
#include <string.h>

#define MAX_INTS 100 // Maximum number of integers in a line

int main() {
    char line[100]; // Assume maximum line length of 100 characters
    int array[MAX_INTS];
    int numInts = 0;
    
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // Reset array and int counter for each line
        numInts = 0;
        memset(array, 0, sizeof(array));

        char *token = strtok(line, ":, \n"); // Split line at ':' and ','
        while (token != NULL && numInts < MAX_INTS) {
            array[numInts++] = atoi(token); // Convert token to integer and store it
            token = strtok(NULL, ":, \n");
        }

        // Now you can use the integers stored in the array

        printf("Integers on this line are: ");
        for (int i = 0; i < numInts; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
