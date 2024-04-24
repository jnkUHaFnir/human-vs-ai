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
    
    // Return the selection made by the user
    if ((strcmp(sel, "VIEW") == 0) || (strcmp(sel, "BID") == 0)) {
        return 1; // 1 represents VIEW or BID
    } else if (strcmp(sel, "CLOSE") == 0) {
        return 0; // 0 represents CLOSE
    } else {
        return -1; // Invalid selection
    }
}

int main() {
    int choice;
    float user_bid;
    int cur_bid[10] = {0}; // Assuming 10 auction items
    
    do {
        int selection = menu();

        if (selection == 1) {
            if (strcmp("VIEW", sel) == 0) {
                // Code to view auction
            } else if (strcmp("BID", sel) == 0) {
                printf("Which auction would you like to bid on?\n");
                scanf("%d", &choice);
                // Code to place a bid on the chosen auction
                printf("How much would you like to bid?\n");
                scanf("%f", &user_bid);
                // Update bid amount
                cur_bid[choice] += user_bid;
            }
        } else if (selection == -1) {
            printf("Invalid selection. Please try again.\n");
        }

    } while (selection != 0);

    // Code to close the auction
    
    return 0;
}
