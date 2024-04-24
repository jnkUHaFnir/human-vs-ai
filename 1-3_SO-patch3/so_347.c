    #include <stdio.h>
    #include <stdlib.h>
    
    int add_even(int);
    int add_odd(int);
    
    int main(void) {
        int num, result_odd, result_even, even_count, odd_count;
        char name[100];
    
        printf("What is your name?\n");
        if (scanf("%99s", name) != 1)
            return 1;
        while (num != 0) {
            printf("Enter a number:\n");
            if (scanf("%d", &num) != 1)
                break;
    
            if (num % 2 == 1) {
                printf("odd\n");
                odd_count++;
                add_odd(num);
            } else
            if (num == 0) {
                printf("%s, the numbers you have entered are broken down as follows:\n",
                      name);
                result_even = add_even(num);
                printf("You entered %d even numbers with a total value of %d\n",
                       even_count, result_even);
                result_odd = add_odd(num);
                printf("You entered %d odd numbers with a total value of %d\n",
                       odd_count, result_odd);
            } else {
                printf("even\n");
                even_count++;
                add_even(num);
            }
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
            num += num;
        }
        return sum;
    }