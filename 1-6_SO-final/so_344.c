    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    enum { MAXLINES = 30 };
    
    int main(void)
    {
        int i = 0;
        char lines[MAXLINES][BUFSIZ];
        FILE *fp = fopen("input.txt", "r");
    
        if (fp == 0)
        {
            fprintf(stderr, "failed to open input.txt");
            exit(1);
        }
        while (i < MAXLINES && fgets(lines[i], sizeof(lines[0]), fp))
        {
            lines[i][strlen(lines[i])-1) = '\0';
            i = i + 1;
        }
        fclose(fp);
        printf("%d", i);
        int j = rand() % i;
        int k = (j+1) % i;
        printf("%s %s", lines[j], lines[k]); 
        return 0;
    }