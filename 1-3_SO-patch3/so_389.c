	char *uppercase(char source[])
	{
		 int i;
		 int len = strlen(tmp);
		 char *tmp;
		 tmp = malloc(len+1);
		 strcpy(tmp, source);
		 for(i=0; i<len; ++i){
			if (tmp[i]>= 'a' && tmp[i]<= 'z'){
				tmp[i]= tmp[i]-'a' +'A';
			}
		}
		
        return tmp;
	}