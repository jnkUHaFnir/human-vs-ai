#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rearrangeArrayWithSpaces(const char* input, char* output) {
    int input_len = strlen(input);
    
    for (int i = 0, j = 0; i < input_len; i += 2) {
        output[j++] = input[i];
        if (i + 1 < input_len) {
            output[j++] = input[i + 1];
            if (i + 2 < input_len) {
                output[j++] = ' ';
            }
        }
    }
    
    output[j] = '\0';
}

int main() {
    const char* input = "ABCDEFGHIJKL";
    int output_len = 2 * strlen(input) - 1;
    char* output = (char*)malloc(output_len + 1); // +1 for null terminator
    
    if (output != NULL) {
        rearrangeArrayWithSpaces(input, output);
        printf("%s\n", output);
        
        free(output);
    } else {
        printf("Memory allocation error!\n");
    }
    
    return 0;
}
