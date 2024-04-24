#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int add_even(int);
int add_odd(int);

int main() {
    int num, result_odd = 0, result_even = 0, even_count = 0, odd_count = 0;
    char name[100]; // Fixed the declaration of name as an array of characters

    printf("What is your name?\n");
    scanf("%s", name); // Changed &name to name as name is already a pointer

    do {
        printf("Enter a number:\n");
        scanf("%d", &num);

        if (num % 2 == 1) {
            printf("Odd\n");
            odd_count++;
            result_odd += num; // Calculate sum of odd numbers
        } else if (num != 0) {
            printf("Even\n");
            even_count++;
            result_even += num; // Calculate sum of even numbers
        }
    } while (num != 0);

    printf("%s, the numbers you have entered are broken down as follows:\n", name);
    printf("You entered %d even numbers with a total value of %d\n", even_count, result_even);
    printf("You entered %d odd numbers with a total value of %d\n", odd_count, result_odd);

    return 0;
} 

int add_even(int num) {
    if (num % 2 != 0) {
        return 0;
    }
    return num;
}

int add_odd(int num) {
    if (num % 2 == 0) {
        return 0;
    }
    return num;
}
