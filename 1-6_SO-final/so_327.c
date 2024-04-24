    #include<stdio.h>
    
    int main (void) {
    
        char buf[32] = {0};
        int num = 0;
        
        while (printf (" Enter a positive number: ") &&
                scanf (" %[^\n]%*c", buf) == 1 && 
                *buf == '-');
            sscanf (buf, " %d", &num);
        
        printf ("\n You entered : %d\n\n", num);
            
        return 0;
    }