    void remove_zero(struct number *a)
    {
        char *b = a->digits;
        while (*b == '0')
            b++;
    
        strcpy(a->digits, b);
    }