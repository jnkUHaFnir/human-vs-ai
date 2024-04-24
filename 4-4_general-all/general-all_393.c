#include <stdio.h>

int main() {
    int price = 0;

    printf("INSERT A PRICE >> ");
    scanf("%d", &price);
    
    double price_final = price - (price * 0.1); // Calculate the final price after removing 10%

    printf("Final value: %.2f\n", price_final); // Assuming price is a floating-point value

    return 0;
}
