    #include <stdio.h>
    #include <string.h>
    
    int main(void) {
    	static char buf[512];
    	static char name[512];
    
    	int is_valid = 0;
    
    	while (!is_valid) {
    		fgets(buf, sizeof(buf), stdin);
    
    		size_t line_len = strlen(buf);
    		if (line_len > 0 && buf[line_len-1] == '\n') {
    			buf[line_len-1] = '\0';
    			line_len--;
    		}
    
    		if (sscanf(buf, " %[a-zA-Z]s", name) == 1 && buf[strlen(name)] == '\0') {
    			is_valid = 1;
    		} else {
    			printf("Please enter a valid name.\n");
    		}
    
    	}
    
    	printf("Name: %s\n", buf);
    
    	return 0;
    }