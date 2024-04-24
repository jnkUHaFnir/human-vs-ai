	char *input(void)
	{
		int n = 2;
		char *str = malloc(n*sizeof(char));
		char *s= str;
		while((*s=getchar())!='\n')
		{
			char *newstr;
			n++;
			if ((newstr = realloc(str,n*sizeof(char)))==0)
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