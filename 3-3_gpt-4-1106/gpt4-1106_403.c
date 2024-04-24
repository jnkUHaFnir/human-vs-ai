#include <stdlib.h> // For `malloc` and `free`

size_t ft_intlen(long int n);
char *ft_strdup(const char *s);

char *ft_itoa(int x) {
    char *s;
    size_t len;
    long int n = x;

    // Special handling for INT_MIN
    if (x == -2147483648) {
        return (ft_strdup("-2147483648"));
    }

    // Compute length and allocate memory
    len = ft_intlen(n) + 1; // +1 for the null terminator
    s = (char*)malloc(sizeof(char) * len);
    if (!s) {
        return (NULL);
    }

    // Handle 0 explicitly
    if (n == 0) {
        s[0] = '0';
        s[1] = '\0'; // Don't forget the null terminator
        return s;
    }

    s[len - 1] = '\0'; // Null terminator for the string
    if (n < 0) {
        s[0] = '-';
        n = -n; // Be cautious with this line (n = -n), it won't work if n is INT_MIN, but we already handled INT_MIN case above
    }

    // Fill in the number from the end
    while (n != 0) {
        len--;
        s[len - 1] = (n % 10) + '0'; // Correct index for the digit
        n /= 10;
    }
    return s;
}
