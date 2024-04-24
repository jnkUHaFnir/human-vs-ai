void pop(linkedPtr* hd)
{
    if (*hd == NULL) {
        // Handle case when trying to pop from an empty stack
        printf("Stack is empty!\n");
        return;
    }

    linkedPtr tmp = *hd;
    *hd = (*hd)->next;
    free(tmp);
}
pop(&head);
