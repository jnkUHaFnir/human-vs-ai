#include <stdio.h>
#include <string.h>

int main() {
    FILE* file;
    char scientificNumber[30]; // Adjust size as needed
    char sign, exponentSign;
    int beforeDot, exponent;
    char betweenDot[20]; // Adjust based on the expected max length
    
    // Assuming you open your file successfully into `file`
    // For demonstration, let's assume we're reading the first matching pattern from the file
    if (fscanf(file, "%29s", scientificNumber) == 1) {
        // Process the read scientific number
        
        // Step 1: Extract the sign
        sign = scientificNumber[0];
        
        // Step 2: Find the dot and the 'E' to split the string
        char* dotPointer = strchr(scientificNumber, '.');
        char* ePointer = strchr(scientificNumber, 'E');
        
        if (dotPointer != NULL && ePointer != NULL) {
            // Step 3: Extract the number before the dot
            sscanf(scientificNumber + 1, "%1d", &beforeDot);
            
            // Step 4: Extract the numbers between the dot and the 'E'
            strncpy(betweenDot, dotPointer + 1, ePointer - dotPointer - 1);
            betweenDot[ePointer - dotPointer - 1] = '\0';
            
            // Step 5: Extract the exponent (including its sign)
            sscanf(ePointer + 1, "%d", &exponent);
            exponentSign = *(ePointer + 1) == '-' ? '-' : '+';
        }
        
        // Print your results (for verification)
        printf("Sign: %c\n", sign);
        printf("Before dot: %d\n", beforeDot);
        printf("Between dot and E: %s\n", betweenDot);
        printf("Exponent: %c%d\n", exponentSign, exponent);
    } else {
        printf("Failed to read the data\n");
    }

    // Make sure to close your file and do proper error checking in your real code
    return 0;
}
