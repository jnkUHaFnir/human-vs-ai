	char *myGetLine(FILE *in)
	{
		char *buffer= NULL;
		int c, i, j;
		
		i= 0; j= 0;
		do
		{
			c= fgetc(in);
			if (i==j) {
				j += 1024;
				buffer= realloc(buffer, j);
			}
			if (c==EOF) break;
			buffer[i++]= c;
		}
		buffer[i]= '\0';
		return buffer;
	}