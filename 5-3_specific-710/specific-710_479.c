#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char newInvoice;
    
    do {
        printf("Would you like to print another invoice? Y=yes, N=No\n");
        scanf(" %c", &newInvoice); // Notice the space before %c to consume the newline character
        
        if(newInvoice == 'Y' || newInvoice == 'y') {
            // Perform the action for yes
            printf("Processing Yes\n");
        }
        else if(newInvoice == 'N' || newInvoice == 'n') {
            // Perform the action for no
            printf("Goodbye!\n");
            break; // Exit the loop
        }
        else {
            printf("Invalid Entry (it has to be y or n)\n");
        }
    } while(1); // This loop will continue indefinitely until the user enters 'N' or 'n'

    return 0;
}
