#include <stdio.h>
#include <string.h>

int menu() {
    printf("Welcome to the Silent Auction!\n");
    printf("Please make a selection from the following:\n");
    printf("View Auction [VIEW]\n");
    printf("Bid on Auction [BID]\n");
    printf("Close Auction [CLOSE]\n");
}

int main() {
    char sel[6];
    int choice;
    float user_bid;
    float cur_bid[10]; // Assuming there are 10 auctions

    do {
        menu(); // Display the menu
        scanf("%s", sel);

        if (strcmp("VIEW", sel) == 0) {
            // Handle VIEW option
            printf("View option selected.\n");
            // Add your logic here to view auctions
        } else if (strcmp("BID", sel) == 0) {
            // Handle BID option
            printf("Bid option selected.\n");
            // Add your logic here to bid on auctions
        } else if (strcmp("CLOSE", sel) == 0) {
            // Handle CLOSE option
            printf("Closing auction.\n");
            // Add your logic here to close the auction
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    } while (strcmp("CLOSE", sel) != 0);

    return 0;
}
