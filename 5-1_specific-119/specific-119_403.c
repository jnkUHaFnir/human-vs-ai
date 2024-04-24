char *ft_itoa(int x) {
    char *s;
    size_t len;
    long int n;

    n = x;
    if (x == -2147483648)
        return ft_strdup("-2147483648");

    len = ft_intlen(n) + 1;
    if (!(s = (char*)malloc(sizeof(char) * (len + (n < 0 ? 1 : 0))))  // Adjusting memory allocation for negative numbers
        return NULL;

    if (n == 0)
        s[0] = '0';

    if (n < 0) {
        s[0] = '-';
        n = -n;
    }
    s[len + (n < 0 ? 0 : -1)] = '\0';  // Adjusting position of '\0' for negative numbers
    while (n) {
        len--;
        s[len - 1] = (n % 10) + '0';
        n /= 10;
    }
    return s;
}
