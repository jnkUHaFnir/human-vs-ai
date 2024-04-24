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
            // Logic for viewing auction
            printf("You selected VIEW.\n");
        } else if (strcmp("BID", sel) == 0) {
            // Logic for bidding on auction
            printf("You selected BID.\n");
            printf("Which auction would you like to bid on?\n");
            scanf("%d", &choice);
            printf("How much would you like to bid?\n");
            scanf("%f", &user_bid);
            // Update bid logic
            cur_bid[choice] += user_bid;
        } else if (strcmp("CLOSE", sel) == 0) {
            // Logic for closing auction
            printf("Closing auction...\n");
            break; // Exit the loop
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    } while (1); // Infinite loop until user chooses to close

    printf("Thank you for using the Silent Auction system.\n");

    return 0;
}
