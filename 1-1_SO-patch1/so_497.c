    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    
    void deldigit(char *str)
    {
        char *res = str;
        int count = 0;
    
        while (*str != '\0') {
            if (isdigit((unsigned char)*str)) {
                count++;
            } else {
                *(str - count) = *str;
            }
            str++;
        }
        *(str - count) = '\0';
        printf("%s", res);
    }
    
    int main(void)
    {
        char str[100];
    	char *ptr;
    
        printf("inset word: ");
        if (fgets(str, sizeof str, stdin)) {
    		if ((ptr = strchr(str, '\n'))) {
    			*ptr = '\0';
    		}
        	deldigit(str);
    	}
        return 0;
    }