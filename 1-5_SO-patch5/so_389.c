	char *uppercase(char source[])
	{
		 int i;
		 int len = strlen(tmp);
		 char *tmp;
		 tmp = malloc(len*sizeof(char));
		 strcpy(tmp, source);
		 for(i=0; i<len-1; ++i){
			if (tmp[i]>= 'a' && tmp[i]<= 'z'){
				tmp[i]= tmp[i]-'a' +'A';
			}
		}
		
			return tmp;
	}