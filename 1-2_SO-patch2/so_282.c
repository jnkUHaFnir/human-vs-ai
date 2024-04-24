    void encode(double f, char *buf) {
    	char line[40];
    	char format[8];
    	int prec;
        int l;
    
    	l = sprintf(line, "%.17g", f);
    	if (l > 16) {
    		prec = 33 - strlen(line);
    		l = sprintf(line, "%.*g", prec, f);
    		while(l > 16) {
    			/* putc('.', stdout);*/
    			prec -=1;
    			l = sprintf(line, "%.*g", prec, f);
    		}
    	}
    	strcpy(buf, line);
    }