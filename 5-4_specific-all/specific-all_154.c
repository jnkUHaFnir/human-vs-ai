char pop(STACK *sptr) {
    if (isEmpty(sptr) == 0)
        return sptr->s[sptr->top--]; // Decrement top after retrieving the element
    else
        return '$';
}
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
    return sptr->top == -1 ? 1 : 0;
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

    return isEmpty(sptr) ? 1 : 0;
}

int main() {
    STACK *sptr = malloc(sizeof(STACK));
    char c[21];
    int ch;
    do {
        printf("Enter sequence: ");
        scanf("%20s", c); // Limit input to avoid buffer overflow
        printf("%s\n", (isBalanced(c, sptr) ? "YES" : "NO"));
        printf("Continue? (1/0): ");
        scanf("%d", &ch);

    } while (ch != 0);

    free(sptr); // Free allocated memory before exiting
    return 0;
}
