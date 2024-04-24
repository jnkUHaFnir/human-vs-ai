	char line[260];//line buffer (hardcoded length for quick demo)
	char *tok={0};
	FILE *f;
	f = fopen("archive.txt","r");//did not have example file for this demo
                                 //therefore do not have delimiters, will guess
	if(f==0) return 0;
	while(fgets(line, 260, f))
	{
	    tok = strtok(line, " ,\n\t");// will tokenize on space, newline, tab and comma
		if(tok)
		{
			len = strlen(tok);
			Archive[i].id = malloc(len + 1);//include space for NULL termination
			strcpy(Archive[i].id, tok);
			
		}
        else {//handle error, free memory and return}
        tok = strtok(NULL, " ,\n\t");//note NULL in first arg this time 
		if(tok)
		{
			len = strlen(tok);
			Archive[i].name= malloc(len + 1);//include space for NULL termination
			strcpy(Archive[i].name, tok);
			
		}
        else {//handle error, free memory and return}
        //...And so on