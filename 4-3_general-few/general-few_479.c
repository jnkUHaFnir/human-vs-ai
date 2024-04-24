#include <stdio.h>

int main() {
    char newInvoice;

    do {
        printf("Would you like to print another invoice? Y=yes, N=no\n");

        scanf(" %c", &newInvoice); // Note the space before %c to ignore leading whitespace

        if (newInvoice == 'Y' || newInvoice == 'y') {
            // Continue the loop for 'Y' or 'y'
            printf("Printing another invoice.\n");
        } else if (newInvoice == 'N' || newInvoice == 'n') {
            printf("Goodbye!\n");
            break; // Exit the loop for 'N' or 'n'
        } else {
            printf("Invalid entry. Please enter either 'Y' or 'N'.\n");
        }
    } while (1); // Infinite loop until 'N' or 'n' is entered

    return 0;
}
