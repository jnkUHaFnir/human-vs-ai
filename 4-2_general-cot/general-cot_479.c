#include <stdio.h>
#include <string.h>

int main() {
    char newInvoice[2]; // Need space for the character and the null terminator

    printf("Would you like to print another invoice? Y=yes, N=No\n");
    
    do {
        scanf("%1s", newInvoice); // Read only one character

        if (strcmp(newInvoice, "Y") == 0) {
            printf("You entered Yes. Asking the question again...\n");
        }
        else if (strcmp(newInvoice, "N") == 0) {
            printf("Goodbye!\n");
            break; // Exit the loop if N is entered
        }
        else {
            printf("Invalid Entry (it has to be Y or N):\n");
        }

    } while (1); // Infinite loop until "N" is entered

    return 0;
}
