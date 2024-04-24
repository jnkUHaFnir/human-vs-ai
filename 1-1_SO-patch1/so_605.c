    //sumline.c  sum integers on each line.
    #include <stdio.h>
    int main(){
      int sum=0;
      int rowcount=0;
      char buf[30]="";
      while(! feof(stdin) )
      { 
        int in,a;
        if( ! scanf("%d",&in))
        {
        	printf("malformed int\n");
        	return 1;
        }
        if( feof(stdin) && rowcount == 0 )
        {
        	return 0;
        }
        sum += in;
        char sep[2];
        if( ! scanf("%1[,:\n]",sep) && !feof(stdin))
        {
        	fgets(buf,30,stdin);
        	printf("inexpected char %30s\n",buf);
        	return 1;
        }
        else    
        {
          ++rowcount;
        }
    
        if( sep[0]=='\n' && rowcount )
        {
        	printf("sum=%d\n",sum);
            sum=0;
    	    rowcount=0;
        }
    
        if( feof(stdin) && rowcount == 0 )
        {
        	return 0;
        }
        if((a=scanf("%1[^0-9-+]",sep)) && !feof(stdin))
        {
        	fgets(buf,30,stdin);
        	printf("unexpected %d char (%c,%30s)\n",sep[0],sep[0],buf);
        	return 1;
        }
      }
    return 0;
    }