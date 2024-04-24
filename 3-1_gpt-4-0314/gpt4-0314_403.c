#include <limits.h>

char *ft_itoa(int x) {
    char *s;
    size_t len;
    long int n;

    n = x;
    if (n == INT_MIN)
        return (ft_strdup("-2147483648"));

    // rest of the code
}
