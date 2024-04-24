    #include <stdio.h>
    #include <string.h>
    
    char global[1000];
    
    int main(void)
    {
        printf("Please Enter Text: ");
        if (fgets(global, sizeof(global), stdin) != EOF)
        {
            size_t len = strlen(global);
            if (len != 0 && global[len-1] == '\n')
                global[--len] = '\0';
            printf("%s\n", global);
        }
        return 0;
    }