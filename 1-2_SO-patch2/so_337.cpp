    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    typedef struct node node;
    
    struct node {
        node *nodes[0xf];
        char *text;
    };
    
    node *top;
    
    void set(unsigned long long A, char *B)
    {
        unsigned char n;
        node *way;
    
        way = top;
    
        for (;A>0;A>>=4)
        {
            n = A & 0xf;
    
            if (way->nodes[n] == NULL)
            {
                way->nodes[n] = malloc(sizeof(node));
                memset(way->nodes[n], 0, sizeof(node));
            }
    
            way = way->nodes[n];
        }
    
        if (way->text != NULL)
        {
            free(way->text);
        }
    
        way->text = strdup(B);
    }
    
    char *get(unsigned long long A)
    {
        unsigned char n;
        node *way;
    
        way = top;
    
        for (; A>0 && way != NULL; A>>=4)
        {
            n = A & 0xf;
            way = way->nodes[n];
        }
    
        if (A == 0 && way != NULL)
        {
            return way->text;
        }
    
        return NULL;
    }
    
    int main()
    {
        top = malloc(sizeof(node));
        memset(top,0,sizeof(node));
    
        set(1230294381243, "test1");
        set(12934839, "test2");
        set(1,"tezt");
    
        printf("%s", get(1230294381243));
        printf("%s", get(12934839));
        printf("%s", get(1));
    
    //    todo: free memory
    //    free_way(top); 
    
        return 0;
    }