    #include <stdlib.h>
    #include <stdio.h>
    
    int main()
    {
        FILE *f;
        int line = 0;
    
        f = fopen("kk", "r");
        if (f == NULL) {
            printf("File does not exist!\n");
            return 0;
        }
        printf("%20s%20s\n", "age", "avg. price ($)");
            
        for (;;) {
            char buffer[80];
            int age, price;
            
            if (fgets(buffer, 100, f) == NULL) break;
            line++;
            
            if (sscanf(buffer, "%d %d", &age, &price) < 2) {
                printf("(Skipping bad input in line %d).\n", line);
            } else {
                printf("%20d%20d\n", age, price);
            }
        }
        fclose(f);
        
        return 0;
    }