int main() {
    STACK *sptr = (STACK *)malloc(sizeof(STACK));
    char c[21];
    int ch;
    do {
        create(sptr); // This line resets the stack for each new input
        printf("enter sequence:");
        scanf("%s", c);
        char *msg = isBalanced(c, sptr);
        printf("%s", msg);
        printf("choice?:");
        scanf("%d", &ch);
    } while(ch);
}
char pop(STACK *sptr) {
    if (isEmpty(sptr) == 0)
        return sptr->s[sptr -> top];
    else
        return '$';
}
char pop(STACK *sptr) {
    if (isEmpty(sptr) == 0)
        return sptr->s[sptr->top--];
    else
        return '$';
}
