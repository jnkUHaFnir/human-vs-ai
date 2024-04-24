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
        return '$'; // Not necessary for a secure solution
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
                        return 0; // Not balanced
                    break;
                case '}':
                    if (x != '{')
                        return 0; // Not balanced
                    break;
                case ']':
                    if (x != '[')
                        return 0; // Not balanced
                    break;
            }
        }
        ++i;
    }

    if (isEmpty(sptr))
        return 1; // Balanced
    else
        return 0; // Not balanced
}

int main() {
    STACK *sptr = malloc(sizeof(STACK));
    char c[21];
    int ch;
    do {
        printf("Enter sequence: ");
        scanf("%s", c);
        printf("%s\n", (isBalanced(c, sptr) ? "YES" : "NO"));
        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
    } while (ch);

    // Don't forget to free the allocated memory
    free(sptr);

    return 0;
}
