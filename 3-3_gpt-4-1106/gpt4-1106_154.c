char pop(STACK *sptr) {
    if (!isEmpty(sptr)) {
        return sptr->s[sptr->top--]; // Decrement top after returning the value.
    } else {
        return '$'; // Or some invalid value that will never match with any bracket.
    }
}
int main() {
    STACK *sptr = (STACK *)malloc(sizeof(STACK));
    create(sptr); // Initialize the stack before use.
    // ... rest of your code ...
}
int main() {
    STACK *sptr = malloc(sizeof(STACK));
    char c[21];
    int ch;
    do {
        create(sptr); // Initialize the stack before each check
        printf("enter sequence:");
        scanf("%s", c);
        printf("%s\n", (isBalanced(c, sptr) ? "YES" : "NO")); // Add newline for readability
        printf("choice?:");
        scanf("%d", &ch);
    } while(ch);
}
// ... rest of your code ...

int main() {
    // ... previous code...

    free(sptr); // Deallocate the stack when done
    return 0; // Signal successful termination
}
