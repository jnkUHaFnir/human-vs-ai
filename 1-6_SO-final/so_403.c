	char *ft_itoa(int x)
	{
		char    *s;
		size_t  len;
		unsigned n;
		int negative;
		
		negative = x < 0;
		n = negative ? -x : x;
		len = ft_uintlen(n) + negative;
		if (!(s = (char*)malloc(len + 1)))
			return (NULL);
		s[len] = '\0';
		if (n == 0)
			s[0] = '0';
		else
		{
			if (negative)
				s[0] = '-';
			do {
				s[--len] = (n % 10) + '0';
				n /= 10;
			} while(n);
		}
		
		return (s);
	}