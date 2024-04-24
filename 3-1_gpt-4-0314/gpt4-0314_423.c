#include <stdio.h>

int main() {
    int number, count = 0, sentinel = -1;
    float sum = 0;

    printf("Enter numbers one by one. Enter -1 to stop input:\n");
    
    while (1) {
        scanf("%d", &number);
        
        if (number == sentinel) {
            break;
        }
        
        sum += number;
        count++;
    }
 
    if (count > 0) {
        printf("Average: %.2f\n", sum / count);
    } else {
        printf("No numbers entered.\n");
    }

    return 0;
}
