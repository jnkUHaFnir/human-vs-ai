    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define BUF_SIZE  1000
    
    int main(void)
    {
        size_t r = 3;
        size_t c = 5;
        size_t i, j;
        char buffer[BUF_SIZE];
        char *token;
        char *tail;
        int arr[r][c];
        int temp_val;
    
        printf("Enter rows of %zu data elements:\n", c);
        
        for(i = 0; i < r; i++){
            j = 0;
            
            if (fgets(buffer, BUF_SIZE, stdin) == NULL) {
                perror("Error in fgets()");
                exit(EXIT_FAILURE);
            }
    
            token = strtok(buffer, " \n");
            while (token != NULL) {
                temp_val = strtol(token, &tail, 10);
                if (tail != token) {
                    arr[i][j] = temp_val;
                    ++j;
                } else {         // token not a valid number
                    j = 0;
                    break;
                }
                
                if (j > c) {     // too many input elements
                    break;
                }
                
                token = strtok(NULL, " \n");
            }
    
            if (j != c) {
                printf("insufficient datapoints\n");
                --i;                    // enter row again
                continue;
            }
        }
    
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                printf("%5d", arr[i][j]);
            }
            putchar('\n');
        }
        
        return 0;
    }