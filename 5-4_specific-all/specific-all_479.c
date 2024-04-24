#include <stdio.h>
#include <string.h>

int main() {
    char newInvoice[2]; // 2 characters for Y/N and null terminator
    
    do {
        printf("Would you like to print another invoice? Y=yes, N=No\n");
        scanf("%1s", newInvoice); // Read only a single character
        
        if(strcmp(newInvoice, "Y") == 0) {
            printf("Processing...\n");
            // Your processing code here
        }
        else if(strcmp(newInvoice, "N") != 0) {
            printf("Invalid Entry (it has to be Y or N)\n");
        }
    } while(strcmp(newInvoice, "N") != 0);

    printf("Goodbye!\n");

    return 0;
}
