#include <stdio.h>

int main() {
    int value;
    printf("Enter 1 to calculate the final price: ");
    scanf("%d", &value);

    if (value == 1) {
        int price;
        printf("INSERT A PRICE >> ");
        scanf("%d", &price);
        
        int price_final = price - (price * 0.1); // Removes 10% of the price
        printf("Final value: %d\n", price_final);
    }

    return 0;
}
