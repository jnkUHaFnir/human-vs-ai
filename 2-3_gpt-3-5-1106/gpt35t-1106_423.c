#include <stdio.h>

int main() {
    int num, sum = 0, count = 0;
    float average;

    printf("Enter numbers (enter any non-numeric character to stop): \n");
    
    while(scanf("%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count != 0) {
        average = (float)sum / count;
        printf("The average of the numbers is: %.2f\n", average);
    } else {
        printf("No valid numbers were entered!\n");
    }

    return 0;
}
