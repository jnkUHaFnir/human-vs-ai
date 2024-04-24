#include <stdlib.h>
#include <limits.h>

// Function to calculate the length of an integer
size_t ft_intlen(long int n) {
    size_t len = 0;
    if (n < 0) {
        len++; // Account for the negative sign
        n = -n; // Convert to positive for counting digits
    }
    while (n) {
        len++;
        n /= 10;
    }
    return len;
}

// Function to convert an integer to a string
char *ft_itoa(int x) {
    char *s;
    size_t len;
    long int n;

    n = x;
    
    // Handle INT_MIN edge case
    if (x == INT_MIN) {
        return strdup("-2147483648"); // Statically allocated string
    }

    len = ft_intlen(n) + 1;
    if (!(s = (char*)malloc(sizeof(char) * len))) {
        return NULL; // Memory allocation failure
    }

    if (n == 0) {
        s[0] = '0';
    }

    if (n < 0) {
        s[0] = '-';
        n = -n;
    }

    s[len - 1] = '\0';
    while (n) {
        len--;
        s[len - 1] = (n % 10) + '0';
        n /= 10;
    }

    return s;
}
