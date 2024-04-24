	void myGetLine(FILE *in)
	{
		char *buffer;
		int c, i, j;
		
		buffer= malloc(1024);
		i= 0; j= 1024;
		while ((c=fgetc(in))!=EOF)
		{
			if (i==j) {
				j += 1024;
				buffer= realloc(buffer, j);
			}
			buffer[i++]= c;
		}
		buffer[i]= '\0';
	}