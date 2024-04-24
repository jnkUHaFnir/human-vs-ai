#include <stdio.h>

int main() {
    int type, daysRented, numberOfMiles, rentalTotal;

    do{
        printf("Enter 0 for End, 1 for sports car, 2 for midsize, 3 for economy: ");
        scanf("%d", &type);

    } while (type != 0);

    printf("Enter days rented: ");
    scanf("%d", &daysRented);
    printf("Enter the number of miles: ");
    scanf("%d", &numberOfMiles);

    if (type == 1){
        rentalTotal = (daysRented * 75) + (numberOfMiles * 2);
        printf("%i\n", rentalTotal);
    }

    return 0;
}
