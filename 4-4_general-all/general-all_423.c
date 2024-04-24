#include <stdio.h>

int main() {
    int num, count = 0;
    int sum = 0;
    float average;

    printf("Enter numbers (enter '0' to calculate the average): \n");

    while (1) {
        scanf("%d", &num);
        
        // Check if the user entered 0 to exit the loop
        if (num == 0) {
            break;
        }

        sum += num;
        count++;
    }

    if (count == 0) {
        printf("No numbers entered.\n");
    } else {
        average = (float)sum / count;
        printf("Average of %d numbers is %.2f\n", count, average);
    }

    return 0;
}
