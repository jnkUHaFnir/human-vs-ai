char pop(STACK *sptr) {
    if (isEmpty(sptr) == 0) {
        return sptr->s[sptr->top--];
    } else {
        return '$';
    }
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
        printf("enter sequence:");
        scanf("%s", c);
        printf("%s", (isBalanced(c, sptr) ? "YES" : "NO"));
        printf("choice?:");
        scanf("%d", &ch);
    } while(ch);
}
