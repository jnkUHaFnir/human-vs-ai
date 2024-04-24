#include <stdio.h>
#include <string.h>

int main() {
    char newInvoice[2];
    
    printf("Would you like to print another invoice? Y=yes, N=No\n");
    do {
        scanf("%s", newInvoice);
        
        if(strcmp(newInvoice, "Y") == 0) {
            printf("Printing another invoice...\n");
        }
        else if(strcmp(newInvoice, "N") == 0) {
            printf("Goodbye!\n");
        }
        else {
            printf("Invalid Entry (it has to be Y or N):\n");
        }
    } while(strcmp(newInvoice, "N") != 0);

    return 0;
}
