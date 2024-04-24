#include <stdio.h>

int main() {
    if (1) { // Assuming you have a condition that leads to this block
        int price = 0;
        printf("INSERT A PRICE >> ");
        scanf("%d", &price); // First, get the price from the user

        // Now, calculate the final price, decreasing by 10%
        // If you want to work exclusively with integers:
        int price_final = price - (price / 10);

        printf("Final value %d\n", price_final);
    }

    return 0;
}
#include <stdio.h>

int main() {
    float price = 0.0f;
    printf("INSERT A PRICE >> ");
    scanf("%f", &price); // Use %f to read a float

    float price_final = price * 0.9f; // Now correctly reduces the price by 10%
    printf("Final value %.2f\n", price_final); // %.2f limits the printed result to two decimal places
    
    return 0;
}
