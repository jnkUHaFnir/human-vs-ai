#include <stdio.h>

int main() {
    int value = 1;
    if (value == 1){
        int price = 0;
        printf("INSERT A PRICE >> ");
        scanf("%d", &price);
        
        int price_final = price - (price * 0.1); // Calculating 10% off price
        printf("Final value: %d\n", price_final);
    }

    return 0;
}
