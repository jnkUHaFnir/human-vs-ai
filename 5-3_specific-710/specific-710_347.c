#include <stdio.h>
#include <stdlib.h>

int add_even(int);
int add_odd(int);

int main() {
    int num, result_odd = 0, result_even = 0, even_count = 0, odd_count = 0;
    char name[50];

    printf("What is your name?\n");
    scanf("%s", name);

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == 0) {
            printf("%s, the numbers you have entered are broken down as follows:\n", name);
            printf("You entered %d even numbers with a total value of %d\n", even_count, result_even);
            printf("You entered %d odd numbers with a total value of %d\n", odd_count, result_odd);
            break;
        } else if (num % 2 == 1) {
            printf("Odd\n");
            odd_count++;
            result_odd += num;
        } else {
            printf("Even\n");
            even_count++;
            result_even += num;
        }
    }
    
    return 0;
}

int add_even(int num) {
    return num % 2 == 0 ? num : 0;
}

int add_odd(int num) {
    return num % 2 == 1 ? num : 0;
}
