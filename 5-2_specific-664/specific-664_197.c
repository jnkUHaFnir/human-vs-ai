#include <stdio.h>

int main() {
    char x[50];
    char specialChar;

    while(scanf("%49[^:]:%c", x, &specialChar) == 2) {
        // Process the read text and special character
        printf("Read text: %s\n", x);
        printf("Special character: %c\n", specialChar);

        // Handle or process the read text and special character as needed
        
        // If you want to stop reading after encountering a specific character (e.g., ':'), you can break out of the loop
        if(specialChar == ':') {
            break;
        }
    }

    return 0;
}
