    void remove_zero(struct number *a)
    {
        char *b = a->digits;
        char *end = a->digits + sizeof a->digits - 1;
    
        while (b < end && *b == '0')
            b++;
    
        if (b != a->digits)
        {
            memmove(a->digits, b, end-b);
            a->digits[n] = '\0';
        }
    }