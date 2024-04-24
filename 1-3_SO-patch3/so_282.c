    void encode(double f, char *buf) {
    	char line[40];
    	char format[8];
    	int prec;
    
    	sprintf(line, "%.17g", f);
    	if (strlen(line) > 16) {
    		prec = 33 - strlen(line);
    		sprintf(line, "%.*g", prec, f);
    		while(strlen(line) > 16) {
    			/* putc('.', stdout);*/
    			prec -=1;
    			sprintf(line, "%.*g", prec, f);
    		}
    	}
    	strcpy(buf, line);
    }