#include <stdio.h>

int main() {
    int price = 0;
    float price_final = 0.0;

    printf("INSERT A PRICE >> ");
    scanf("%d", &price);

    price_final = price - (price * 0.10); // Deducting 10% from the price

    printf("Final value: %.2f\n", price_final); // Displaying the final price with 2 decimal places

    return 0;
}
