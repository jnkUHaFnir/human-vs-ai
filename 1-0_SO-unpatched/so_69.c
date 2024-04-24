c
#include <stdio.h>
int main(void) {
    float sales = 0;
    float salary;
    int res;
    do {
        printf("Enter sales in dollars (-1 to end): ");
        fflush(stdout);
        res = scanf(" %f", &sales);
        // Notice    ^ the addition of a space before %f, this will help by
        // discarding all space at the beginning of the line, making the
        // program just a little bit more flexible.
        if (res == EOF) {
            // Something bad happened.
            if (feof(stdin))
                fputs("End of input reached.\n", stderr);
            else
                perror("Error reading input");
            return 1;
        }
        if (sales != -1 && sales < 0) {
            // Perhaps it would be a better idea to say "invalid value" here?
            puts("Input error, please try again.");
            res = 0;
        }
        
        // Either the value was read correctly (res = 1) or it wasn't (res = 0).
        // In any case, consume the rest of the line.
        scanf("%*[^\n]");
    } while (res != 1 && sales != -1.0);
    if (sales != -1.0) {
        salary = 200 + (0.09 * sales);
        printf("Salary is: $%.2f\n", salary);
    }
    return 0;
}
  [1]: https://stackoverflow.com/questions/18170410/what-is-the-use-of-fflushstdin-in-c-programming/18170435#18170435