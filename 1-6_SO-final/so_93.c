	void myGetLine(FILE *in)
	{
		char *buffer;
		char buf[1024];
		int c, i, j;
		
		buffer= malloc(1024);
		i= 0; j= 1;
		while ((c=fgetc(in))!=EOF)
		{
			if (i<1024) buf[i++]= c;
			else {
				buffer= realloc(buffer, (j+1)*1024);
				memcpy(buffer+(j*1024), buf, 1024);
				i= 0;
				j++;
			}
		}
		memcpy(buffer+((j-1)*1024), buf, i);
		buffer[((j-1)*1024)+i+1]= '\0';
	}