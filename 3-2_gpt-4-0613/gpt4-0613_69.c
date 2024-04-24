while (sales != -1)
{
    printf("Enter sales in dollars (-1 to end): ");
    if(scanf("%f", &sales) != 1){                      
        while(getchar() != '\n');        
        puts("Input error, please try again");
    }else{
        if (sales != -1)
        {
            salary = 200 + (0.09 * sales);
            printf("Salary is: $%.2f\n", salary);
        }
    }
}
``` 

Here, If `scanf()` fails (returns a value less than the total number of input items expected, which is `1`), it means that the user has entered a char or a string instead of a number. So, we need to clean the buffer before the next iteration. We achieve this by using `while(getchar() != '\n');` line which takes all the remaining characters in the `stdin` buffer including '\n' itself. Thus, `stdin` is ready for a new entry. 

Also note, using floating point numbers for money can lead to rounding errors and precision loss. It might be better to use integer types (like `int` or `long long`) and to consider storing cents instead of dollars (or the smallest unit your currency allows).
