    #include <stdio.h>
    
    int main()
    {
        int v;
        if (scanf("%d", &v) == 1) {
            printf("OK\n");
        } else {
            printf("Not an integer.\n");
    	}
        return 0;
    }