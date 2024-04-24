#include <stdio.h>
#include <string.h>

int main() {
    char sel[6];
    int choice;
    float user_bid;
    float cur_bid[5]; // Assume there are 5 auction options

    do {
        printf("Welcome to the Silent Auction!\n");
        printf("Please make a selection from the following:\n");
        printf("View Auction [VIEW]\n");
        printf("Bid on Auction [BID]\n");
        printf("Close Auction [CLOSE]\n");

        scanf("%s", sel);

        if (strcmp("VIEW", sel) == 0) {
            // View Auction logic
            printf("Viewing Auction...\n");
        } else if (strcmp("BID", sel) == 0) {
            printf("Which auction would you like to bid on?\n");
            scanf("%d", &choice);
            // Bid on Auction logic
            printf("How much would you like to bid?\n");
            scanf("%f", &user_bid);
            cur_bid[choice] += user_bid;
        } else if (strcmp("CLOSE", sel) == 0) {
            // Close Auction logic
            printf("Closing Auction...\n");
            break;  // Exit the loop when CLOSE is selected
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    } while (1);

    return 0;
}
