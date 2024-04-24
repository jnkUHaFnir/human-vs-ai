#include <stdio.h>
#include <string.h>

int main() {
    char output[] = "ABCDEFGHIJKL";
    int input_len = strlen(output);
    
    // Calculate the length of the new output
    int output_len = (2 * input_len) - 1;
    
    // Create a new array to hold the rearranged output
    char rearranged[output_len + 1];
    
    int j = 0;
    for (int i = 0; i < input_len; i++) {
        rearranged[j++] = output[i];
        
        // Insert space after every 2 characters except the last one
        if (i < input_len - 1) {
            rearranged[j++] = ' ';
        }
    }
    
    rearranged[output_len] = '\0'; // Add null terminator
    
    printf("Original: %s\n", output);
    printf("Rearranged: %s\n", rearranged);

    return 0;
}
