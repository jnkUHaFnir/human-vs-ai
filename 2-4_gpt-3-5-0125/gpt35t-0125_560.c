#include <stdio.h>
#include <string.h>

int menu() {
    printf("Welcome to the Silent Auction!\n");
    printf("Please make a selection from the following:\n");
    printf("View Auction [VIEW]\n");
    printf("Bid on Auction [BID]\n");
    printf("Close Auction [CLOSE]\n");

    return 0;
}

int main() {
    char sel[6];
    int choice;
    float user_bid;
    float cur_bid[10]; // assuming you have 10 auctions

    do {
        menu();
        scanf("%s", sel);

        if (strcmp("VIEW", sel) == 0) {
            // Logic for viewing auction
        }
        else if (strcmp("BID", sel) == 0) {
            printf("Which auction would you like to bid on?\n");
            scanf("%d", &choice);
            // Logic for bidding on auction
        }
        else if (strcmp("CLOSE", sel) == 0) {
            break; // Exit the loop and end the program
        }
        else {
            // Invalid selection, display an error message
            printf("Invalid selection, please try again.\n");
        }

    } while (1); // Infinite loop until user selects "CLOSE"

    // Additional logic for closing the auction

    return 0;
}
