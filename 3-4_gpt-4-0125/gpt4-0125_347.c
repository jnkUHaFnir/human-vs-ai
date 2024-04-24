char name[50];  // Assuming the name won't be longer than 49 characters.
int num = -1, result_odd = 0, result_even = 0, even_count = 0, odd_count = 0;
scanf("%49s", name);
#include <stdio.h>
#include <stdlib.h>

int add(int, int);

int main() {
    int num = -1, result_odd = 0, result_even = 0, even_count = 0, odd_count = 0;
    char name[50];

    printf("What is your name?\n");
    scanf("%49s", name);

    while (num != 0) {
        printf("Enter a number:\n");
        scanf("%d", &num);

        if (num == 0) break; // Break the loop immediately if 0 is entered.

        if (num % 2 == 1) {
            printf("odd\n");
            odd_count++;
            result_odd = add(result_odd, num);
        } else {
            printf("even\n");
            even_count++;
            result_even = add(result_even, num);
        }
    }

    printf("%s, the numbers you have entered are broken down as follows:\n", name);
    printf("You entered %d even numbers with a total value of %d\n", even_count, result_even);
    printf("You entered %d odd numbers with a total value of %d\n", odd_count, result_odd);

    return 0;
} 

int add(int total, int num) {
    return total + num;
}
