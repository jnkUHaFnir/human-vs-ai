#include <stdio.h>

int main() {
    char newInvoice;
    
    do {
        printf("Would you like to print another invoice? Y=yes, N=No\n");
        
        // Using %c to read a single character and a space before %c
        // to skip any newline characters left in the input buffer.
        scanf(" %c", &newInvoice);
        
        if(newInvoice == 'Y' || newInvoice == 'y') {
            printf("Printing another invoice...\n");
            // Insert the logic to print another invoice here
        }
        else if(newInvoice == 'N' || newInvoice == 'n') {
            printf("Goodbye!\n");
            break; // Exit the loop
        }
        else {
            printf("Invalid Entry (it has to be y or n):\n");
        }
    } while(newInvoice != 'N' && newInvoice != 'n');
    
    return 0;
}
