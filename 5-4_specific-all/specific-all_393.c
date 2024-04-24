#include <stdio.h>

int main() {
    int value = 1;
    if (value == 1){
        int price = 0;
        int price_final;
        
        printf ("INSERT A PRICE >> ");
        scanf ("%d", &price);
        
        // Calculate 10% discount
        price_final = price - (price * 0.10);
        
        printf ("Final value: %d\n", price_final);
    }

    return 0;
}
