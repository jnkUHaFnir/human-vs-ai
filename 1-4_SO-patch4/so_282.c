    void encode(double f, char *buf) {
    	char line[40];
    	char format[8];
    	int prec;
    
    	sprintf(line, "%.17g", f);
    	if (strlen(line) > 16) {
    		prec = 33 - strlen(line);
    		sprintf(format,"%%.%2dg", prec);
    		sprintf(line, format, f);
    		while(strlen(line) > 16) {
    			/* putc('.', stdout);*/
    			prec -=1;
    			sprintf(format,"%%.%2dg", prec);
    			sprintf(line, format, f);
    		}
    	}
    	strcpy(buf, line);
    }