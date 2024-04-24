#include <stdio.h>
#include <stdlib.h>

int add_even(int);
int add_odd(int);

int main() {
    int num, result_odd=0, result_even=0, even_count=0, odd_count=0;
    char name[20];

    printf("What is your name?\n");
    scanf("%s", name);

    do {
        printf("Enter a number (Enter 0 to exit):\n");
        scanf("%d", &num);

        if (num % 2 == 1) {
            printf ("odd\n");
            odd_count++;
            result_odd += num;
        } else if (num % 2 == 0 && num != 0) {
            printf("even\n");
            even_count++;
            result_even += num;
        }
    } while (num != 0);

    printf("%s, the numbers you have entered are broken down as follows:\n",
                  name);
    printf("You entered %d even numbers with a total value of %d\n",
                   even_count, result_even);
    printf("You entered %d odd numbers with a total value of %d\n",
                   odd_count, result_odd);

    return 0;
} 

int add_even(int num) {
    static int sum = 0;

    if (num == 0) {
        return sum;
    }

    if (num % 2 == 0) {
        sum += num;
    }

    return add_even(num-1);
}

int add_odd(int num) {
    static int sum = 0;

    if (num == 0) {
        return sum;
    }

    if (num % 2 == 1) {
        sum += num;
    }

    return add_odd(num-1);
}
