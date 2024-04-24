#include <stdio.h>
#include <string.h>

void menu() {
    printf("Welcome to the Silent Auction!\n");
    printf("Please make a selection from the following:\n");
    printf("View Auction [VIEW]\n");
    printf("Bid on Auction [BID]\n");
    printf("Close Auction [CLOSE]\n");
}

int main() {
    char sel[6]; // Making sure it's large enough for the word plus null terminator
    int choice;
    float user_bid; // Assuming these variables are declared elsewhere

    do {
        menu();
        scanf("%5s", sel); // Using %5s to prevent buffer overflow

        if (strcmp(sel, "VIEW") == 0) {
            // View logic here
            printf("Viewing auctions...\n");
        } else if (strcmp(sel, "BID") == 0) {
            // Bid logic here
            printf("Bid on which auction?\n");
            scanf("%d", &choice);
            // Assuming there's logic here to check if choice is valid

            printf("How much would you like to bid?\n");
            scanf("%f", &user_bid);
            // Assuming there's logic here to process the bid
        } else if (strcmp(sel, "CLOSE") == 0) {
            // Close logic here
            printf("Closing auction...\n");
        } else {
            printf("Invalid selection, please try again.\n");
        }
        // Loop will exit if "CLOSE" is selected, because of the condition in while
    } while (strcmp(sel, "CLOSE") != 0);

    return 0;
}
