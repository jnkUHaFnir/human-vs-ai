    #include <stdio.h>
    #include <strings.h>
    #include <stdlib.h>
    
    int main()
    {
    	double decpart;
    	printf("Enter a floating number num: ");
    	char buf[100];
    	int len;
    	char *endptr;
    
    	while (1)
    	{
    		fgets(buf,sizeof(buf),stdin);
    		len = strlen(buf)-1;
    
    		// right strip spaces (replace by linefeed like fgets ends the input)
    		while(len>0)
    		{
    			len--;
    			if (buf[len]==' ')
    			{
    				buf[len]='\n';
    			}
    			else
    			{
    				break;
    			}
    		}
    
    		double floatnum = strtod(buf,&endptr);
    
    		if (endptr[0]!='\n')
    		{
    			printf("Invalid floating point number, enter again: ");
    		}
    		else
    		{
    			int intpart = (int)floatnum;
    			double decpart = floatnum - intpart;
    			if (decpart == 0.000000){
    				printf("Invalid floating point number, enter again: ");
    			}
    			else
    			{
    				printf("Number entered = %.2f\n", floatnum);
    				break;
    			} 
    		}
    	}
    	return 0;
    }