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
    return (sptr->top == -1);
}

void push(STACK *sptr, char data) {
    sptr->s[++sptr->top] = data;
}

char pop(STACK *sptr) {
    if (!isEmpty(sptr))
        return sptr->s[sptr->top--];
    else
        return '$'; // Handle empty stack case
}

int isBalanced(char *s, STACK *sptr) {
    int i = 0;
    
    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(sptr, s[i]);
        } else {
            if (isEmpty(sptr)) {
                return 0; // Unmatched closing parenthesis
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
    
    return isEmpty(sptr); // Return 1 if stack is empty (balanced), 0 otherwise
}

int main() {
    STACK *sptr = malloc(sizeof(STACK));
    char c[21];
    int ch;
    
    do {
        printf("enter sequence:");
        scanf("%s", c);
        printf("%s\n", (isBalanced(c, sptr) ? "YES" : "NO")); // Print YES if balanced, NO if not balanced
        printf("choice?:");
        scanf("%d", &ch);
    } while (ch);
    
    free(sptr); // Free allocated memory
    return 0;
}
