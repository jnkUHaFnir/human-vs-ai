	char *input(void)
	{
		int n = 1;
		char *str = malloc(n);
		char *s= str;
		while((*s=getchar())!='\n')
		{
			char *newstr;
			n++;
			if ((newstr = realloc(str,n))==0)
				return 0;				// out of memory
			if (newstr != str) {
				s= newstr + (s-str);	// let s point into the new string
				str= newstr;			// set str point to the new string
			}
			s++;
		}
		*s= '\0';
		return str;
	}