#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000

typedef struct stack {
    char s[MAX_STACK_SIZE];
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

int isFull(STACK *sptr) {
    if (sptr->top == MAX_STACK_SIZE-1)
        return 1;
    else
        return 0;
}

void push(STACK *sptr, char data) {
    if (isFull(sptr)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    sptr->s[++sptr->top] = data;
}

char pop(STACK *sptr) {
    if (isEmpty(sptr)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return sptr->s[sptr->top--];
}

int isBalanced(char *s, STACK *sptr) {
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(sptr, s[i]);
        } else {
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
    create(sptr);
    char c[21];
    int ch;
    do {
        printf("Enter sequence:");
        scanf("%s", c);
        printf("%s\n", (isBalanced(c, sptr) ? "YES" : "NO"));
        printf("Continue? (0 to exit): ");
        scanf("%d", &ch);

    } while(ch);
    free(sptr);
    return 0;
}
