#include <stdio.h>

int main() {
    int price = 0;

    printf("INSERT A PRICE >> ");
    scanf("%d", &price);

    float price_final = price - (price * 0.1); // Deduct 10% from the price

    printf("Final value: %.2f\n", price_final);

    return 0;
}
