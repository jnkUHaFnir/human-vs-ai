#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char newInvoice[2];
    
    do {
        printf("Would you like to print another invoice? Y=yes, N=No\n");
        scanf(" %1s", newInvoice); // Reading only one character
        newInvoice[0] = toupper(newInvoice[0]); // Convert to uppercase for case-insensitivity
        
        if (newInvoice[0] == 'Y') {
            printf("Processing invoice...\n");
        } else if (newInvoice[0] == 'N') {
            printf("Goodbye!\n");
            break; // Exit the loop
        } else {
            printf("Invalid Entry (it has to be Y or N).\n");
        }
    } while (newInvoice[0] != 'N');

    return 0;
}
