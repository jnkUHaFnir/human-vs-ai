#include <stdio.h>
#include <ctype.h>

void sanitizeData(char* data) {
    char sanitizedData[1000]; // Assuming a max length of 1000 characters
    int j = 0;
    
    for (int i = 0; data[i] != '\0'; i++) {
        if (isalnum(data[i]) || isspace(data[i])) {
            sanitizedData[j] = data[i];
            j++;
        }
    }
    sanitizedData[j] = '\0'; // Add null terminator to end the string
    
    // Copy the sanitized data back to the original variable
    for (int i = 0; sanitizedData[i] != '\0'; i++) {
        data[i] = sanitizedData[i];
    }
    data[j] = '\0'; // Add null terminator to end the string
}

int main() {
    char data[] = "Hello! This data contains^% extra line breaks and numbers 12345.";
    
    printf("Before sanitization:\n%s\n", data);
    
    sanitizeData(data);
    
    printf("\nAfter sanitization:\n%s\n", data);

    return 0;
}
