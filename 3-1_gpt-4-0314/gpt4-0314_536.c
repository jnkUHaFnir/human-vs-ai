void pop(linkedPtr* hd) {
    linkedPtr tmp = *hd;
    *hd = (*hd)->next;
    free(tmp);
}
while (!isEmpty(head)) {
    printf("Top of stack value is: %d\n", top(head));
    pop(&head);
}
