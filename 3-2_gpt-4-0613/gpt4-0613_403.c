char *ft_itoa(int x) {
    char *s;
    size_t len;
    long int n;

    n = x;
    if (x == -2147483648) {
        s = (char*)malloc(sizeof(char) * 12); // Reserving memory for 11 characters and '\0'
        if (!s)
            return (NULL);
        return ft_strcpy(s, "-2147483648");
    }
    len = ft_intlen(n) + 1 + (n < 0 ? 1 : 0);
    if (!(s = (char*)malloc(sizeof(char) * len)))
        return (NULL);
    s[len - 1] = '\0';
    if (n == 0)
        s[0] = '0';
    if (n < 0) {
        s[0] = '-';
        n = -n;
    }
    while (n) {
        len--;
        s[len - 1] = (n % 10) + '0';
        n /= 10;
    }
    return (s);
}
