#include <stdio.h>
#include <string.h>

int main() {
    char newInvoice[2]; // Array to store the user input

    printf("Would you like to print another invoice? Y=yes, N=No\n");
    
    do {
        scanf("%1s", newInvoice); // %1s to read only one character
        if(strcmp(newInvoice, "Y") == 0 || strcmp(newInvoice, "y") == 0) {
            printf("Printing another invoice...\n");
        }
        else if(strcmp(newInvoice, "N") == 0 || strcmp(newInvoice, "n") == 0) {
            printf("Goodbye!\n");
            break; // Exit the loop
        }
        else {
            printf("Invalid Entry (it has to be y or n):\n");
        }
    } while(1); // Loop indefinitely until user enters Y or N

    return 0;
}
