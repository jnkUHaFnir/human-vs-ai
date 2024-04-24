#include <stdio.h>
#include <stdlib.h>

int add_even(int);
int add_odd(int);

int main() {
    int num, result_odd = 0, result_even = 0, even_count = 0, odd_count = 0;
    char name[50]; // Define as an array of characters

    printf("What is your name?\n");
    scanf("%s", name); // Use the array name to store user's name

    while (1) { // Infinite loop until break

        printf("Enter a number:\n");
        scanf("%d", &num);

        if (num == 0) {
            printf("%s, the numbers you have entered are broken down as follows:\n", name);
            result_even = add_even(num);
            printf("You entered %d even numbers with a total value of %d\n", even_count, result_even);
            result_odd = add_odd(num);
            printf("You entered %d odd numbers with a total value of %d\n", odd_count, result_odd);
            
            break; // Exit the loop when 0 is entered
        }

        if (num % 2 == 1) {
            printf("odd\n");
            odd_count++;
        } else {
            printf("even\n");
            even_count++;
        }
    }
    return 0;
} 

int add_even(int num) {
    static int sum_even = 0;

    if (num % 2 != 0) {
        return 0;
    }

    sum_even += num;
    return sum_even;
}

int add_odd(int num) {
    static int sum_odd = 0;

    if (num % 2 == 0) {
        return 0;
    }
    
    sum_odd += num;
    return sum_odd;
}
