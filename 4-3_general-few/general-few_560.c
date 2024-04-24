#include <stdio.h>
#include <string.h>

int menu() {
    char sel[6];

    printf("Welcome to the Silent Auction!\n");
    printf("Please make a selection from the following:\n");
    printf("View Auction [VIEW]\n");
    printf("Bid on Auction [BID]\n");
    printf("Close Auction [CLOSE]\n");

    scanf("%s", sel);
    
    return sel;
}

int main() {
    char sel[6];

    do {
        strcpy(sel, menu());

        if (strcmp("VIEW", sel) == 0) {
            // Code for viewing auction
            printf("Viewing auction...\n");
        } else if (strcmp("BID", sel) == 0) {
            // Code for bidding on auction
            printf("Bidding on auction...\n");
        } else if (strcmp("CLOSE", sel) == 0) {
            // Code for closing auction
            printf("Closing auction...\n");
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    } while (strcmp("CLOSE", sel) != 0);

    return 0;
}
