#include <stdio.h>

int main() {
    int type, daysRented, numberOfMiles, rentalTotal, totalRevenue = 0;

    do {
        printf("Enter 0 for End, 1 for sports car, 2 for midsize, 3 for economy: ");
        scanf("%d", &type);

        if (type != 0) {
            printf("Enter days rented: ");
            scanf("%d", &daysRented);
            printf("Enter the number of miles: ");
            scanf("%d", &numberOfMiles);

            if (type == 1) {
                rentalTotal = (daysRented * 75) + (numberOfMiles * 2);
                totalRevenue += rentalTotal; // Accumulating total revenue
                printf("Rental Total: %d\n", rentalTotal);
            }
            // Add similar if conditions for type 2 and type 3 if needed
        }
    } while (type != 0);

    printf("Total Revenue: %d\n", totalRevenue); // Print total revenue at the end

    return 0;
}
