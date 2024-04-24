#include <stdio.h>
#include <stdlib.h>

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
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(sptr, s[i]);
        } else {
            if (isEmpty(sptr)) {
                return 0;
            }
            char x = pop(sptr);
            switch (s[i]) {
              case ')':
                if (x != '(')
                    return 0; 
                break;
              case '}':
                if (x != '{') 
                    return 0;
                break;
              case ']':
                if (x != '[') 
                    return 0;
                break;
            }
        }
        ++i;
    }

    if (isEmpty(sptr))
        return 1;
    else 
        return 0;
}

int main() {
    STACK *sptr = malloc(sizeof(STACK));
    char c[21];
    int ch;
    do {
        printf("enter sequence:");
        scanf("%s", c);
        printf("%s", (isBalanced(c, sptr) ? "YES" : "NO"));
        printf("\nchoice?:");
        scanf("%d", &ch);

    } while(ch);
}
