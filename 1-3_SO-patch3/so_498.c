    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    
    void deldigit(char *str)
    {
    	char *res = str;
    	int count = 0;
    
    	while (*str!='\0') {
    		if (isdigit(*str)) {
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
    
    	printf("inset word");
    	scanf("%s", str); /* you don't need the address of operator & */
    	deldigit(str);
    	return 0;
    }