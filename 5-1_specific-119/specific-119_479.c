#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char newInvoice[2];

    printf("Would you like to print another invoice? Y=yes, N=No\n");
    do {
        fgets(newInvoice, sizeof(newInvoice), stdin);
        newInvoice[0] = toupper(newInvoice[0]); // Convert input to uppercase for case insensitivity

        if(strcmp(newInvoice, "Y\n") == 0) {
            // User wants to print another invoice, continue the loop
            printf("Printing another invoice...\n");
        }
        else if(strcmp(newInvoice, "N\n") == 0) {
            printf("Goodbye!\n");
            break; // Exit the loop
        }
        else {
            printf("Invalid Entry. Please enter 'Y' or 'N':\n");
        }
    } while(1);

    return 0;
}
