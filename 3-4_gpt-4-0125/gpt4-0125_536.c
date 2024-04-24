void pop (linkedPtr* hd)
{
    if (*hd == NULL) {
        return;
    }

    linkedPtr tmp = *hd;
    *hd = (*hd)->next;
    free(tmp);
}
pop(&head);
while (!isEmpty(head))
{
    printf("Top of stack value is: %d\n", top(head));
    pop(&head);
}
