    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    typedef struct node node;
    
    struct node {
        node *node0;
        node *node1;
        node *node2;
        node *node3;
        node *node4;
        node *node5;
        node *node6;
        node *node7;
        node *node8;
        node *node9;
        char *text;
    };
    
    node *top;
    
    void set(unsigned long long A, char *B)
    {
        unsigned char n;
        node *way,**next;
    
        way = top;
    
        for (;A>0; A=A/10)
        {
            n = A % 10;
    
            switch (n)
            {
            case 0:
               next = &way->node0;
               break;
    
            case 1:
               next = &way->node1;
               break;
    
            case 2:
               next = &way->node2;
               break;
    
            case 3:
               next = &way->node3;
               break;
    
            case 4:
               next = &way->node4;
               break;
    
            case 5:
               next = &way->node5;
               break;
    
            case 6:
               next = &way->node6;
               break;
    
            case 7:
               next = &way->node7;
               break;
    
            case 8:
               next = &way->node8;
               break;
    
            default:
               next = &way->node9;
               break;
    
            }
    
            if (*next == NULL)
            {
                *next = malloc(sizeof(node));
                memset(*next, 0, sizeof(node));
            }
    
            way = *next;
    
        }
    
        if (way->text != NULL)
        {
            free(way->text);
        }
    
        way->text = malloc(sizeof(char)*strlen(B)+sizeof(char));
        strcpy(way->text, B);
    
    }
    
    char *get(unsigned long long A)
    {
        unsigned char n;
        node *way;
    
        way = top;
    
        for (; A>0 && way != NULL; A=A/10)
        {
            n = A % 10;
    
            switch (n)
            {
            case 0:
               way = way->node0;
               break;
    
            case 1:
               way = way->node1;
               break;
    
            case 2:
               way = way->node2;
               break;
    
            case 3:
               way = way->node3;
               break;
    
            case 4:
               way = way->node4;
               break;
    
            case 5:
               way = way->node5;
               break;
    
            case 6:
               way = way->node6;
               break;
    
            case 7:
               way = way->node7;
               break;
    
            case 8:
               way = way->node8;
               break;
    
            default:
               way = way->node9;
               break;
    
            }
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
        memset(top, 0, sizeof(node));
    
        set(1230294381243, "test1");
        set(12934839, "test2");
    
        printf("%s", get(1230294381243));
        printf("%s", get(12934839));
    
        // to do: free memory from *top* variable
        // free_way(top);
    
        return 0;
    }