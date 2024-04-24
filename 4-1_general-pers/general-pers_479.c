#include <stdio.h>
#include <string.h>

int main() {
    char newInvoice[2];
    
    do {
        printf("Would you like to print another invoice? Y=yes, N=no\n");
        scanf("%1s", newInvoice);
        getchar(); // consume the newline character
        
        if (strcmp(newInvoice, "Y") == 0 || strcmp(newInvoice, "y") == 0) {
            printf("Printing another invoice...\n");
        } else if (strcmp(newInvoice, "N") == 0 || strcmp(newInvoice, "n") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid entry. Please enter Y or N.\n");
        }
    } while (1); // Infinite loop until user provides valid input
    
    return 0;
}
