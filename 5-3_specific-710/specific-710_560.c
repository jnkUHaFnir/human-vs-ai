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
    float cur_bid[10];  // Assuming 10 auctions to bid on

    menu();

    do {
        printf("\nEnter your selection: ");
        scanf("%s", sel);

        if (strcmp("VIEW", sel) == 0) {
            // Handle view auction logic
            printf("Viewing Auction...\n");
        } else if (strcmp("BID", sel) == 0) {
            printf("Which auction would you like to bid on? (Enter auction number): ");
            scanf("%d", &choice);
            // Handle bid auction logic
            if (choice < 0 || choice >= 10) {
                printf("Invalid auction number\n");
            } else {
                printf("How much would you like to bid? ");
                scanf("%f", &user_bid);
                // Handle bid amount logic
                cur_bid[choice] += user_bid;
                printf("Bid successful!\n");
            }
        } else if (strcmp("CLOSE", sel) == 0) {
            // Handle close auction logic
            printf("Closing Auction...\n");
        } else {
            printf("Invalid selection. Please try again.\n");
        }

    } while (strcmp("CLOSE", sel) != 0);

    return 0;
}
