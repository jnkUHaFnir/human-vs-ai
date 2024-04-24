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
    char sel[6];
    int choice;
    float user_bid;
    int cur_bid[10] = {0};  // Assuming you have 10 auctions

    do {
        menu(); // Print the menu at the start of each loop iteration

        scanf("%s", sel);

        if (strcmp("VIEW", sel) == 0) {
            // View logic
            printf("View selected.\n");
        } else if (strcmp("BID", sel) == 0) {
            // Bid logic
            printf("Bid selected. Which auction would you like to bid on?\n");
            scanf("%d", &choice);
            
            printf("How much would you like to bid?\n");
            scanf("%f", &user_bid);
            
            // Handle bid logic here
            cur_bid[choice] += user_bid;
        } else if (strcmp("CLOSE", sel) == 0) {
            // Close auction logic
            printf("Close selected.\n");
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    } while (strcmp("CLOSE", sel) != 0);

    return 0;
}
