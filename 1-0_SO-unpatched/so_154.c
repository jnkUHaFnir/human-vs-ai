    #include <stdio.h>
    
    typedef struct stack {
        char s[1000];
        int top;
    } STACK;
    
    void create(STACK *sptr) {
        sptr->top = -1;
    }
    
    int isEmpty(STACK *sptr) {
        if (sptr->top == -1)
            return 1;
        else 
            return 0;
    }
    
    void push(STACK *sptr, char data) {
        sptr->s[++sptr->top] = data;
    }
    
    char pop(STACK *sptr) {
        if (isEmpty(sptr) == 0)
            return sptr->s[sptr->top--];
        else
            return '$';
    }
    int isBalanced(char *s, STACK *sptr) {
        int i;
    
        for (i = 0; s[i] != '\0'; i++) {
            switch (s[i]) {
              case '(':
              case '{':
              case '[':
                push(sptr, s[i]);
                break;
              case ')':
                if (pop(sptr) != '(')
                    return 0; 
                break;
              case '}':
                if (pop(sptr) != '{') 
                    return 0;
                break;
              case ']':
                if (pop(sptr) != '[') 
                    return 0;
                break;
            }
        }
        return isEmpty(sptr);
    }
    int main() {
        STACK s, *sptr = &s;
        char c[100];
        int ch;
        do {
            printf("Enter sequence: ");
            if (scanf("%99s", c) != 1)
                break;
            create(sptr);
            printf("%s\n", isBalanced(c, sptr) ? "YES" : "NO");
            printf("Choice? ");
            scanf("%d", &ch);
        } while (ch);
        return 0;
    }