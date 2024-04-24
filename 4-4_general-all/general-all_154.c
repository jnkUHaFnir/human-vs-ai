#include <stdio.h>
#include <stdlib.h>

// Define stack structure
typedef struct stack {
    char s[1000];
    int top;
} STACK;

// Initialize stack
void create(STACK *sptr) {
    sptr->top = -1;
}

// Check if stack is empty
int isEmpty(STACK *sptr) {
    if (sptr->top == -1)
        return 1;
    else
        return 0;
}

// Push element onto stack
void push(STACK *sptr, char data) {
    sptr->s[++sptr->top] = data;
}

// Pop element from stack
char pop(STACK *sptr) {
    if (isEmpty(sptr) == 0)
        return sptr->s[sptr->top--];
    else
        return '$'; // Return '$' or any other special character to indicate empty stack
}

// Check if the parentheses are balanced
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
        return 1; // Stack is empty, balanced
    else
        return 0;
}

int main() {
    STACK *sptr = (STACK *)malloc(sizeof(STACK));
    char c[21];
    int ch;
    do {
        printf("enter sequence:");
        scanf("%s", c);
        
        printf("%s", (isBalanced(c, sptr) ? "YES" : "NO")); // Ternary operator to print YES or NO
        printf("\nchoice?:");
        scanf("%d", &ch);
    } while(ch);
    
    free(sptr); // Free memory allocated for the stack

    return 0;
}
