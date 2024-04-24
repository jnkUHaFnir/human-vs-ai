    #include <stdio.h>
    #include <stdlib.h>
    
    int add_even(int);
    int add_odd(int);
    
    int main(void) {
        int num, result_odd, result_even, even_count = 0, odd_count = 0;
        char name[100];
    
        printf("What is your name? ");
        if (scanf("%99[^\n]", name) != 1)
            return 1;
        for (;;) {
            printf("Enter a number: ");
            if (scanf("%d", &num) != 1 || num == 0)
                break;
    
            if (num % 2 == 1) {
                printf("odd\n");
                odd_count++;
                add_odd(num);
            } else {
                printf("even\n");
                even_count++;
                add_even(num);
            }
            printf("%s, the numbers you have entered are broken down as follows:\n", name);
            result_even = add_even(0);
            printf("You entered %d even numbers with a total value of %d\n",
                   even_count, result_even);
            result_odd = add_odd(0);
            printf("You entered %d odd numbers with a total value of %d\n",
                   odd_count, result_odd);
        }
        return 0;
    } 
    
    int add_even(int num) {
        static int sum = 0;
    
        if (num % 2 == 0) {
            sum += num;
        }
        return sum;
    }
    
    int add_odd(int num) {
        static int sum = 0;
    
        if (num % 2 != 0) {
            sum += num;
        }
        return sum;
    }