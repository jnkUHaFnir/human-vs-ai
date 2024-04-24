#include <stdio.h>

int main() {
    int value;
    
    printf("Enter a value (1 for discount calculation): ");
    scanf("%d", &value);
    
    if (value == 1) {
        int price = 0;
        float discount = 0.1; // 10% discount

        printf("INSERT A PRICE >> ");
        scanf("%d", &price);

        float price_final = price - (price * discount);

        printf("Final value: %.2f\n", price_final);
    }

    return 0;
}
