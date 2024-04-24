#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *s) {
    char *d = malloc(strlen(s) + 1);
    if (d) strcpy(d, s);
    return d;
}

size_t ft_intlen(long int n) {
    size_t len = 0;
    if (n <= 0) {
        len = 1; // Account for the negative sign
        n = -n;  // Make n positive
    }
    while (n > 0) {
        len++;
        n /= 10;
    }
    return len;
}

char *ft_itoa(int x) {
    char *s;
    size_t len;
    long int n;

    n = x;
    if (x == -2147483648)
        return ft_strdup("-2147483648");

    len = ft_intlen(n) + 1;
    if (!(s = (char*)malloc(sizeof(char) * len)))
        return NULL;

    if (n == 0)
        s[0] = '0';

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
