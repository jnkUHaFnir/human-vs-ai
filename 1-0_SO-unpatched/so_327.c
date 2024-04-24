    #include<stdio.h>
    
    int main (void) {
    
        char buf[32] = {0};
        int num = -1;
        
        while ( num < 0) {
            printf (" Enter a positive number: ");
            scanf (" %[^\n]%*c", buf);
            if (*buf < '0' || *buf > '9') continue;
            sscanf (buf, " %d", &num);
        }
        
        printf ("\n You entered : %d\n\n", num);
            
        return 0;
    }