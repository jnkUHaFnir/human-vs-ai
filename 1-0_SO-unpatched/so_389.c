	char *uppercase(char source[])
	{
		 int i;
		 size_t len = strlen(source);
		 char *tmp;
		 tmp = malloc(len+1);
		 if (tmp!==NULL){
			 memcpy(tmp, source, len+1);
			 for(i=0; i<len; ++i){
				if (tmp[i]>= 'a' && tmp[i]<= 'z'){
					tmp[i]= tmp[i]-'a' +'A';
				}
			}
		}
		else {
			return NULL;
		}
		return tmp;
	}