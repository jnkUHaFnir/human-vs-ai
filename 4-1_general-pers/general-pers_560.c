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
    float cur_bid[10] = {0}; // Assuming there are 10 auctions

    do {
        menu();

        scanf("%s", sel);

        if (strcmp("VIEW", sel) == 0) {
            // Action for viewing auction
            printf("Viewing auction...\n");
        } else if (strcmp("BID", sel) == 0) {
            printf("Which auction would you like to bid on?\n");
            scanf("%d", &choice);

            printf("How much would you like to bid?\n");
            scanf("%f", &user_bid);

            // Ensure valid input and handle bidding logic
            if (choice >= 0 && choice < 10 && user_bid > 0) {
                cur_bid[choice] += user_bid;
                printf("Bid successful!\n");
            } else {
                printf("Invalid auction or bid amount. Please try again.\n");
            }
        } else if (strcmp("CLOSE", sel) == 0) {
            // Action for closing auction
            printf("Closing auction...\n");
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    } while (strcmp("CLOSE", sel) != 0);

    return 0;
}
