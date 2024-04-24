#include <stdio.h>
#include <stdlib.h>

int add_even(int);
int add_odd(int);

int main() {
    int num, result_odd = 0, result_even = 0, even_count = 0, odd_count = 0;
    char name[50];
    int numbers[100];
    int index = 0;

    printf("What is your name?\n");
    fgets(name, sizeof(name), stdin);

    printf("Enter a number (0 to stop):\n");

    while (1) {
        scanf("%d", &num);
        
        if (num == 0) {
            printf("%s, the numbers you have entered are broken down as follows:\n", name);
            for (int i = 0; i < index; i++) {
                if (numbers[i] % 2 == 0) {
                    even_count++;
                    result_even += numbers[i];
                } else {
                    odd_count++;
                    result_odd += numbers[i];
                }
            }
            break;
        }
        
        numbers[index] = num;
        index++;
    }

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
