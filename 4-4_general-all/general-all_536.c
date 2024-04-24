void pop(linkedPtr *hd)
{
    if (*hd == NULL) {
        return; // No elements to pop
    }

    linkedPtr tmp = *hd;
    *hd = (*hd)->next;
    free(tmp);
}
pop(&head);
